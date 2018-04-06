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
#include <directfb_strings.h>
#include <directfb_util.h>

static const DirectFBPixelFormatNames( format_names );

/**********************************************************************************************************************/

static int
print_usage( const char *prg )
{
     int i = 0;

     fprintf (stderr, "\n");
     fprintf (stderr, "== DirectFB Font Test (version %s) ==\n", DIRECTFB_VERSION);
     fprintf (stderr, "\n");
     fprintf (stderr, "Known pixel formats:\n");

     while (format_names[i].format != DSPF_UNKNOWN) {
          DFBSurfacePixelFormat format = format_names[i].format;

          fprintf (stderr, "   %-10s %2d bits, %d bytes",
                   format_names[i].name, DFB_BITS_PER_PIXEL(format),
                   DFB_BYTES_PER_PIXEL(format));

          if (DFB_PIXELFORMAT_HAS_ALPHA(format))
               fprintf (stderr, "   ALPHA");

          if (DFB_PIXELFORMAT_IS_INDEXED(format))
               fprintf (stderr, "   INDEXED");

          if (DFB_PLANAR_PIXELFORMAT(format)) {
               int planes = DFB_PLANE_MULTIPLY(format, 1000);

               fprintf (stderr, "   PLANAR (x%d.%03d)",
                        planes / 1000, planes % 1000);
          }

          fprintf (stderr, "\n");

          ++i;
     }

     fprintf (stderr, "\n");

     fprintf (stderr, "\n");
     fprintf (stderr, "Usage: %s [options] <file>\n", prg);
     fprintf (stderr, "\n");
     fprintf (stderr, "Options:\n");
     fprintf (stderr, "  -h, --help                        Show this help message\n");
     fprintf (stderr, "  -v, --version                     Print version information\n");

     return -1;
}

/**********************************************************************************************************************/

static IDirectFBFont *
CreateFont( IDirectFB *dfb, const char *url, int size )
{
     DFBResult           ret;
     DFBFontDescription  fdesc;
     IDirectFBFont      *font;

     /* Create the font. */
     fdesc.flags  = DFDESC_HEIGHT;
     fdesc.height = size;

     ret = dfb->CreateFont( dfb, url, &fdesc, &font );
     if (ret) {
          D_DERROR( ret, "DFBTest/Font: IDirectFB::CreateFont( '%s' ) failed!\n", url );
          return NULL;
     }

     return font;
}

int
main( int argc, char *argv[] )
{
     int                     i;
     DFBResult               ret;
     DFBSurfaceDescription   desc;
     IDirectFB              *dfb;
     IDirectFBSurface       *dest = NULL;
     const char             *url  = NULL;

     /* Initialize DirectFB. */
     ret = DirectFBInit( &argc, &argv );
     if (ret) {
          D_DERROR( ret, "DFBTest/Font: DirectFBInit() failed!\n" );
          return ret;
     }

     /* Parse arguments. */
     for (i=1; i<argc; i++) {
          const char *arg = argv[i];

          if (strcmp( arg, "-h" ) == 0 || strcmp (arg, "--help") == 0)
               return print_usage( argv[0] );
          else if (strcmp (arg, "-v") == 0 || strcmp (arg, "--version") == 0) {
               fprintf (stderr, "dfbtest_blit version %s\n", DIRECTFB_VERSION);
               return false;
          }
          else if (!url)
               url = arg;
          else
               return print_usage( argv[0] );
     }

     /* Check if we got an URL. */
     if (!url)
          return print_usage( argv[0] );
          
     /* Create super interface. */
     ret = DirectFBCreate( &dfb );
     if (ret) {
          D_DERROR( ret, "DFBTest/Font: DirectFBCreate() failed!\n" );
          return ret;
     }

     /* Fill description for a primary surface. */
     desc.flags = DSDESC_CAPS;
     desc.caps  = DSCAPS_PRIMARY | DSCAPS_FLIPPING;

     dfb->SetCooperativeLevel( dfb, DFSCL_FULLSCREEN );

     /* Create a primary surface. */
     ret = dfb->CreateSurface( dfb, &desc, &dest );
     if (ret) {
          D_DERROR( ret, "DFBTest/Font: IDirectFB::CreateSurface() failed!\n" );
          goto out;
     }

     dest->GetSize( dest, &desc.width, &desc.height );
     dest->GetPixelFormat( dest, &desc.pixelformat );

     D_INFO( "DFBTest/Font: Destination is %dx%d using %s\n",
             desc.width, desc.height, dfb_pixelformat_name(desc.pixelformat) );

     dest->SetColor( dest, 0xff, 0xff, 0xff, 0xff );


     IDirectFBFont *font;

     font = CreateFont( dfb, url, 20 );

     for (i=10; i<50; i++) {
          dest->Clear( dest, 0, 0, 0, 0 );

          dest->SetFont( dest, font );
          dest->DrawString( dest, "Test string with lots of characters", -1, 100, 100, DSTF_TOPLEFT );

          dest->Flip( dest, NULL, DSFLIP_NONE );

          sleep( 1 );
     }

     font->Release( font );


out:
     if (dest)
          dest->Release( dest );

     /* Shutdown DirectFB. */
     dfb->Release( dfb );

     return ret;
}

