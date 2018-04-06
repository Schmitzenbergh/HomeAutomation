#define JPEG_SUPPORT       1
#define THUMBNAIL_SUPPORT  1
//#define DITHER_SUPPORT     1
//#define THREAD_DECODING    1

#ifdef JPEG_SUPPORT
/****************************************************************************
* Purpose : Jpeg decoder (using jpeglib)
* Module  : JPEG
* Author  : J-M Harvengt
* History : 10/08/97 Creation
****************************************************************************/
#include <stdio.h>
#include "mystdio.h"
#include "console.h"
//#include <errno.h>

#include "jpeglib.h"
#include "jinclude.h"
#include "systypes.h"


#include "lld.h"
#ifdef THUMBNAIL_SUPPORT
//#include "bmp.h"
#endif
#ifdef DITHER_SUPPORT
#include "dither.h"
#endif
#include "mem.h"
#include "std.h"
//#include "rpm.h"

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
//#include <signal.h>
//#include <unistd.h>
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

#include "jpeg.h"

/**************************************
* Local macros/typedef
**************************************/
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

/***************************************
* Local data
***************************************/
static unsigned char  tmprgb[4096*3];
static Pixel timage[256*120];


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

/*
#ifdef RGB_PROCESSING
#ifdef GLOBAL_CACHE
extern char gcache[];
static Pixel  * image = (Pixel*)gcache;
#else
static Pixel image[EDGE*EDGE];
#endif
#endif

#ifdef YUV_PROCESSING
#ifdef GLOBAL_CACHE
extern char gcache[];
static unsigned long  * image = (unsigned long*)gcache;
#else
static unsigned long  image[EDGE*EDGE];
#endif
#endif
*/


/* Thumbnail decoding variables */
static char tjpgfilename[128];
static char tname[256];
static int tjpgState;
static int is_tcinfo=0;
static struct jpeg_decompress_struct tcinfo;
static struct my_error_mgr tjerr;
static unsigned int tinfile;
static JSAMPARRAY tbuffer;
static unsigned char * trgbsrc;
static Pixel * tdst;
static Pixel * tdest;
static int tFormat;
static int tWidth, tHeight, tStride;
static int txinc,tyinc;
static int txoff,tyoff;
static int txpos,typos;
static int tycount;
static char * tinfo;
static int torientation;

/* Main decoding variables */
static char jpgfilename[128];
static int jpgState;
static struct jpeg_decompress_struct cinfo;
static JSAMPARRAY buffer;
static struct my_error_mgr jerr;
static unsigned int infile;

#ifdef RGB_PROCESSING
static Pixel * dp;
static Pixel * dst;
static Pixel * dest;
#endif
#ifdef YUV_PROCESSING
static unsigned long * dp;
static unsigned short * dst;
static unsigned long * dest;
#endif
static int dsty;

static unsigned char * datasrc;
static int dstFormat;
static int dstWidth, dstHeight, dstStride;
static int skipDisplay;
static int xinc,yinc;
static int xoff,yoff;
static int ycount;
static int xpos, ypos, curypos;
static int i;


/***************************************
* Global data
***************************************/
extern JSAMPLE * image_buffer;	/* Points to large array of R,G,B-order data */
extern int image_height;	/* Number of rows in image */
extern int image_width;		/* Number of columns in image */

/***************************************
* Exported procedures
***************************************/
/***************************************
* Initialization.
***************************************/
void jpg_Init(void)
{
  jpgState  = STATE_IDLE; 
  tjpgState = STATE_IDLE;
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
  jpg_InfoStop();
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
  if (tjpgState == STATE_ENDING)
  {
      /* Please the decoder */
      while (tcinfo.output_scanline < tcinfo.output_height)
	  {
        (void) jpeg_read_scanlines(&tcinfo, tbuffer, 1);
	  }
      (void) jpeg_finish_decompress(&tcinfo);
      jpeg_destroy_decompress(&tcinfo);
      JFCLOSE(tinfile);
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
  Pixel          * trowsrc;
#endif
#endif
  unsigned short *dest16;
  unsigned long  *dest32;
  unsigned long  value;

  tinfile = JFOPEN(filename, "rb");
  tcinfo.err = jpeg_std_error(&tjerr.pub);
  tjerr.pub.error_exit = my_error_exit;
#ifdef SETJMP_SUPPORT
  if (setjmp(jerr.setjmp_buffer)) {
    /* If we get here, the JPEG code has signaled an error.
     * We need to clean up the JPEG object, close the input file, and return.
     */
    if (is_tcinfo) jpeg_destroy_decompress(&tcinfo);
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
	  case PIXFORMAT_R5G6B5:
	  case PIXFORMAT_R5G5B5A1:
      case PIXFORMAT_R4G4B4A4:
#ifdef DITHER_SUPPORT
        /* 16bits 656 */
        for (txpos = 0; txpos < tWidth; txpos++) 
		{
          tmprgb[3*txpos]   = trgbsrc[3*(txoff>>8)];
          tmprgb[3*txpos+1] = trgbsrc[3*(txoff>>8)+1];
          tmprgb[3*txpos+2] = trgbsrc[3*(txoff>>8)+2];
          txoff += txinc;
		} 
//        trowsrc = (Pixel*)tmprgb;
        dit_fs2dither(tmprgb, tWidth, 1);
        dest16 = tdst;
        for (txpos = 0; txpos < tWidth; txpos++) 
		{
          *dest16++ = col_GetColor(RGBVAL(tmprgb[txpos*3+0], tmprgb[txpos*3+1], tmprgb[txpos*3+2]));
		}
#else
        dest16 = tdst;
        for (txpos = 0; txpos < tWidth; txpos++) 
		{
          *dest16++ = RGBVAL( trgbsrc[3*(txoff>>8)],
	                          trgbsrc[3*(txoff>>8)+1],
                              trgbsrc[3*(txoff>>8)+2] );
          txoff += txinc;
		}
#endif
		break;
	  case PIXFORMAT_Y8U8V8Y8:
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
	  case PIXFORMAT_A8R8G8B8:
	    /* 32bits ARGB */
        dest32 = (unsigned long *)tdst;
        for (txpos = 0; txpos < tWidth; txpos++) 
		{
          *dest32++ = RGBVAL32( trgbsrc[3*(txoff>>8)],
	                            trgbsrc[3*(txoff>>8)+1],
                                trgbsrc[3*(txoff>>8)+2] );
          txoff += txinc;
		}
		break;
	  case PIXFORMAT_CLUT8:
	  case PIXFORMAT_CLUT16:
#ifdef ModeLut
#ifdef DITHER_SUPPORT
        /* CLUT mode (Dithering if 8 bits) */
        for (txpos = 0; txpos < tWidth; txpos++) 
		{
          tmprgb[3*txpos]   = trgbsrc[3*(txoff>>8)];
          tmprgb[3*txpos+1] = trgbsrc[3*(txoff>>8)+1];
          tmprgb[3*txpos+2] = trgbsrc[3*(txoff>>8)+2];
          txoff += txinc;
		} 
        trowsrc = (Pixel*)tmprgb;
        dit_fs2dither(tmprgb, tWidth, 1);
        dest16 = tdst;
        for (txpos = 0; txpos < tWidth; txpos++) 
		{
          *dest16++= trowsrc[txpos];
		}
#else
        dest16 = tdst;
        for (txpos = 0; txpos < tWidth; txpos++) 
		{
          *dest16++ = RGBVAL( trgbsrc[3*(txoff>>8)],
	                          trgbsrc[3*(txoff>>8)+1],
                              trgbsrc[3*(txoff>>8)+2] );
          txoff += txinc;
		}
#endif
#endif
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
  (void) jpeg_finish_decompress(&tcinfo);
  jpeg_destroy_decompress(&tcinfo);
  JFCLOSE(tinfile);
  return 1;
}





/**************************************/
void jpg_PlayThumbSync(char * filename, int dstFormat, int dstWidth, 
			           int dstHeight, int dstStride, void * data)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  int retval=0;

#ifdef THUMBNAIL_SUPPORT
  tWidth  = dstWidth;
  tHeight = dstHeight;
  tStride = dstStride;
  tFormat = dstFormat;
  tdst    = (Pixel*)data;
  std_strcpy(tjpgfilename, filename);
  is_tcinfo=0;
  torientation = 0;

  ResetJpgfile();
  memset(&ImageInfo, 0, sizeof(ImageInfo));
  if ((retval = ReadJpegFile(tjpgfilename, READ_EXIF)) == 0)
  {
//        std_strcpy(tinfo, ImageInfo.DateTime);      
		/* Read thumbnail */
        if (ImageInfo.ThumbnailPointer)
		{
		  /* Setup memory filesystem as pointing to thumbnail data */
          std_vprintf(tname, "mem:%x %u\n", ImageInfo.ThumbnailPointer, ImageInfo.ThumbnailSize);
		  /* Read JPEG from memory */
          jpg_readJPEG(tname);
		  /* Read orientation */
          if (ImageInfo.Orientation != 1) torientation = 1;
          DiscardData();
          tjpgState = STATE_IDLE; //STATE_ENDING; 
          return;
		}
  }
  else
  {
    printf("Cannot display non JPEG (%s) because bad JPEG first marker !!\n", jpgfilename);
    jpgState = STATE_IDLE;
    return;
  }
#endif
}


/**************************************/
void jpg_PlaySync(char * filename, int dstFormat, int dstWidth, 
			      int dstHeight, int dstStride, void * data)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  unsigned int infile;
  struct jpeg_decompress_struct cinfo;
  JSAMPARRAY buffer;
  struct my_error_mgr err;
//#ifdef DITHER_SUPPORT
//  unsigned char  tmprgb[4096*3];
//#endif
  Pixel * dst;
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
  if (dstFormat == PIXFORMAT_Y8U8V8Y8) 
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
  dit_fs2dither_init(dstWidth);
#endif
  xinc = ((long)cinfo.output_width << 8)/dstWidth;
  yinc = ((long)cinfo.output_height << 8)/dstHeight;
  yoff=0;
  ycount=-1;
  dst = (Pixel*)data;
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
	  case PIXFORMAT_R5G6B5:
	  case PIXFORMAT_R5G5B5A1:
#ifdef DITHER_SUPPORT
        /* 16bits 656 */
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          tmprgb[3*xpos]   = rgbsrc[3*(xoff>>8)];
          tmprgb[3*xpos+1] = rgbsrc[3*(xoff>>8)+1];
          tmprgb[3*xpos+2] = rgbsrc[3*(xoff>>8)+2];
          xoff += xinc;
		} 
//        trowsrc = (Pixel*)tmprgb;
        dit_fs2dither(tmprgb, dstWidth, 1);
        dest16 = dst;
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          *dest16++ = col_GetColor(RGBVAL(tmprgb[xpos*3+0], tmprgb[xpos*3+1], tmprgb[xpos*3+2]));
		}
#else
        dest16 = dst;
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          *dest16++ = RGBVAL( rgbsrc[3*(xoff>>8)],
	                          rgbsrc[3*(xoff>>8)+1],
                              rgbsrc[3*(xoff>>8)+2] );
          xoff += xinc;
		}
#endif
		break;
	  case PIXFORMAT_Y8U8V8Y8:
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
	  case PIXFORMAT_A8R8G8B8:
	    /* 32bits ARGB */
        dest32 = (unsigned long *)dst;
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          *dest32++ = RGBVAL32( rgbsrc[3*(xoff>>8)],
	                            rgbsrc[3*(xoff>>8)+1],
                                rgbsrc[3*(xoff>>8)+2] );
          xoff += xinc;
		}
		break;
	  case PIXFORMAT_CLUT8:
	  case PIXFORMAT_CLUT16:
#ifdef ModeLut
#ifdef DITHER_SUPPORT
        /* CLUT mode (Dithering if 8 bits) */
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          tmprgb[3*xpos]   = rgbsrc[3*(xoff>>8)];
          tmprgb[3*xpos+1] = rgbsrc[3*(xoff>>8)+1];
          tmprgb[3*xpos+2] = rgbsrc[3*(xoff>>8)+2];
          xoff += xinc;
		} 
        trowsrc = (Pixel*)tmprgb;
        dit_fs2dither(tmprgb, dstWidth, 1);
        dest16 = dst;
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          *dest16++= trowsrc[xpos];
		}
#else
        dest16 = dst;
        for (xpos = 0; xpos < dstWidth; xpos++) 
		{
          *dest16++ = RGBVAL( rgbsrc[3*(xoff>>8)],
	                          rgbsrc[3*(xoff>>8)+1],
                              rgbsrc[3*(xoff>>8)+2] );
          xoff += xinc;
		}
#endif
#endif
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
			  int height, int stride, void * buffer)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  if (jpgState == STATE_IDLE) 
  {
    skipDisplay = 0;
    dstFormat = format;
    dstWidth  = width;
    dstHeight = height;
    dstStride = stride;
    dst       = (Pixel*)buffer;
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


#ifdef THUMBNAIL_SUPPORT
/**************************************/
void jpg_GetThumbnail(void)
//void jpg_GetThumbnail(GBmp * bmp)
/**************************************
 * Parameters :
 * Purpose    : Get thumbnail taking 
 *              rotation into account.
 **************************************/
{
/*  int x,y,k; */

  if (tjpgState != STATE_IDLE)
    return;
/*
  if (bmp)
  {
    bmp->Width  = tWidth;
    bmp->Height = tHeight;
    bmp->xoffset = 0;
    bmp->yoffset = 0;
    bmp->istrans = 0;
    bmp->nbframe = 1;
    k=0;
    if (torientation)
	{
      for (y=0;y<120;y++)
        for (x=0;x<160;x++)
          bmp->bmap[k++] = timage[y*160+x];
	}
    else
	{
      for (y=0;y<120;y++)
        for (x=0;x<160;x++)
          bmp->bmap[k++] = timage[y*160+x];
	}
  }
*/
}
#endif




/**************************************/
void jpg_InfoStop(void)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  if (tjpgState == STATE_IDLE)
    return;
#ifdef THREAD_DECODING
  while ( (tjpgState == STATE_STARTING) )
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
  tjpgState = STATE_ENDING;
#ifdef THREAD_DECODING
  while (tjpgState == STATE_ENDING) 
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
  tjpgState = STATE_IDLE;
}



/**************************************/
void jpg_GetInfo(char * filename, char * info, 
				 int format, int width, int height, 
				 int stride, void * buffer, int mode)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  if (tjpgState == STATE_IDLE) 
  {

    tWidth  = width;
    tHeight = height;
    tStride = stride;
    tFormat = format;
    tdst    = (Pixel*)buffer;
    std_strcpy(tjpgfilename, filename);
    is_tcinfo=0;
    tinfo = info;
    torientation = 0;
    tjpgState = STATE_STARTING;
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
int jpg_InfoReady(void)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  return((tjpgState == STATE_IDLE));
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
  int ttargYpos;
//#ifdef DITHER_SUPPORT
//  Pixel * rowsrc;
//#endif
  Pixel * trowsrc;
#ifdef _trimedia
  unsigned long dummy;
#endif
#ifdef THUMBNAIL_SUPPORT
  int retval;
#endif

  /* Block till request when both idle !! */
  if ( (jpgState <= STATE_STARTING) && (tjpgState <= STATE_STARTING) ) 
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
#ifdef THUMBNAIL_SUPPORT
      /* Check if valid file !!! */
      ResetJpgfile();
      memset(&ImageInfo, 0, sizeof(ImageInfo));
	  retval = ReadJpegFile(jpgfilename, READ_EXIF);
      DiscardData();
      if (retval == 1)
      {
        printf("Cannot display non JPEG (%s) because bad JPEG first marker !!\n", jpgfilename);
        jpgState = STATE_IDLE;
		return;
      }
#endif

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
      jpeg_destroy_decompress(&tcinfo);
      JFCLOSE(infile);
      jpgState = STATE_IDLE;
      return;
  }
#endif

      jpeg_create_decompress(&cinfo);
      jpeg_stdio_src(&cinfo, infile);
      (void) jpeg_read_header(&cinfo, TRUE);
	  if (dstFormat == PIXFORMAT_Y8U8V8Y8)
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
		  case PIXFORMAT_R5G6B5:
		  case PIXFORMAT_R5G5B5A1:
          case PIXFORMAT_R4G4B4A4:
	        /* 16bits ARGB */
		    dest = dst;
		    for (xpos = 0; xpos < dstWidth; xpos++) 
			{
              *dest++ = RGBVAL  ( datasrc[3*(xoff>>8)],
	                              datasrc[3*(xoff>>8)+1],
                                  datasrc[3*(xoff>>8)+2] );
              xoff += xinc;
			}
            dst += dstStride;
		    break;
	      case PIXFORMAT_A8R8G8B8:
	        /* 32bits ARGB */
		    dest = dst;
		    for (xpos = 0; xpos < dstWidth; xpos++) 
			{
              *dest++ = RGBVAL32( datasrc[3*(xoff>>8)],
	                              datasrc[3*(xoff>>8)+1],
                                  datasrc[3*(xoff>>8)+2] );
              xoff += xinc;
			}
            dst += dstStride;
		    break;

		  case PIXFORMAT_Y8U8V8Y8:
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
		  case PIXFORMAT_CLUT8:
		  case PIXFORMAT_CLUT16:
#ifdef ModeLut
#ifdef DITHER_SUPPORT
		    /* CLUT mode (Dithering if 8 bits) */
/*
            for (xpos = 0; xpos < EDGE; xpos++) 
			{
              tmprgb[3*xpos]   = datasrc[3*(xoff>>8)];
              tmprgb[3*xpos+1] = datasrc[3*(xoff>>8)+1];
              tmprgb[3*xpos+2] = datasrc[3*(xoff>>8)+2];
              xoff += xinc;
			}
            dit_fs2dither(tmprgb, EDGE, 1);
	        rowsrc = (Pixel*)tmprgb;
            for (xpos = 0; xpos < EDGE; xpos++) 
			{
              *dp++= col_GetColor(rowsrc[xpos]);
			}
	        while((y >> 8) == ypos)
			{
              dest = dst;
	          for(i=0;i<dstWidth;i++)
			  {
		        if ( (x & ~MASK1) || (y & ~MASK1) )
		          *dest++ = 0;
		        else
		          *dest++ = image[((y&MASK2)<<SHIFT2) + ((x&MASK2)>>SHIFT1)];
                x += xic;
			  }
              y += yic;
              dst += dstStride;
			}
*/
#else
/*
            for (xpos = 0; xpos < EDGE; xpos++) 
			{ 
	          *dp++ = RGBVAL( datasrc[3*(xoff>>8)],
		                      datasrc[3*(xoff>>8)+1],
                              datasrc[3*(xoff>>8)+2]);
              xoff += xinc;
			}
	        while((y >> 8) == ypos)
			{
              if (dsty < dstHeight)
			  {
                dest = dst;
	            for(i=0;i<dstWidth;i++)
				{
		          if ( (x & ~MASK1) || (y & ~MASK1) )
		            *dest++ = 0;
		          else
		            *dest++ = image[((y&MASK2)<<SHIFT2) + ((x&MASK2)>>SHIFT1)];
                  x += xic;
				}
                y += yic;
                dst += dstStride;
			    dsty++;
			  }
			}
*/
#endif
#endif
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


  /* Thumbnail decoding */
  if (jpgState == STATE_IDLE) switch(tjpgState)
  {
    case STATE_STARTING:
#ifdef THUMBNAIL_SUPPORT
      ResetJpgfile();
      memset(&ImageInfo, 0, sizeof(ImageInfo));
      if ((retval = ReadJpegFile(tjpgfilename, READ_EXIF)) == 0)
	  {
//              DiscardData();
//              tjpgState = STATE_IDLE; //STATE_ENDING; 
//              return;
//      std_printf("B\n");

        if (tinfo)
          std_strcpy(tinfo, ImageInfo. DateTime);      
		/* Read thumbnail */
        if (ImageInfo.ThumbnailPointer)
		{
		  /* Setup memory filesystem as pointing to thumbnail data */
          std_vprintf(tname, "mem:%x %u\n", ImageInfo.ThumbnailPointer, ImageInfo.ThumbnailSize);
		  /* Read JPEG from memory */
          jpg_readJPEG(tname);
		  /* Read orientation */
          if (ImageInfo.Orientation != 1) torientation = 1;
          DiscardData();
          tjpgState = STATE_IDLE; //STATE_ENDING; 
          return;
		}
	  }
      else
      {
//	      retval=1;
          switch (retval)
          {
            case 1:
              printf("Bad file (%s) having bad JPEG first marker !!\n", tjpgfilename);
              DiscardData();
              tjpgState = STATE_IDLE; //STATE_ENDING; 
              return;
              break;
            default:
              break;
          }
      }
      DiscardData();
#endif

      if (!(tinfile = JFOPEN(tjpgfilename, "rb"))) {
      tjpgState = STATE_IDLE; //STATE_ENDING; 
      return;
	  }
      tcinfo.err = jpeg_std_error(&tjerr.pub);
      tjerr.pub.error_exit = my_error_exit;
#ifdef SETJMP_SUPPORT
      if (setjmp(jerr.setjmp_buffer)) {
      /* If we get here, the JPEG code has signaled an error.
       * We need to clean up the JPEG object, close the input file, and return.
       */
      if (is_tcinfo) jpeg_destroy_decompress(&tcinfo);
      JFCLOSE(tinfile);
	  is_tcinfo=0;
      tjpgState = STATE_IDLE; //STATE_ENDING; 
      return;
  }
#endif

      jpeg_create_decompress(&tcinfo);
      is_tcinfo=1;
      jpeg_stdio_src(&tcinfo, tinfile);
      (void) jpeg_read_header(&tcinfo, TRUE);
      tcinfo.jpeg_color_space = JCS_YCbCr; //JCS_GRAYSCALE; //JCS_RGB; //YCbCr;
      jpeg_start_decompress(&tcinfo);
      tbuffer = (*tcinfo.mem->alloc_sarray)
		  ((j_common_ptr) &tcinfo, JPOOL_IMAGE, (tcinfo.output_width * tcinfo.output_components), 1);
#ifdef DITHER_SUPPORT
      dit_fs2dither_init(tWidth);
#endif
      tdst=timage;
      if ((!torientation) && (tcinfo.output_width < tcinfo.output_height)) torientation=1;
      txinc = ((long)tcinfo.output_width << 8)/tWidth;
      tyinc = ((long)tcinfo.output_height << 8)/tHeight;
      tyoff=0;
      tycount=-1;
      typos=0;
      tjpgState = STATE_DECODING_LINE;
	  break;

    case STATE_DECODING_LINE:
      ttargYpos = typos + JPEG_PROCESSING_RESOLUTION;
      while ((typos < ttargYpos) && (typos < tHeight) )
	  {
        while((tyoff>>8) != tycount)
		{
          (void) jpeg_read_scanlines(&tcinfo, tbuffer, 1);
	      trgbsrc = *tbuffer;
          tycount++;
		} 
        txoff=0;
#ifdef ModeLut
#ifdef DITHER_SUPPORT
        for (txpos = 0; txpos < tWidth; txpos++) 
		{
          tmprgb[3*txpos]   = trgbsrc[3*(txoff>>8)];
          tmprgb[3*txpos+1] = trgbsrc[3*(txoff>>8)+1];
          tmprgb[3*txpos+2] = trgbsrc[3*(txoff>>8)+2];
          txoff += txinc;
		}
        dit_fs2dither(tmprgb, tWidth, 1);
	    trowsrc = (Pixel*)tmprgb;
#else
#endif
#else
	    trowsrc = (Pixel*)tmprgb;
        for (txpos = 0; txpos < tWidth; txpos++) 
		{
 	      trowsrc[txpos] = RGBVAL(trgbsrc[3*(txoff>>8)], trgbsrc[3*(txoff>>8)+1], trgbsrc[3*(txoff>>8)+2]);
          txoff += txinc;
		}
#endif
        tdest = tdst;
        for (txpos = 0; txpos < tWidth; txpos++) 
		{
          *tdest++= col_GetColor(trowsrc[txpos]);
		}
        tdst += tStride;
        tyoff += tyinc;
	    typos++;
	  }
      if (typos >= tHeight)
	  {
        tjpgState = STATE_ENDING;   
	  }
	  break;

    case STATE_ENDING:
      /* Please the decoder */
	  if (is_tcinfo) 
	  {
        while (tcinfo.output_scanline < tcinfo.output_height)
		{
          (void) jpeg_read_scanlines(&tcinfo, tbuffer, 1);
		}
        (void) jpeg_finish_decompress(&tcinfo);
        jpeg_destroy_decompress(&tcinfo);
        JFCLOSE(tinfile);
	  }
      tjpgState = STATE_IDLE;   
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
