/*
   (c) Copyright 2006-2007  directfb.org

   All rights reserved.

   Written by Denis Oliver Kropp <dok@directfb.org>.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the
   Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#include <config.h>

#include <direct/interface.h>
#include <direct/memcpy.h>
#include <direct/messages.h>

#include <fusion/fusion.h>
#include <fusion/shmalloc.h>

#include <sawman.h>
#include <sawman_internal.h>

#include "isawman.h"
#include "isawmanmanager.h"


static ReactionResult ISaWMan_Tier_Update( const void *msg_data,
                                           void       *ctx );

/**********************************************************************************************************************/

static void
ISaWMan_Destruct( ISaWMan *thiz )
{
     ISaWMan_data *data = thiz->priv;

     fusion_reactor_detach( ((SaWManTier*) data->sawman->tiers)->reactor, &data->reaction );

     pthread_mutex_destroy( &data->lock );
     pthread_cond_destroy( &data->cond );

     dfb_updates_deinit( &data->updates );

     DIRECT_DEALLOCATE_INTERFACE( thiz );
}

/**********************************************************************************************************************/

static DirectResult
ISaWMan_AddRef( ISaWMan *thiz )
{
     DIRECT_INTERFACE_GET_DATA( ISaWMan )

     data->ref++;

     return DFB_OK;
}

static DirectResult
ISaWMan_Release( ISaWMan *thiz )
{
     DIRECT_INTERFACE_GET_DATA( ISaWMan )

     if (--data->ref == 0)
          ISaWMan_Destruct( thiz );

     return DFB_OK;
}

/**********************************************************************************************************************/

static DirectResult
ISaWMan_Start( ISaWMan    *thiz,
               const char *name,
               pid_t      *ret_pid )
{
     int     ret;
     char   *tmp = NULL;
     SaWMan *sawman;

     DIRECT_INTERFACE_GET_DATA( ISaWMan )

     if (!name)
          return DFB_INVARG;

     sawman = data->sawman;

     D_MAGIC_ASSERT( sawman, SaWMan );

     ret = sawman_lock( sawman );
     if (ret)
          goto out;

     tmp = SHSTRDUP( sawman->shmpool, name );
     if (!tmp) {
          ret = D_OOSHM();
          goto out;
     }

     ret = sawman_call( sawman, SWMCID_START, tmp );
     if (ret < 0) {
          if (ret_pid)
               *ret_pid = -ret;
          ret = DFB_OK;
     }

out:
     if (tmp)
          SHFREE( sawman->shmpool, tmp );

     sawman_unlock( sawman );

     return ret;
}

static DirectResult
ISaWMan_Stop( ISaWMan *thiz,
              pid_t    pid )
{
     DirectResult  ret;
     SaWMan       *sawman;

     DIRECT_INTERFACE_GET_DATA( ISaWMan )

     sawman = data->sawman;

     D_MAGIC_ASSERT( sawman, SaWMan );

     ret = sawman_lock( sawman );
     if (ret)
          return ret;

     ret = sawman_call( sawman, SWMCID_STOP, (void*)(long) pid );

     sawman_unlock( sawman );

     return ret;
}

static DirectResult
ISaWMan_ReturnKeyEvent( ISaWMan        *thiz,
                        DFBWindowEvent *event )
{
     DirectResult  ret;
     SaWMan       *sawman;

     DIRECT_INTERFACE_GET_DATA( ISaWManManager )

     if (!event)
          return DFB_INVARG;

     /* Only key events! */
     if (event->type != DWET_KEYDOWN && event->type != DWET_KEYUP)
          return DFB_UNSUPPORTED;

     /* Don't return same event twice! 'flags' is only valid for KEY events. */
     if (event->flags & DWEF_RETURNED)
          return DFB_LIMITEXCEEDED;

     event->flags |= DWEF_RETURNED;

     sawman = data->sawman;
     D_MAGIC_ASSERT( sawman, SaWMan );

     ret = sawman_lock( sawman );
     if (ret)
          return ret;

     if (sawman->unselkeys_window)
          ret = sawman_post_event( sawman, sawman->unselkeys_window, event );

     sawman_unlock( sawman );

     return ret;
}

static DirectResult
ISaWMan_CreateManager( ISaWMan                  *thiz,
                       const SaWManCallbacks    *callbacks,
                       void                     *context,
                       ISaWManManager          **ret_manager )
{
     DirectResult    ret;
     ISaWManManager *manager;
     SaWMan         *sawman;

     DIRECT_INTERFACE_GET_DATA( ISaWMan )

     if (!callbacks || !ret_manager)
          return DFB_INVARG;

     sawman = data->sawman;

     D_MAGIC_ASSERT( sawman, SaWMan );

     ret = sawman_lock( sawman );
     if (ret)
          return ret;

     ret = sawman_register( sawman, callbacks, context );
     if (ret)
          goto out;

     DIRECT_ALLOCATE_INTERFACE( manager, ISaWManManager );

     ret = ISaWManManager_Construct( manager, data->sawman, data->process );
     if (ret) {
          /* FIXME: sawman_unregister! */
          goto out;
     }

     *ret_manager = manager;

     /*
      * Attach to existing entities.
      */
     if (callbacks->ProcessAdded) {
          SaWManProcess *process;

          direct_list_foreach (process, sawman->processes) {
               D_MAGIC_ASSERT( process, SaWManProcess );

               callbacks->ProcessAdded( context, process );
          }
     }

     if (callbacks->WindowAdded) {
          SaWManWindow     *window;
          SaWManWindowInfo *info;
          
          info = &sawman->callback.info;
          direct_list_foreach (window, sawman->windows) {
               D_MAGIC_ASSERT( window, SaWManWindow );
               info->handle = (SaWManWindowHandle)window;
               info->caps   = window->caps;
               SAWMANWINDOWCONFIG_COPY( &info->config, &window->window->config )

               callbacks->WindowAdded( context, info );
          }
     }


out:
     sawman_unlock( sawman );

     return ret;
}

static DirectResult
ISaWMan_GetUpdates( ISaWMan                *thiz,
                    DFBWindowStackingClass  stacking_class,
                    DFBRegion              *ret_updates,
                    unsigned int           *ret_num )
{
     DIRECT_INTERFACE_GET_DATA( ISaWMan )

     if (!ret_updates || !ret_num)
          return DFB_INVARG;

     pthread_mutex_lock( &data->lock );

     while (!data->updates.num_regions) {
          pthread_cond_wait( &data->cond, &data->lock );
     }

     direct_memcpy( ret_updates, data->updates.regions, sizeof(DFBRegion) * data->updates.num_regions );

     *ret_num = data->updates.num_regions;

     dfb_updates_reset( &data->updates );

     pthread_mutex_unlock( &data->lock );

     return DFB_OK;
}

/**********************************************************************************************************************/

DirectResult
ISaWMan_Construct( ISaWMan       *thiz,
                   SaWMan        *sawman,
                   SaWManProcess *process )
{
     DIRECT_ALLOCATE_INTERFACE_DATA( thiz, ISaWMan )

     data->ref     = 1;
     data->sawman  = sawman;
     data->process = process;

     pthread_mutex_init( &data->lock, NULL );
     pthread_cond_init( &data->cond, NULL );

     dfb_updates_init( &data->updates, data->updates_regions, D_ARRAY_SIZE(data->updates_regions) );

//     fusion_reactor_attach_channel( ((SaWManTier*) sawman->tiers->next)->reactor,
//                                    SAWMAN_TIER_UPDATE, ISaWMan_Tier_Update, data, &data->reaction );

     thiz->AddRef         = ISaWMan_AddRef;
     thiz->Release        = ISaWMan_Release;
     thiz->Start          = ISaWMan_Start;
     thiz->Stop           = ISaWMan_Stop;
     thiz->ReturnKeyEvent = ISaWMan_ReturnKeyEvent;
     thiz->CreateManager  = ISaWMan_CreateManager;
     thiz->GetUpdates     = ISaWMan_GetUpdates;

     return DFB_OK;
}

/**********************************************************************************************************************/

static ReactionResult
ISaWMan_Tier_Update( const void *msg_data,
                     void       *ctx )
{
     int                     i;
     const SaWManTierUpdate *update = msg_data;
     ISaWMan_data           *data   = ctx;

     pthread_mutex_lock( &data->lock );
     
     for (i=0; i<update->num_regions; i++) {
          dfb_updates_add( &data->updates, &update->regions[i] );
     }
          
     pthread_mutex_unlock( &data->lock );

     pthread_cond_broadcast( &data->cond );

     return RS_OK;
}
