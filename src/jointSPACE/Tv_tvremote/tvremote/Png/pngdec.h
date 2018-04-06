/****************************************************************************
* Purpose : PNG decoder
* Module  : PNGDEC
* Author  : J-M Harvengt
* History : 10/08/97 Creation
****************************************************************************/
#ifndef _PNG
#define _PNG

/***************************************
* Exported procedures
***************************************/
extern void png_PlaySync(char * filename, int format, int width, int height, int stride, void * data);

#endif
