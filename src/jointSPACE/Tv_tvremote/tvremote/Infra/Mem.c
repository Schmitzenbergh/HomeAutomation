/****************************************************************************
* Module name : MEM
* Description : Memory manager
* Author      : J-M Harvengt
* History     : 14-07-97 Creation
****************************************************************************/
//#define DEBUG_MEM 1 
#include "mem.h"

#ifdef DEBUG_MEM
#include <stdio.h>
#define OVERFLOW_THRESHOLD 1500000
#endif

/****************************************************************************
* Local macros / typedefs
****************************************************************************/
#ifndef ASSERT
#define ASSERT(x)
#endif
#ifndef NULL
#define NULL		0
#endif

#if ( (GP32) || (GBA) || (NDS) )
//#ifdef GP32
#define POOL_SIZE       0x0080000UL
#define SEGMENT_MASK    0x007FFFFUL
#define SEGMENT_SIZE    0x0080000UL
#else
  #ifdef DASH
#define POOL_SIZE       0x0080000UL
#define SEGMENT_MASK    0x007FFFFUL
#define SEGMENT_SIZE    0x0080000UL
  #else
   #ifdef NGC
//#define POOL_SIZE       0x0100000UL
//#define SEGMENT_MASK    0x00FFFFFUL
//#define SEGMENT_SIZE    0x0100000UL
#define POOL_SIZE       0x0080000UL
#define SEGMENT_MASK    0x007FFFFUL
#define SEGMENT_SIZE    0x0080000UL
   #else
#define POOL_SIZE       0x0400000UL
#define SEGMENT_MASK    0x03FFFFFUL
#define SEGMENT_SIZE    0x0400000UL
   #endif
  #endif
#endif

/*  All pointers (returned) will be aligned on 4 bytes.*/
/*  last 2 bits must be zero.*/
#define ALIGN_MASK 0x3L

/*  For storage of UsedBlock info (in bytes).*/
/*  Must be at least sizeof(UsedBlock) and aligned */
#define ALLOC_EXTRA 4

/*  Do not leave gaps smaller than MINFREEBLOCKSIZE (in bytes) */
/*  Must be at least sizeof(FreeBlock) and aligned */
#define MINFREEBLOCKSIZE    8


#define AlignUpOffset( ptr, mask ) ( (unsigned int) ( (unsigned int)(ptr) & (unsigned int)(mask) ? 1 + (unsigned int)(mask) - ( (unsigned int)(ptr) & (unsigned int)(mask) ) : 0 ) )

#define AlignDownOffset( ptr, mask ) ( (unsigned int)(ptr) & (unsigned int)(mask) )

#define AlignAllocateSize( size, mask ) ( (int)(size) & (int)(mask) ? 1 + (int)(mask) - ( (int)(size) & (int)(mask) ) : 0 )

#define InSameSegment( ptr1, ptr2 ) ( ((unsigned int)(ptr1) & ~SEGMENT_MASK) == ((unsigned int)(ptr2) & ~SEGMENT_MASK) )

typedef struct _FreeBlock
{
    struct _FreeBlock * link;
    unsigned int size; /* including MINFREEBLOCKSIZE bytes for administration */
} FreeBlock;

typedef struct _UsedBlock
{
    unsigned int size; /* including ALLOC_EXTRA bytes administration */
} UsedBlock;


/****************************************************************************
* Local procedures declaration
****************************************************************************/
static int SetUpLinkedList( unsigned int base, int size);

/****************************************************************************
* Static variables
****************************************************************************/
static void * BaseAddress;
static FreeBlock * Avail, * Rover;
static int BlockCount; /* The number of free blocks */
#ifdef VIPER    
static unsigned char * MemPool;
#else
static unsigned char MemPool[POOL_SIZE];
#endif

#ifdef DEBUG_MEM
static FILE * deb;
#endif
static int memMallocTotal;


/****************************************************************************
* Local procedures
****************************************************************************/
/****************************************************************************
* Exported procedures
****************************************************************************/
/***************************************
* Purpose : Initialization.
***************************************/
void mem_Init(void)
{
    unsigned int StartAddress;
    unsigned int EndAddress;
    unsigned int Offset;
    int Size;
#ifdef DEBUG_MEM
    deb = fopen("deb_mem","w+b");
#endif
    
#ifdef VIPER    
    MemPool = malloc(POOL_SIZE);
#endif
	Size= POOL_SIZE;
    ASSERT( Size > 0 );
    StartAddress = (unsigned int)MemPool;
    memMallocTotal=0;

    Offset= AlignUpOffset( StartAddress, ALIGN_MASK);
    if (Offset > 0) {
        StartAddress+= Offset;
        /* OffSet < ALIGN_MASK, so cast is safe */
        Size-= (int)Offset;
    }

#ifdef DEBUG_MEM
    fprintf(deb,"Heap at %x size %x\n", StartAddress, Size);
#endif

    /* Does a FreeBlock fit from StartAddress in 'this' segment?    */
    Offset= AlignUpOffset( StartAddress, SEGMENT_MASK);
    if (Offset < MINFREEBLOCKSIZE) { /* Offset==0 or it doesn't fit */
        StartAddress += Offset;
        /* Offset < SEGMENT_MASK, so cast is safe.*/
        Size-= (int)Offset;
    }

    ASSERT( Size > 0 );
    if (Size & ALIGN_MASK) /* make the size a multiple of the alignment */
    {
        Size &= ~ALIGN_MASK;
    }

    EndAddress= StartAddress + Size;
    /*  Does a FreeBlock fit in 'last' segment? */
    Offset= AlignDownOffset( EndAddress, SEGMENT_MASK);
    if (Offset < MINFREEBLOCKSIZE) { /* Offset==0 or it doesn't fit */
        /* Offset < SEGMENT_MASK, so cast is safe */
        Size-= (int)Offset;
    }

    /*  Do we have any memory to allocate?  */
    ASSERT( Size > 2 * MINFREEBLOCKSIZE);

    BaseAddress= (void *)StartAddress;
    /* Allocate the Avail at the end    */
    Size-= MINFREEBLOCKSIZE;
    Avail= (FreeBlock *) (StartAddress + Size);
    Avail->size= 0;
    Avail->link= (FreeBlock *)StartAddress;
    BlockCount= SetUpLinkedList(StartAddress, Size);
    Rover= Avail;
}

void mem_TurnOn(void)
{
}

void mem_TurnOff(void)
{
#ifdef VIPER    
  free(MemPool);
#endif
#ifdef DEBUG_MEM
  fclose(deb);
#endif
}


/***************************************
* Purpose : Others
***************************************/
/**************************************/
void * mem_malloc( int size )
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
    FreeBlock * p;
    FreeBlock * q;
    UsedBlock * r;
    unsigned int       k;
    int         n;

    ASSERT( BlockCount > 0 );
    ASSERT( size >= 0 ); /* Result is defined? */
    if (size<=0)
    {
        /* Result is NULL or undefined */
        return NULL;
    }
    size+= ALLOC_EXTRA;
    size+= AlignAllocateSize( size, ALIGN_MASK);

    memMallocTotal += size;
#ifdef DEBUG_MEM
    fprintf(deb,"malloc %u/%u\n", size, memMallocTotal);
	if (memMallocTotal >= OVERFLOW_THRESHOLD)
	{
      fprintf(deb,"-----MEM OVERFLOW-----\n");
	}
#endif

    p= Rover;
    n= BlockCount;
    /* Find a large enough free block */
    do
    {
        q= p;
        p= p->link;
        ASSERT( BaseAddress <= (void *)p );
        ASSERT( p <= Avail );
        if ( (BaseAddress>(void *)p) || (p>Avail ))
        {
            n=-1; /* Memory corrupt */
        }
        else
        {
            n--;
        }
    } while ( (n>0) && (p->size<(unsigned int)size) );
    ASSERT( n>=0 );
    if (n<0)
    {
        /*  The following should raise a fatal error */
        /*  Memory corrupt  */
        /* !!!!!!!!!!!!! */
#ifdef DEBUG_MEM
        fprintf(deb,"Memory corrupt\n");
#endif
        return NULL;
    }
    if (p->size<(unsigned int)size) { /* Found block is too small */
        /*  The following should raise a fatal error */
        /*  Out of memory */
        /* !!!!!!!!!!!!!! */
#ifdef DEBUG_MEM
        fprintf(deb,"Out of memory\n");
#endif
        return NULL;
    }
    /*  p->size>=size   */
    k= p->size - size; /* Amount of space left */
    if (k<MINFREEBLOCKSIZE)
    {
        /* This free block becomes a used block */
        q->link= p->link;
        Rover= q;
        r= (UsedBlock*)p;
        r->size= p->size;
        BlockCount--;
    }
    else
    {
        /* Split this free block into a free block and a used block */
        p->size= k;
        Rover= p;
        r=(UsedBlock *)( ((char *)p) + k );
        r->size= size;
    }

    return (((char *)r) + ALLOC_EXTRA);
}   /*  mem_malloc   */

/**************************************/
void mem_free( void * ptr )
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
    int         n;
    int         m;
    unsigned int       size;
    FreeBlock * p;
    FreeBlock * q;
    FreeBlock * f;
    void *      x;

    if (NULL==ptr)
    {
        return;
    }
    x= (char *)ptr - ALLOC_EXTRA;
    /*  Check if pointer belongs to the pool    */
    ASSERT( BaseAddress <= x );
    if (BaseAddress>x)
    {
        return;
    }
    size= ((UsedBlock *)x)->size;

    memMallocTotal -= size;
#ifdef DEBUG_MEM
    fprintf(deb,"free %u/%u\n", size, memMallocTotal);
#endif

    /*  Check if pointer belongs to the pool    */
    ASSERT( (void *)((char *)x+size)<=(void *)Avail );

    if ( (void *)((char *)x+size)>(void *)Avail )
    {
        return;
    }
    p= Avail;
    n= BlockCount;
    do
    {
        q= p;
        p= p->link;
        /*  Memory corrupt? */
        ASSERT( BaseAddress <= (void *)p );
        ASSERT( p <= Avail );
        if ( (BaseAddress>(void *)p) || (p>Avail ))
        {
            n=-1;
        }
        else
        {
            n--;
        }
    } while ( ((void *)p <= (void *)x) && (n>=0) );
    /* Memory corrupt? */
    ASSERT( n>=0 );
    if (n<0)
    {
#ifdef DEBUG_MEM
        fprintf(deb,"Memory corrupt at free\n");
#endif
        return;
    }
    /* x<p and ( q<=x or q=Avail) */
    f= (FreeBlock *) x;
    f->size = size;
    m=1;
    if (InSameSegment(f, p) && ( (char *)p==(char *)f+ f->size ) && (p!=Avail))
    {
        /* merge p into f */
        f->size += p->size;
        f->link= p->link;
        if (Rover==p)
        {
            Rover=f;
        }
        m--;
    }
    else
    {
        f->link= p;
    }
    if (InSameSegment(q, f) && ( (char *)f==(char *)q+ q->size ) && (q!=Avail))
    {
        /* merge f into q */
        q->size+= f->size;
        q->link= f->link;
        if (Rover==f)
        {
            Rover= q;
        }
        m--;
    }
    else
    {
        q->link= f;
    }
    BlockCount+= m;
}   /*  mem_free */

/**************************************/
void * mem_realloc( void * ptr, int newsize )
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
    UsedBlock * p;
    int         size;
    void *      newptr;

    ASSERT( newsize >= 0 );
    if (NULL==ptr)
    {
        return mem_malloc(newsize);
    }
    if (newsize<=0)
    {
        mem_free (ptr);
        return NULL;
    }
    p= (UsedBlock *)((char *)ptr-ALLOC_EXTRA);

    /* Check if pointer belongs to the pool */
    ASSERT( BaseAddress <= (void *) p );
    ASSERT( (void *)((char *)p + p->size)<=(void *)Avail );

    size= p->size-ALLOC_EXTRA;
    if ( size>=newsize)
    {
        /* Perhaps use the extra room? */
        return ptr;
    }
    /* Copy the contents of ptr */
    newptr= mem_malloc( newsize ); /* mem_malloc handles the fatal error */
    if (newptr) /* no fatal error? */
    {
        mem_memcpy( newptr, ptr, size );
        mem_free( ptr ); /* implementation choice: only free when no fatal error */
    }
    return newptr;
}   /*  mem_realloc */

/**************************************/
void mem_memset( void * ptr, int data, int size )
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  int i;
  unsigned char * mptr = ptr;

  for (i=0;i<size;i++)
    *mptr++ = data;
}

/**************************************/
void mem_memcpy( void * dst, void * src, int size )
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  int i;
  unsigned char * msrc = src;
  unsigned char * mdst = dst;

  if (src >=dst)
  {
    for (i=0;i<size;i++)
      *mdst++ = *msrc++;
  }
  else
  {
     msrc += size;
     mdst += size;
     for (i=0;i<size;i++)
      *--mdst = *--msrc;
  }
}


/***************************************
* Local procedures
***************************************/
/**************************************/
static int SetUpLinkedList( unsigned int base, int size)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
/* During initialization, sets up a linked list of free blocks in the heap.
   There is one 64K free block per segment. Returns number of free blocks. */
{
    FreeBlock * p;
    unsigned int       offset;
    int         count=0;
    do
    {
        offset= AlignUpOffset( base, SEGMENT_MASK);
        if (0==offset)
        {
            offset= SEGMENT_SIZE;
        }
        /* offset <= SEGMENT_SIZE, so cast is safe  */
        if ((int)offset > size)
        {
            offset= size;
        }
        p= (FreeBlock *) base;
        p->size= offset;
        p->link= (FreeBlock *)(base+offset);
/*        FillBlockFree( p ); */
        base+= offset;
        size-= offset;
        count++;
    } while (size>0);
    /*  One extra for the empty block at the end of the pool    */
    return (count+1);
}   /*  SetUpLinkedList */












