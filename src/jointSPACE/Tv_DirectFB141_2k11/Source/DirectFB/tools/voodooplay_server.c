/*
   (c) Copyright 2001-2010  The world wide DirectFB Open Source Community (directfb.org)
   (c) Copyright 2000-2004  Convergence (integrated media) GmbH

   All rights reserved.

   Written by Denis Oliver Kropp <dok@directfb.org>,
              Andreas Hundt <andi@fischlustig.de>,
              Sven Neumann <neo@directfb.org>,
              Ville Syrjälä <syrjala@sci.fi> and
              Claudio Ciccani <klan@users.sf.net>.

   This file is subject to the terms and conditions of the MIT License:

   Permission is hereby granted, free of charge, to any person
   obtaining a copy of this software and associated documentation
   files (the "Software"), to deal in the Software without restriction,
   including without limitation the rights to use, copy, modify, merge,
   publish, distribute, sublicense, and/or sell copies of the Software,
   and to permit persons to whom the Software is furnished to do so,
   subject to the following conditions:

   The above copyright notice and this permission notice shall be
   included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
   CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
   TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
   SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <config.h>

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <directfb.h>

#include <direct/debug.h>
#include <direct/interface.h>
#include <direct/mem.h>
#include <direct/messages.h>
#include <direct/util.h>

#include <voodoo/app.h>
#include <voodoo/play.h>
#include <voodoo/play_server.h>

#define APPFILENAME     "./application.lst"
#define LINE_LENGTH     (255)
#define MAXAPPS         (256)

typedef struct
{
	char    name[VOODOO_APP_DESCRIPTION_NAME_LENGTH];
	char    exe[256];
	char    arg[256];
} AppInfo;

static AppInfo     appstable[MAXAPPS];
static int         nbapps = 0;
static const char  *m_name = NULL;
static pid_t       oldp=-1;

/**********************************************************************************************************************/

static DFBBoolean parse_command_line( int argc, char *argv[] );

/**********************************************************************************************************************/

/*
 * FIXME
 */
static void
generate_uuid( u8 *buf )
{
     int i;

     for (i=0; i<16; i++) {
          buf[i] = rand();
     }
}

static void
player_exec( const char *prog,
			 const char *arg,
             const char *addr )
{
     char addr_arg[100];
	 char argcopy[256]; // Total argument string < 256 chars
     char * argv[64];   // Max 64 arguments!
	 int i,j;
	 int argsize;

     snprintf( addr_arg, sizeof(addr_arg), "--dfb:remote=%s", addr );

	 i = 0;
	 argv[i++] = (char*)prog;
	 argv[i++] = addr_arg;
	 j = 0;
	 strcpy(argcopy, arg);
	 argsize = strlen(arg);
	 while ( (arg[j]) && (i<64) && (j<argsize) )
	 {
	   argv[i++] = &argcopy[j];
	   while ( (arg[j] != 0 ) && (arg[j] != ' ') )
	   {
		   j++;
	   }
	   argcopy[j++] = 0;
	 }
	 argv[i++] = NULL;

//	 i=0;
//     while(argv[i])
//	 {
//		 printf("%s\n", argv[i]);
//		 i++;
//	 }


     execv( prog, argv );
//     execl( prog, prog, addr_arg, arg, NULL );

     D_PERROR( "exec( %s %s ) failed!\n", prog, addr_arg );

     exit( 1 );
}

static     VoodooAppDescription apps[MAXAPPS];


static DirectResult
player_launch( VoodooPlayer                *player,
               void                        *ctx,
               const VoodooAppDescription  *app,
               const VoodooPlayInfo        *player_info,
               const char                  *player_addr,
               void                       **ret_data )
{
	 int i;
     D_INFO( "Received launch request for '%s' to run on '%s' (%s)!\n",
             app->name, player_info->name, player_addr );

     pid_t p = fork();

     switch (p) {
          case 0:
			   for (i=0; i<nbapps; i++)
			   {
			       if (!strcmp( app->name, appstable[i].name )) 
				   {
					   if (oldp > 0)
					   {
                           kill( oldp, SIGKILL );
					   }
                       oldp = p;
                       player_exec( appstable[i].exe, appstable[i].arg, player_addr );
				   }
               }

               D_BUG( "Invalid application" );
               exit(1);

               break;

          default:
               D_INFO( "Child process has pid %d\n", p );
               *ret_data = (void*) p;
               break;
     }

     return DR_OK;
}

static DirectResult
player_stop( VoodooPlayer *player,
             void         *ctx,
             void         *data )
{
     pid_t p = (pid_t) data;

     D_INFO( "Received stop request for pid %d\n", p );

     kill( p, SIGTERM );

     sleep( 1 );

     kill( p, SIGKILL );

     return DR_OK;
}

static void FindString( char **param, int size, char *result )
{
    char *Cptr = NULL;
    
    Cptr = *param;
    while( *Cptr == ' ' )
    {
        Cptr++;
    }
    while( ( *Cptr != ';' ) && ( *Cptr != ':' ) && ( *Cptr != '\0' ) && ( *Cptr != '\n' ) && ( *Cptr != '\r' ) && (size>0) )
    {
        *result = *Cptr;
        result++;
        Cptr++;
		size--;
    }
    *result = '\0';
    Cptr++;
    *param = Cptr;
}


int
main( int argc, char *argv[] )
{
     DFBResult       ret;
     VoodooPlayInfo  info   = {0};
     VoodooPlayer   *player = NULL;
     FILE*   fd = NULL;
     char    Line[ LINE_LENGTH ];
     char    *Cptr;

     srand( direct_clock_get_abs_micros() );

     /* Initialize DirectFB including command line parsing. */
     ret = DirectFBInit( &argc, &argv );
     if (ret) {
          DirectFBError( "DirectFBInit() failed", ret );
          return -1;
     }

     /* Parse the command line. */
     if (!parse_command_line( argc, argv ))
          return -2;

     if (m_name) {
          direct_snputs( info.name, m_name, VOODOO_PLAYER_NAME_LENGTH );
     }

     ret = voodoo_player_create( m_name ? &info : NULL, &player );
     if (ret) {
          D_ERROR( "Voodoo/Play: Could not create the player (%s)!\n", DirectFBErrorString(ret) );
          goto out;
     }

     voodoo_player_broadcast( player );

     sleep( 2 );
    


    if ( (fd = fopen( APPFILENAME, "r" )) )
	{
        nbapps = 0;
        while( (fgets( Line, LINE_LENGTH - 1, fd ) != NULL) && (nbapps < MAXAPPS) )
        {
            Cptr = Line;
            if( *Cptr != '#' ) // skip comment lines
            {
               FindString( &Cptr, VOODOO_APP_DESCRIPTION_NAME_LENGTH, appstable[nbapps].name );
			   if ( !strlen(appstable[nbapps].name) ) continue;
               FindString( &Cptr, 256, appstable[nbapps].exe );
			   if ( !strlen(appstable[nbapps].exe) ) continue;
               FindString( &Cptr, 256, appstable[nbapps].arg );
			   printf("%s  %s  %s\n", appstable[nbapps].name, appstable[nbapps].exe, appstable[nbapps].arg);
               generate_uuid( apps[nbapps].uuid );
               apps[nbapps].flags = VADESC_NAME;
               direct_snputs( apps[nbapps].name, appstable[nbapps].name, VOODOO_APP_DESCRIPTION_NAME_LENGTH );
			   nbapps++;
			}
        }

        fclose( fd );
	}

     voodoo_player_run_server( player, apps, nbapps, player_launch, player_stop, NULL );

out:
     if (player)
          voodoo_player_destroy( player );

     return ret;
}

/**********************************************************************************************************************/

static DFBBoolean
print_usage( const char *name )
{
     fprintf( stderr, "Usage: %s [-n <name>] [-r]\n", name );

     return DFB_FALSE;
}

static DFBBoolean
parse_command_line( int argc, char *argv[] )
{
     int i;

     for (i=1; i<argc; i++) {
          if (!strcmp( argv[i], "-n" )) {
               if (++i == argc)
                    return print_usage( argv[0] );

               m_name = argv[i];
          }
     }

     return DFB_TRUE;
}

