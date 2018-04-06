/*
   (c) Copyright 2008  Denis Oliver Kropp

   All rights reserved.

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

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <direct/messages.h>

#include <directfb.h>
#include <directfb_util.h>


static void
write_data( void *ptr,
            int   size )
{
     int  i;
     u16 *p = ptr;

     for (i=0; i<size/2; i++) {
          p[i] = i%64;
     }
}

int
main( int argc, char *argv[] )
{
     DFBResult  ret;
     int        w;
     IDirectFB *dfb;

     /* Initialize DirectFB. */
     ret = DirectFBInit( &argc, &argv );
     if (ret) {
          D_DERROR( ret, "DFBTest/Write: DirectFBInit() failed!\n" );
          return ret;
     }

     /* Create super interface. */
     ret = DirectFBCreate( &dfb );
     if (ret) {
          D_DERROR( ret, "DFBTest/Write: DirectFBCreate() failed!\n" );
          return ret;
     }

     IDirectFBDisplayLayer *layer;
     IDirectFBWindow       *window;
     IDirectFBSurface      *dest;
     IDirectFBSurface      *temp;

     dfb->GetDisplayLayer( dfb, DLID_PRIMARY, &layer );

     /* Fill description for a primary surface. */
     DFBSurfaceDescription  sdesc;
     sdesc.flags        = DSDESC_CAPS | DSDESC_RESOURCE_ID;
     sdesc.caps         = DSCAPS_VIDEOONLY;
     sdesc.resource_id  = 1100;

     sdesc.flags       |= DSDESC_PIXELFORMAT;
     sdesc.pixelformat  = DSPF_ARGB;

     sdesc.flags       |= DSDESC_WIDTH | DSDESC_HEIGHT;
     sdesc.width        = 320;
     sdesc.height       = 200;

     /* Create a primary surface. */
     ret = dfb->CreateSurface( dfb, &sdesc, &temp );
     if (ret) {
          D_DERROR( ret, "DFBTest/Write: IDirectFB::CreateSurface() failed!\n" );
          return ret;
     }


     DFBWindowDescription desc;

     desc.flags        = DWDESC_RESOURCE_ID;
     desc.resource_id  = 1100;

     desc.flags       |= DWDESC_PIXELFORMAT;
     desc.pixelformat  = DSPF_ARGB;

     desc.flags       |= DWDESC_WIDTH | DWDESC_HEIGHT;
     desc.width        = 320;
     desc.height       = 200;

     /* Create a primary surface. */
     ret = layer->CreateWindow( layer, &desc, &window );
     if (ret) {
          D_DERROR( ret, "DFBTest/Write: IDirectFB::CreateWindow() failed!\n" );
          return ret;
     }

     window->GetSurface( window, &dest );

     window->SetOpacity( window, 0xff );

     dest->GetSize( dest, &desc.width, &desc.height );
     dest->GetPixelFormat( dest, &desc.pixelformat );

     D_INFO( "DFBTest/Write: Destination is %dx%d using %s\n",
             desc.width, desc.height, dfb_pixelformat_name(desc.pixelformat) );


     int   pitch = DFB_BYTES_PER_LINE( desc.pixelformat, desc.width );
     void *buf   = malloc( pitch * desc.height );

     for (w=0; w<10; w++) {
          memset( buf, w * 0x55, pitch * desc.height );


          DFBRectangle rect = { 0, 0, desc.width, desc.height };

          temp->Write( temp, &rect, buf, pitch );

          dest->SetBlittingFlags( dest, DSBLIT_BLEND_ALPHACHANNEL );
          dest->Blit( dest, temp, NULL, 0, 0 );
          dest->Blit( dest, temp, NULL, 0, 0 );
          dest->Blit( dest, temp, NULL, 0, 0 );
          dest->Blit( dest, temp, NULL, 0, 0 );
          dest->Flip( dest, NULL, DSFLIP_NONE );

          dfb->WaitIdle( dfb );

//          sleep( 1 );
     }

     temp->Release( temp );
     dest->Release( dest );

     /* Shutdown DirectFB. */
     dfb->Release( dfb );

     return ret;
}

