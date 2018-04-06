/****************************************************************************
* Module name : GUI
* Description : Low Level Display routines
* Author      : J-M Harvengt
* History     : 14-07-97 Creation
****************************************************************************/
#ifndef _GUI
#define _GUI

/****************************************************************************
* Typedef/macros
****************************************************************************/
#define RGB565VAL(r,g,b)              ( (((r>>3)&0x1f)<<11) | (((g>>2)&0x3f)<<5) | (((b>>3)&0x1f)<<0) )
#define RGBA5551VAL(r,g,b)            ( (((r>>3)&0x1f)<<10) | (((g>>3)&0x1f)<<5) | (((b>>3)&0x1f)<<0) )
#define RGB888VAL(r,g,b)              ( (0xff<<24) | (r<<16) | (g<<8) | (b) )
#define ARGB8888VAL(a,r,g,b)          ( (a<<24) | (r<<18) | (g<<8) | (b<<0) )
#define ARGB4444VAL(r,g,b)            ( (0xf000) | (((r>>4)&0x0f)<<8) | (((g>>4)&0x0f)<<4) | (((b>>4)&0x0f)<<0) )
#define ARGB4444VALANDROID(r,g,b)     ( (0x000f) | (((b>>4)&0x0f)<<4) | (((r>>4)&0x0f)<<12) | (((g>>4)&0x0f)<<8) )
//#define ARGB4444VAL(a,r,g,b)          ( (((a>>4)&0x0f)<<12) | (((r>>4)&0x0f)<<8) | (((g>>4)&0x0f)<<4) | (((b>>4)&0x0f)<<0) )

#define GUIPIXELFORMATIS16BITS(x)  ( x<GUIPFM_ARGB8888 ? 1 : 0 )
#define GUIPIXELFORMAT2DEPTH(x)    ( GUIPIXELFORMATIS16BITS(x) ? 2 : 4 )

typedef enum
{
  GUIRET_OK                        = 0,
  GUIRET_ERR,
} GuiRetval;

typedef enum
{
  GUIPFM_UNDEFINED                 = 0,
  GUIPFM_RGB565                    = 2,
  GUIPFM_RGBA5551                  = 3,
  GUIPFM_ARGB4444                  = 4,
  GUIPFM_YUYV                      = 5,
  GUIPFM_ARGB8888                  = 6,
} GuiPixelFormat;

typedef enum
{
  GUIBIF_NONE                      = 0x0000,
  GUIBIF_PREALLOCATED              = 0x0001,
  GUIBIF_CREATEFROMFILE            = 0x0002,
  GUIBIF_FRAMEBUFFER               = 0x0004,
} GuiBitmapFlags;

typedef enum
{
  GUIBLF_NONE                      = 0x0000,
  GUIBLF_FLIPUPDOWN                = 0x0001,
  GUIBLF_COLORKEYED                = 0x0002,
} GuiBlittingFlags;

typedef struct
{
  int			 x;
  int			 y;
  int			 w;
  int			 h;
} GuiRect;

typedef struct
{
  int            flags;
  GuiPixelFormat format;
  int			 w;
  int			 h;
  int			 pitch;
  void	         *pixels;
  int            clipx;
  int            clipy;
  int            clipw;
  int            cliph;
  int            dirtyx1;
  int            dirtyy1;
  int            dirtyx2;
  int            dirtyy2;
} GuiBitmap;




/****************************************************************************
* Exported procedures
****************************************************************************/
extern GuiRetval  gui_BitmapCreate (int flags, int width, int height, int pitch, GuiPixelFormat format, void * data, GuiBitmap *bitmap);
extern GuiRetval  gui_BitmapDestroy(GuiBitmap *bitmap);
extern GuiRetval  gui_BitmapSetClip(GuiBitmap *bitmap, GuiRect *rectangle);
extern GuiRetval  gui_BitmapFillRectangle(GuiBitmap *bitmap, GuiRect *rectangle, unsigned char r,unsigned char g,unsigned char b,unsigned char a);
extern GuiRetval  gui_BitmapClear(GuiBitmap *bitmap, unsigned char r,unsigned char g,unsigned char b,unsigned char a);
extern GuiRetval  gui_BitmapBlit(int flags, GuiBitmap *bitmap, GuiBitmap *srcbitmap, GuiRect *rectangle );
extern GuiRetval  gui_BitmapGetFramebuffer(GuiBitmap **bitmap);
extern int        gui_BitmapFlip(GuiBitmap *bitmap);
extern void       gui_BitmapCacheInit(char *path,  char **asset);
extern GuiBitmap* gui_BitmapGetFromCache(int bmpId, int width, int height, GuiPixelFormat format);

#endif



