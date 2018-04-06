/****************************************************************************
* Module name : Sinus
* Description : Sinus/Cosinus routines
* Author      : J-M Harvengt
* History     : 14-07-97 Creation
****************************************************************************/
#ifndef _SINUS
#define _SINUS

/****************************************************************************
* Typedef/macros
****************************************************************************/
extern signed short sinus[];
extern signed short sinux[];
#define cosinus(x,y) (signed short)((long)(sinus[(y)+64]*(x)*2)>>16)
#define sinus(x,y) (signed short)((long)(sinus[(y)]*(x)*2)>>16)
#define cosinux(x,y) (signed short)((long)(sinux[(y)+512]*(x)*2)>>16)
#define sinux(x,y) (signed short)((long)(sinux[(y)]*(x)*2)>>16)

/****************************************************************************
* Exported procedures
****************************************************************************/
extern void sin_Init( void );
extern void sin_TurnOn( void );
extern void sin_TurnOff( void );

#endif
