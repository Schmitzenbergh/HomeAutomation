#define JPEG_SUPPORT       1
#define THUMBNAIL_SUPPORT  1
#define DITHER_SUPPORT     1
//#define THREAD_DECODING    1

#ifdef JPEG_SUPPORT
/****************************************************************************
* Purpose : Jpeg decoder (using jpeglib)
* Module  : JPEG
* Author  : J-M Harvengt
* History : 10/08/97 Creation
****************************************************************************/
#include "mystdio.h"
#include <stdlib.h>
#include <math.h>
#include "console.h"

#include "jpeglib.h"
#include "jinclude.h"
#include "systypes.h"

#include "gui.h"
#include "mem.h"
#include "std.h"

#ifdef THREAD_DECODING
#ifdef WIN32
#include "winthd.h"
#endif
#ifdef _trimedia
#include <psos.h>
#endif
#ifdef _arch_dreamcast
#include "kos.h"
#endif
#if ( (VIPER) && (!LINUX) )
#include <vxworks.h>
#include <semLib.h>
#include <taskLib.h>
#endif
#if (LINUX)
#include <pthread.h>
#include <sched.h>
#include <sys/time.h>
#include <sys/resource.h>
#endif
#endif


#ifdef THUMBNAIL_SUPPORT
#include "jthumb.h"
#endif

#ifndef _arch_dreamcast
#define SETJMP_SUPPORT 1
#endif

#ifdef SETJMP_SUPPORT
#include <setjmp.h>
#endif

#include "jpgdec.h"

/**************************************
* Local macros/typedef
**************************************/
#define MAXROWSIZE                 4096

#define STATE_IDLE                 0
#define STATE_STARTING             1
#define STATE_DECODING_LINE        2
#define STATE_ENDING               3

#ifdef THREAD_DECODING
#define JPEG_PROCESSING_RESOLUTION 10
#else
#define JPEG_PROCESSING_RESOLUTION 20
#endif


#ifdef SETJMP_SUPPORT
struct my_error_mgr 
{
  struct jpeg_error_mgr pub;	/* "public" fields */
  jmp_buf setjmp_buffer;	/* for return to caller */
};
#else
struct my_error_mgr 
{
  struct jpeg_error_mgr pub;
};
#endif

typedef struct my_error_mgr * my_error_ptr;

/***************************************
* Local procedures definition
***************************************/
#ifdef THREAD_DECODING
static void jpg_Decoder(void);
#endif
#ifdef DITHER_SUPPORT
static int pvnear(int r, int g, int b);
#endif


/***************************************
* Local data
***************************************/
#ifdef WIN32
#ifdef _XBOX
#define YUV_PROCESSING 1
#else
#define RGB_PROCESSING 1
#endif
#endif
#ifdef _WIN32_WCE
#define RGB_PROCESSING 1
#endif
#ifdef _arch_dreamcast
#define RGB_PROCESSING 1
#endif
#ifdef _trimedia
#define YUV_PROCESSING 1
#endif
#ifdef NGC
#define RGB_PROCESSING 1
//#define YUV_PROCESSING 1
#endif
#ifdef GP32
#define RGB_PROCESSING 1
#endif
#if ( (VIPER) && (!LINUX) )
#define RGB_PROCESSING 1
#endif
#if (LINUX)
#define RGB_PROCESSING 1
#endif
#ifdef PSP
#define RGB_PROCESSING 1
#endif
#ifdef NDS
#define RGB_PROCESSING 1
#endif

#ifdef THREAD_DECODING

#ifdef _arch_dreamcast
static semaphore_t * sema;
#endif
#ifdef _trimedia
#define EVENT1 0x10000
//static ULONG sema;
static ULONG jpeg_task;
#endif
#if ( (VIPER) && (!LINUX) )
static int /*SEM_ID*/ semSync;
static int thread_tid;
#endif
#if (LINUX)
static pthread_attr_t attr; 
static pthread_t decoding_thread;
static pthread_mutex_t wait_mutex;
static pthread_cond_t wait_cont;
static struct sched_param schedulingParam;
static int m_threadstacksize = -1;
static int m_threadSchedulingPolicy = SCHED_OTHER;
static int m_threadprio = 10;
static int schedulingPolicy;
static int tid;
typedef struct{
    void* __padding[ 16 ];
    struct { void* next; void* prev; } list;
    pid_t tid;
    pid_t pid;
} PThreadInfo;
#endif

#endif


/* Thumbnail decoding variables */
static char tjpgfilename[1024];
static char tname[1024];
static int is_tcinfo=0;
static unsigned char * trgbsrc;
static unsigned char * tdst;
static int tFormat, tWidth, tHeight, tStride, tColorkey;
static int txinc,tyinc;
static int txoff,tyoff;
static int txpos,typos;
static int tycount;
static int torientation;

/* Main decoding variables */
static char jpgfilename[1024];
static int jpgState;
static struct jpeg_decompress_struct cinfo;
static JSAMPARRAY buffer;
static struct my_error_mgr jerr;
static unsigned int infile;

#ifdef RGB_PROCESSING
static void * dst;
#endif
#ifdef YUV_PROCESSING
static unsigned short * dst;
#endif
static unsigned long  * dest;
static unsigned short *dest16;
static unsigned long  *dest32;


static int dsty;

static unsigned char * datasrc;
static int dstFormat, dstWidth, dstHeight, dstStride, dstColorkey;
static int skipDisplay;
static int xinc,yinc;
static int xoff,yoff;
static int ycount;
static int xpos, ypos, curypos;

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
/***************************************
* Initialization.
***************************************/
void jpg_Init(void)
{
  jpgState  = STATE_IDLE; 
#ifdef THREAD_DECODING
#ifdef WIN32
  thdJpgCreate(&jpg_Decoder);
#endif
#ifdef _trimedia
  t_create( "jpeg",  2,  32000,  32000,  0,  &jpeg_task );
  t_start( jpeg_task, T_PREEMPT | T_TSLICE | T_ASR | T_ISR, jpg_Decoder,  0 );
#endif
#ifdef _arch_dreamcast
  sem_init();
  sema = sem_create(0);
  thd_create(jpg_Decoder, NULL);
#endif
#if ( (VIPER) && (!LINUX) )
//  thread_tid = taskSpawn ("JPEG", 30, 0, 0x10000, (void (*)()) jpg_Decoder );
  thread_tid = taskSpawn("JPEG", 128, 0, 0x10000, (FUNCPTR)jpg_Decoder, 0,0,0,0,0, 0,0,0,0,0);
  semSync = semBCreate (SEM_Q_FIFO, SEM_EMPTY);
#endif
#if (LINUX)
	pthread_attr_init(&attr); 
	if (m_threadstacksize >= 0) 
	{
		pthread_attr_setstacksize(&attr, m_threadstacksize);
	}
	pthread_create(&decoding_thread, &attr, (void*)jpg_Decoder, (void*)0);	
	pthread_getschedparam(decoding_thread, &schedulingPolicy, &schedulingParam);
	if ( m_threadSchedulingPolicy != SCHED_OTHER )
	{
		schedulingParam.sched_priority = m_threadprio;
		pthread_setschedparam(decoding_thread, m_threadSchedulingPolicy, &schedulingParam);
	}
	else
	{
		schedulingParam.sched_priority = 0;
		pthread_setschedparam(decoding_thread, m_threadSchedulingPolicy, &schedulingParam);
		tid = ((PThreadInfo*)decoding_thread)->tid;
		printf("Jpeg decoding thread = > tid: %d\n", tid);
		setpriority(PRIO_PROCESS, tid, m_threadprio);	
	}
	pthread_mutex_init(&wait_mutex, NULL);
	pthread_cond_init (&wait_cont, NULL);
#endif

#endif
}


void jpg_TurnOn(void)
{
}

void jpg_TurnOff(void)
{
  jpg_Stop();
#ifdef THREAD_DECODING
#ifdef _trimedia
  t_suspend(jpeg_task);
#endif
#if ( (VIPER) && (!LINUX) )
  taskDelete ( thread_tid );
#endif
#if (LINUX)
  // Wait for the thread to end.
  pthread_join(decoding_thread, NULL);
  pthread_mutex_destroy(&wait_mutex);
  pthread_cond_destroy(&wait_cont);
#endif
#endif
#ifdef WIN32
#ifdef THREAD_DECODING
  thdJpgKill();
#else
  /* Better clean up for windows */
  if (jpgState == STATE_ENDING)
  {
      /* Please the decoder */
      while (cinfo.output_scanline < cinfo.output_height)
	  {
        (void) jpeg_read_scanlines(&cinfo, buffer, 1);
	  }
      (void) jpeg_finish_decompress(&cinfo);
      jpeg_destroy_decompress(&cinfo);
      JFCLOSE(infile);
  }
#endif
#endif
}

/***************************************
* Others
***************************************/
METHODDEF(void) my_error_exit (j_common_ptr cinfo)
{
  my_error_ptr myerr = (my_error_ptr) cinfo->err;
//  jpgState = STATE_IDLE;   
//  (*cinfo->err->output_message) (cinfo);
#ifdef SETJMP_SUPPORT
  /* Return control to the setjmp point */
  longjmp(myerr->setjmp_buffer, 1);
#endif
}


/**************************************/
static int jpg_readJPEG(char * filename)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
#ifdef ModeLut
#ifdef DITHER_SUPPORT
  Pixel          *trowsrc;
#endif
#endif
  unsigned short *dest16;
  unsigned long  *dest32;
  unsigned long  value;

  unsigned int tinfile;
  struct jpeg_decompress_struct tcinfo;
  JSAMPARRAY tbuffer;
  struct my_error_mgr terr;

  tinfile = JFOPEN(filename, "rb");
  tcinfo.err = jpeg_std_error(&terr.pub);
  terr.pub.error_exit = my_error_exit;
#ifdef SETJMP_SUPPORT
  if (setjmp(terr.setjmp_buffer)) {
    /* If we get here, the JPEG code has signaled an error.
     * We need to clean up the JPEG object, close the input file, and return.
     */
//    if (is_tcinfo) jpeg_destroy_decompress(&tcinfo);
    JFCLOSE(tinfile);
    return 1;
  }
#endif
  jpeg_create_decompress(&tcinfo);
  jpeg_stdio_src(&tcinfo, tinfile);
  (void) jpeg_read_header(&tcinfo, TRUE);
  tcinfo.jpeg_color_space = JCS_YCbCr; //JCS_GRAYSCALE; //JCS_RGB; //YCbCr;
  jpeg_start_decompress(&tcinfo);
  tbuffer = (*tcinfo.mem->alloc_sarray)
		((j_common_ptr) &tcinfo, JPOOL_IMAGE, (tcinfo.output_width * tcinfo.output_components), 1);
#ifdef DITHER_SUPPORT
  dit_Init();
  dit_fs2dither_init(tWidth);
#endif
//  tdst=timage;
  if ((!torientation) && (tcinfo.output_width < tcinfo.output_height)) torientation=1;


  if ( (!tWidth) || (!tHeight)  )
  {
      tWidth = (int)tcinfo.output_width;
      tHeight = (int)tcinfo.output_height;
  }

  if ( !tStride )
  {
      tStride = tWidth;
  }

  
  txinc = ((long)tcinfo.output_width << 8)/tWidth;
  tyinc = ((long)tcinfo.output_height << 8)/tHeight;
  tyoff=0;
  tycount=-1;



//  dst = (Pixel*)data;
  for (typos = 0; typos <tHeight; typos++) 
  {
    while((tyoff>>8) != tycount)
    {
      (void) jpeg_read_scanlines(&tcinfo, tbuffer, 1);
	  trgbsrc = *tbuffer;
      tycount++;
    } 
    txoff=0;
    switch(tFormat)
	{
	  case GUIPFM_RGB565:
#ifdef DITHER_SUPPORT
        /* 16bits 565 */
        for (txpos = 0; txpos < tWidth; txpos++) 
		{
          tmprgb[3*txpos]   = trgbsrc[3*(txoff>>8)];
          tmprgb[3*txpos+1] = trgbsrc[3*(txoff>>8)+1];
          tmprgb[3*txpos+2] = trgbsrc[3*(txoff>>8)+2];
          txoff += txinc;
		} 
//        trowsrc = (Pixel*)tmprgb;
        dit_fs2dither(0, tmprgb, tWidth, 1);
        dest16 = (unsigned short*)tdst;
        for (txpos = 0; txpos < tWidth; txpos++) 
		{
          *dest16++ = RGB565VAL(tmprgb[txpos*3+0], tmprgb[txpos*3+1], tmprgb[txpos*3+2]);
		}
#else
        dest16 = (unsigned short*)tdst;
        for (txpos = 0; txpos < tWidth; txpos++) 
		{
          *dest16++ = RGB565VAL( trgbsrc[3*(txoff>>8)],
	                          trgbsrc[3*(txoff>>8)+1],
                              trgbsrc[3*(txoff>>8)+2] );
          txoff += txinc;
		}
#endif
		break;
	  case GUIPFM_RGBA5551:
#ifdef DITHER_SUPPORT
        /* 16bits others */
        for (txpos = 0; txpos < tWidth; txpos++) 
		{
          tmprgb[3*txpos]   = trgbsrc[3*(txoff>>8)];
          tmprgb[3*txpos+1] = trgbsrc[3*(txoff>>8)+1];
          tmprgb[3*txpos+2] = trgbsrc[3*(txoff>>8)+2];
          txoff += txinc;
		} 
//        trowsrc = (Pixel*)tmprgb;
        dit_fs2dither(0, tmprgb, tWidth, 1);
        dest16 = (unsigned short*)tdst;
        for (txpos = 0; txpos < tWidth; txpos++) 
		{
          *dest16++ = RGBA5551VAL(tmprgb[txpos*3+0], tmprgb[txpos*3+1], tmprgb[txpos*3+2]);
		}
#else
        dest16 = (unsigned short*)tdst;
        for (txpos = 0; txpos < tWidth; txpos++) 
		{
          *dest16++ = RGBA5551VAL( trgbsrc[3*(txoff>>8)],
	                               trgbsrc[3*(txoff>>8)+1],
                                   trgbsrc[3*(txoff>>8)+2] );
          txoff += txinc;
		}
#endif
		break;
      case GUIPFM_ARGB4444:
#ifdef DITHER_SUPPORT
        /* 16bits others */
        for (txpos = 0; txpos < tWidth; txpos++) 
		{
          tmprgb[3*txpos]   = trgbsrc[3*(txoff>>8)];
          tmprgb[3*txpos+1] = trgbsrc[3*(txoff>>8)+1];
          tmprgb[3*txpos+2] = trgbsrc[3*(txoff>>8)+2];
          txoff += txinc;
		} 
//        trowsrc = (Pixel*)tmprgb;
        dit_fs2dither(0, tmprgb, tWidth, 1);
        dest16 = (unsigned short*)tdst;
        for (txpos = 0; txpos < tWidth; txpos++) 
		{
          *dest16++ = ARGB4444VAL(tmprgb[txpos*3+0], tmprgb[txpos*3+1], tmprgb[txpos*3+2]);
		}
#else
        dest16 = (unsigned short*)tdst;
        for (txpos = 0; txpos < tWidth; txpos++) 
		{
          *dest16++ = ARGB4444VAL( trgbsrc[3*(txoff>>8)],
	                               trgbsrc[3*(txoff>>8)+1],
                                   trgbsrc[3*(txoff>>8)+2] );
          txoff += txinc;
		}
#endif
		break;
	  case GUIPFM_YUYV:
	    /* 32bits YUVY */
        dest32 = (unsigned long *)tdst;
        for (txpos = 0; txpos < tWidth; txpos++) 
		{
          value = ( (trgbsrc[3*(txoff>>8)]  << 8)   | /* Y0*/
	                (trgbsrc[3*(txoff>>8)+1])       | /* U0*/
                    (trgbsrc[3*(txoff>>8)+2]<< 16) ); /* V0*/
          *dest32++= value;
          txoff += txinc;
		}
		break;
	  case GUIPFM_ARGB8888:
	    /* 32bits ARGB */
        dest32 = (unsigned long *)tdst;
        for (txpos = 0; txpos < tWidth; txpos++) 
		{
          *dest32++ = RGB888VAL( trgbsrc[3*(txoff>>8)],
	                             trgbsrc[3*(txoff>>8)+1],
                                 trgbsrc[3*(txoff>>8)+2] );
          txoff += txinc;
		}
		break;
	}
    tdst += tStride;
    tyoff += tyinc; 
  }



  /* Please the decoder */
  while (tcinfo.output_scanline < tcinfo.output_height)
  {
    (void) jpeg_read_scanlines(&tcinfo, tbuffer, 1);
  }
//  (void) jpeg_finish_decompress(&tcinfo);
  jpeg_destroy_decompress(&tcinfo);
  JFCLOSE(tinfile);
  return 1;
}





/**************************************/
void jpg_PlayThumbSync(char * filename, int dstFormat, int dstWidth, 
			           int dstHeight, int dstStride, void * data, int colorkey)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  int       retval=0;
#ifdef THUMBNAIL_SUPPORT
  uchar     *ThumbnailPointer;
  Section_t * ExifSection;
  
  tWidth    = dstWidth;
  tHeight   = dstHeight;
  tStride   = dstStride;
  tFormat   = dstFormat;
  tColorkey = colorkey;
  tdst      = (unsigned char*)data;
  std_strcpy(tjpgfilename, filename);
  is_tcinfo=0;
  torientation = 0;

  ResetJpgfile();
  memset(&ImageInfo, 0, sizeof(ImageInfo));
  if ((retval = ReadJpegFile(tjpgfilename, READ_IMAGE|READ_METADATA /*READ_EXIF*/)) == 1)
  {
        ExifSection = FindSection(M_EXIF);
		if (ExifSection) ThumbnailPointer = ExifSection->Data+ImageInfo.ThumbnailOffset+8;		
        if ( (ThumbnailPointer) && (ExifSection) )
		{
		  /* Setup memory filesystem as pointing to thumbnail data */
          std_vprintf(tname, "mem:%x %u\n", ThumbnailPointer, ImageInfo.ThumbnailSize);
		  /* Read JPEG from memory */
          jpg_readJPEG(tname);
		  /* Read orientation */
          if (ImageInfo.Orientation != 1) torientation = 1;
          DiscardData();
          return;
		}
		else
		{
		  // No thumbnail !!!
//          DiscardData();
          jpg_readJPEG(tjpgfilename);
          return;
		}
  }
  else
  {
    printf("Cannot display non JPEG (%s) because bad JPEG first marker !!\n", tjpgfilename);
    jpgState = STATE_IDLE;
    return;
  }
#endif
}


/**************************************/
void jpg_PlaySync(char * filename, int dstFormat, int dstWidth, 
			      int dstHeight, int dstStride, void * data, int colorkey)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  unsigned int infile;
  struct jpeg_decompress_struct cinfo;
  JSAMPARRAY buffer;
  struct my_error_mgr err;
  unsigned char  * dst;
  unsigned short * dest16;
  unsigned long  * dest32;
  int xinc,yinc;
  int xoff,yoff;
  int xpos,ypos;
  int ycount;
#ifdef ModeLut
#ifdef DITHER_SUPPORT
  Pixel * trowsrc;
#endif
#endif

  unsigned char * rgbsrc;
  unsigned long value;
  unsigned char r,g,b;

  /* Force state to idle */
  jpgState  = STATE_IDLE; 
  infile = JFOPEN(filename, "rb");
  cinfo.err = jpeg_std_error(&err.pub);
  err.pub.error_exit = my_error_exit;
#ifdef SETJMP_SUPPORT
  if (setjmp(err.setjmp_buffer)) {
    /* If we get here, the JPEG code has signaled an error.
     * We need to clean up the JPEG object, close the input file, and return.
     */
    jpeg_destroy_decompress(&cinfo);
    JFCLOSE(infile);
  }
#endif
  jpeg_create_decompress(&cinfo);
  jpeg_stdio_src(&cinfo, infile);
  (void) jpeg_read_header(&cinfo, TRUE);
  if (dstFormat == GUIPFM_YUYV) 
    cinfo.jpeg_color_space = JCS_RGB;
  else
    cinfo.jpeg_color_space = JCS_YCbCr; //JCS_GRAYSCALE; //JCS_RGB; //YCbCr;
  jpeg_start_decompress(&cinfo);
  buffer = (*cinfo.mem->alloc_sarray)
		((j_common_ptr) &cinfo, JPOOL_IMAGE, (cinfo.output_width * cinfo.output_components), 1);

//  while (cinfo.output_scanline < cinfo.output_height)
//  {
//		(void) jpeg_read_scanlines(&cinfo, buffer, 1);
//  }

#ifdef DITHER_SUPPORT
  dit_Init();
  dit_fs2dither_init(dstWidth);
#endif
  xinc = ((long)cinfo.output_width << 8)/dstWidth;
  yinc = ((long)cinfo.output_height << 8)/dstHeight;
  yoff=0;
  ycount=-1;
  dst = (unsigned char *)data;
  for (ypos = 0; ypos <dstHeight; ypos++) 
  {
    while((yoff>>8) != ycount)
    {
      (void) jpeg_read_scanlines(&cinfo, buffer, 1);
	  rgbsrc = *buffer;
      ycount++;
    } 
    xoff=0;
    switch(dstFormat)
	{
	  case GUIPFM_RGB565:
#ifdef DITHER_SUPPORT
        /* 16bits 565 */
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          r = rgbsrc[3*(xoff>>8)]; g = rgbsrc[3*(xoff>>8)+1]; b = rgbsrc[3*(xoff>>8)+2];
		  if(colorkey != -1)
		  {
            if (r < 16) r = 16;
            if (g < 8) g = 8;
            if (b < 16) b = 16;
		  }
          tmprgb[3*xpos]   = r;
          tmprgb[3*xpos+1] = g;
          tmprgb[3*xpos+2] = b;
          xoff += xinc;
		} 
//        trowsrc = (Pixel*)tmprgb;
        dit_fs2dither(0, tmprgb, dstWidth, 1);
        dest16 = (void*)dst;
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          *dest16++ =RGB565VAL(tmprgb[xpos*3+0], tmprgb[xpos*3+1], tmprgb[xpos*3+2]);
		}
#else
        dest16 = dst;
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          r = rgbsrc[3*(xoff>>8)]; g = rgbsrc[3*(xoff>>8)+1]; b = rgbsrc[3*(xoff>>8)+2];
		  if(colorkey != -1)
		  {
            if (r < 16) r = 16;
            if (g < 8) g = 8;
            if (b < 16) b = 16;
		  }
          *dest16++ = RGB565VAL( r,g,b);
          xoff += xinc;
		}
#endif
		break;
	  case GUIPFM_RGBA5551:
#ifdef DITHER_SUPPORT
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          tmprgb[3*xpos]   = rgbsrc[3*(xoff>>8)];
          tmprgb[3*xpos+1] = rgbsrc[3*(xoff>>8)+1];
          tmprgb[3*xpos+2] = rgbsrc[3*(xoff>>8)+2];
          xoff += xinc;
		} 
//        trowsrc = (Pixel*)tmprgb;
        dit_fs2dither(0, tmprgb, dstWidth, 1);
        dest16 = (void*)dst;
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          *dest16++ = RGBA5551VAL(tmprgb[xpos*3+0], tmprgb[xpos*3+1], tmprgb[xpos*3+2]);
		}
#else
        dest16 = dst;
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          *dest16++ = RGBA5551VAL( rgbsrc[3*(xoff>>8)],
	                               rgbsrc[3*(xoff>>8)+1],
                                   rgbsrc[3*(xoff>>8)+2] );
          xoff += xinc;
		}
#endif
		break;
	  case GUIPFM_ARGB4444:
#ifdef DITHER_SUPPORT
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          tmprgb[3*xpos]   = rgbsrc[3*(xoff>>8)];
          tmprgb[3*xpos+1] = rgbsrc[3*(xoff>>8)+1];
          tmprgb[3*xpos+2] = rgbsrc[3*(xoff>>8)+2];
          xoff += xinc;
		} 
//        trowsrc = (Pixel*)tmprgb;
        dit_fs2dither(0, tmprgb, dstWidth, 1);
        dest16 = (void*)dst;
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          *dest16++ = ARGB4444VAL(tmprgb[xpos*3+0], tmprgb[xpos*3+1], tmprgb[xpos*3+2]);
		}
#else
        dest16 = dst;
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          *dest16++ = ARGB4444VAL( rgbsrc[3*(xoff>>8)],
	                               rgbsrc[3*(xoff>>8)+1],
                                   rgbsrc[3*(xoff>>8)+2] );
          xoff += xinc;
		}
#endif
		break;
	  case GUIPFM_YUYV:
	    /* 32bits YUVY */
        dest32 = (unsigned long *)dst;
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          value = ( (rgbsrc[3*(xoff>>8)]  << 8)   | /* Y0*/
	                (rgbsrc[3*(xoff>>8)+1])       | /* U0*/
                    (rgbsrc[3*(xoff>>8)+2]<< 16) ); /* V0*/
          *dest32++= value;
          xoff += xinc;
		}
		break;
	  case GUIPFM_ARGB8888:
	    /* 32bits ARGB */
        dest32 = (unsigned long *)dst;
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          *dest32++ = RGB888VAL( rgbsrc[3*(xoff>>8)],
	                             rgbsrc[3*(xoff>>8)+1],
                                 rgbsrc[3*(xoff>>8)+2] );
          xoff += xinc;
		}
		break;
	}
    dst += dstStride;
    yoff += yinc; 
  }

  /* Please the decoder */
  while (cinfo.output_scanline < cinfo.output_height)
  {
    (void) jpeg_read_scanlines(&cinfo, buffer, 1);
  }

  (void) jpeg_finish_decompress(&cinfo);
  jpeg_destroy_decompress(&cinfo);
  JFCLOSE(infile);
}



/**************************************/
void jpg_Play(char * filename, int format, int width, 
			  int height, int stride, void * buffer, int colorkey)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  if (jpgState == STATE_IDLE) 
  {
    skipDisplay = 0;
    dstFormat = format;
    dstColorkey = colorkey;
    dstWidth  = width;
    dstHeight = height;
    dstStride = stride;
    dst       = buffer;
	dsty      = 0;
    std_strcpy(jpgfilename, filename);
	curypos   = 0;
    jpgState  = STATE_STARTING;
#ifdef THREAD_DECODING
#ifdef WIN32
	semJpgSignal();
#endif
#ifdef _trimedia
    ev_send(jpeg_task, EVENT1);
#endif
#ifdef _arch_dreamcast
	sem_signal(sema);
#endif
#if ( (VIPER) && (!LINUX) )
    semGive (semSync);
#endif
#if (LINUX)
	pthread_mutex_lock(&wait_mutex);
	pthread_cond_signal(&wait_cont);
	pthread_mutex_unlock(&wait_mutex);
#endif
#endif
  }
}


/**************************************/
void jpg_Stop(void)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  if (jpgState == STATE_IDLE)
	return;
#ifdef THREAD_DECODING
  while ( (jpgState == STATE_STARTING) )
#ifdef _trimedia
        tm_wkafter(5)
#endif
#if ( (VIPER) && (!LINUX) )
        taskDelay(1)
#endif
#if (LINUX)
        usleep(1000);
#endif
#ifdef WIN32
	    krnWait(5)
#endif
		;
#endif
  jpgState = STATE_ENDING;
#ifdef THREAD_DECODING
  while (jpgState == STATE_ENDING) 
#ifdef _trimedia
        tm_wkafter(5)
#endif
#if ( (VIPER) && (!LINUX) )
        taskDelay(1)
#endif
#if (LINUX)
        usleep(1000);
#endif
#ifdef WIN32
	    krnWait(5)
#endif
        ;
#endif
  jpgState = STATE_IDLE;
}


/**************************************/
int jpg_Playing(void)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  if (jpgState == STATE_IDLE)
	  return (0);
  else
  {
      if ( curypos )
	    return (curypos);
      else
	    return (-1);
  }
//  return((jpgState != STATE_IDLE));
}






#ifdef THREAD_DECODING
void jpg_OnTimer(void)
{
}

static void jpg_Task(void)
#else
void jpg_OnTimer(void)
#endif
{
  unsigned long value;
  int targYpos;
  
//#ifdef DITHER_SUPPORT
//  Pixel * rowsrc;
//#endif
#ifdef _trimedia
  unsigned long dummy;
#endif
#ifdef TTHUMBNAIL_SUPPORT
  int retval;
#endif

  /* Block till request when both idle !! */
  if ( jpgState <= STATE_STARTING ) 
  {
#ifdef THREAD_DECODING
#ifdef WIN32
	  semJpgWait();
#endif
#ifdef _trimedia
      ev_receive( EVENT1, EV_WAIT | EV_ANY, 100, &dummy);
#endif
#ifdef _arch_dreamcast
      sem_wait(sema);
#endif
#if ( (VIPER) && (!LINUX) )
      semTake (semSync, WAIT_FOREVER);    
#endif
#if (LINUX)
	pthread_mutex_lock(&wait_mutex);
	pthread_cond_wait(&wait_cont, &wait_mutex);
	pthread_mutex_unlock(&wait_mutex);
#endif
#endif
  }

  /* Main decoding */
  switch(jpgState)
  {
    case STATE_STARTING:
      if (!(infile = JFOPEN(jpgfilename, "rb"))) 
	  {
        jpgState = STATE_IDLE;
        return;
	  }
      cinfo.err = jpeg_std_error(&jerr.pub);
      jerr.pub.error_exit = my_error_exit;
#ifdef SETJMP_SUPPORT
      if (setjmp(jerr.setjmp_buffer)) {
      /* If we get here, the JPEG code has signaled an error.
       * We need to clean up the JPEG object, close the input file, and return.
       */
      jpeg_destroy_decompress(&cinfo);
      JFCLOSE(infile);
      jpgState = STATE_IDLE;
      return;
  }
#endif

      jpeg_create_decompress(&cinfo);
      jpeg_stdio_src(&cinfo, infile);
      (void) jpeg_read_header(&cinfo, TRUE);
	  if (dstFormat == GUIPFM_YUYV)
        cinfo.jpeg_color_space = JCS_RGB;   //YUV!!!!!!!
	  else
        cinfo.jpeg_color_space = JCS_YCbCr; 
      (void) jpeg_start_decompress(&cinfo);
      buffer = (*cinfo.mem->alloc_sarray)
		((j_common_ptr) &cinfo, JPOOL_IMAGE, (cinfo.output_width * cinfo.output_components), 1);
      yoff=0;
      ypos=0;
      ycount=-1;
      xinc = ((long)cinfo.output_width << 8)/dstWidth;
      yinc = ((long)cinfo.output_height << 8)/dstHeight;
      jpgState = STATE_DECODING_LINE;
	  break;

    case STATE_DECODING_LINE:
      targYpos = ypos + JPEG_PROCESSING_RESOLUTION;
      while ((ypos < targYpos) && (ypos < dstHeight) )
	  {
        while((yoff>>8) != ycount)
		{
          (void) jpeg_read_scanlines(&cinfo, buffer, 1);
	      datasrc = *buffer;
          ycount++;
		} 
        xoff=0;
        switch(dstFormat)
		{
		  case GUIPFM_RGB565:
	        /* 16bits ARGB */
		    dest = dst;
		    for (xpos = 0; xpos < dstWidth; xpos++) 
			{
              *dest++ = RGB565VAL ( datasrc[3*(xoff>>8)],
	                              datasrc[3*(xoff>>8)+1],
                                  datasrc[3*(xoff>>8)+2] );
              xoff += xinc;
			}
            dst += dstStride;
		    break;
		  case GUIPFM_RGBA5551:
		    for (xpos = 0; xpos < dstWidth; xpos++) 
			{
              *dest16++ = RGBA5551VAL ( datasrc[3*(xoff>>8)],
	                                    datasrc[3*(xoff>>8)+1],
                                        datasrc[3*(xoff>>8)+2] );
              xoff += xinc;
			}
            dst += dstStride;
		    break;
          case GUIPFM_ARGB4444:
		    dest16 = dst;
		    for (xpos = 0; xpos < dstWidth; xpos++) 
			{
              *dest16++ = ARGB4444VAL ( datasrc[3*(xoff>>8)],
	                                    datasrc[3*(xoff>>8)+1],
                                        datasrc[3*(xoff>>8)+2] );
              xoff += xinc;
			}
            dst += dstStride;
		    break;
	      case GUIPFM_ARGB8888:
	        /* 32bits ARGB */
		    dest32 = dst;
		    for (xpos = 0; xpos < dstWidth; xpos++) 
			{
              *dest32++ = RGB888VAL( datasrc[3*(xoff>>8)],
	                                 datasrc[3*(xoff>>8)+1],
                                     datasrc[3*(xoff>>8)+2] );
              xoff += xinc;
			}
            dst += dstStride;
		    break;

		  case GUIPFM_YUYV:
		    dest = dst;
		    for (xpos = 0; xpos < dstWidth; xpos++) 
			{
              value = ( (datasrc[3*(xoff>>8)]  << 8)   | 
		                (datasrc[3*(xoff>>8)+1])       | 
                        (datasrc[3*(xoff>>8)+2]<< 16) ); 
              *dest++= value;
              xoff += xinc;
			}
            dst += dstStride;
		    /* 32bits YUVY */
/*
            for (xpos = 0; xpos < EDGE; xpos++) 
			{
              value = ( (datasrc[3*(xoff>>8)]  << 8)   | 
		                (datasrc[3*(xoff>>8)+1])       | 
                        (datasrc[3*(xoff>>8)+2]<< 16) ); 

              *dp++= value;
              xoff += xinc;
			}
            value=0;
	        while((y >> 8) == ypos)
			{
              dest = dst;
	          for(i=0;i<dstWidth;i++)
			  {
	            if ((i & 0x01) == 0x01)
				{ 
		          if ( (x & ~MASK1) || (y & ~MASK1) )
		            value = 0x108010;
		          else	  
	                value |= ((image[((y&MASK2)<<SHIFT2) + ((x&MASK2)>>SHIFT1)] << 16) & 0xff000000); // Y1
		          *dest = value; dest++; value=0;
				}
	            else
				{
		          if ( (x & ~MASK1) || (y & ~MASK1) )
		            value = 0x108010;
		          else
		            value = image[((y&MASK2)<<SHIFT2) + ((x&MASK2)>>SHIFT1)];
				}
                x += xic;
			  }
              y += yic;
              dst += dstStride;
			}
*/
		    break;
		}
		yoff += yinc;
	    ypos++;
	  }

      if (ypos >= dstHeight)
	  {
	    curypos = ypos-1;
        jpgState = STATE_ENDING;   
	  }
	  else
	  {
        curypos = ypos;
	  }
	  break;

    case STATE_ENDING:
      /* Please the decoder */
      while (cinfo.output_scanline < cinfo.output_height)
	  {
        (void) jpeg_read_scanlines(&cinfo, buffer, 1);
	  }
      (void) jpeg_finish_decompress(&cinfo);
      jpeg_destroy_decompress(&cinfo);
      JFCLOSE(infile);
      jpgState = STATE_IDLE;   
	  break;

    case STATE_IDLE:
	default:
	  break;
  }
}


/***************************************
* Local procedures
***************************************/
#ifdef THREAD_DECODING
static void jpg_Decoder(void)
{
    while(1)
    {
      jpg_Task();
    }
}
#endif
#endif
