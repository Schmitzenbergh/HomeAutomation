/****************************************************************************
* Module name : MYSTDIO
* Description : Standard File system routines.
* Author      : J-M Harvengt
* History     : 14-07-97 Creation
****************************************************************************/

#include <stdio.h>
#ifdef WIN32
#ifdef _XBOX
#include <xtl.h>
#else
#include <windows.h>
#endif
#include <sys/stat.h>
#include "systypes.h"
#endif
#ifdef _WIN32_WCE
#include <winbase.h>
#include "systypes.h"
#endif
#ifdef _trimedia
//#include <IODrivers.h>
#include <dirent.h>
#include <sys/stat.h>
#include <psos.h>
#include <time.h>
#include <pHILEplus.h>
#include "systypes.h"
#endif
#ifdef _arch_dreamcast
#include <kos.h>
#include <sys/stat.h>
#include "systypes.h"
#endif
#if ( (VIPER) && (!LINUX) )
/* USB IO access */
#include <ioLib.h>
#include <dirent.h>
#include <sys/stat.h>
#include "systypes.h"
#endif
#if (LINUX)
#include <dirent.h>
#include <sys/stat.h>
#include "systypes.h"
#endif
#ifdef NGC
#include "fat.h"
#include <dirent.h>
#include "systypes.h"
#endif
#if ( (NDS) && (!LINUX) )
#include "fat.h"
#include <dirent.h>
#include "systypes.h"
#endif
#ifdef PSP
#include <pspkernel.h>
#include "systypes.h"
#endif

#include "mystdio.h"
#include "mem.h"


#define MYMALLOC mem_malloc
#define MYFREE   mem_free


/****************************************************************************
* Local macros / typedefs
****************************************************************************/

/****************************************************************************
* Local procedures declaration
****************************************************************************/
static int  lparsepath(char * path, char * volName, char * pathName);
static int  lfrecogn(char * filename);
static unsigned int lfcreate(char * filename, char * mode);
static unsigned int lfopen(char * filename, char * mode);
static int  lfclose(unsigned int stream);
static int  lfread(void * data, int sizeelem , int nelem, unsigned int stream);
static int  lfwrite(void * data, int sizeelem , int nelem, unsigned int stream);
static long lftell(unsigned int stream);
static int  lfseek(unsigned int stream, long offset, int mode);
static unsigned int lfrm(char * filename);
static unsigned int lfstat(char * filename);
static unsigned int lfcreatedir(char * dirname);
static unsigned int lfopendir(char * dirname);
static unsigned int lfreaddir(unsigned int dir, char * filenamept);
static unsigned int lfclosedir(unsigned int dir);
static unsigned int lfrmdir(char * dirname);
static unsigned int lfsize(char * filename);
static int          lfmetadata(char * filename, char * typeorcodecinfo, char * dateorduration, char * moreinfo);

static int  mparsepath(char * path, char * volName, char * pathName);
static int  mfrecogn(char * filename);
static unsigned int mfopen(char * filename, char * mode);
static int  mfclose(unsigned int stream);
static int  mfread(void * data, int sizeelem , int nelem, unsigned int stream);
static int  mfwrite(void * data, int sizeelem , int nelem, unsigned int stream);
static long mftell(unsigned int stream);
static int  mfseek(unsigned int stream, long offset, int mode);
static unsigned int mfsize(char * filename);

static int  fparsepath(char * path, char * volName, char * pathName);
static int  ffrecogn(char * filename);
static unsigned int ffopen(char * filename, char * mode);
static int  ffclose(unsigned int stream);
static int  ffread(void * data, int sizeelem , int nelem, unsigned int stream);
static int  ffwrite(void * data, int sizeelem , int nelem, unsigned int stream);
static long fftell(unsigned int stream);
static int  ffseek(unsigned int stream, long offset, int mode);
static unsigned int ffstat(char * filename);
static unsigned int ffopendir(char * dirname);
static unsigned int ffreaddir(unsigned int dir, char * filenamept);
static unsigned int ffclosedir(unsigned int dir);
static unsigned int ffsize(char * filename);
static int          ffmetadata(char * filename, char * typeorcodecinfo, char * dateorduration, char * moreinfo);


static int fsHandlerAdd(fs_handler * hnd);
static fs_handler * fsGetHandler( char *fn); 

/****************************************************************************
* Static variables
****************************************************************************/
/* Default stdio filesystem */
static fs_handler stdio_fs = 
{
	0,          /* Caching */
	NULL,		/* Next */
	
	lfrecogn,
	lfcreate,
	lfopen,
	lfclose,
	lfread,
	lfwrite,
	lftell,
	lfseek,
	lfrm,
	lfstat,
	lfcreatedir,
	lfopendir,
	lfreaddir,
	lfclosedir,
	lfrmdir,
	lfsize,
	lfmetadata
};

/* Memory filesystem */
static fs_handler mem_fs = 
{
	0,          /* Caching */
	&stdio_fs,	/* Next */
	
	mfrecogn,
	NULL,       /* Fcreate */
	mfopen,
	mfclose,
	mfread,
	NULL,       /* Fwrite */
	mftell,
	mfseek,
	NULL,       /* Frm */  
	NULL,
	NULL,       /* Fcreatedir */
	NULL,
	NULL,
	NULL,
	NULL,		/* Frmdir */
	mfsize,
	NULL
};

/* Flash filesystem */
static fs_handler flash_fs = 
{
	0,          /* Caching */
	&mem_fs,	/* Next */
	
	ffrecogn,
	NULL,       /* Fcreate */
	ffopen,
	ffclose,
	ffread,
	NULL,       /* Fwrite */
	fftell,
	ffseek,
	NULL,       /* Frm */  
	ffstat,
	NULL,       /* Createdir */
	ffopendir,
	ffreaddir,
	ffclosedir,
	NULL,		/* Frmdir */
	ffsize,
	ffmetadata
};

static fs_handler * fs_handlers=&flash_fs;

/****************************************************************************
* Exported procedures
****************************************************************************/

/***************************************
* Purpose : Initialization.
***************************************/

/***************************************
* Purpose : Global Filesystem
***************************************/
unsigned int fsm_myfcreate(char * filename, char * mode)
{
  fs_handler	* cur;
  unsigned int h;
  f_handle * hnd;

  /* Look for a filesystem handler for such prefix */
  cur = fsGetHandler(filename);
  if (cur == NULL) return 0;

  /* Invoke the handler */
  if (cur->fcreate == NULL) return 0;
  h = cur->fcreate(filename, mode);
  if (h == 0) return 0;
  /* Wrap it up in a structure */
  hnd = (f_handle *)MYMALLOC(sizeof(f_handle));
  if (hnd == NULL) 
  {
	cur->fclose(h);
	return 0;
  }
  hnd->handler = cur;
  hnd->hnd = h;
  hnd->filePosition = 0;
  return (unsigned int)hnd;
}

unsigned int fsm_myfopen(char * filename, char * mode)
{
  fs_handler	* cur;
  unsigned int h;
  f_handle * hnd;

  /* Look for a filesystem handler for such prefix */
  cur = fsGetHandler(filename);
  if (cur == NULL) return 0;

  /* Invoke the handler */
  if (cur->fopen == NULL) return 0;
  h = cur->fopen(filename, mode);
  if (h == 0) return 0;
  /* Wrap it up in a structure */
  hnd = (f_handle *)MYMALLOC(sizeof(f_handle));
  if (hnd == NULL) 
  {
	cur->fclose(h);
	return 0;
  }
  hnd->handler = cur;
  hnd->hnd = h;
  hnd->filePosition = 0;
  return (unsigned int)hnd;
}

int fsm_myfclose(unsigned int stream)
{
  int        retval;
  f_handle   * hnd;
  fs_handler * cur;

  hnd=(f_handle*)stream;
  cur = hnd->handler;
  retval = cur->fclose(hnd->hnd);
  MYFREE(hnd);
  return(retval);
}

int fsm_myfread(void * data, int sizeelem , int nelem, unsigned int stream)
{
  int retval;
  f_handle   * hnd;
  fs_handler * cur;

  hnd=(f_handle*)stream;
  cur = hnd->handler;
  retval = cur->fread(data, sizeelem, nelem, hnd->hnd);
  hnd->filePosition += retval;
  return (retval);
}

char fsm_myfgetc(unsigned int stream)
{
  char cc;
  int k;

  k=fsm_myfread(&cc, 1, 1, stream);
  if (k!=1) cc=-1;
  return(cc);
}

char * fsm_myfgets(char * s, int n, unsigned int stream)
{
	register signed char c;
	register char *cs;

	cs = s;
	while (--n>0 && (c = (signed char)fsm_myfgetc(stream))>=0) {
		*cs++ = c;
		if  (c=='\n')
			break;
	}
	if (c<0 && cs==s)
	{
//		printf("EOF\n");
		return(NULL);
	}
//	else
//	{
//		printf("NO EOF\n");
//	}
	*cs++ = '\0';
	return(s);
}


int fsm_myfwrite(void * data, int sizeelem , int nelem, unsigned int stream)
{
  int retval;
  f_handle   * hnd;
  fs_handler * cur;

  hnd=(f_handle*)stream;
  cur = hnd->handler;
  retval = cur->fwrite(data, sizeelem, nelem, hnd->hnd);
  hnd->filePosition += retval;
  return (retval);

//  return (-1); // will fail!!!
}

long fsm_myftell(unsigned int stream)
{
  f_handle   * hnd;
  fs_handler * cur;

  hnd=(f_handle*)stream;
  cur = hnd->handler;
//  return(hnd->filePosition);
  return(cur->ftell(hnd->hnd));
}

#ifdef no_fseek
#define SCRATCH_BUFFER_SIZE  16384
static char scratchBuffer[SCRATCH_BUFFER_SIZE];
int fsm_myfseek(unsigned int stream, long offset, int mode)
{
  int retval;
  f_handle   * hnd;
  fs_handler * cur;
  int total=offset;

  hnd=(f_handle*)stream;
  cur = hnd->handler;

  switch(mode)
  {
    case SEEK_SET:
	 /* Should never happen */
     hnd->filePosition = offset;
     retval=-1;
     break;
    case SEEK_CUR:
     while(total>SCRATCH_BUFFER_SIZE)  
	 {
	  cur->fread(scratchBuffer, 1, SCRATCH_BUFFER_SIZE, hnd->hnd);
	  total -= SCRATCH_BUFFER_SIZE;
	 }
     retval = cur->fread(scratchBuffer, 1, total, hnd->hnd);
     hnd->filePosition += offset;
     break;
    case SEEK_END:
	 /* Should never happen */
     hnd->filePosition = 0; //-= offset;
     retval=-1;
     break;
    default:
     retval=-1;
     break;
  }
  return(retval);
}
#else
int fsm_myfseek(unsigned int stream, long offset, int mode)
{
  int retval;
  f_handle   * hnd;
  fs_handler * cur;

  hnd=(f_handle*)stream;
  cur = hnd->handler;
  switch(mode)
  {
    case SEEK_SET:
     hnd->filePosition = offset;
     retval = cur->fseek(hnd->hnd, offset, mode);
//     retval=-1;
     break;
    case SEEK_CUR:
     hnd->filePosition += offset;
     retval = cur->fseek(hnd->hnd, offset, mode);
     break;
    case SEEK_END:
     retval = cur->fseek(hnd->hnd, offset, mode);
//     hnd->filePosition = 0; //-= offset;
//     retval=-1;
     break;
    default:
     retval=-1;
     break;
  }
  return(retval);
}
#endif

unsigned int fsm_mystat(char * filename)
{
  fs_handler	* cur;

  /* Look for a filesystem handler for such prefix */
  cur = fsGetHandler(filename);
  if (cur == NULL) return 0;

  /* Invoke the handler */
  if (cur->fstat == NULL) return 0;
  return(cur->fstat(filename));
}

unsigned int  fsm_myfrm(char * filename)
{
  fs_handler	* cur;

  /* Look for a filesystem handler for such prefix */
  cur = fsGetHandler(filename);
  if (cur == NULL) return 0;

  /* Invoke the handler */
  if (cur->frm == NULL) return 0;
  return( cur->frm(filename) );
}

unsigned int fsm_mycreatedir(char * dirname)
{
  fs_handler	* cur;

  /* Look for a filesystem handler for such prefix */
  cur = fsGetHandler(dirname);
  if (cur == NULL) return 0;

  /* Invoke the handler */
  if (cur->fcreatedir == NULL) return 0;
  return( cur->fcreatedir(dirname) );
}

unsigned int fsm_myopendir(char * dirname)
{
  fs_handler	* cur;
  unsigned int h;
  f_handle * hnd;

  /* Look for a filesystem handler for such prefix */
  cur = fsGetHandler(dirname);
  if (cur == NULL) return 0;

  /* Invoke the handler */
  if (cur->fopendir == NULL) return 0;
  h = cur->fopendir(dirname);
  if (h == 0) return 0;
  /* Wrap it up in a structure */
  hnd = (f_handle *)MYMALLOC(sizeof(f_handle));
  if (hnd == NULL) 
  {
	cur->fclosedir(h);
	return 0;
  }
  hnd->handler = cur;
  hnd->hnd = h;
  return (unsigned int)hnd;
}

unsigned int fsm_myreaddir(unsigned int dir, char * filenamept)
{
  f_handle   * hnd;
  fs_handler * cur;

  hnd=(f_handle*)dir;
  cur = hnd->handler;
  return(cur->freaddir(hnd->hnd, filenamept));
}

unsigned int fsm_myclosedir(unsigned int dir)
{
  int        retval;
  f_handle   * hnd;
  fs_handler * cur;

  hnd=(f_handle*)dir;
  cur = hnd->handler;
  retval = cur->fclosedir(hnd->hnd);
  MYFREE(hnd);
  return(retval);
}

unsigned int fsm_myrmdir(char * dirname)
{
  fs_handler	* cur;

  /* Look for a filesystem handler for such prefix */
  cur = fsGetHandler(dirname);
  if (cur == NULL) return 0;

  /* Invoke the handler */
  if (cur->frmdir == NULL) return 0;
  return( cur->frmdir(dirname) );
}

unsigned int fsm_myfsize(char * filename)
{
  fs_handler	* cur;

  /* Look for a filesystem handler for such prefix */
  cur = fsGetHandler(filename);
  if (cur == NULL) return 0;

  /* Invoke the handler */
  if (cur->fsize == NULL) return 0;
  return(cur->fsize(filename));
}

int fsm_myfmetadata(char * filename, char * typeorcodecinfo, char * dateorduration, char * moreinfo)
{
  fs_handler	* cur;

  /* Look for a filesystem handler for such prefix */
  cur = fsGetHandler(filename);
  if (cur == NULL) return 0;

  /* Invoke the handler */
  if (cur->fmetadata == NULL) return 0;
  return(cur->fmetadata(filename, typeorcodecinfo, dateorduration, moreinfo));
}



int fsm_fsHandlerAdd(fs_handler * hnd) 
{
	hnd->next = fs_handlers;
	fs_handlers = hnd;
	return 0;
}



/***************************************
* Local procedures
***************************************/
/**************************************/
static fs_handler * fsGetHandler( char * fn) 
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
	fs_handler	* cur;

	cur = fs_handlers;
	/* Scan the handler table and look for a path match */
	while (cur != NULL) 
	{
		if (cur->frecog(fn)) break;
		cur = cur->next;
	}
	if (cur == NULL) {
		/* Couldn't find a handler */
		return NULL;
	}
	else
	{
		return cur;
	}
}



/***************************************
* Local procedures (stdio)
***************************************/
static int lparsepath(char * path, char * volName, char * pathName)
{
  char  *vpName = NULL; /* volume + pathname, without THFS prefix */

  pathName[0] = volName[0] = '\0'; /* initialise to empty string */
  /*std_*/strcpy(pathName, path);
  return(1);
}

static int lfrecogn(char * filename)
{
  return(1);
}

static unsigned int lfcreate(char * filename, char * mode)
{
//#ifdef GP32
//  F_HANDLE 	handle;
//  ERR_CODE 	result;
//
//  result = GpFileOpen(filename, OPEN_R, &handle);
//  if (result != SM_OK)
// 	return 0;
//  else
// 	return((unsigned int)handle);
//#else
return((unsigned int)fopen(filename, "wb"));
//#endif
}

static unsigned int lfopen(char * filename, char * mode)
{
//#ifdef GP32
//  F_HANDLE 	handle;
//  ERR_CODE 	result;
//
//  result = GpFileOpen(filename, OPEN_R, &handle);
//  if (result != SM_OK)
// 	return 0;
//  else
// 	return((unsigned int)handle);
//#else
return((unsigned int)fopen(filename, mode));
//#endif
}

static int lfclose(unsigned int stream)
{
//#ifdef GP32
//	GpFileClose((F_HANDLE)stream);
//#else
  return(fclose((FILE*)stream));
//#endif
}

static int lfread(void * data, int sizeelem , int nelem, unsigned int stream)
{
#ifdef GP32
  int ret;
  ret = fread(data, sizeelem, nelem, (FILE*)stream);
  if (ret > 0) ret --;
  return(ret);
//  unsigned int dwSize,dwDummy;
//  dwSize = sizeelem*nelem;
//  GpFileRead((F_HANDLE)stream, data, dwSize, &dwDummy);
//  return(dwSize);
#else
  return (fread(data, sizeelem, nelem, (FILE*)stream));
#endif
}

static int lfwrite(void * data, int sizeelem , int nelem, unsigned int stream)
{
#ifdef GP32
  return (1);
#else
  return (fwrite(data, sizeelem, nelem, (FILE*)stream));
#endif
}

static long lftell(unsigned int stream)
{
  return(ftell((FILE *)stream));
}

static int lfseek(unsigned int stream, long offset, int mode)
{
//  int retval;
//  retval = fseek((FILE*)stream, offset, mode);
//std_printf("offset:%d %d\n",offset,retval);
//  return(retval);
//		GpFileSeek(fHandle, FROM_BEGIN, 0, NULL);
  return(fseek((FILE*)stream, offset, mode));
}



#ifdef WIN32
//  HANDLE hFind;
  static int firstTime;
  WIN32_FIND_DATA f1;
  char matchString[256];
#endif
#ifdef _WIN32_WCE
//  HANDLE hFind;
  static int firstTime;
  WIN32_FIND_DATA f1;
  short matchString[256];
#endif
#ifdef _arch_dreamcast
  dirent_t *de;
#endif
#ifdef _trimedia
  struct dirent * buf;
  struct stat attr;
//  char matchString[256];
#endif
#ifdef GP32
  ulong		  dir_count_unmasked;
  GPFILEATTR  attr;
  GPDIRENTRY  *dir_entry_unmasked;
  int		  readcount;
  int         fcount;
#endif
#if ( (VIPER) && (!LINUX) )
  struct dirent * buf;
  struct stat attr;
//  char matchString[256];
#endif
#if (LINUX)
  struct dirent * buf;
  struct stat attr;
#endif
#ifdef NGC
  struct dirent * buf;
  struct stat attr;
#endif
#if ( (NDS) && (!LINUX) )
  struct dirent * buf;
  struct stat attr;
#endif
#ifdef PSP
  SceIoDirent buf;
#endif

static unsigned int lfrm(char * filename)
{
#ifdef WIN32
  return(remove(filename));
#endif
#ifdef _WIN32_WCE
  return(1);
#endif
#ifdef _arch_dreamcast
  return(1);
#endif
#ifdef _trimedia
  return(1);
#endif
#ifdef GP32
  return(1);
#endif
#if ( (VIPER) && (!LINUX) )
  return(remove(filename));
#endif
#if (LINUX)
  return(remove(filename));
#endif
#ifdef NGC
  return(1);
#endif
#if ( (NDS) && (!LINUX) )
  return(1);
#endif
#ifdef PSP
  return(1);
#endif
}

// returns 1 if it is a directory
static unsigned int lfstat(char * filename)
{
#ifdef WIN32
  if((f1.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
#endif
#ifdef _WIN32_WCE
  if((f1.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
#endif
#ifdef _arch_dreamcast
  if((de->size <0 ))
#endif
#ifdef _trimedia
//  stat(matchString, &attr);
  stat(filename, &attr);
  if(attr.st_mode & _IFDIR)
#endif
#ifdef GP32
  if ((attr.attr & 0x10))
#endif
#if ( (VIPER) && (!LINUX) )
  stat(filename, &attr);
  if(attr.st_mode & S_IFDIR )
#endif
#if (LINUX)
  stat(filename, &attr);
  if(attr.st_mode & S_IFDIR )
#endif
#ifdef NGC
  if( 1 )
#endif
#ifdef NGC
  stat(filename, &attr);
  if(S_ISDIR(attr.st_mode))
#endif
#if ( (NDS) && (!LINUX) )
  stat(filename, &attr);
  if(S_ISDIR(attr.st_mode))
#endif
#ifdef PSP
  if(buf.d_stat.st_attr & FIO_SO_IFDIR)
#endif
  {
	  return(0);
  }
  else
  {
#if (LINUX)
  if ( (attr.st_mode & S_IXOTH ) || 
	   (attr.st_mode & S_IXGRP) || 
	   (attr.st_mode & S_IXUSR) )
    return(2);
  else
    return(1);
#else
	return(1);
#endif
  }
}


#ifdef _WIN32_WCE
static int u2nstrcpy( char * str2, short * str )
{
	int cnt=0;

	while (*str)
	{
		*str2++ = (*str++)&0xff;
		cnt++;
	}
	*str2 = 0;
	return(cnt);
}

static int n2ustrcpy( short * str2, char * str )
{
	int cnt=0;

	while (*str)
	{
		*str2++ = (short)(*str++)&0xff;
		cnt++;
	}
	*str2 = 0;
	return(cnt);
}

static char * ustrcat(short * s, short * append)
{
	char *save = s;

	for (; *s; ++s);
	while ((*s++ = *append++));
	return(save);
}
//#define CF_CARDS_FLAGS (FILE_ATTRIBUTE_DIRECTORY|FILE_ATTRIBUTE_TEMPORARY)
#endif

static unsigned int lfcreatedir(char * dirname)
{
#ifdef WIN32
  return(mkdir(dirname));
#endif
#ifdef _WIN32_WCE
  return(1);
#endif
#ifdef _arch_dreamcast
  return(1);
#endif
#ifdef _trimedia
  return(1);
#endif
#ifdef GP32
  return(1);
#endif
#if ( (VIPER) && (!LINUX) )
  return(mkdir(dirname));
#endif
#if (LINUX)
  return(mkdir(dirname,""));
#endif
#ifdef NGC
  return(1);
#endif
#if ( (NDS) && (!LINUX) )
  return(1);
#endif
#ifdef PSP
  return(1);
#endif
}


static unsigned int lfopendir(char * dirname)
{
#ifdef WIN32
  HANDLE hFind;
  firstTime=1;
  /*std_*/strcpy(matchString,dirname);
  /*std_*/strcat(matchString,"*");
  hFind = FindFirstFile(matchString,&f1);
  if (hFind == (HANDLE)0xffffffff) 
	return(0);
  else
    return((unsigned int)hFind);
#endif
#ifdef _WIN32_WCE
  HANDLE hFind;
  firstTime=1;
  /*std_*/n2ustrcpy(matchString,dirname);
  /*std_*/ustrcat(matchString,L"*");
  hFind = FindFirstFile(matchString,&f1);
  if (hFind == 0xffffffff) 
	return(0);
  else
    return((unsigned int)hFind);
#endif
#ifdef _arch_dreamcast
  file_t d;
  d = fs_open(dirname, O_RDONLY | O_DIR);
  return(d);
#endif
#ifdef _trimedia
  DIR * dir;
  dir = opendir(dirname);
  return((unsigned int)dir);
#endif
#ifdef GP32
  int ret =0;
  GpRelativePathSet(dirname);
//  std_printf("read %s\n", dirname);

  if( GpDirEnumNum("\\", &dir_count_unmasked) == SM_OK)
  {
	dir_entry_unmasked = gm_calloc( (int)dir_count_unmasked, sizeof(GPDIRENTRY));
	if( GpDirEnumList("\\", 0, dir_count_unmasked, dir_entry_unmasked, &readcount) == SM_OK)
	{
//      std_printf("count= %d\n", readcount);
	  fcount=0;
  	  ret=1;
	}
  }
  return(ret);
#endif
#if ( (VIPER) && (!LINUX) )
  DIR * dir;
  dir = opendir(dirname);
  return((unsigned int)dir);
#endif
#if (LINUX)
  DIR * dir;
  dir = opendir(dirname);
  return((unsigned int)dir);
#endif
#ifdef NGC
  DIR * dir;
  dir = opendir(dirname);
  return((unsigned int)dir);
#endif
#if ( (NDS) && (!LINUX) )
  DIR * dir;
  dir = opendir(dirname);
  return((unsigned int)dir);
#endif
#ifdef PSP
  int dir;
  dir = sceIoDopen(dirname);
  return((unsigned int)dir);
#endif
}


static unsigned int lfreaddir(unsigned int dir, char * filenamept)
{
#ifdef WIN32
  if(firstTime)
  {
	  firstTime = 0;
      /*std_*/strcpy(filenamept,f1.cFileName);
	  return(1);
  }
  else
  {
	  if (FindNextFile((HANDLE)dir/*hFind*/, &f1))
	  {
        /*std_*/strcpy(filenamept,f1.cFileName);
	    return(1);       
	  }
	  else
	  {
		return(0);
	  }
  }
#endif
#ifdef _WIN32_WCE
  unsigned int retval=0;

  if(firstTime)
  {
	  firstTime = 0;
      /*std_*/u2nstrcpy(filenamept,f1.cFileName);
	  return(1);
  }
  else
  {
	  if (FindNextFile((HANDLE)dir/*hFind*/, &f1))
	  {
        /*std_*/u2nstrcpy(filenamept,f1.cFileName);
	    return(1);       
	  }
	  else
	  {
		return(0);
	  }
  }
#endif
#ifdef _arch_dreamcast
  de = fs_readdir(dir);
  if (de)
  {
     /*std_*/strcpy(filenamept,de->name);
	 return(1);       
  }
  else
  {
	 return(0);       
  }
#endif
#ifdef _trimedia
  buf = readdir((DIR *)dir);
  if (buf)
  {
     /*std_*/strcpy(filenamept,buf->d_name);
	 return(1);       
  }
  else
  {
	 return(0);       
  }
#endif
#ifdef GP32
  if (fcount<readcount) 
  {
//    std_printf("file %s\n", dir_entry_unmasked[fcount].name);
    /*std_*/strcpy(filenamept,dir_entry_unmasked[fcount].name);
    GpFileAttr(dir_entry_unmasked[fcount].name, &attr);
    fcount++;
    return(1);
  }
  else 
  {
    return(0);
  }
#endif
#if ( (VIPER) && (!LINUX) )
  buf = readdir((DIR *)dir);
  if (buf)
  {
     /*std_*/strcpy(filenamept,buf->d_name);
	 return(1);       
  }
  else
  {
	 return(0);       
  }
#endif
#if (LINUX)
  buf = readdir((DIR *)dir);
  if (buf)
  {
     /*std_*/strcpy(filenamept,buf->d_name);
	 return(1);       
  }
  else
  {
	 return(0);       
  }
#endif
#ifdef NGC
  buf = readdir((DIR *)dir);
  if (buf)
  {
     /*std_*/strcpy(filenamept,buf->d_name);
	 return(1);       
  }
  else
  {
	 return(0);       
  }
#endif
#if ( (NDS) && (!LINUX) )
  buf = readdir((DIR *)dir);
  if (buf)
  {
     /*std_*/strcpy(filenamept,buf->d_name);
	 return(1);       
  }
  else
  {
	 return(0);       
  }
#endif
#ifdef PSP
  if (sceIoDread(dir, &buf) > 0)
  {
     /*std_*/strcpy(filenamept,buf.d_name);
	 return(1);       
  }
  else
  {
	 return(0);       
  }
#endif
}

static unsigned int lfclosedir(unsigned int dir)
{
#ifdef WIN32
  FindClose((HANDLE)dir/*hFind*/);
#endif
#ifdef _WIN32_WCE
  FindClose((HANDLE)dir/*hFind*/);
#endif
#ifdef _arch_dreamcast
  fs_close(dir);
#endif
#ifdef _trimedia
  closedir((DIR *)dir);
#endif
#ifdef GP32
  if(dir_entry_unmasked!=NULL)
 	gm_free(dir_entry_unmasked);
#endif
#if ( (VIPER) && (!LINUX) )
  closedir((DIR *)dir);
#endif
#if (LINUX)
  closedir((DIR *)dir);
#endif
#ifdef NGC
  closedir((DIR *)dir);
#endif
#if ( (NDS) && (!LINUX) )
  closedir((DIR *)dir);
#endif
#ifdef PSP
  sceIoDclose(dir);
#endif
  return(1);
}

static unsigned int lfrmdir(char * dirname)
{
#ifdef WIN32
  return(rmdir(dirname));
#endif
#ifdef _WIN32_WCE
  return(1);
#endif
#ifdef _arch_dreamcast
  return(1);
#endif
#ifdef _trimedia
  return(1);
#endif
#ifdef GP32
  return(1);
#endif
#if ( (VIPER) && (!LINUX) )
  return(rmdir(dirname));
#endif
#if (LINUX)
  return(rmdir(dirname));
#endif
#ifdef NGC
  return(1);
#endif
#if ( (NDS) && (!LINUX) )
  return(1);
#endif
#ifdef PSP
  return(1);
#endif
}

static unsigned int lfsize(char * filename)
{
#ifdef WIN32
  struct stat lattr;
  stat(matchString, &lattr);
  stat(filename, &lattr);
  return (lattr.st_size);
#endif
#ifdef _WIN32_WCE
  FILE * f;
  unsigned int fileSize;
  f = fopen(filename,"r+b");
  fseek(f,0,SEEK_END);
  fileSize = ftell(f);
  fseek(f,0,SEEK_SET);
  fclose(f);
//  struct stat lattr;
//  stat(matchString, &lattr);
//  stat(filename, &lattr);
//  return (lattr.st_size);
//  return (0);
  return (fileSize);
#endif
#ifdef _arch_dreamcast
  return (fstat(filename));
#endif
#ifdef _trimedia
  struct stat lattr;
//  stat(matchString, &lattr);
  stat(filename, &lattr);
  return (lattr.st_size);
#endif
#ifdef GP32
  GpFileAttr(filename, &attr);
  return (attr.size);
#endif
#if ( (VIPER) && (!LINUX) )
  struct stat lattr;
  stat(filename, &lattr);
  return (lattr.st_size);
#endif
#if (LINUX)
  struct stat lattr;
  stat(filename, &lattr);
  return (lattr.st_size);
#endif
#ifdef NGC
  struct stat lattr;
  stat(filename, &lattr);
  return (lattr.st_size);
#endif
#if ( (NDS) && (!LINUX) )
  struct stat lattr;
  stat(filename, &lattr);
  return (lattr.st_size);
#endif
#ifdef PSP
  SceIoStat attr;
  sceIoGetstat(filename, &attr);
  return (attr.st_size);
#endif
}

static int lfmetadata(char * filename, char * typeorcodecinfo, char * dateorduration, char * moreinfo)
{
  return(0);
}




/***************************************
* Local procedures (mem)
***************************************/
#define PATH_PREFIX       "mem:"    /* pathname prefix recognised by IODAL  */
#define PATH_PREFIX_LEN   4         /* length of the prefix                 */

static short memfilehandler;
static int memfilesize;
static int memfilept;
static unsigned int memdatapt;

static int mparsepath(char * path, char * volName, char * pathName)
{
  char  *vpName = NULL; /* volume + pathname, without THFS prefix */

  pathName[0] = volName[0] = '\0'; /* initialise to empty string */
  /*std_*/strcpy(pathName, path);

  if (/*std_*/strncmp(path, PATH_PREFIX, PATH_PREFIX_LEN) != 0) /* check prefix */
  {
	return(0);
  }
  else /* prefix recognised */
  {
		vpName = path + PATH_PREFIX_LEN; /* strip the prefix */
  }

  /* get memory address and size */
  if (sscanf(vpName, "%x %u", &memdatapt, &memfilesize) < 2)
	return(0);
  else
    return(1);
}

static int mfrecogn(char * filename)
{
  return(/*std_*/strncmp(filename, PATH_PREFIX, PATH_PREFIX_LEN) == 0);
}

static unsigned int mfopen(char * filename, char * mode)
{
  char volName[32], pathName[255];
  memfilehandler = 0; 
  memfilept     = 0;

  if (mparsepath(filename, volName, pathName))
  { /* correct volume name */
    return((unsigned int)&memfilehandler);
  }
  else
  {
    return(0);
  }
}

static int mfclose(unsigned int stream)
{
  return(1);
}

static int mfread(void * data, int sizeelem , int nelem, unsigned int stream)
{
  int size;
  int i;
  unsigned char * databuf = data;
  unsigned char * src = (unsigned char *)(memfilept+memdatapt);
  int oldmemfilept = memfilept;

  i=0;
  size = sizeelem*nelem;
  while ( (i<size) && (memfilept<memfilesize) )
  {
    databuf[i++] = *src++;
	memfilept++;
  }
  if (nelem == 1)
	return((memfilept - oldmemfilept) == size ? 1: 0);
  else
    return(memfilept - oldmemfilept);
}

static int mfwrite(void * data, int sizeelem , int nelem, unsigned int stream)
{
  return (1);
}

static long mftell(unsigned int stream)
{
  return(memfilept);
}

static int mfseek(unsigned int stream, long offset, int mode)
{
  switch(mode)
  {
    case SEEK_SET:
     memfilept = offset;
     break;
    case SEEK_CUR:
     memfilept = memfilept+offset;
     break;
    case SEEK_END:
     memfilept = memfilesize-offset;
     break;
    default:
     memfilept = 0;
     break;
  }
  return(0);
}

static unsigned int mfsize(char * filename)
{
  return(memfilesize);
}
	

/***************************************
* Local procedures (flash)
***************************************/
#define FPATH_PREFIX       "flash:"  /* pathname prefix recognised by IODAL  */
#define FPATH_PREFIX_LEN   6         /* length of the prefix                 */

#ifdef LSB_FIRST
 #define get_word(x) (x)
 #define get_lword(x) (x)
#else
 #define get_word(x)  (((x>>8) & 0xff) | ((x << 8) & 0xff00 )) 
 #define get_lword(x) ( ( (x & 0xff000000)>>24) | ( (x & 0x00ff0000)>>8)  | ( (x & 0x0000ff00)<<8)  | ( (x & 0x000000ff)<<24) )
#endif

#define BLOCKSIZE      256
#define DATASIZE       (BLOCKSIZE-6)
#define DISKSIZE       2048*1024 
#define TOTALBLOCK     (DISKSIZE/BLOCKSIZE)

typedef struct
{
  unsigned short next;
  unsigned short prev;
  unsigned short checksum;
  unsigned char data[BLOCKSIZE-6];
} fsblock;

typedef struct
{
  unsigned short next;
  unsigned short prev;
  unsigned short checksum;
  unsigned short nextfile;
  unsigned short prevfile;
  unsigned short start;
  unsigned int   size;
  char filename[BLOCKSIZE-16];
} fileblock;

typedef struct
{
  unsigned short next;
  unsigned short prev;
  unsigned short checksum;
  unsigned short blocksize;
  unsigned short totalblock;
  unsigned short totalfile;
  unsigned short firstfree;
  unsigned short firstfile;
  char  filesysname[BLOCKSIZE-16];
} rootblock;

/* Generic for every block **
fafb  : address of next block; 0000h if none;
fcfd  : address of previous block; 0000h if none;
feff  : checksum

** Root block **
0001  : block size (256)
0203  : total amount of blocks
0405  : total amount of files
0607  : adress of first free block;
0809  : adress of first free title
0af9  : filesys name
fafb  : address of next block; 0000h if none;
fcfd  : address of previous block; 0000h if none;
feff  : checksum
*/

static unsigned char * disk=NULL;
static short filehandler;
static int filesize;
static int filept;
static int datapt;
static fileblock * oldfileblockpt;
static short next_block;

static unsigned char blockbuf[BLOCKSIZE];

void fsm_fsFlashMount(unsigned char * aBuffer, int aSize )
{
  disk = aBuffer;
}

static int readblock() 
{
  int i;
  fsblock * blockpt;
  short checksum=0;

  blockpt = (fsblock *)&disk[next_block*BLOCKSIZE];
  if (next_block == 0) return(0);
  for (i=0; i<DATASIZE; i++)
  { 
    blockbuf[i] = blockpt->data[i];
    checksum += blockbuf[i]; 
  }
  next_block = get_word(blockpt->next);

  return(DATASIZE);
}


static int fparsepath(char * path, char * volName, char * pathName)
{
  char  *vpName = NULL; /* volume + pathname, without THFS prefix */

  pathName[0] = volName[0] = '\0'; /* initialise to empty string */
  /*std_*/strcpy(pathName, path);

  if (/*std_*/strncmp(path, FPATH_PREFIX, FPATH_PREFIX_LEN) != 0) /* check prefix */
  {
	return(0);
  }
  else /* prefix recognised */
  {
		vpName = path + FPATH_PREFIX_LEN; /* strip the prefix */
  }
  /*std_*/strcpy(pathName, vpName);
  return(1);
}

static int ffrecogn(char * filename)
{
  return(/*std_*/strncmp(filename, FPATH_PREFIX, FPATH_PREFIX_LEN) == 0);
}

static unsigned int ffopen(char * filename, char * mode)
{
  char volName[32], pathName[255];
  char * fileName;
  rootblock * rootpt;
  fileblock * fileblockpt;
  int nbfile;
  int found=0;

  if (fparsepath(filename, volName, pathName))
  { /* correct volume name */
    fileName = (char *)(std_strchr(pathName, SLASHCHAR));
	if (fileName == NULL) 
		fileName=pathName;
	else
		fileName++;
    filehandler = 1;
    rootpt = (rootblock *)&disk[0]; 
    nbfile= get_word(rootpt->totalfile);
    fileblockpt = (fileblock*)&disk[get_word(rootpt->firstfile)*BLOCKSIZE]; 
    while( (nbfile>0) && (!found) )
	{
      if ( !/*std_*/strcmp( fileName, fileblockpt->filename) ) 
	  {
	    found=1;
	  }
	  else
	  {
        fileblockpt = (fileblock*)&disk[get_word(fileblockpt->nextfile)*BLOCKSIZE]; 
	    nbfile--;
	  }
	}
  
    if (found)
	{
	  oldfileblockpt = fileblockpt;
      next_block = get_word(fileblockpt->start);
      filesize   = get_lword(fileblockpt->size);
      filept     = 0;
	}
    else
	{
      return(0);
	}
    return((unsigned int)&filehandler);
  }
  else
  {
    return(0);
  }
}

static int ffclose(unsigned int stream)
{
  return(1);
}

static int ffread(void * data, int sizeelem , int nelem, unsigned int stream)
{
  int size;
  int i;
  unsigned char * databuf = data;

  i=0;
  size = sizeelem*nelem;
  while ( (i<size) && (filept<filesize) )
  {
    if ( (filept % DATASIZE) == 0)
    {
      if (!readblock())
      {
        return (0);
      }
      datapt=0;
    }   
    databuf[i++] = blockbuf[datapt++];
    filept++;
  }
  return (i); 
}

static int ffwrite(void * data, int sizeelem , int nelem, unsigned int stream)
{
  return (1);
}

static long fftell(unsigned int stream)
{
  return(filept);
}

static int ffseek(unsigned int stream, long offset, int mode)
{
  long i;
  long pos;

  next_block = get_word(oldfileblockpt->start);
  filesize   = get_lword(oldfileblockpt->size);
  switch(mode)
  {
    case SEEK_SET:
     pos = offset;
     break;
    case SEEK_CUR:
     pos = filept+offset;
     break;
    case SEEK_END:
     pos = filesize-offset;
     break;
    default:
     pos = 0;
     break;
  }

  i=0;
  filept = 0;
  while ( (i<pos) && (filept<filesize) )
  {
    if ( (filept % DATASIZE) == 0)
    {
      if (!readblock())
      {
         return (-1);
      }
      datapt=0;
    }   
    i++;
    datapt++;
    filept++;
  }

  return(0);
}


static unsigned int ffstat(char * filename)
{
  char volName[32], pathName[255];

  if (fparsepath(filename, volName, pathName))
  { /* correct volume name */
  if ( !/*std_*/strcmp( pathName, ".") ) 
  {
    return(0);
  }
  /* Never a directory !!!*/
  }
  return(1);
}


static rootblock * drootpt;
static fileblock * dfileblockpt;
static int dnbfile;
static int dfilesize;
static int firstTime;


static unsigned int ffopendir(char * dirname)
{
  int ret =0;

//  if ( !/*std_*/strcmp( dirname, "flash:") ) 
//  {
      drootpt = (rootblock *)&disk[0]; 
      dfileblockpt = (fileblock*)&disk[get_word(drootpt->firstfile)*BLOCKSIZE]; 
      dnbfile= get_word(drootpt->totalfile);
	  firstTime=1;
      ret=1;
//  }
//  else
//  {
//      dnbfile=0;
//  }
  return(ret);
}

static unsigned int ffreaddir(unsigned int dir, char * filenamept)
{
  int retval=0;

  if (dnbfile>0)
  {
	 if (firstTime)
	 {
	   firstTime=0;
       /*std_*/strcpy(filenamept,".");
	 }
	 else
	 {
       /*std_*/strcpy(filenamept,dfileblockpt->filename);
       dfilesize   = get_lword(dfileblockpt->size);
       dfileblockpt = (fileblock*)&disk[get_word(dfileblockpt->nextfile)*BLOCKSIZE]; 
       dnbfile--;
	 }
     retval = 1;
  }
  return(retval);
}



static unsigned int ffclosedir(unsigned int dir)
{
  return(1);
}

static unsigned int ffsize(char * filename)
{
  char volName[32], pathName[255];
  char * fileName;
  rootblock * rootpt;
  fileblock * fileblockpt;
  int nbfile;
  int found=0;

  if (fparsepath(filename, volName, pathName))
  { /* correct volume name */
    fileName = (char *)(std_strchr(pathName, SLASHCHAR));
	if (fileName == NULL) 
		fileName=pathName;
	else
		fileName++;
    rootpt = (rootblock *)&disk[0]; 
    nbfile= get_word(rootpt->totalfile);
    fileblockpt = (fileblock*)&disk[get_word(rootpt->firstfile)*BLOCKSIZE]; 
    while( (nbfile>0) && (!found) )
	{
      if ( !/*std_*/strcmp( fileName, fileblockpt->filename) ) 
	  {
	    found=1;
	  }
	  else
	  {
        fileblockpt = (fileblock*)&disk[get_word(fileblockpt->nextfile)*BLOCKSIZE]; 
	    nbfile--;
	  }
	}
  
    if (found)
	{
      return ( get_lword(fileblockpt->size) );
	}
    else
	{
      return(0);
	}
  }
  else
  {
    return(0);
  }
}

static int ffmetadata(char * filename, char * typeorcodecinfo, char * dateorduration, char * moreinfo)
{
  return(0);
}















