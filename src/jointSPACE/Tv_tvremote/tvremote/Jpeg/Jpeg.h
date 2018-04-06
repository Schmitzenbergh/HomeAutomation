/****************************************************************************
* Purpose : JPEG decoder
* Module  : JPEG
* Author  : J-M Harvengt
* History : 10/08/97 Creation
****************************************************************************/
#ifndef _JPEG
#define _JPEG

#ifndef _LLD
#include "lld.h"
#endif


/***************************************
* Exported macros/typedef
***************************************/
/*
#ifdef THUMBNAIL_SUPPORT
typedef struct
{
  int Width;
  int Height;
  int xoffset;
  int yoffset;
  unsigned char istrans;
  unsigned char trans;
  Pixel * bmap;
  int nbframe;
  void * bmptable[0];
} GBmp;
#endif
*/

/***************************************
* Exported procedures
***************************************/
extern void jpg_Init(void);
extern void jpg_TurnOn(void);
extern void jpg_TurnOff(void);


extern void jpg_PlayThumbSync(char * filename, int format, int width, int height, int stride, void * data);
extern void jpg_PlaySync(char * filename, int format, int width, int height, int stride, void * data);
extern void jpg_GetInfoSync(char * filename, int * width, int * height);

extern void jpg_Play(char * filename, int format, int width, int height, int stride, void * data);
extern void jpg_Stop(void);
extern int  jpg_Playing(void);

extern void jpg_GetInfo(char * filename, char * info, int format, int width, int height, int stride, void * data, int mode);
extern int  jpg_InfoReady(void);
extern void jpg_InfoStop(void);
#ifdef THUMBNAIL_SUPPORT
//extern void jpg_GetThumbnail(GBmp * bmp);
extern void jpg_GetThumbnail(void);
#endif


extern void jpg_OnTimer(void);

#endif
