/****************************************************************************
* Purpose : JPEG decoder
* Module  : JPEG
* Author  : J-M Harvengt
* History : 10/08/97 Creation
****************************************************************************/
#ifndef _JPEG
#define _JPEG


/***************************************
* Exported macros/typedef
***************************************/


/***************************************
* Exported procedures
***************************************/
extern void jpg_Init(void);
extern void jpg_TurnOn(void);
extern void jpg_TurnOff(void);


extern void jpg_PlayThumbSync(char * filename, int format, int width, int height, int stride, void * data, int colorkey);
extern void jpg_PlaySync(char * filename, int format, int width, int height, int stride, void * data, int colorkey);
extern void jpg_Play(char * filename, int format, int width, int height, int stride, void * data, int colorkey);
extern void jpg_Stop(void);
extern int  jpg_Playing(void);

extern void jpg_OnTimer(void);

#endif
