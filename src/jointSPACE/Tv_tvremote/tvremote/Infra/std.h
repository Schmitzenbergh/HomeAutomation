/****************************************************************************
* Module name : Std
* Description : Standart IO.
* Author      : J-M Harvengt
* History     : 14-07-97 Creation
****************************************************************************/
#ifndef _STD
#define _STD

/***************************************
* Global variables
***************************************/

/***************************************
* Exported procedures
***************************************/
extern void std_Init( void );
extern void std_TurnOn(void);
extern void std_TurnOff(void);

extern int  std_strcmp( char * str1, char * str2);
extern int  std_strncmp( char * str1, char * str2, int n);
extern int  std_stricmp( char * str1, char * str2);
extern int  std_strincmp( char * str1, char * str2, int n);
extern int  std_strtailcmp( char * str1, char * str2);
extern int  std_strlen( char * str );
extern int  std_strnlen( char *s, int size );
extern int  std_strcpy( char * str, char * str2 );
extern char * std_strncpy(char * dst, char * src, int n);
extern int  std_strcpycase( char * str, char * str2 );
extern int  std_strcpytodot( char * str, char * str2 );
extern int  std_strcpyfromslashtodot( char * str, char * str2 );
extern char * std_strtail(char *p, int ch);
extern char * std_strchr(char *p, int ch);
extern char * std_strrchr(char *p, int ch);
extern char * std_strstrip(char *p, int ch);
extern void   std_stripspace( char str );
extern char * std_strcat(char * s, char * append);
extern char * std_longToHMS(unsigned long n);
extern char * std_longToHex(unsigned long n);
extern char * std_shortToHex(unsigned short n);
extern char * std_charToHex(unsigned char n);
extern char * std_charToDec(unsigned char n);
extern char * std_shortToDec(unsigned short n);
extern char * std_longToDec(unsigned long n);
extern char * std_longToPercent(unsigned long num, unsigned long denom);

#endif

