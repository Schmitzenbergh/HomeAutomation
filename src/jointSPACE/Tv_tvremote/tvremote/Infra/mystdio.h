/****************************************************************************
* Module name : MYSTDIO
* Description : FIle system routines
* Author      : J-M Harvengt
* History     : 14-07-97 Creation
****************************************************************************/
#ifndef _MYSTDIO
#define _MYSTDIO

/****************************************************************************
* Typedef/macros
****************************************************************************/
#ifndef EOF
#define EOF		(-1)
#endif
#ifndef SEEK_SET
#define SEEK_SET	0
#endif
#ifndef SEEK_CUR
#define SEEK_CUR	1
#endif
#ifndef SEEK_END
#define SEEK_END	2
#endif


/* Flesystem Handler */
typedef struct fs_handler_str {
	int	         cache;			        /* Allow VFS cacheing; 0=no, 1=yes */
	struct       fs_handler_str * next;	/* Linked list pointer */	
	int          (*frecog) (char * path );
    unsigned int (*fcreate)(char * filename, char * mode);
    unsigned int (*fopen)(char * filename, char * mode);
    int          (*fclose)(unsigned int stream);
    int          (*fread)(void * ptr, int size , int nelem, unsigned int stream);
    int          (*fwrite)(void * ptr, int size , int nelem, unsigned int stream);
    long         (*ftell)(unsigned int stream);
    int          (*fseek)(unsigned int stream, long offset, int mode);
    unsigned int (*frm)(char * filename);
    unsigned int (*fstat)(char * filename);
    unsigned int (*fcreatedir)(char * dirname);
    unsigned int (*fopendir)(char * dirname);
    unsigned int (*freaddir)(unsigned int dir, char * filenamept);
    unsigned int (*fclosedir)(unsigned int dir);
    unsigned int (*frmdir)(char * dirname);
    unsigned int (*fsize)(char * filename);
    int          (*fmetadata)(char * filename, char * typeorcodecinfo, char * dateorduration, char * moreinfo);
} fs_handler;

typedef struct {
  fs_handler * handler;
  unsigned int hnd; 
  unsigned int filePosition;
} f_handle;


/****************************************************************************
* Exported procedures
****************************************************************************/
extern unsigned int  fsm_myfcreate(char * filename, char * mode);
extern unsigned int  fsm_myfopen(char * filename, char * mode);
extern int           fsm_myfclose(unsigned int stream);
extern int           fsm_myfread(void * data, int sizeelem , int nelem, unsigned int stream);
extern char          fsm_myfgetc(unsigned int stream);
extern char *        fsm_myfgets(char * s, int n, unsigned int stream);
extern int           fsm_myfwrite(void * data, int sizeelem , int nelem, unsigned int stream);
extern long          fsm_myftell(unsigned int stream);
extern int           fsm_myfseek(unsigned int stream, long offset, int mode);
extern unsigned int  fsm_myfrm(char * filename);
extern unsigned int  fsm_mystat(char * filename);
extern unsigned int  fsm_mycreatedir(char * dirname);
extern unsigned int  fsm_myopendir(char * dirname);
extern unsigned int  fsm_myreaddir(unsigned int dir, char * filenamept);
extern unsigned int  fsm_myclosedir(unsigned int dir);
extern unsigned int  fsm_myrmdir(char * dir);
extern unsigned int  fsm_myfsize(char * filename);
extern int           fsm_myfmetadata(char * filename, char * typeorcodecinfo, char * dateorduration, char * moreinfo);

extern int           fsm_fsHandlerAdd(fs_handler * hnd); 
extern void          fsm_fsFlashMount(unsigned char * aBuffer, int aSize );

#endif



