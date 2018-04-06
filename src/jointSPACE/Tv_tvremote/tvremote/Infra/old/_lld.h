/****************************************************************************
* Module name : LLD
* Description : Low Level Display routines
* Author      : J-M Harvengt
* History     : 14-07-97 Creation
****************************************************************************/
#ifndef _LLD
#define _LLD

#ifndef OVERULE_DEFAULTPIXDEPTH

#ifdef WIN32
//#define DFAST				1
#define Mode16bits			1
//#define Mode32bits			1
//#define ModeLut             1
#else
#ifdef _trimedia
#define Mode16bits			1
#else
  #ifdef GP32
#define Mode16bits			1
  #else
  #ifdef NGC
#define Mode16bits			1
//#define ModeLut	  		    1
  #else
    #ifdef NDS
#define Mode16bits			1
//#define ModeLut	  		    1
    #else
      #ifdef PSP
#define Mode16bits			1
      #else
        #ifdef TRIDENT
#define Mode16bits			1
        #else
// VIPER
// WCE
// _WIN32_WCE
// _arch_dreamcast
// GBA
// NDS
// PSP
//#define Mode16bits			1
#define Mode32bits			1
        #endif
      #endif
    #endif
  #endif
  #endif
#endif
#endif

#endif

//#define GLOBAL_XBUF 1

/****************************************************************************
* Typedef/macros
****************************************************************************/
#define RGBVAL32(r,g,b)               ( (0xff<<24) | (r<<16) | (g<<8) | (b) )
#define ARGBVAL32(a,r,g,b)            ( (a<<24) | (r<<18) | (g<<8) | (b<<0) )
#define R5G6B5VAL(r,g,b)              ( (((r>>3)&0x1f)<<11) | (((g>>2)&0x3f)<<5) | (((b>>3)&0x1f)<<0) )
#define B5G5R5A1VAL(r,g,b)            ( (((b>>3)&0x1f)<<10) | (((g>>3)&0x1f)<<5) | (((r>>3)&0x1f)<<0) )
#define R5G5B5A1VAL(r,g,b)            ( (((r>>3)&0x1f)<<10) | (((g>>3)&0x1f)<<5) | (((b>>3)&0x1f)<<0) )
#define R4G4B4A4VAL(r,g,b)            (0xf000 | (((r>>4)&0x0f)<<8) | (((g>>4)&0x0f)<<4) | (((b>>4)&0x0f)<<0) )
#define R5G5B5A1GP32VAL(r,g,b)        (((((r>>3))&0x1f)<<11)|((((g>>3))&0x1f)<<6)|((((b>>3))&0x1f)<<1))
#define R5G5B5A1NDSVAL(r,g,b)         ((r>>3)|((g>>3)<<5)|((b>>3)<<10) | 0x8000)
#define R5G6B5PSPVAL(r,g,b)           ( (((b>>3)&0x1f)<<11) | (((g>>2)&0x3f)<<5) | (((r>>3)&0x1f)<<0) )
//#define R5G6B5VAL4444SIM(r,g,b)       ( (((r>>3)&0x1e)<<11) | (((g>>2)&0x3c)<<5) | (((b>>3)&0x1e)<<0) )
//#define R5G5B5A1VAL4444SIM(r,g,b)     ( (((r>>3)&0x1e)<<10) | (((g>>3)&0x1e)<<5) | (((b>>3)&0x1e)<<0) )

#define RGBAQUADR5G6B5(p)             (p>>8) & 0xf8 , (p<<3) & 0xfc , (p<<3) & 0xf8, 0xff 
#define RGBAQUADR4G4B4A4(p)           (p>>4) & 0xf0 , (p) & 0xf0 , (p<<4) & 0xf0, (p>>8) & 0xf0 
#define RGBAQUAD32(p)                 (p>>16) & 0xff , (p>>8) & 0xff , (p) & 0xff, (p>>24) & 0xff 


#ifdef ModeLut // Lutmode also possible in 16bits!!
#define CLUT_RESERVED     (16+32)
#endif


// 16bits
#ifdef Mode16bits
typedef unsigned short Pixel;

#ifdef ModeLut // 16bits with Lut (possible)!!


/* 32K colors */
#define CLUT_NR   32
#define CLUT_NG   32
#define CLUT_NB   32
#ifdef NGC
#define RGBVAL(b,g,r)    ( ( (((r>>3)&0x1f)<<10) | (((g>>3)&0x1f)<<5) | (((b>>3)&0x1f)<<0) ) + CLUT_RESERVED)
#else
#define RGBVAL(r,g,b)    ( ( (((r>>3)&0x1f)<<10) | (((g>>3)&0x1f)<<5) | (((b>>3)&0x1f)<<0) ) + CLUT_RESERVED)
#endif

/* 4K colors */
/*
#define CLUT_NR   16
#define CLUT_NG   16
#define CLUT_NB   16
#ifdef NGC
#define RGBVAL(b,g,r)    ( ( (((r>>4)&0x0f)<<8) | (((g>>4)&0x0f)<<4) | (((b>>4)&0x0f)<<0) ) + CLUT_RESERVED)
#else
#define RGBVAL(r,g,b)    ( ( (((r>>4)&0x0f)<<8) | (((g>>4)&0x0f)<<4) | (((b>>4)&0x0f)<<0) ) + CLUT_RESERVED)
#endif
*/
#define CLUT_SIZE (CLUT_NR*CLUT_NG*CLUT_NB+16+32) //32 spare for user defined



#else // 16bits, No Lut

#ifdef WIN32
#define ARGBVAL(a,r,g,b)  ( (((r>>3)&0x1f)<<11) | (((g>>2)&0x3f)<<5) | (((b>>3)&0x1f)<<0) )
#else
 #ifdef ALPHA
#define ARGBVAL(a,r,g,b)  ((((a>>4)&0x0f)<<12) | (((r>>4)&0x0f)<<8) | (((g>>4)&0x0f)<<4) | (((b>>4)&0x0f)<<0) )
 #else
#define ARGBVAL(a,r,g,b)  ( (((r>>3)&0x1f)<<11) | (((g>>2)&0x3f)<<5) | (((b>>3)&0x1f)<<0) )
 #endif
#endif

#ifdef WIN32
 #ifdef DFAST
  #define RGBVAL R5G6B5VAL
//  #define RGBVAL R5G6B5VAL4444SIM

 #else
  #ifdef XBOX
  #define RGBVAL R5G6B5VAL
  #else
//  #define RGBVAL R5G6B5VAL
  #define RGBVAL R5G5B5A1VAL
//  #define RGBVAL R5G5B5A1VAL4444SIM
  #endif
 #endif
#else
 #ifdef GP32
  #define RGBVAL R5G5B5A1GP32VAL
 #else
  #ifdef _WIN32_WCE
  #define RGBVAL R5G6B5VAL //R5G5B5A1VAL
  #else
    #ifdef GBA
  #define RGBVAL R5G5B5A1GP32VAL
    #else
      #ifdef NDS
  #define RGBVAL R5G5B5A1NDSVAL
      #else
        #ifdef PSP
  #define RGBVAL R5G6B5PSPVAL
        #else
          #ifdef TRIDENT
  #define RGBVAL B5G5R5A1VAL
          #else
            #ifdef VIPER
              #ifdef ALPHA
               #define RGBVAL R4G4B4A4VAL
               #define RGBAQUAD RGBAQUADR4G4B4A4
              #else
               #define RGBVAL R5G6B5VAL
               #define RGBAQUAD RGBAQUADR5G6B5
              #endif
            #else
// WCE 
// _arch_dreamcast
// _trimedia
//  #define RGBVAL R4G4B4A4VAL
               #define RGBVAL R5G6B5VAL
               #define RGBAQUAD RGBAQUADR5G6B5
            #endif
          #endif
        #endif
      #endif
    #endif
  #endif
 #endif
#endif

#endif






// 32bits
#elif Mode32bits
typedef unsigned long Pixel;
#define RGBVAL   RGBVAL32
#define ARGBVAL  ARGBVAL32
#define RGBAQUAD RGBAQUAD32



// Clut 8
#else 
typedef unsigned char Pixel;
#define CLUT_SIZE     256
#define CLUT_NR       4
#define CLUT_NG       4
#define CLUT_NB       4
#define RGBVAL(r,g,b)    ( ( (((r>>6)&0x3)<<4) | (((g>>6)&0x03)<<2) | (((b>>6)&0x03)<<0) ) + CLUT_RESERVED)
/* For DIRECTFB only */
#define RGBAQUAD(p)      (p>>16) & 0xff , (p>>8) & 0xff , (p) & 0xff, (p>>24) & 0xff 
#endif









#ifdef ModeLut
#define ColorTrans          0
#define ColorRed            1 
#define ColorGreen          2 
#define ColorBlue           3 
#define ColorCyan           4 
#define ColorPink           5 
#define ColorYellow         6 
#define ColorElectricBlue   7 
#define ColorGreenBlue      8 
#define ColorGreenBlueLight 9 
#define ColorLightBlue      10 
#define ColorBlack          11
#define ColorDarkGrey       12
#define ColorGrey           13
#define ColorLightGrey      14
#define ColorWhite          15
#define col_GetColor(x)     (Pixel)(x)
#else
#define ColorTrans          0
#define ColorRed            RGBVAL(255,0,  0)
#define ColorGreen          RGBVAL(0,  255,0)
#define ColorBlue           RGBVAL(0,  0,  255)
#define ColorCyan           RGBVAL(128,224,255)
#define ColorPink           RGBVAL(255,0,  255) 
#define ColorYellow         RGBVAL(255,255,0) 
#define ColorElectricBlue   RGBVAL(0, 0,   100) 
#define ColorGreenBlue      RGBVAL(64, 128,128) 
#define ColorGreenBlueLight RGBVAL(32, 64, 64) 
#define ColorLightBlue      RGBVAL(0,  80, 128) 
#define ColorBlack          RGBVAL(0,  0,  32)
#define ColorDarkGrey       RGBVAL(50, 50, 50)
#define ColorGrey           RGBVAL(63, 63, 63)
#define ColorLightGrey      RGBVAL(127,127,127)
#define ColorWhite          RGBVAL(255,255,255)
#define col_GetColor(x)     (Pixel)(x)
#endif



/* Pixel format */
#define PIXFORMAT_CLUT8       0
#define PIXFORMAT_CLUT16      1
#define PIXFORMAT_R5G6B5      2 
#define PIXFORMAT_R5G5B5A1    3 
#define PIXFORMAT_R4G4B4A4    4
#define PIXFORMAT_Y8U8V8Y8    5
#define PIXFORMAT_A8R8G8B8    6

#define PIXDEPTH_CLUT8        1
#define PIXDEPTH_CLUT16       2
#define PIXDEPTH_R5G6B5       2 
#define PIXDEPTH_R5G5B5A1     2 
#define PIXDEPTH_R4G4B4A4     2
#define PIXDEPTH_Y8U8V8Y8     4
#define PIXDEPTH_A8R8G8B8     4


typedef struct
{
  int			xref;
  int			yref;
  int			x;
  int			y;
  int			Format;
  int			Width;
  int			Stride;
  int			Height;
  Pixel	        * data;
  void	        * userdata;
} GGdc;

typedef GGdc * GHGdc;

#define NULLGGDC {0,0,0,0,0,0}

#define RECT_MAX_NR (8+3)

typedef struct
{
  int			XMin;
  int			YMin;
  int			XMax;
  int			YMax;
} Rect;


/****************************************************************************
* Global variables
****************************************************************************/

/****************************************************************************
* Exported procedures
****************************************************************************/
extern void   lld_Init(void);
extern void   lld_TurnOn(void);
extern void   lld_TurnOff(void);

extern unsigned int lld_Layer2Buffer(int Lid);
extern void   lld_SetFrameBuffer(unsigned int Sid);
extern GGdc * lld_GetFrameBufferContext(void);
extern Pixel  lld_GetFrameBufferColorKey(void);
extern void   lld_SetPalette(unsigned int Pid);
extern unsigned char * lld_GetPalette( void );
extern Pixel  lld_SetPaletteEntry(int indice, int r, int g, int b, int a);
extern Pixel  lld_GetPaletteEntry(int r, int g, int b, int a);
extern void   lld_SetOverlay(unsigned int Sid);
extern GGdc * lld_GetOverlayContext(void);
extern void   lld_PushOverlayContext(GGdc * newContext);
extern void   lld_PopOverlayContext(void);

extern void   lld_InvalidateArea(GGdc * dstrect);
extern int    lld_ClipInContext( int x, int y, int Width, int Height, Pixel * bmap, GGdc * dstrect, GGdc * result);
extern int    lld_ClipStretchInContext( int x, int y, int Width, int Height, Pixel * bmap, GGdc * dstrect, GGdc * result);
extern int    lld_Clip( int x, int y, int Width, int Height, Pixel * bmap, GGdc * shadow, GGdc * result);
extern void   lld_Fill( GGdc * srcrect, GGdc * dstrect, Pixel color);
extern void   lld_FillWhereEqual( GGdc * srcrect, GGdc * dstrect, Pixel color, Pixel RepColor);
extern void   lld_FillWhereNotEqual( GGdc * srcrect, GGdc * dstrect, Pixel color, Pixel RepColor);
extern void   lld_BitBlt( GGdc * srcrect, GGdc * dstrect, int trans);
extern void   lld_GetPixels( GGdc * srcrect, GGdc * dstrect, Pixel * buffer);
extern void   lld_SetPixels( GGdc * srcrect, GGdc * dstrect, Pixel * data);
extern void   lld_StretchBlt( int bWidth, int bHeight, int bStride,
		   					  int strWidth, int strHeight, GGdc * srcrect, GGdc * dstrect, int trans );
extern void   lld_StretchBlt2( int bWidth, int bHeight,
		   					   int strWidth, int strHeight, GGdc * srcrect, GGdc * dstrect, int trans );
//extern void   lld_Expand( GGdc * srcrect, GGdc * dstrect, Pixel * clut);
//extern void   lld_StretchExpand( int bWidth, int bHeight, int bStride,
//		   					     int strWidth, int strHeight, GGdc * srcrect, GGdc * dstrect, Pixel * clut);
extern void   lld_Expand( int bWidth, int bHeight, int bStride,
						  int strWidth, int strHeight, 
						  int xMode, int yMode,
						  GGdc * srcrect, GGdc * dstrect, Pixel * clut);
extern void   lld_PaternBlt( int bWidth, int bHeight,
		   				     GGdc * srcrect, GGdc * dstrect, int trans );
extern void   lld_DrawText( int aX, int aY, char * aText, Pixel color, GGdc * dstrect);
extern void   lld_DrawConsole( unsigned short * data, int width, int stride, int height, GGdc * dstrect);
extern void   lld_DrawConsole2( char * data, int width, int stride, int height, GGdc * dstrect);

extern GGdc * lld_CreateContext( GGdc * aGdc, int aLeft, int aTop,
							     int aWidth, int aHeight, GGdc * dstGdc);
extern GGdc * lld_DuplicateContext( GGdc * aGdc, GGdc * dstGdc);
extern GGdc * lld_AdaptClippingContext(GGdc * aGdc, GGdc * newContext);

extern int    lld_DrawRectangle( int aX, int aY,
							     int aWidth, int aHeight, Pixel aColor,
					             GGdc * dstrect);
extern int    lld_StringWidth( char * aText);
extern int    lld_StringNWidth( char * aText, int nrChar);
extern int    lld_StringHeight( char * aText);


extern void   lld_DrawLine(GGdc * dstrect, Pixel color, int y0x0, int y1x1);
extern void   lld_DrawTextureTriangle(GGdc * dstrect, Pixel texture[], int y0x0, int y1x1, int y2x2, int v0u0, int v1u1, int v2u2);
extern void   lld_MatrixXRotate (int nbpixels, int * srcpixels, int * dstpixels, int angle, int xoffset, int yoffset);
extern void   lld_MatrixYRotate (int nbpixels, int * srcpixels, int * dstpixels, int angle, int xoffset, int yoffset);


#endif



