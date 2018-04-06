#ifndef _SYSTYPES
#define _SYSTYPES
/****************************************************************************
* Module name : SYSTYPES
* Description : System types definitions
* Author      : J-M Harvengt
* History     : 14-07-97 Creation
****************************************************************************/
#define ROM
#define IRAM
#ifndef NEAR
#define NEAR
#endif
#ifndef ASSERT
#define ASSERT(x)
#endif
#ifndef NULL
#define NULL 0
#endif

#define FARCODE
#define XDRAM
#define IDRAM
#define Byte    Nat8    /** koala type Byte **/
#define EXT_ROM ROM     /** koala type EXT_ROM **/
#define idram   IRAM    /** koala type idram **/

/*
#define Byte char
#define Void void
#define Nat int
#define Nat32 int
*/
#define IN_ROM FARCODE
#define PUT_IN_ROM FARCODE

#ifndef Bool
typedef unsigned char Bool;
#endif
typedef void Void;
typedef int Any;
typedef short Int15;
typedef short Font;
typedef short Language;

typedef unsigned char  byte;
typedef unsigned short word;
typedef unsigned long  dword;
typedef signed char    offset;
#ifndef VIPER
typedef unsigned long  ULONG;
#endif
#ifndef Nat8
typedef unsigned char  Nat8;
#endif
#ifndef Nat16
typedef unsigned short Nat16;
#endif
#ifndef Nat32
typedef unsigned long  Nat32;
#endif

#ifndef INT8
#define INT8 signed char
#endif
#ifndef INT16
#define INT16 signed short
#endif
#ifndef INT32
#define INT32 signed int
#endif
#ifndef UINT8
#define UINT8 unsigned char
#endif
#ifndef UINT16
#define UINT16 unsigned short
#endif
#ifndef UINT32
#define UINT32 unsigned int
#endif
/*
typedef signed char INT8;
typedef signed short INT16;
typedef signed int INT32;
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
*/

#ifndef Int8 
typedef char Int8;
#endif
#ifndef Int16
typedef short Int16;
#endif
#ifndef Int32
typedef long Int32;
#endif
#ifndef UInt8
typedef unsigned char UInt8;
#endif
#ifndef UInt16
typedef unsigned short UInt16;
#endif
#ifndef UInt32
typedef unsigned int UInt32;
#endif

#ifndef _arch_dreamcast
#ifndef PSP
typedef char int8;
typedef short int16;
typedef long int32;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
#endif
#endif

typedef char * String;
typedef void * Address;

#ifdef WIN32
#define SLASH "\\"
#define SLASHCHAR '\\'
#else
#ifdef GP32
#define SLASH "\\"
#define SLASHCHAR '\\'
#else
#ifdef _WIN32_WCE
#define SLASH "\\"
#define SLASHCHAR '\\'
#else
#define SLASH "/"
#define SLASHCHAR '/'
#endif
#endif
#endif

typedef union 
{
#ifdef LSB_FIRST
	struct { UINT8 l,h,h2,h3; } b;
	struct { UINT16 l,h; } w;
#else
	struct { UINT8 h3,h2,h,l; } b;
	struct { UINT16 h,l; } w;
#endif
	UINT32 d;
}	PAIR;

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#define MIN(x,y) ( (x<y) ? x : y ) 
#define MAX(x,y) ( (x>y) ? x : y ) 

//#define ASSERT(x)  

#endif
