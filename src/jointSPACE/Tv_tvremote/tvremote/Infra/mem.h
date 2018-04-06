/****************************************************************************
* Module name : MEM
* Description : Memory manager
* Author      : J-M Harvengt
* History     : 14-07-97 Creation
****************************************************************************/
#ifndef _MEM
#define _MEM

/****************************************************************************
* Typedef/macros
****************************************************************************/

/*
#define malloc mem_malloc
#define realloc mem_realloc
#define free mem_free
#define memset mem_memset
#define memcpy mem_memcpy
*/

/****************************************************************************
* Exported procedures
****************************************************************************/
extern void mem_Init(void);
extern void mem_TurnOn(void);
extern void mem_TurnOff(void);

extern void * mem_malloc( int size );
extern void * mem_realloc( void * ptr, int newsize );
extern void mem_free( void * ptr );
extern void mem_memset( void * ptr, int data, int size );
extern void mem_memcpy( void * dst, void * src, int size );

#endif



