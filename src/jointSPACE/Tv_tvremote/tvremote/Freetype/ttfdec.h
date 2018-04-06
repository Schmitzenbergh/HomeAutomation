/****************************************************************************
* Module name : TTF
* Description : True type font routines
* Author      : J-M Harvengt
* History     : 14-07-97 Creation
****************************************************************************/
#ifndef _TTF
#define _TTF

#ifndef _GUI
#include "gui.h"
#endif

#include "freetype.h"

/****************************************************************************
* Typedef/macros
****************************************************************************/
#define MAX_FONT_SIZE 256

typedef struct
{
  int Width;  
  int Height;  
  int xstep;
  int yoffset;
  void * data;  
} Pchar;

typedef struct
{
  Pchar chr[MAX_FONT_SIZE];
} Pcharset;

typedef struct
{
  TT_Engine            engine;
  TT_Face              face;
  TT_Face_Properties   properties;
  TT_Instance          instance;
  TT_Glyph             glyph;
  TT_Instance_Metrics  imetrics;
  TT_CharMap           cmap;
  TT_Outline           outline;
  TT_Glyph_Metrics     metrics;
  TT_Raster_Map        Bit;
  int                  Width;
  int                  Height;
  GuiBitmap            CacheBitmap;
  Pcharset             raster;
} GTTFnt;




typedef struct {
	int		defencoding;
	TT_Engine 	engine;		/* freetype stuff*/
	TT_Face 	face;
	TT_Instance	instance;
	TT_CharMap 	char_map;
	TT_Matrix 	matrix;
	TT_Glyph 	glyph;
	short 		last_glyph_code;
	short 		last_pen_pos;
} MWFREETYPEFONT, *PMWFREETYPEFONT;

//extern PMWFREETYPEFONT
//freetype_createfont(const char *name);
//extern void
//drawchar(PMWFREETYPEFONT pf, GGdc * dstrect, TT_Glyph glyph, int x_offset,
//	int y_offset);

/****************************************************************************
* Exported procedures
****************************************************************************/
extern void ttf_Init();
extern void ttf_TurnOn(void);
extern void ttf_TurnOff(void);

extern void ttf_FontCreate(char * filename, int PointSize, int Width, int Height, 
							  GuiPixelFormat format,
					          int a, int r, int g, int b, GTTFnt *font);
extern void ttf_FontDestroy(GTTFnt *aFont);
extern void ttf_FontDrawString(int aX, int aY, char * aText,
						       GTTFnt *aFont,
                               GuiBitmap *bitmap);

#endif
