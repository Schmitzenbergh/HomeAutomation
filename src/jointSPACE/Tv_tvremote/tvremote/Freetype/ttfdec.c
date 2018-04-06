/****************************************************************************
* Module name : TTF
* Description : Truetype fonts routines
* Author      : J-M Harvengt
* History     : 14-07-97 Creation
****************************************************************************/
#ifndef _SYSTYPES
#include "systypes.h"
#endif

#include "mem.h"

#include "ttfdec.h"


/****************************************************************************
* Local macros / typedefs
****************************************************************************/
#define CODING_L1     0
#define CODING_L2     1
#define CODING_UTF8   2

/****************************************************************************
* Local procedures declaration
****************************************************************************/
void FTError(char*, TT_Error);
void Error(char*);
int find_unicode_cmap(TT_Face, TT_CharMap*);
unsigned short *l1toUnicode(char *);
unsigned short *l2toUnicode(char *);
unsigned short *UTF8toUnicode(char *);

/****************************************************************************
* Static variables
****************************************************************************/
static char  gray_indice[5];
static unsigned short gray_palette16[5];
static unsigned long  gray_palette32[5];
//char * alphabet = "abcdefghijklmnopqrstuvwxyzÈË‡ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 +-/*.,;:!?<>()[]\'#%";
static char alphabet[256];
static char outBmp[50*50];

/****************************************************************************
* Exported procedures
****************************************************************************/
/***************************************
* Purpose : Initialization.
***************************************/
void ttf_Init(void)
{
  int i;
  char * aPt=alphabet;

  for (i = 0x1f;i<=0x7e;i++)
	  *aPt++=i;
  for (i = 0xa0;i<=0xff;i++)
	  *aPt++=i;
  *aPt=0;
}

void ttf_TurnOn(void)
{
}

void ttf_TurnOff(void)
{
}



/***************************************
* Purpose : Others
***************************************/
/**************************************/
void ttf_FontCreate(char * filename, int PointSize, int Width, int Height, GuiPixelFormat format,
					int a, int r, int g, int b, GTTFnt *fnt)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  TT_Error       error;
  TT_Raster_Map  raster;
  Pcharset       *chrset;
  int            index;
  unsigned int   c;
  int            i,j,k,l;
  unsigned short *unicodeString;
  unsigned short encoding;
  unsigned short *p;
  int            flags;
  TT_F26Dot6 	 xmin, ymin, xmax, ymax;
  int 		     width, height;
  int            offHeight;
  int            maxHeight;
  int            maxWidth;
  char           * rasterpool;
  unsigned short *dst16;
  unsigned long  *dst32;

  encoding  = CODING_L1;
  flags =  TTLOAD_SCALE_GLYPH;
  flags |= TTLOAD_HINT_GLYPH;

  if ( encoding == CODING_L1 )
    unicodeString=l1toUnicode(alphabet);
  else if ( encoding == CODING_L2 )
    unicodeString=l2toUnicode(alphabet);
  else if ( encoding == CODING_UTF8 )
    unicodeString=UTF8toUnicode(alphabet);

  chrset = &fnt->raster;

  error=TT_Init_FreeType(&fnt->engine);
  if (error) FTError("Coudn't initialise FreeType engine", error);
  error=TT_Open_Face(fnt->engine, filename, &fnt->face);
  if (error) FTError("Coudn't open font file", error);
  error=TT_Get_Face_Properties (fnt->face, &fnt->properties);
  if (error) FTError("Coudget properties", error);


  error=TT_New_Glyph(fnt->face, &fnt->glyph);
  if (error) FTError("Coudn't create glyph", error); 
  error=TT_New_Instance(fnt->face, &fnt->instance);
  if (error) FTError("Couldn't create new instance", error);
  error = TT_Set_Instance_Resolutions (fnt->instance, 96, 96);
  if (error) FTError("Couldn't set resolution", error);
  if (PointSize)
  {
    offHeight = PointSize;
    error = TT_Set_Instance_PointSize( fnt->instance, PointSize );
    if (error) FTError("Couldn't set point size", error);
  }
  else if ( (Width) && (Height) )
  {
    offHeight = Height;
    error=TT_Set_Instance_CharSizes(fnt->instance, Width*64L, Height*64L);
    if (error) FTError("Coudn't set point size", error);
  }

  error=find_unicode_cmap(fnt->face, &fnt->cmap);
  if (error) Error("Couldn't find suitable Cmap");


  maxWidth = 0;
  maxHeight = 0;
  for(i=0,p=unicodeString; *p!=0xFFFF; p++, i++)
  {
    c = alphabet[i] & 0xff;
    index = TT_Char_Index(fnt->cmap, *p);
    error=TT_Load_Glyph(fnt->instance, fnt->glyph, index, flags);
    if (error) FTError("Couldn't load glyph", error);
    error=TT_Get_Glyph_Metrics(fnt->glyph, &fnt->metrics);
    if (error) FTError("Couldn't get glyph metrics", error);

	/* we begin by grid-fitting the bounding box */
	xmin   = (fnt->metrics.bbox.xMin & -64) >> 6;
	ymin   = (fnt->metrics.bbox.yMin & -64) >> 6;
	xmax   = ((fnt->metrics.bbox.xMax + 63) & -64) >> 6;
	ymax   = ((fnt->metrics.bbox.yMax + 63) & -64) >> 6;
	maxWidth  = MAX(maxWidth,(xmax - xmin));
	maxHeight = MAX(maxHeight,(ymax - ymin));
  }

  gui_BitmapCreate(GUIBIF_NONE, maxWidth*256, maxHeight, 0, format, 0, &fnt->CacheBitmap);

  /* Define grey palette for TTF font smoothing */
  gray_indice[0] = 0;
  gray_indice[1] = 1; 
  gray_indice[2] = 2;
  gray_indice[3] = 3;
  gray_indice[4] = 4;
  if ( GUIPIXELFORMATIS16BITS(fnt->CacheBitmap.format) )
  {

#define VAL(x,y) (x==0?0:y)
	if (fnt->CacheBitmap.format == GUIPFM_ARGB4444)
	{
		gray_palette16[0] = ARGB4444VAL(0x00,0x00,0x00);
		gray_palette16[1] = ARGB4444VAL(VAL(r,0x80),VAL(g,0x80),VAL(b,0x80)); 
		gray_palette16[2] = ARGB4444VAL(VAL(r,0xc0),VAL(g,0xc0),VAL(b,0xc0)); 
		gray_palette16[3] = ARGB4444VAL(VAL(r,0xe0),VAL(g,0xe0),VAL(b,0xe0)); 
		gray_palette16[4] = ARGB4444VAL(VAL(r,0xff),VAL(g,0xff),VAL(b,0xff)); 
	}
	else
	{
		gray_palette16[0] = RGB565VAL(0x00,0x00,0x00);
		gray_palette16[1] = RGB565VAL(VAL(r,0x80),VAL(g,0x80),VAL(b,0x80)); 
		gray_palette16[2] = RGB565VAL(VAL(r,0xc0),VAL(g,0xc0),VAL(b,0xc0)); 
		gray_palette16[3] = RGB565VAL(VAL(r,0xe0),VAL(g,0xe0),VAL(b,0xe0)); 
		gray_palette16[4] = RGB565VAL(VAL(r,0xff),VAL(g,0xff),VAL(b,0xff)); 
	}
  }
  else
  {
    gray_palette32[0] = ARGB8888VAL(0x00,0x00,0x00,0x00);
    gray_palette32[1] = ARGB8888VAL(a,VAL(r,0x80),VAL(g,0x80),VAL(b,0x80)); 
    gray_palette32[2] = ARGB8888VAL(a,VAL(r,0xc0),VAL(g,0xc0),VAL(b,0xc0)); 
    gray_palette32[3] = ARGB8888VAL(a,VAL(r,0xe0),VAL(g,0xe0),VAL(b,0xe0)); 
    gray_palette32[4] = ARGB8888VAL(a,VAL(r,0xff),VAL(g,0xff),VAL(b,0xff)); 
  }
  TT_Set_Raster_Gray_Palette(fnt->engine,gray_indice);


  rasterpool = fnt->CacheBitmap.pixels;
  for(i=0,p=unicodeString; *p!=0xFFFF; p++, i++)
  {
    c = alphabet[i] & 0xff;
    index = TT_Char_Index(fnt->cmap, *p);
    error=TT_Load_Glyph(fnt->instance, fnt->glyph, index, flags);
    if (error) FTError("Couldn't load glyph", error);
    error=TT_Get_Glyph_Metrics(fnt->glyph, &fnt->metrics);
    if (error) FTError("Couldn't get glyph metrics", error);

	/* we begin by grid-fitting the bounding box */
	xmin   = (fnt->metrics.bbox.xMin & -64) >> 6;
	ymin   = (fnt->metrics.bbox.yMin & -64) >> 6;
	xmax   = ((fnt->metrics.bbox.xMax + 63) & -64) >> 6;
	ymax   = ((fnt->metrics.bbox.yMax + 63) & -64) >> 6;
    raster.rows   = (ymax - ymin);
    raster.width  = (xmax - xmin); 
	raster.cols   = (raster.width + 7) & -8;	/* pad to 64-bits ??? */
    raster.flow   = TT_Flow_Down;
    raster.bitmap = outBmp;
    for(j=0; j<(raster.cols*raster.rows); j++) 
		outBmp[j]=0;

    raster.size=((long)raster.rows*raster.cols);
    /* Get bitmap */
    error=TT_Get_Glyph_Pixmap(fnt->glyph, &raster,-xmin * 64L, -ymin * 64L);
//    error=TT_Get_Glyph_Bitmap(fnt->glyph, &raster,-xmin * 64L, -ymin * 64L);
    if (error) 
		FTError("Couldn't typeset glyph", error);

    chrset->chr[c].Width   = raster.cols;
    chrset->chr[c].Height  = raster.rows;
    chrset->chr[c].xstep   = (fnt->metrics.advance >>6)+1;
    chrset->chr[c].yoffset = offHeight - ymax;
    chrset->chr[c].data    = rasterpool;

    if ( GUIPIXELFORMATIS16BITS(fnt->CacheBitmap.format) )
	{
	  dst16 = (unsigned short*)rasterpool;
      l = 0;
      for(k=0; k<raster.rows; k++)
	  {
        for(j=0;j<raster.cols;j++)
		{ 
		  dst16[j]=gray_palette16[outBmp[l++]];
		}
		dst16 += fnt->CacheBitmap.w;
	  }
	}
    else
	{
      dst32 = (unsigned long*)rasterpool;
      l = 0;
      for(k=0; k<raster.rows; k++)
	  {
        for(j=0;j<raster.cols;j++)
		{ 
		  dst32[j]=gray_palette32[outBmp[l++]];
		}
		dst32 += fnt->CacheBitmap.w;
	  }
	}
    rasterpool += raster.cols*GUIPIXELFORMAT2DEPTH(fnt->CacheBitmap.format);
  }

  fnt->Width = Width;
  fnt->Height = Height;

  /* Free all resources */
  TT_Close_Face(fnt->face);
  TT_Done_FreeType(fnt->engine);
  mem_free(unicodeString);
}

/**************************************/
void ttf_FontDestroy(GTTFnt * aFont)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
/*
  int i;
  char * p;
  Pcharset * chrset;

  chrset = &fnt->raster;
  for(p=alphabet; *p!=0; p++)
  {
    i = (int)*p;
    mem_free(chrset->chr[i].data);
  }
*/
  gui_BitmapDestroy( &aFont->CacheBitmap);
}


/**************************************/
void ttf_FontDrawString(int aX, int aY, char * aText,
						GTTFnt * aFont,
                        GuiBitmap *bitmap)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  unsigned int i;
  Pcharset     *chrset;
  int          xpos;
  char         *p;
  GuiBitmap    *charbmap = &aFont->CacheBitmap;
  GuiRect      blitrectangle = {0,0,0,0};

  chrset = &aFont->raster;
  xpos = aX;
  for(p=aText; *p!=0; p++)
  {
    i = ((int)*p) & 0xff;

	blitrectangle.x = xpos;
	blitrectangle.y = aY+chrset->chr[i].yoffset;
	charbmap->w = chrset->chr[i].Width;
	charbmap->h = chrset->chr[i].Height;
	charbmap->pixels = chrset->chr[i].data;
	gui_BitmapBlit(GUIBLF_COLORKEYED, bitmap, charbmap, &blitrectangle );
    xpos += chrset->chr[i].xstep;
  }
}


/***************************************
* Local procedures
***************************************/
/**************************************/
int find_unicode_cmap(TT_Face face, TT_CharMap *cmap)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  int i,n;
  unsigned short p,e;

  n=TT_Get_CharMap_Count(face);
  for(i=0; i<n; i++) {
    if(!TT_Get_CharMap_ID(face, i, &p, &e))
      if ( ( (p==3) && (e==1) ) ||
           (p==0) ||
           ( (p==2) && (e==1) ) )
        if(!TT_Get_CharMap(face, i, cmap))
          return 0;
  }
  return 1;
}


/**************************************/
unsigned short * l1toUnicode(char *string)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  unsigned short *r;
  int n,i;

  n=256; //strlen(string);
  if((r=mem_malloc(sizeof(unsigned short)*(n+1)))==NULL)
    Error("Couldn't allocate string");

  for(i=0; i<n; i++)
    r[i]=string[i]&0xFF;

  r[n]=0xFFFF;
  return r;
}

static unsigned short iso8859_2_tophalf[]=
{ 0x00A0, 0x0104, 0x02D8, 0x0141, 0x00A4, 0x013D, 0x015A, 0x00A7,
  0x00A8, 0x0160, 0x015E, 0x0164, 0x0179, 0x00AD, 0x017D, 0x017B,
  0x00B0, 0x0105, 0x02DB, 0x0142, 0x00B4, 0x013E, 0x015B, 0x02C7,
  0x00B8, 0x0161, 0x015F, 0x0165, 0x017A, 0x02DD, 0x017E, 0x017C,
  0x0154, 0x00C1, 0x00C2, 0x0102, 0x00C4, 0x0139, 0x0106, 0x00C7,
  0x010C, 0x00C9, 0x0118, 0x00CB, 0x011A, 0x00CD, 0x00CE, 0x010E,
  0x0110, 0x0143, 0x0147, 0x00D3, 0x00D4, 0x0150, 0x00D6, 0x00D7,
  0x0158, 0x016E, 0x00DA, 0x0170, 0x00DC, 0x00DD, 0x0162, 0x00DF,
  0x0155, 0x00E1, 0x00E2, 0x0103, 0x00E4, 0x013A, 0x0107, 0x00E7,
  0x010D, 0x00E9, 0x0119, 0x00EB, 0x011B, 0x00ED, 0x00EE, 0x010F,
  0x0111, 0x0144, 0x0148, 0x00F3, 0x00F4, 0x0151, 0x00F6, 0x00F7,
  0x0159, 0x016F, 0x00FA, 0x0171, 0x00FC, 0x00FD, 0x0163, 0x02D9};

/**************************************/
unsigned short * l2toUnicode(char *string)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  unsigned short *r;
  int n,i;

  n=strlen(string);
  if((r=mem_malloc(sizeof(unsigned short)*(n+1)))==NULL)
    Error("Couldn't allocate string");

  for(i=0; i<n; i++) {
    if((string[i]&0xFF)<0xA0)
      r[i]=string[i]&0xFF;
    else
      r[i]=iso8859_2_tophalf[(string[i]&0xFF)-0xA0];
  }

  r[n]=0xFFFF;
  return r;
}

/**************************************/
static int UTF8toUnicodeInternal(unsigned short *dest, char *src)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  unsigned short *d;
  char *s;
  int i;

  /* Assumes correct input and no characters outside the BMP. */

  for(i=0, d=dest, s=src; *s; i++) {
    if((s[0]&0x80)==0) {
      if(dest) *d=s[0];
      s++;
    } else if((s[0]&0x20)==0) {
      if(dest) *d=(s[0]&0x1F)<<6 | (s[1]&0x3F);
      s+=2;
    } else if((s[0]&0x10)==0) {
      if(dest) *d=(s[0]&0x0F)<<12 | (s[1]&0x3F)<<6 | (s[2]&0x3F);
      s+=3;
    } else
      Error("Incorrect UTF-8");
    if(dest)
      d++;
  }
  return i;
}

/**************************************/
unsigned short * UTF8toUnicode(char *string)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  int n;
  unsigned short *r;

  n=UTF8toUnicodeInternal(NULL, string);

  if((r=mem_malloc(sizeof(unsigned short)*(n+1)))==NULL)
    Error("Couldn't allocate string");

  UTF8toUnicodeInternal(r, string);
  r[n]=0xFFFF;
  return r;
}

/**************************************/
void FTError(char *str, TT_Error error)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  exit(2);
}

/**************************************/
void Error(char *string)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  exit(2);
}

