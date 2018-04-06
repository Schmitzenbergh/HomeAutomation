#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <direct/types.h>

#include <directfb.h>


/* macro for a safe call to DirectFB functions */
#define DFBCHECK(x...)                                           \
do {                                                             \
     int err = x;                                                \
     if (err != DFB_OK) {                                        \
          fprintf( stderr, "%s <%d>:\n\t", __FILE__, __LINE__ ); \
          DirectFBErrorFatal( #x, err );                         \
     }                                                           \
} while (0)


#define ERROR(x...)                                              \
do {                                                             \
     fprintf (stderr, "%s <%i>: ", __FILE__, __LINE__);          \
        fprintf (stderr, x);                                     \
        fprintf (stderr, "\n");                                  \
     exit (-1);                                                  \
} while (0)


static char **fontname_list;
static int fontname_count;

static IDirectFB             *dfb;
static IDirectFBEventBuffer  *keybuffer;
static IDirectFBDisplayLayer *layer;
static IDirectFBSurface      *surface;

static int show_help         = 0;
static int show_ascender     = 0;
static int show_descender    = 0;
static int show_baseline     = 0;
static int show_glyphrect    = 0;
static int show_glyphadvance = 0;
static int show_glyphorigin  = 0;

static int antialias         = 1;
static int unicode_mode      = 1;

static DFBEnumerationResult
encoding_callback( DFBTextEncodingID  id,
                   const char        *name,
                   void              *context )
{
     printf( "  (%02d) %s\n", id, name );

     return DFENUM_OK;
}

static void
render_font_page (IDirectFBSurface *surface,
                  const char       *fontname1,
                  const char       *fontname2)
{
     DFBFontDescription fontdesc;
     IDirectFBFont *font1, *font2;
     int width, height;
     int bwidth, bheight;
     int xborder, yborder;
     int baseoffset;
     int ascender, descender;
     char label[32];
     int i, j;

     surface->GetSize (surface, &width, &height);

     bwidth = width * 7 / 8;
     bheight = height * 7 / 8;

     xborder = (width - bwidth) / 2;
     yborder = (height - bheight) / 2;

     fontdesc.flags = DFDESC_ATTRIBUTES;
     fontdesc.attributes = antialias ? 0 : DFFA_MONOCHROME;

//     DFBCHECK(dfb->CreateFont (dfb, NULL, NULL, &fixedfont));
//     surface->SetFont (surface, fixedfont);

     fontdesc.flags = DFDESC_HEIGHT | DFDESC_ATTRIBUTES;
     fontdesc.height = 56;//9 * bheight / glyphs_per_yline / 16;
     fontdesc.attributes = antialias ? 0 : DFFA_MONOCHROME;
     fontdesc.attributes |= unicode_mode ? 0 : DFFA_NOCHARMAP;

     if (dfb->CreateFont (dfb, fontname1, &fontdesc, &font1) != DFB_OK) {

          static const char *msg = "failed opening '";
          char text [strlen(msg) + strlen(fontname1) + 2];

          strcpy (text, msg);
          strcpy (text + strlen(msg), fontname1);
          strcpy (text + strlen(msg) + strlen(fontname1), "'");
          printf("GEG: %s\n", text);
          surface->SetColor (surface, 0xff, 0x00, 0x00, 0xff);
          surface->DrawString (surface,
                               text, -1, width/2, 10, DSTF_TOPCENTER);
          return;
     }

     if (dfb->CreateFont (dfb, fontname2, &fontdesc, &font2) != DFB_OK) {

          static const char *msg = "failed opening '";
          char text [strlen(msg) + strlen(fontname2) + 2];

          strcpy (text, msg);
          strcpy (text + strlen(msg), fontname2);
          strcpy (text + strlen(msg) + strlen(fontname2), "'");
          printf("GEG: %s\n", text);
          surface->SetColor (surface, 0xff, 0x00, 0x00, 0xff);
          surface->DrawString (surface,
                               text, -1, width/2, 10, DSTF_TOPCENTER);
          return;
     }

     {
          static bool done = false;

          if (!done) {
               printf( "\nEncodings %s\n", fontname1 );
               font1->EnumEncodings( font1, encoding_callback, NULL );
               done = true;
          }
     }

     {
          static bool done = false;

          if (!done) {
               printf( "\nEncodings %s\n", fontname2 );
               font2->EnumEncodings( font2, encoding_callback, NULL );
               done = true;
          }
     }

     surface->SetFont(surface, font1);
     surface->DrawString(surface, "Hello", -1, 100, 100, DSTF_LEFT);
     surface->SetFont(surface, font2);
     surface->DrawString(surface, "AB", -1, 100, 100, DSTF_LEFT);

     font1->Release (font1);
     font2->Release (font2);
}

static void
cleanup( void )
{
     if (keybuffer) keybuffer->Release (keybuffer);
     if (surface)   surface->Release (surface);
     if (layer)     layer->Release (layer);
     if (dfb)       dfb->Release (dfb);
}

static void
print_usage( void )
{
     printf ("DirectFB Font Viewer version " VERSION "\n\n");
     printf ("Usage: df_fonts <fontfile> ... <fontfile>\n\n");
}

int
main( int argc, char *argv[] )
{
     DFBSurfaceDescription surface_desc;
     DFBInputEvent evt;
     int first_glyph  = 0;
     int current_font = 0;
     int update       = 1;

     if (argc < 2 || strcmp(argv[1], "--help") == 0) {
          print_usage();
          return EXIT_FAILURE;
     }

     fontname_count = argc - 1;
     fontname_list  = argv + 1;

     DFBCHECK(DirectFBInit(&argc, &argv));
     DFBCHECK(DirectFBSetOption("bg-none", NULL));
     DFBCHECK(DirectFBCreate(&dfb));

     atexit (cleanup);

     //dfb->SetCooperativeLevel(dfb, DFSCL_FULLSCREEN);

     surface_desc.flags = DSDESC_CAPS;
     surface_desc.caps = DSCAPS_PRIMARY /*| DSCAPS_DOUBLE*/;

     DFBCHECK(dfb->CreateSurface(dfb, &surface_desc, &surface));

     DFBCHECK(dfb->CreateInputEventBuffer(dfb, DICAPS_KEYS,
                                          DFB_FALSE, &keybuffer));

     while (1) {
          surface->Clear (surface, 0xff, 0xff, 0xff, 0xff);
          render_font_page (surface, argv[1], argv[2]);
          surface->Flip (surface, NULL, DSFLIP_WAITFORSYNC);

          keybuffer->WaitForEvent(keybuffer);

          while (keybuffer->GetEvent(keybuffer, DFB_EVENT(&evt)) == DFB_OK) {

          }
     }

     return EXIT_SUCCESS;
}
