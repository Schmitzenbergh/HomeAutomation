/****************************************************************************
* Module name : gui
* Description : Low Level Display and 
* Author      : J-M Harvengt
* History     : 14-07-97 Creation
****************************************************************************/
#include "mem.h"
#include "pngdec.h"
#include "gui.h"
#include "std.h"

/****************************************************************************
* Local macros / typedefs
****************************************************************************/
#define MIN(x,y)                   ( (x<y) ? x : y ) 
#define MAX(x,y)                   ( (x>y) ? x : y ) 

#define CACHE_MAX_ENTRY            128
#define CACHE_POOL_SIZE            (0x0100000UL)

typedef struct
{
  GuiBitmap * bmpInCache;
  int next;
  int prev;
} BmpInfo;



/***************************************
* Local variables
***************************************/
static GuiBitmap       *framebufferBitmap=0;
static BmpInfo         bmpInfoTable[CACHE_MAX_ENTRY+1];
static int             maxBmpId;
static int             fifoTop;
static int             fifoBottom;

static char            datapath[256]; 
static char            filename[256]; 
static char            **assetTable;


/***************************************
* Local procedures declaration
***************************************/
static void memInit(void);
static void * memMalloc( int size );
static void memFree( void * ptr );
static int setUpLinkedList( unsigned int base, int size);
static void * bmpMalloc( int bmpId, int size );


/****************************************************************************
* Exported procedures
****************************************************************************/
GuiRetval gui_BitmapCreate (int flags, int width, int height, int pitch, GuiPixelFormat format, void * data, GuiBitmap *bitmap)
{
	if ( (!format) || (!height) || (!width) || (!bitmap) )
		return GUIRET_ERR;

	if (!pitch) 
		pitch = width*GUIPIXELFORMAT2DEPTH(format);

	if (flags & GUIBIF_PREALLOCATED)
	{
		bitmap->pixels = data;
	}
	else
	{
        if ( !(bitmap->pixels = mem_malloc(pitch*height)) )
		  return GUIRET_ERR;
	}

	if ( (flags & GUIBIF_CREATEFROMFILE) && (data) )
	{
		png_PlaySync((char*)data, format, width, height, pitch, bitmap->pixels); 
	}
	bitmap->format  = format;
	bitmap->w       = width;
	bitmap->h       = height;
	bitmap->pitch   = pitch;
	bitmap->clipx   = 0;
	bitmap->clipy   = 0;
	bitmap->clipw   = width;
	bitmap->cliph   = height;
	bitmap->flags   = flags;
	bitmap->dirtyx1 = 65536;
	bitmap->dirtyy1 = 65536;
	bitmap->dirtyx2 = -1;
	bitmap->dirtyy2 = -1;
	if (flags & GUIBIF_FRAMEBUFFER)
    {
		framebufferBitmap = bitmap;
	}

	return GUIRET_OK;
}

GuiRetval gui_BitmapDestroy(GuiBitmap *bitmap)
{
	if (!bitmap)
		return GUIRET_ERR;
	if (bitmap->pixels)
	{
		if (!(bitmap->flags & GUIBIF_PREALLOCATED))
		{
		  mem_free(bitmap->pixels);
		}
	}

	return GUIRET_OK;
}


GuiRetval gui_BitmapSetClip(GuiBitmap *bitmap, GuiRect *rectangle)
{
	if (!bitmap)
		return GUIRET_ERR;

    if (!rectangle)
	{
		bitmap->clipx   = 0;
		bitmap->clipy   = 0;
		bitmap->clipw   = bitmap->w;
		bitmap->cliph   = bitmap->h;
	}
	else
	{
		if ( (rectangle->x < 0 ) ||
			(rectangle->y < 0 ) ||
			((rectangle->x+rectangle->w) > bitmap->w ) ||
			((rectangle->y+rectangle->h) > bitmap->h ) )
			return GUIRET_ERR;

		bitmap->clipx   = rectangle->x;
		bitmap->clipy   = rectangle->y;
		bitmap->clipw   = rectangle->w;
		bitmap->cliph   = rectangle->h;
	}

	return GUIRET_OK;
}


GuiRetval gui_BitmapFillRectangle(GuiBitmap *bitmap, GuiRect *rect, unsigned char r,unsigned char g,unsigned char b,unsigned char a)
{
	unsigned char  *dst;
	unsigned short *dst16;
	unsigned long  *dst32;
	unsigned short color16;
	unsigned long  color32;
	int            i,j;
	GuiRect        rectangle;

	if (!bitmap)
		return GUIRET_ERR;

	rectangle.x = rect->x;
	rectangle.y = rect->y;
	rectangle.w = rect->w;
	rectangle.h = rect->h;
    if (rectangle.x < bitmap->clipx)
	{
		rectangle.w -= (bitmap->clipx - rectangle.x);
		rectangle.x  = bitmap->clipx;
	}
	if ((rectangle.x + rectangle.w) > (bitmap->clipx + bitmap->clipw))
	{
		rectangle.w -= (rectangle.x + rectangle.w - (bitmap->clipx + bitmap->clipw));
	}

    if (rectangle.y < bitmap->clipy)
	{
		rectangle.h -= (bitmap->clipy - rectangle.y);
		rectangle.y  = bitmap->clipy;
	}
	if ((rectangle.y + rectangle.h) > (bitmap->clipy + bitmap->cliph))
	{
		rectangle.h -= (rectangle.y + rectangle.h - (bitmap->clipy + bitmap->cliph));
	}

	if ( (rectangle.w > 0) && (rectangle.h > 0) )
	{
        bitmap->dirtyx1 = MIN(bitmap->dirtyx1,rectangle.x);
        bitmap->dirtyy1 = MIN(bitmap->dirtyy1,rectangle.y);
        bitmap->dirtyx2 = MAX(bitmap->dirtyx2,rectangle.x+rectangle.w);
        bitmap->dirtyy2 = MAX(bitmap->dirtyy2,rectangle.y+rectangle.h);
		if (GUIPIXELFORMATIS16BITS(bitmap->format))
		{
			if (bitmap->format == GUIPFM_ARGB4444)
				color16 =  ARGB4444VAL(r,g,b);
			else
				color16 =  RGB565VAL(r,g,b);
			dst16   =  (unsigned short *)bitmap->pixels;
			dst     =  (unsigned char *)&dst16[rectangle.x];
			dst     += (bitmap->pitch*rectangle.y);
	        for (j=0;j<rectangle.h;j++)
			{
				dst16 = (unsigned short *)dst;
				for (i=0;i<rectangle.w;i++)
				{
					*dst16++=color16;
				}
				dst += bitmap->pitch;
			}
		}
		else
		{  
//printf("clear  %d,%d %d,%d\n", rectangle.x, rectangle.y, rectangle.w, rectangle.h);
			color32 =  ARGB8888VAL(a,r,g,b);
			dst32   =  (unsigned long *)bitmap->pixels;
			dst     =  (unsigned char *)&dst32[rectangle.x];
			dst     += (bitmap->pitch*rectangle.y);
	        for (j=0;j<rectangle.h;j++)
			{
				dst32 = (unsigned long *)dst;
				for (i=0;i<rectangle.w;i++)
				{
					*dst32++=color32;
				}
				dst += bitmap->pitch;
			}
		}
	}

	return GUIRET_OK;
}


GuiRetval gui_BitmapClear(GuiBitmap *bitmap, unsigned char r,unsigned char g,unsigned char b,unsigned char a)
{
    GuiRect rectangle;

	if (!bitmap)
		return GUIRET_ERR;

    rectangle.x = 0;
    rectangle.y = 0;
    rectangle.w = bitmap->w;
    rectangle.h = bitmap->h;

	return (gui_BitmapFillRectangle(bitmap, &rectangle, r, g, b, a) );
}


GuiRetval gui_BitmapBlit(int flags, GuiBitmap *bitmap, GuiBitmap *srcbitmap, GuiRect *rect )
{
	unsigned char  *dst;
	unsigned short *dst16;
	unsigned long  *dst32;
	unsigned char  *src;
	unsigned short *src16;
	unsigned long  *src32;
	int            i,j,x,y,pitch;
	GuiRect        rectangle;

	if ( (!bitmap) || (!srcbitmap) )
		return GUIRET_ERR;

	if (rect)
	{
		rectangle.x = rect->x;
		rectangle.y = rect->y;
	}
	else
	{
		rectangle.x = 0;
		rectangle.y = 0;
	}
	rectangle.w = srcbitmap->w;
	rectangle.h = srcbitmap->h;

	x = rectangle.x;
	y = rectangle.y;

    if (rectangle.x < bitmap->clipx)
	{
		rectangle.w -= (bitmap->clipx - rectangle.x);
		rectangle.x  = bitmap->clipx;
	}
	if ((rectangle.x + rectangle.w) > (bitmap->clipx + bitmap->clipw))
	{
		rectangle.w -= (rectangle.x + rectangle.w - (bitmap->clipx + bitmap->clipw));
	}

    if (rectangle.y < bitmap->clipy)
	{
		rectangle.h -= (bitmap->clipy - rectangle.y);
		rectangle.y  = bitmap->clipy;
	}
	if ((rectangle.y + rectangle.h) > (bitmap->clipy + bitmap->cliph))
	{
		rectangle.h -= (rectangle.y + rectangle.h - (bitmap->clipy + bitmap->cliph));
	}

	if ( (rectangle.w > 0) && (rectangle.h > 0) )
	{
        bitmap->dirtyx1 = MIN(bitmap->dirtyx1,rectangle.x);
        bitmap->dirtyy1 = MIN(bitmap->dirtyy1,rectangle.y);
        bitmap->dirtyx2 = MAX(bitmap->dirtyx2,rectangle.x+rectangle.w);
        bitmap->dirtyy2 = MAX(bitmap->dirtyy2,rectangle.y+rectangle.h);
		if ( (GUIPIXELFORMATIS16BITS(bitmap->format)) && (GUIPIXELFORMATIS16BITS(srcbitmap->format)) )
		{
			src16 =  (unsigned short *)srcbitmap->pixels;
			src   =  (unsigned char *)&src16[rectangle.x-x];
			src   += (srcbitmap->pitch*(rectangle.y-y));
			dst16 =  (unsigned short *)bitmap->pixels;
			dst   =  (unsigned char *)&dst16[rectangle.x];
			if (flags & GUIBLF_FLIPUPDOWN)
			{
			    dst   += (bitmap->pitch*(bitmap->h-1));
				pitch = -bitmap->pitch;
			}
			else
			{
				pitch = bitmap->pitch;
			}
			dst   += (pitch*rectangle.y);
			if (flags & GUIBLF_COLORKEYED)
			{
				for (j=0;j<rectangle.h;j++)
				{
					src16 = (unsigned short *)src;
					dst16 = (unsigned short *)dst;
					for (i=0;i<rectangle.w;i++)
					{
						if (*src16)
						{
							*dst16++=*src16++;
						}
						else
						{
							src16++;
							dst16++;
						}
					}
					src += srcbitmap->pitch;
					dst += pitch;
				}
			}
			else
			{
				for (j=0;j<rectangle.h;j++)
				{
					src16 = (unsigned short *)src;
					dst16 = (unsigned short *)dst;
					for (i=0;i<rectangle.w;i++)
					{
						*dst16++=*src16++;
					}
					src += srcbitmap->pitch;
					dst += pitch;
				}
			}
		}
		else
		{  
			src32 =  (unsigned long *)srcbitmap->pixels;
			src   =  (unsigned char *)&src32[rectangle.x-x];
			src   += (srcbitmap->pitch*(rectangle.y-y));
			dst32 =  (unsigned long *)bitmap->pixels;
			dst   =  (unsigned char *)&dst32[rectangle.x];
			if (flags & GUIBLF_FLIPUPDOWN)
			{
			    dst   += (bitmap->pitch*(bitmap->h-1));
				pitch = -bitmap->pitch;
			}
			else
			{
				pitch = bitmap->pitch;
			}
			dst   += (pitch*rectangle.y);
			if (flags & GUIBLF_COLORKEYED)
			{
				for (j=0;j<rectangle.h;j++)
				{
					src32 = (unsigned long *)src;
					dst32 = (unsigned long *)dst;
					for (i=0;i<rectangle.w;i++)
					{
						if (*src32&0xffffff)
						{
							*dst32++=*src32++;
						}
						else
						{
							src32++;
							dst32++;
						}
					}
					src += srcbitmap->pitch;
					dst += pitch;
				}
			}
			else
			{
				for (j=0;j<rectangle.h;j++)
				{
					src32 = (unsigned long *)src;
					dst32 = (unsigned long *)dst;
					for (i=0;i<rectangle.w;i++)
					{
						*dst32++=*src32++;
					}
					src += srcbitmap->pitch;
					dst += pitch;
				}
			}
		}
	}

	return GUIRET_OK;
}

GuiRetval gui_BitmapGetFramebuffer(GuiBitmap **bitmap)
{
	*bitmap = framebufferBitmap;

	if (framebufferBitmap)
	{
		return GUIRET_OK;
	}
	else
	{
		return GUIRET_ERR;
	}
}

int gui_BitmapFlip(GuiBitmap *bitmap)
{
    int retval = 1;

	if ( (bitmap->dirtyx1 == 65536) &&
         (bitmap->dirtyy1 == 65536) &&
         (bitmap->dirtyx2 == -1) &&
         (bitmap->dirtyy2 == -1) )
	{
		retval = 0;
	}
	else
	{
	    bitmap->dirtyx1 = 65536;
	    bitmap->dirtyy1 = 65536;
	    bitmap->dirtyx2 = -1;
	    bitmap->dirtyy2 = -1;
	}
	bitmap->clipx   = 0;
	bitmap->clipy   = 0;
	bitmap->clipw   = bitmap->w;
	bitmap->cliph   = bitmap->h;

	return retval;
}

void gui_BitmapCacheInit(char *path,  char **asset)
{

	std_strcpy(datapath,path);
	assetTable = asset;

    memInit();
}


GuiBitmap * gui_BitmapGetFromCache(int bmpId, int width, int height, GuiPixelFormat format)
{
    GuiBitmap *bitmap;
    int pitch;
	unsigned char * buffer;
	int bmpid = bmpId+1;

    if ( (!format) || (!height) || (!width) || (bmpId >= maxBmpId) )
	    return (GuiBitmap *)GUIRET_ERR;

	pitch = width*GUIPIXELFORMAT2DEPTH(format);
    if ( (buffer = bmpMalloc(bmpid, sizeof(GuiBitmap) + pitch*height)) )
	{
        bitmap = (GuiBitmap *)buffer;
        bitmap->pixels = buffer + (sizeof(GuiBitmap));
		std_strcpy(filename,datapath);
        std_strcat(filename,assetTable[bmpId]); // Table starts with ID=0, first bitmap!
//printf("opening %s\n",filename);
	    png_PlaySync(filename, format, width, height, pitch, bitmap->pixels);
	    bitmap->format  = format;
	    bitmap->w       = width;
	    bitmap->h       = height;
	    bitmap->pitch   = pitch;
	    bitmap->clipx   = 0;
	    bitmap->clipy   = 0;
	    bitmap->clipw   = width;
	    bitmap->cliph   = height;
	    bitmap->flags   = GUIBIF_CREATEFROMFILE;
	    bitmap->dirtyx1 = 65536;
	    bitmap->dirtyy1 = 65536;
	    bitmap->dirtyx2 = -1;
	    bitmap->dirtyy2 = -1;	  
	}
    else
	{
		bitmap=(GuiBitmap*)bmpInfoTable[bmpid].bmpInCache;

	}
    return(bitmap);
}





/***************************************
* Local memory manager
***************************************/
#define NULL             0

#define SEGMENT_MASK     (CACHE_POOL_SIZE-1)
#define SEGMENT_SIZE     (CACHE_POOL_SIZE)
#define ALIGN_MASK       0x3L
#define ALLOC_EXTRA      4
#define MINFREEBLOCKSIZE 8

#define AlignUpOffset( ptr, mask )      ( (unsigned int) ( (unsigned int)(ptr) & (unsigned int)(mask) ? 1 + (unsigned int)(mask) - ( (unsigned int)(ptr) & (unsigned int)(mask) ) : 0 ) )
#define AlignDownOffset( ptr, mask )    ( (unsigned int)(ptr) & (unsigned int)(mask) )
#define AlignAllocateSize( size, mask ) ( (int)(size) & (int)(mask) ? 1 + (int)(mask) - ( (int)(size) & (int)(mask) ) : 0 )
#define InSameSegment( ptr1, ptr2 )     ( ((unsigned int)(ptr1) & ~SEGMENT_MASK) == ((unsigned int)(ptr2) & ~SEGMENT_MASK) )

typedef struct _FreeBlock
{
  struct _FreeBlock * link;
  unsigned int size; /* including MINFREEBLOCKSIZE bytes for administration */
} FreeBlock;

typedef struct _UsedBlock
{
  unsigned int size; /* including ALLOC_EXTRA bytes administration */
} UsedBlock;



static unsigned int MemStartAddress;
static int MemSize;
static void * BaseAddress;
static FreeBlock * Avail, * Rover;
static int BlockCount; /* The number of free blocks */
static unsigned char MemPool[CACHE_POOL_SIZE];
static int memMallocTotal=0;


/***************************************
* Local procedures
***************************************/
/**************************************/
static void memInit(void)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
    unsigned int EndAddress;
    unsigned int Offset;
 	int i;
   
	MemSize= CACHE_POOL_SIZE;
    MemStartAddress = (unsigned int)MemPool;

	Offset= AlignUpOffset( MemStartAddress, ALIGN_MASK);
    if (Offset > 0) {
        MemStartAddress+= Offset;
        /* OffSet < ALIGN_MASK, so cast is safe */
        MemSize-= (int)Offset;
    }

    /* Does a FreeBlock fit from StartAddress in 'this' segment?    */
    Offset= AlignUpOffset( MemStartAddress, SEGMENT_MASK);
    if (Offset < MINFREEBLOCKSIZE) { /* Offset==0 or it doesn't fit */
        MemStartAddress += Offset;
        /* Offset < SEGMENT_MASK, so cast is safe.*/
        MemSize-= (int)Offset;
    }

    if (MemSize & ALIGN_MASK) /* make the size a multiple of the alignment */
    {
        MemSize &= ~ALIGN_MASK;
    }

    EndAddress= MemStartAddress + MemSize;
    /*  Does a FreeBlock fit in 'last' segment? */
    Offset= AlignDownOffset( EndAddress, SEGMENT_MASK);
    if (Offset < MINFREEBLOCKSIZE) { /* Offset==0 or it doesn't fit */
        /* Offset < SEGMENT_MASK, so cast is safe */
        MemSize-= (int)Offset;
    }

    BaseAddress= (void *)MemStartAddress;
    /* Allocate the Avail at the end    */
    MemSize-= MINFREEBLOCKSIZE;
    Avail= (FreeBlock *) (MemStartAddress + MemSize);
    Avail->size= 0;
    Avail->link= (FreeBlock *)MemStartAddress;
    BlockCount= setUpLinkedList(MemStartAddress, MemSize);
    Rover= Avail;


	i = 0;
	while (assetTable[i])
	{
	  i++; // First entry assumed to be zero!!!!!
	  bmpInfoTable[i].bmpInCache = (GuiBitmap *)0;
	  bmpInfoTable[i].next = 0;
	  bmpInfoTable[i].prev = 0;
	}
	maxBmpId = i;
    fifoTop    = 0;
    fifoBottom = 0;
}

/**************************************/
static int setUpLinkedList( unsigned int base, int size)
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
}   /*  setUpLinkedList */


/**************************************/
static void * memMalloc( int size )
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

    if (size<=0)
    {
        /* Result is NULL or undefined */
        return NULL;
    }
    size+= ALLOC_EXTRA;
    size+= AlignAllocateSize( size, ALIGN_MASK);


    p= Rover;
    n= BlockCount;
    /* Find a large enough free block */
    do
    {
        q= p;
        p= p->link;
        if ( (BaseAddress>(void *)p) || (p>Avail ))
        {
            n=-1; /* Memory corrupt */
        }
        else
        {
            n--;
        }
    } while ( (n>0) && (p->size<(unsigned int)size) );
    if (n<0)
    {
        /*  The following should raise a fatal error */
        /*  Memory corrupt  */
        /* !!!!!!!!!!!!! */
        return NULL;
    }
    if (p->size<(unsigned int)size) { /* Found block is too small */
        /*  The following should raise a fatal error */
        /*  Out of memory */
        /* !!!!!!!!!!!!!! */
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
    memMallocTotal += size;

    return (((char *)r) + ALLOC_EXTRA);
}   /*  mem_malloc   */

/**************************************/
static void memFree( void * ptr )
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
    if (BaseAddress>x)
    {
        return;
    }
    size= ((UsedBlock *)x)->size;


    /*  Check if pointer belongs to the pool    */

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
    if (n<0)
    {
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
    memMallocTotal -= size;
}   /*  mem_free */


/**************************************/
static void * bmpMalloc( int bmpId, int size )
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  int done   = 0;
  void * bmpMallocPt = 0; 
  
  while( !done )
  {
		  if (!bmpInfoTable[bmpId].bmpInCache)
		  {
			/* Not yet in FIFO cache */
            bmpMallocPt = memMalloc(size);
			if (bmpMallocPt)
			{
//printf("CCC not in cache, malloc ok\n");
		      bmpInfoTable[bmpId].bmpInCache = (GuiBitmap *)bmpMallocPt;
              done = 1;
 		      if (fifoBottom)
			  {
                bmpInfoTable[fifoTop].next = bmpId;
		        bmpInfoTable[bmpId].next = 0;
		        bmpInfoTable[bmpId].prev = fifoTop;
                fifoTop = bmpId;
			  }
			  else
			  {
		        fifoBottom = bmpId;
		        fifoTop    = bmpId;
		        bmpInfoTable[bmpId].next = 0;
		        bmpInfoTable[bmpId].prev = 0;
			  }
			}
			else
			{
	          /* Free the oldest element in the cache => we should redefine the bottom here !*/
	          if (fifoBottom)
			  {
printf("CCC not in cache, malloc fails\n");
		        memFree((void*)bmpInfoTable[fifoBottom].bmpInCache);
	            bmpInfoTable[fifoBottom].bmpInCache = (GuiBitmap *)0;
                if (bmpInfoTable[fifoBottom].next)
				{
                  bmpInfoTable[bmpInfoTable[fifoBottom].next].prev = 0;
				  fifoBottom=bmpInfoTable[fifoBottom].next;
				}
		        else
				{
		          fifoTop = 0;
				  fifoBottom=0;
				}
			  }
			  else
			  {
printf("CCC not in cache, malloc fails resetting memory\n");
			    /* This should never happen !(thanks MGR, it happens!!!) */
				memInit();
			  }
			}
		  }
		  else
		  {
//printf("CCC Found in cache\n");
		    /* Already in cache!, move it to top of FIFO (latest used) */
		    if(bmpId != fifoTop)
			{
              if (bmpInfoTable[bmpId].prev)
			  {
				if (bmpInfoTable[bmpId].next) 
				{
					bmpInfoTable[bmpInfoTable[bmpId].prev].next = bmpInfoTable[bmpId].next;
					bmpInfoTable[bmpInfoTable[bmpId].next].prev = bmpInfoTable[bmpId].prev;
				}
			  }
			  else
			  {
				if (bmpInfoTable[bmpId].next) 
				{
					/* next and no prev means it is the bottom !!! */
					bmpInfoTable[bmpInfoTable[bmpId].next].prev = 0;
					fifoBottom = bmpInfoTable[bmpId].next;
				}
			  }
              bmpInfoTable[fifoTop].next = bmpId;
		      bmpInfoTable[bmpId].next = 0;
		      bmpInfoTable[bmpId].prev = fifoTop;
              fifoTop = bmpId;
			}
			done = 1;
		  } 
  }
		
  return(bmpMallocPt);
}







