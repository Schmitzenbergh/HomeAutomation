#define PNG_SUPPORT      1
//#define DITHER_SUPPORT   1


#ifdef PNG_SUPPORT
/****************************************************************************
* Purpose : PNG decoder (using pnglib)
* Module  : PNG
* Author  : J-M Harvengt
* History : 10/08/97 Creation
****************************************************************************/
#include "mystdio.h"
#include <stdlib.h>
#include <math.h>

#include "gui.h"

/* to make PNG2UBF verbose so we can find problems (needs to be before png.h) */
#ifndef PNG_DEBUG
#define PNG_DEBUG 0
#endif

#include "png.h"

/* Define png_jmpbuf() in case we are using a pre-1.0.6 version of libpng */
#ifndef png_jmpbuf
#  define png_jmpbuf(png_ptr) ((png_ptr)->jmpbuf)
#endif

#define MAXROWSIZE         4096



/***************************************
* Local procedures definition
***************************************/
#ifdef DITHER_SUPPORT
static int pvnear(int r, int g, int b);
#endif


/***************************************
* Local data
***************************************/
static unsigned int fp;
static unsigned char rgbsrc[MAXROWSIZE*4];
#ifdef DITHER_SUPPORT
static unsigned char tmprgb[MAXROWSIZE*4];
static double gama = 1.85;
static int nr;
static int ng;
static int nb;

static unsigned char cmap[4096*4];	/* Bytes of blue, green, red, reserved */
static int tab7[1024], tab5[1024], tab3[1024], tab1[1024];
static unsigned char neartable[16*16*16];
static int *rtab, *gtab, *btab;
static int gamatab[256];
static unsigned char degama[4*512];
static int gamacmap[4*4096];
static int (*nearrtn)(int,int,int);
static int scanerr[MAXROWSIZE*3];
static int pal_offset;
static int dit_initialized=0;


/***************************************
* Local procedures
***************************************/
static void dit_Init( void )
{
  int nbcol;
  int r,g,b,k;

  if (!dit_initialized)
  {
    dit_initialized++;
    nr = 16;
    ng = 16;
    nb = 16;

    for(k= 0; k<512; k++)
	{
      tab7[512+k]= (7*k+8)/16;
      tab7[512-k]= -tab7[512+k];
      tab5[512+k]= (5*k+8)/16;
      tab5[512-k]= -tab5[512+k];
      tab3[512+k]= (3*k+8)/16;
      tab3[512-k]= -tab3[512+k];
      tab1[512+k]= (1*k+8)/16;
      tab1[512-k]= -tab1[512+k];
	}

    for(k= 0; k<256; k++)
      gamatab[k] = (int)(511.0*pow(k/255.0, gama) + 0.5);

    for(k= 0; k<512; k++)
	{
      degama[k]= 0;
      degama[k+512]= (int)(255.0*pow(k/511.0, 1/gama) + 0.5);
      degama[k+1024]= 255;
      degama[k+1536]= 255;
	}

      // Ordered colormap
	for(k= r= 0; r<nr; r++)
      {
	  for(g= 0; g<ng; g++)
        {
	    for(b= 0; b<nb; b++)
          {
		cmap[k++]= b*255/(nb-1);
		cmap[k++]= g*255/(ng-1);
		cmap[k++]= r*255/(nr-1);
		k++;
	    }
	  }
	}
	rtab= (int *)(&neartable[0]);
	gtab= rtab+256;
	btab= gtab+256;
	for(k= 0; k<256; k++)
      {
	  rtab[k]= ng * nb * ( k * nr/256 );
	  gtab[k]= nb * ( k * ng/256 );
	  btab[k]= k * nb/256;
	}
	for(k= 0; k<4*4096; k++)
	  gamacmap[k]= gamatab[cmap[k]];
    nbcol = nr*ng*nb;

    /* Copy to real palette */
    pal_offset = 0;
  }
}

static void dit_fs2dither_init(int Width)
{
  int x= 3*Width+6;
  while(--x>=0)scanerr[x]= 0;	
}

static int dit_fs2dither(int alpha, unsigned char * ptr, int Width, int Height)
{
  int x, y, r, g, b, a, pv;
  int ru, gu, bu;
  unsigned char * outbuf = ptr;
  unsigned char *pc;
  int *pe;

  nearrtn = pvnear;

    ru= 0; gu= 0; bu= 0;
    for(y= 0; y<Height; y++)
    {
      pc = ptr;
      pe = scanerr+3;
      for(x= 0; x<Width; x++)
      {
	  r= gamatab[pc[2]] + tab7[ru] + pe[2];
	  g= gamatab[pc[1]] + tab7[gu] + pe[1];
	  b= gamatab[pc[0]] + tab7[bu] + pe[0];
	  pv= (*nearrtn)(r,g,b);
// 	  outbuf[x]= pv + pal_offset;

	  if (alpha)
	  {
	    a = pc[3];
        outbuf[x*4]= cmap[(pv + pal_offset)*4+0];
 	    outbuf[x*4+1]= cmap[(pv + pal_offset)*4+1];
 	    outbuf[x*4+2]= cmap[(pv + pal_offset)*4+2];
		outbuf[x*4+3]= a;
	  }
	  else
	  {
        outbuf[x*3]= cmap[(pv + pal_offset)*4+0];
 	    outbuf[x*3+1]= cmap[(pv + pal_offset)*4+1];
 	    outbuf[x*3+2]= cmap[(pv + pal_offset)*4+2];
	  }
  	  pv *= 4;
	  r -= gamacmap[pv+2]-512; if(r>1023) r = 1023;
	  g -= gamacmap[pv+1]-512; if(g>1023) g = 1023;
	  b -= gamacmap[pv+0]-512; if(b>1023) b = 1023;
	  pe[-1] += tab3[r];
	  pe[-2] += tab3[g];
	  pe[-3] += tab3[b];
	  pe[2]= tab5[r] + tab1[ru];
	  pe[1]= tab5[g] + tab1[gu];
	  pe[0]= tab5[b] + tab1[bu];
	  ru= r; gu= g; bu= b;
	  pe += 3;
	  if (alpha)
	  {
	    pc += 4;
	  }
	  else
	  {
	    pc += 3;
	  }
      }
    }

  return(0);
}


static int pvnear(int r, int g, int b)
{	/* reds x greens x blues colormap */
	return rtab[degama[512+r]] + gtab[degama[512+g]] + btab[degama[512+b]];
}
#endif












/***************************************
* Exported procedures
***************************************/
int png_PlaySync(char * filename, int dstFormat, int dstWidth, 
			      int dstHeight, int dstStride, void * data, int alpha)
{
  png_struct    *png_ptr = NULL;
  png_info	    *info_ptr = NULL;
  png_byte      buf[8];
  png_byte      **row_pointers = NULL;
  png_byte      *png_pixels = NULL;
  png_byte      *pix_ptr = NULL;
  png_byte      *row_ptr = NULL;
  png_uint_32   row_bytes;


  unsigned char  *dst;
  unsigned short *dest16;
  unsigned long  *dest32;
  int            xinc,yinc;
  int            xoff,yoff;
  int            xpos,ypos;
  int            ycount;


  png_uint_32    width;
  png_uint_32    height;
  int            bit_depth;
  int            channels;
  int            color_type;
  int            alpha_present;
  int            col;
  int            ret;
  int            i;
  unsigned short value;
  unsigned short r,g,b,a;
  unsigned char  *bufpt;

  fp = fsm_myfopen(filename, "rb");
  if (!fp)
    return 0;

  
  /* read and check signature in PNG file */
  ret = fsm_myfread (buf, 1, 8, fp );
  if (ret != 8)
    return 0;

  ret = png_check_sig (buf, 8);
  if (!ret)
    return 0;

  /* create png and info structures */

  png_ptr = png_create_read_struct (PNG_LIBPNG_VER_STRING,
    NULL, NULL, NULL);
  if (!png_ptr)
    return 0;   /* out of memory */

  info_ptr = png_create_info_struct (png_ptr);
  if (!info_ptr)
  {
    png_destroy_read_struct (&png_ptr, NULL, NULL);
    return 0;   /* out of memory */
  }

  if (setjmp (png_jmpbuf(png_ptr)))
  {
    png_destroy_read_struct (&png_ptr, &info_ptr, NULL);
    return 0;
  }

  /* set up the input control for C streams */
  png_init_io (png_ptr, (void*)fp);
  png_set_sig_bytes (png_ptr, 8);  /* we already read the 8 signature bytes */

  /* read the file information */
  png_read_info (png_ptr, info_ptr);

  /* get size and bit-depth of the PNG-image */
  png_get_IHDR (png_ptr, info_ptr, &width, &height, &bit_depth, &color_type, NULL, NULL, NULL);

  /* set-up the transformations */

  /* transform paletted images into full-color rgb */
  if (color_type == PNG_COLOR_TYPE_PALETTE)
    png_set_expand (png_ptr);
  /* expand images to bit-depth 8 (only applicable for grayscale images) */
  if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
    png_set_expand (png_ptr);
  /* transform transparency maps into full alpha-channel */
  if (png_get_valid (png_ptr, info_ptr, PNG_INFO_tRNS))
    png_set_expand (png_ptr);


  /* all transformations have been registered; now update info_ptr data,
   * get rowbytes and channels, and allocate image memory */

  png_read_update_info (png_ptr, info_ptr);

  /* get the new color-type and bit-depth (after expansion/stripping) */
//  png_get_IHDR (png_ptr, info_ptr, &width, &height, &bit_depth, &color_type, NULL, NULL, NULL);

  /* check for 16-bit files */
  if (bit_depth == 16)
  {
    fprintf (stderr, "PNG2UBF\n");
    fprintf (stderr, "Error:  PNG-file is 16bits per channel!\n");
    exit (1);
  }

  /* calculate new number of channels and store alpha-presence */
  if (color_type == PNG_COLOR_TYPE_GRAY)
    channels = 1;
  else if (color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
    channels = 2;
  else if (color_type == PNG_COLOR_TYPE_RGB)
    channels = 3;
  else if (color_type == PNG_COLOR_TYPE_RGB_ALPHA)
    channels = 4;
  else
    channels = 0; /* should never happen */

  /* check if alpha is expected to be present in file */
  if (!channels)
  {
    fprintf (stderr, "PNG2UBF\n");
    fprintf (stderr, "Error:  PNG-file contain invalid amount of channel\n");
    exit (1);
  }

  alpha_present = (channels - 1) % 2;


  /* row_bytes is the width x number of channels x (bit-depth / 8) */
  row_bytes = png_get_rowbytes (png_ptr, info_ptr);

  if ((png_pixels = (png_byte *) malloc (row_bytes * height * sizeof (png_byte))) == NULL) {
    png_destroy_read_struct (&png_ptr, &info_ptr, NULL);
    return 0;
  }

  if ((row_pointers = (png_byte **) malloc (height * sizeof (png_bytep))) == NULL)
  {
    png_destroy_read_struct (&png_ptr, &info_ptr, NULL);
    free (png_pixels);
    png_pixels = NULL;
    return 0;
  }

  /* set the individual row_pointers to point at the correct offsets */
  for (i = 0; i < (height); i++)
    row_pointers[i] = png_pixels + i * row_bytes;

  /* now we can go ahead and just read the whole image */
  png_read_image (png_ptr, row_pointers);

  /* read rest of file, and get additional chunks in info_ptr - REQUIRED */
  png_read_end (png_ptr, info_ptr);

  /* clean up after the read, and free any memory allocated - REQUIRED */
  png_destroy_read_struct (&png_ptr, &info_ptr, (png_infopp) NULL);


#ifdef DITHER_SUPPORT
  dit_Init();
  dit_fs2dither_init(dstWidth);
#endif
  xinc = ((long)width << 8)/dstWidth;
  yinc = ((long)height << 8)/dstHeight;
  yoff=0;
  ycount=-1;
  dst = (unsigned char*)data;

  row_ptr = png_pixels;
  for (ypos = 0; ypos <dstHeight; ypos++) 
  {
    // Skip untill row required
    while((yoff>>8) != ycount)
    {
	  pix_ptr = row_ptr;
	  row_ptr += row_bytes;
      ycount++;
    } 
    xoff=0;


    bufpt=rgbsrc;
	for (col = 0; col < width; col++)
    {
      if ( channels <= 2 ) /* GREY scale */
      {
          r = (unsigned short) *pix_ptr++;
          g = r;
          b = r;
      }
      else /* RGB */
      {
          r = (unsigned short) *pix_ptr++;
          g = (unsigned short) *pix_ptr++;
          b = (unsigned short) *pix_ptr++;
      }
      a = (alpha_present ? (unsigned short) *pix_ptr++ : 0x00ff);
	  *bufpt++ = r;
	  *bufpt++ = g;
	  *bufpt++ = b;
	  *bufpt++ = a;
    } /* end for col */


    switch(dstFormat)
	{
	  case GUIPFM_RGB565:
#ifdef DITHER_SUPPORT
        /* 16bits 656 */
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          tmprgb[4*xpos]   = rgbsrc[4*(xoff>>8)];
          tmprgb[4*xpos+1] = rgbsrc[4*(xoff>>8)+1];
          tmprgb[4*xpos+2] = rgbsrc[4*(xoff>>8)+2];
          tmprgb[4*xpos+3] = rgbsrc[4*(xoff>>8)+3];
          xoff += xinc;
		} 
        dit_fs2dither(1, tmprgb, dstWidth, 1);
        dest16 = (void*)dst;
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          *dest16++ = RGB565VAL(tmprgb[xpos*4+0], tmprgb[xpos*4+1], tmprgb[xpos*4+2]);
		}
#else
        dest16 = dst;
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          *dest16++ = RGB565VAL( rgbsrc[4*(xoff>>8)],
	                          rgbsrc[4*(xoff>>8)+1],
                              rgbsrc[4*(xoff>>8)+2] );
          xoff += xinc;
		}
#endif
		break;
	  case GUIPFM_RGBA5551:
#ifdef DITHER_SUPPORT
        /* 16bits 656 */
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          tmprgb[4*xpos]   = rgbsrc[4*(xoff>>8)];
          tmprgb[4*xpos+1] = rgbsrc[4*(xoff>>8)+1];
          tmprgb[4*xpos+2] = rgbsrc[4*(xoff>>8)+2];
          tmprgb[4*xpos+3] = rgbsrc[4*(xoff>>8)+3];
          xoff += xinc;
		} 
        dit_fs2dither(1, tmprgb, dstWidth, 1);
        dest16 = (void*)dst;
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          *dest16++ = RGBA5551VAL(tmprgb[xpos*4+0], tmprgb[xpos*4+1], tmprgb[xpos*4+2]));
		}
#else
        dest16 = dst;
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          *dest16++ = RGBA5551VAL( rgbsrc[4*(xoff>>8)],
	                          rgbsrc[4*(xoff>>8)+1],
                              rgbsrc[4*(xoff>>8)+2] );
          xoff += xinc;
		}
#endif
		break;
	  case GUIPFM_YUYV:
	    /* 32bits YUVY */
        dest32 = (unsigned long *)dst;
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          value = ( (rgbsrc[4*(xoff>>8)]  << 8)   | /* Y0*/
	                (rgbsrc[4*(xoff>>8)+1])       | /* U0*/
                    (rgbsrc[4*(xoff>>8)+2]<< 16) ); /* V0*/
          *dest32++= value;
          xoff += xinc;
		}
		break;
	  case GUIPFM_ARGB8888:
	    /* 32bits ARGB */
        dest32 = (unsigned long *)dst;
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          *dest32++ = RGB888VAL( rgbsrc[4*(xoff>>8)],
	                            rgbsrc[4*(xoff>>8)+1],
                                rgbsrc[4*(xoff>>8)+2] );
          xoff += xinc;
		}
		break;
#ifdef OBSOLETE
	  case PIXFORMAT_CLUT8:
	  case PIXFORMAT_CLUT16:
#ifdef ModeLut
#ifdef DITHER_SUPPORT
        /* CLUT mode (Dithering if 8 bits) */
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          tmprgb[4*xpos]   = rgbsrc[4*(xoff>>8)];
          tmprgb[4*xpos+1] = rgbsrc[4*(xoff>>8)+1];
          tmprgb[4*xpos+2] = rgbsrc[4*(xoff>>8)+2];
          tmprgb[4*xpos+3] = rgbsrc[4*(xoff>>8)+3];
          xoff += xinc;
		} 
        trowsrc = (Pixel*)tmprgb;
        dit_fs2dither(1, tmprgb, dstWidth, 1);
        dest16 = dst;
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          *dest16++= trowsrc[xpos];
		}
#else
        dest16 = dst;
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          *dest16++ = RGBVAL( rgbsrc[4*(xoff>>8)],
	                          rgbsrc[4*(xoff>>8)+1],
                              rgbsrc[4(xoff>>8)+2] );
          xoff += xinc;
		}
#endif
#endif
	    break;
#endif
	}

    dst += dstStride;
    yoff += yinc; 
  }


  if (row_pointers != (unsigned char**) NULL)
    free (row_pointers);
  if (png_pixels != (unsigned char*) NULL)
    free (png_pixels);

  return 1;

} /* end of source */

#endif
