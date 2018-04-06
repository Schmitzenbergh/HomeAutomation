/****************************************************************************
* Module name : console
* Description : Standart console output
* Author      : J-M Harvengt
* History     : 14-07-97 Creation
****************************************************************************/
#ifndef _CON
#define _CON

/***************************************
* Exported macros/typedef
***************************************/
#define STD_DEFWIDTH                 20
#define STD_DEFHEIGHT                10
#define STD_MAXWIDTH                 80
#define STD_MAXHEIGHT                100

#define CON_MAXWIDTH                 56 
#define CON_MAXHEIGHT                28
#define CON_STRIDE                   66 

/***************************************
* Exported procedures
***************************************/
extern void con_Init( void );
extern void con_TurnOn(void);
extern void con_TurnOff(void);

extern void con_SetPlane ( int plane );
extern int  con_GetPlaneWidth ( int plane );
extern void con_ClearScreen ( int plane );
extern void con_Clear ( int row, int col, int height, int width );
extern int  con_GetPlaneHeight ( int plane );
extern int  con_GetCurrentRow ( void );
extern void con_Fill( int row, int col, int height, int width, int chr );
extern void con_SetFg ( int color );
extern void con_SetBg ( int color );
extern int  con_GetCurrentBg( void );
extern int  con_GetCurrentColumn( void );
extern int  con_GetCurrentFg( void );
extern int  con_GetCurrentPlane( void );
extern void con_Goto( int row, int col );
extern void con_Print( char *txt );

extern int  std_vprintf(char * buf, char *fmt, ...);
extern int  std_printf(char *fmt, ...);
extern void std_Display( void);
extern void std_InitDisplay( int aX, int aY,
					         int aWidth, int aHeight);
extern void std_Clear( void );
extern int  std_GetWidth(void);
extern int  std_GetHeight(void);
extern char * std_GetBuffer(void);
extern int  std_MaxRow(void);
extern int  std_GetRow(void);
extern void std_RowUp(void);
extern void std_RowDown(void);

#endif
