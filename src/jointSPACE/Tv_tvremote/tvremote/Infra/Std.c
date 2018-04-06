/****************************************************************************
* Purpose : Standard IO
* Module  : std
* Author  : J-M Harvengt
* History : 10/08/97 Creation
****************************************************************************/
#include "std.h"

/**************************************
* Local macros/typedef
**************************************/
#define TRUE  1
#define FALSE 0
#define NULL  0
#ifdef WIN32
#define SLASH "\\"
#define SLASHCHAR '\\'
#else
 #ifdef GP32
  #define SLASH "\\"
  #define SLASHCHAR '\\'
 #else
  #define SLASH "/"
  #define SLASHCHAR '/'
 #endif
#endif

/***************************************
* Local procedures definition
***************************************/

/***************************************
* Global data
***************************************/
static char hexString[9];
static char * digitsUp = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

#define _U	0x01	/* upper */
#define _L	0x02	/* lower */
#define _N	0x04	/* number */
#define _S	0x08	/* space */
#define _P	0x10	/* punct */
#define _C	0x20	/* control */
#define _X	0x40	/* hex number */
#define _B	0x80	/* blank */

/* hardcoded POSIX locale... */
static const char _ctype_[256] = {
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,	/* 00-07 */
	_C,	_C|_S,	_C|_S,	_C|_S,	_C|_S,	_C|_S,	_C,	_C,	/* 08-0f */
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,	/* 10-17 */
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,	/* 18-1f */
	_S|_B,	_P,	_P,	_P,	_P,	_P,	_P,	_P,	/* 20-27 */
	_P,	_P,	_P,	_P,	_P,	_P,	_P,	_P,	/* 28-2f */
	_N,	_N,	_N,	_N,	_N,	_N,	_N,	_N,	/* 30-37 */
	_N,	_N,	_P,	_P,	_P,	_P,	_P,	_P,	/* 38-3f */
	_P,	_U|_X,	_U|_X,	_U|_X,	_U|_X,	_U|_X,	_U|_X,	_U,	/* 40-47 */
	_U,	_U,	_U,	_U,	_U,	_U,	_U,	_U,	/* 48-4f */
	_U,	_U,	_U,	_U,	_U,	_U,	_U,	_U,	/* 50-57 */
	_U,	_U,	_U,	_P,	_P,	_P,	_P,	_P,	/* 58-5f */
	_P,	_L|_X,	_L|_X,	_L|_X,	_L|_X,	_L|_X,	_L|_X,	_L,	/* 60-67 */
	_L,	_L,	_L,	_L,	_L,	_L,	_L,	_L,	/* 68-6f */
	_L,	_L,	_L,	_L,	_L,	_L,	_L,	_L,	/* 70-77 */
	_L,	_L,	_L,	_P,	_P,	_P,	_P,	_C	/* 78-7f */
									/* 80-ff */
};
/***************************************
* Local data
***************************************/

/***************************************
* Exported procedures
***************************************/

/***************************************
* Purpose : Initialization.
***************************************/
void std_Init( void )
{
}

void std_TurnOn(void)
{
}

void std_TurnOff(void)
{
}

/***************************************
* Purpose : Others
***************************************/
static int MYisupper(int c)
{
	return (_ctype_[c] & _U);
}

static int MYtolower(int c)
{
	return (MYisupper(c) ? (c + ('a' - 'A')) : c);
}

/**************************************/
int std_strcmp( char * str1, char * str2)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
	int ret = -1;

	if ((str1 != NULL) && (str2 != NULL)) {
		ret=*(unsigned char *)str1 - *(unsigned char *)str2;

		while (!ret && *str1)
		{
			str1++;
			str2++;
			ret = *(unsigned char *)str1 - *(unsigned char *)str2;
		}
	}
  return( ret );
}

/**************************************/
int std_strncmp( char * str1, char * str2, int n)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  int ret=*(unsigned char *)str1 - *(unsigned char *)str2;
	n--;

  while (!ret && *str1 && n)
  {
		n--;
    str1++;
    str2++;
    ret = *(unsigned char *)str1 - *(unsigned char *)str2;
  }
  return( ret );
}

/**************************************/
int std_stricmp( char * str1, char * str2)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
	int ret = -1;

	if ((str1 != NULL) && (str2 != NULL)) {
		ret=MYtolower(*(unsigned char *)str1) - MYtolower(*(unsigned char *)str2);

		while (!ret && *str1)
		{
			str1++;
			str2++;
			ret = MYtolower(*(unsigned char *)str1) - MYtolower(*(unsigned char *)str2);
		}
	}
  return( ret );
}

/**************************************/
int std_strincmp( char * str1, char * str2, int n)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  int ret=MYtolower(*(unsigned char *)str1) - MYtolower(*(unsigned char *)str2);
	n--;

  while (!ret && *str1 && n)
  {
	n--;
    str1++;
    str2++;
    ret = MYtolower(*(unsigned char *)str1) - MYtolower(*(unsigned char *)str2);
  }
  return( ret );
}

/**************************************/
int std_strtailcmp( char * str1, char * str2)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
	int ret = -1;
	char * str;
	int i,j;
	i = std_strlen(str1);
	j = std_strlen(str2);
	if ((str1 != NULL) && (str2 != NULL) && (j<=i)){
        str = &str1[i-j];
		ret=*(unsigned char *)str - *(unsigned char *)str2;

		while (!ret && *str)
		{
			str++;
			str2++;
			ret = *(unsigned char *)str - *(unsigned char *)str2;
		}
	}
    return( ret );
}

/**************************************/
int std_strlen( char * str )
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  int n = 0;

  while (*str++)
  {
      n++;
  }
  return(n);
}

/***************************************************/
int std_strnlen( char *s, int size )
{
  int n = 0;

  while ( (*s++) && (size) )
  {
    n++;
    size--;
  }
  return(n);
}

/**************************************/
int std_strcpy( char * str2, char * str )
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
	int cnt=0;

	while (*str)
	{
		*str2++ = *str++;
		cnt++;
	}
	*str2 = 0;
	return(cnt);
}


/**************************************/
char * std_strncpy(char * dst, char * src, int n)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
	if (n != 0) 
	{
		register char *d = dst;
		register char *s = src;

		do 
		{
			if ((*d++ = *s++) == 0) 
			{
				/* NUL pad the remaining n-1 bytes */
				while (--n != 0)
					*d++ = 0;
				break;
			}
		} while (--n != 0);
	}
	return (dst);
}


/**************************************/
int std_strcpycase( char * str2, char * str )
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
	int cnt=0;
	int up=1;
    char c;

	while ( (c = *str) )
	{
		c |= 0x20; /* Force lower case ! */
		if ( (c >= 0x61) && (c <= 0x7a) )
		{
			if (up) 
			{
				c &= ~0x20; /* Force upper case after a space and at start ! */
				up=0;
			}
	  	  *str2++ = c; str++;
		}
		else
		{
	  	  *str2++ = *str++;
		}
		if (c == 0x20) up=1;
		cnt++;
	}
	*str2 = 0;
	return(cnt);
}

/**************************************/
int std_strcpytodot( char * str2, char * str )
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
	int cnt=0;

	while ( (*str) && (*str!='.') )
	{
		*str2++ = *str++;
		cnt++;
	}
	*str2 = 0;
	return(cnt);
}

/**************************************/
int std_strcpyfromslashtodot( char * str2, char * str )
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
	int cnt=0;
	char * dst=str2;

	while ( (*str) && (*str!='.') )
	{
		if (*str == SLASHCHAR)
		{
			str++;
			cnt=0;
            dst=str2;
		}
		else
		{
		  *dst++ = *str++;
		  cnt++;
		}
	}
	*dst = 0;
	return(cnt);
}

/**************************************/
char * std_strtail(char *p, int ch)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
	int len;
	
	if (p)
	{
		len = std_strlen(p);
		if (len)
		{
          len--;  
		  if ((p[len] == ch) && (len) ) len--; // ignore SLASH if at last position
		  p += len;
          while ( (*p != ch) && (len>=0)  )
		  {
		    p--;
			len--;
		  }
		}
	}
    return (p);
}

/**************************************/
char * std_strchr(char *p, int ch)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
	for (;; ++p) {
		if (*p == ch)
			return((char *)p);
		if (!*p)
			return((char *)NULL);
	}
}

/**************************************/
char * std_strrchr(char *p, int ch)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
	char *save;

	for (save = NULL;; ++p) {
		if (*p == ch)
			save = (char *)p;
		if (!*p)
			return(save);
	}
}

/**************************************/
char * std_strstrip(char *p, int ch)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
	char * tmp;
    int len;

	len = std_strlen(p);
	if (len)
	{
	  tmp = &p[len-1];
	  while (len--)
	  {
	    *tmp = 0;
        tmp--;
		if ( (len != 0) && (*tmp == ch) ) break;
	  }
	}
    return(p);
}

/**************************************/
void std_stripspace (char str)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
}

/**************************************/
char * std_strcat(char * s, char * append)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
	char *save = s;

	for (; *s; ++s);
	while ((*s++ = *append++));
	return(save);
}

/**************************************/
char * std_longToHMS(unsigned long x)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  unsigned int h,m,s,rest;

  rest = x;
  h=rest/3600;
  rest-=h*3600;
  m=rest/60;
  rest-=m*60;
  s=rest;
  hexString[0]= h/10 +'0';
  hexString[1]= h%10 +'0';
  hexString[2]= ':';
  hexString[3]= m/10 +'0';
  hexString[4]= m%10 +'0';
  hexString[5]= ':';
  hexString[6]= s/10 +'0';
  hexString[7]= s%10 +'0';
  hexString[8]= 0;
  return(hexString);
}


/**************************************/
char * std_longToHex(unsigned long x)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  hexString[0]=digitsUp[(x>>28) & 0xf];
  hexString[1]=digitsUp[(x>>24) & 0xf];
  hexString[2]=digitsUp[(x>>20) & 0xf];
  hexString[3]=digitsUp[(x>>16) & 0xf];
  hexString[4]=digitsUp[(x>>12) & 0xf];
  hexString[5]=digitsUp[(x>>8) & 0xf];
  hexString[6]=digitsUp[(x>>4) & 0xf];
  hexString[7]=digitsUp[x & 0xf];
  hexString[8]=0;
  return(hexString);
}

/**************************************/
char * std_shortToHex(unsigned short x)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  hexString[0]=digitsUp[(x>>12) & 0xf];
  hexString[1]=digitsUp[(x>>8) & 0xf];
  hexString[2]=digitsUp[(x>>4) & 0xf];
  hexString[3]=digitsUp[x & 0xf];
  hexString[4]=0;
  return(hexString);
}


/**************************************/
char * std_charToHex(unsigned char x)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  hexString[0]=digitsUp[(x>>4) & 0xf];
  hexString[1]=digitsUp[x & 0xf];
  hexString[2]=0;
  return(hexString);
}

/**************************************/
char * std_charToDec(unsigned char x)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  hexString[0]= (x / 10)+'0';
  hexString[1]= (x % 10)+'0'; 
  hexString[2]=0;
  return(hexString);
}

/**************************************/
char * std_shortToDec(unsigned short x)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  unsigned short rest=x;
  unsigned short i;
  unsigned short tot=0;
  int k=0;

  /* Ignore above fifth digit */
  i = rest/10000;
  rest -= i*10000;
  tot+=i;
  if(tot) hexString[k++]= i +'0';
  i = rest/1000;
  rest -= i*1000;
  tot+=i;
  if(tot) hexString[k++]= i +'0';
  i = rest/100;
  rest -= i*100;
  tot+=i;
  if(tot) hexString[k++]= i +'0';
  i = rest/10;
  rest -= i*10;
  tot+=i;
  if(tot) hexString[k++]= i +'0';
  hexString[k++]= rest +'0'; 
  hexString[k]=0;
  return(hexString);
}

/**************************************/
char * std_longToDec(unsigned long x)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  unsigned long rest=x;
  unsigned long i;
  unsigned long tot=0;
  int k=0;

  /* Ignore above seventh digit */
  i = rest/1000000;
  rest -= i*1000000;
  tot+=i;
  if(tot) hexString[k++]= (char)i +'0';
  i = rest/100000;
  rest -= i*100000;
  tot+=i;
  if(tot) hexString[k++]= (char)i +'0';
  i = rest/10000;
  rest -= i*10000;
  tot+=i;
  if(tot) hexString[k++]= (char)i +'0';
  i = rest/1000;
  rest -= i*1000;
  tot+=i;
  if(tot) hexString[k++]= (char)i +'0';
  i = rest/100;
  rest -= i*100;
  tot+=i;
  if(tot) hexString[k++]= (char)i +'0';
  i = rest/10;
  rest -= i*10;
  tot+=i;
  if(tot) hexString[k++]= (char)i +'0';
  hexString[k++]= (char)rest +'0'; 
  hexString[k]=0;
  return(hexString);
}

/**************************************/
extern char * std_longToPercent(unsigned long num, unsigned long denom)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  unsigned int val;
  unsigned int rest;
  unsigned int i;

  if (denom)
    val = (num*100)/denom;
  else
	val = 100;
  rest=val;
  i = rest/100;
  rest -= i*100;
  hexString[0]= i +'0';
  i = rest/10;
  rest -= i*10;
  hexString[1]= i +'0';
  hexString[2]= rest +'0'; 
  hexString[3]= '%';
  hexString[4]= 0;
  return(hexString);
}






/***************************************
* Local procedures
***************************************/
