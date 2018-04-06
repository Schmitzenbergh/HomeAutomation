/****************************************************************************
* Module name : console
* Description : Standart console output
* Author      : J-M Harvengt
* History     : 14-07-97 Creation
****************************************************************************/
#include "console.h"
#include <stdarg.h>

/**************************************
* Local macros/typedef
**************************************/

/***************************************
* Local data
***************************************/

static char vbuffer[2048];
static int res;

static char * digitsLow="0123456789abcdefghijklmnopqrstuvwxyz";
static char * digitsUp = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/***************************************
* Local procedures declaration
***************************************/

static int  lvsprintf(char *buf, char *fmt, va_list args);



/***************************************
* Purpose : Standard console output
***************************************/
/**************************************/
int std_vprintf(char * buf, char *fmt, ...)
/**************************************
 * Parameters :
 * Purpose    :
 **************************************/
{
  va_list args;
  int i;

  va_start(args, fmt);
  i=lvsprintf(buf,fmt,args);
  va_end(args);
  return i;
}




/****************************************************
 * Following routines are based on the great
 * Linux kernel sources.
 * They mainly define a printf and a vprintf
 * functionality.
 *
 * Note that :
 * - %f, %e%E and %g%G are not supported,
 * - %s is defined for strings stored in RAM (*char),
 *
 * Static data definitions
 ****************************************************/

/* we use this so that we can do without the ctype library */
#define is_digit(c) ((c) >= '0' && (c) <= '9')

/***************************************************/
static int skip_atoi(char **s)
{
  int i=0;

  while (is_digit(**s))
    i = i*10 + *((*s)++) - '0';
  return i;
}


#define ZEROPAD 1   /* pad with zero */
#define SIGN  2     /* unsigned/signed long */
#define PLUS  4     /* show plus */
#define SPACE 8     /* space if plus */
#define LEFT  16    /* left justified */
#define SPECIAL 32  /* 0x */
#define LARGE 64    /* use 'ABCDEF' instead of 'abcdef' */


/***************************************************/
static char * number(char * str, long num, int base, int size, int precision
  ,int type)
{
  char c,sign,tmp[66];
  char * digits= digitsLow;
  int i;

  if (type & LARGE)
    digits = digitsUp;
  if (type & LEFT)
    type &= ~ZEROPAD;
  if (base < 2 || base > 36)
    return 0;
  c = (type & ZEROPAD) ? '0' : ' ';
  sign = 0;
  if (type & SIGN) {
    if (num < 0) {
      sign = '-';
      num = -num;
      size--;
    } else if (type & PLUS) {
      sign = '+';
      size--;
    } else if (type & SPACE) {
      sign = ' ';
      size--;
    }
  }
  if (type & SPECIAL) {
    if (base == 16)
      size -= 2;
    else if (base == 8)
      size--;
  }
  i = 0;
  if (num == 0)
    tmp[i++]='0';
  else while (num != 0)
    {
      res = ((unsigned long) num) % (unsigned) base;
      num = ((unsigned long) num) / (unsigned) base;
      tmp[i++] = digits[res];
    }

  if (i > precision)
    precision = i;
  size -= precision;
  if (!(type&(ZEROPAD+LEFT)))
    while(size-->0)
      *str++ = ' ';
  if (sign)
    *str++ = sign;
  if (type & SPECIAL)
  {
    if (base==8)
      *str++ = '0';
    else if (base==16) 
	{
      *str++ = '0';
      *str++ = digits[33];
    }
  }
  if (!(type & LEFT))
    while (size-- > 0)
      *str++ = c;
  while (i < precision--)
    *str++ = '0';
  while (i-- > 0)
    *str++ = tmp[i];
  while (size-- > 0)
    *str++ = ' ';
  return str;
}

/***************************************************/
static int lstrnlen( char *s, int size )
{
  int n = 0;

  while ( (*s++) && (size) )
  {
    n++;
    size--;
  }
  return(n);
}


/***************************************************/
static int lvsprintf(char *buf, char *fmt, va_list args)
{
  int len;
  unsigned long num;
  int i, base;
  char * str;
  char * s;

  int flags;    /* flags to number() */

  int field_width;  /* width of output field */
  int precision;    /* min. # of digits for integers; max
           number of chars for from string */
  int qualifier;    /* 'h', 'l', or 'L' for integer fields */

  for (str=buf ; *fmt ; ++fmt) {
    if (*fmt != '%') {
      *str++ = *fmt;
      continue;
    }

    /* process flags */
    flags = 0;
    repeat:
      ++fmt;    /* this also skips first '%' */
      switch (*fmt) {
        case '-': flags |= LEFT; goto repeat;
        case '+': flags |= PLUS; goto repeat;
        case ' ': flags |= SPACE; goto repeat;
        case '#': flags |= SPECIAL; goto repeat;
        case '0': flags |= ZEROPAD; goto repeat;
        }

    /* get field width */
    field_width = -1;
    if (is_digit(*fmt))
      field_width = skip_atoi(&fmt);
    else if (*fmt == '*') {
      ++fmt;
      /* it's the next argument */
      field_width = va_arg(args, int);
      if (field_width < 0) {
        field_width = -field_width;
        flags |= LEFT;
      }
    }

    /* get the precision */
    precision = -1;
    if (*fmt == '.') {
      ++fmt;
      if (is_digit(*fmt))
        precision = skip_atoi(&fmt);
      else if (*fmt == '*') {
        ++fmt;
        /* it's the next argument */
        precision = va_arg(args, int);
      }
      if (precision < 0)
        precision = 0;
    }

    /* get the conversion qualifier */
    qualifier = -1;
    if (*fmt == 'h' || *fmt == 'l' || *fmt == 'L') {
      qualifier = *fmt;
      ++fmt;
    }

    /* default base */
    base = 10;

    switch (*fmt) {
    case 'c':
      if (!(flags & LEFT))
        while (--field_width > 0)
          *str++ = ' ';
      *str++ = (unsigned char) va_arg(args, int);
      while (--field_width > 0)
        *str++ = ' ';
      continue;

    case 's':
      s = va_arg(args, char *);
//      if (!s)
//        s = "<NULL>";
      len = lstrnlen(s, precision);
      if (!(flags & LEFT))
        while (len < field_width--)
          *str++ = ' ';
      for (i = 0; i < len; ++i)
        *str++ = *s++;
      while (len < field_width--)
        *str++ = ' ';
      continue;

    case 'p':
      if (field_width == -1) {
        field_width = 2*sizeof(void *);
        flags |= ZEROPAD;
      }
      str = number(str,
        (unsigned long) va_arg(args, void *), 16,
        field_width, precision, flags);
      continue;

    case 'n':
      if (qualifier == 'l') {
        long * ip = va_arg(args, long *);
        *ip = (str - buf);
      } else {
        int * ip = va_arg(args, int *);
         *ip = (str - buf);
      }
      continue;

    /* integer number formats - set up the flags and "break" */
    case 'o':
      base = 8;
      break;

    case 'X':
      flags |= LARGE;
    case 'x':
      base = 16;
      break;

    case 'd':
    case 'i':
      flags |= SIGN;
    case 'u':
      break;

    default:
      if (*fmt != '%')
        *str++ = '%';
      if (*fmt)
        *str++ = *fmt;
      else
        --fmt;
      continue;
    }
    if (qualifier == 'l')
      num = va_arg(args, unsigned long);
    else if (qualifier == 'h')
	{
	}
//      if (flags & SIGN)
//        num = va_arg(args, short);
//      else
//        num = va_arg(args, unsigned short);
    else if (flags & SIGN)
    {
      num = va_arg(args, int); 
    } 
    else
      num = va_arg(args, unsigned int);
    str = number(str, num, base, field_width, precision, flags);
  }
  *str = '\0';
  return str-buf;
}






#ifdef sscanf



#define	BUF		513	/* Maximum length of numeric string. */

/*
 * Flags used during conversion.
 */
#define	LONG		0x01	/* l: long or double */
#define	LONGDBL		0x02	/* L: long double; unimplemented */
#define	SHORT		0x04	/* h: short */
#define	QUAD		0x08	/* q: quad */
#define	LONGLONG	0x10	/* ll: long long */
#define	SUPPRESS	0x20	/* suppress assignment */
#define	POINTER		0x40	/* weird %p pointer (`fake hex') */
#define	NOSKIP		0x80	/* do not skip blanks */

/*
 * The following are used in numeric conversions only:
 * SIGNOK, NDIGITS, DPTOK, and EXPOK are for floating point;
 * SIGNOK, NDIGITS, PFXOK, and NZDIGITS are for integral.
 */
#define	SIGNOK		0x080	/* +/- is (still) legal */
#define	NDIGITS		0x100	/* no digits detected */

#define	DPTOK		0x200	/* (float) decimal point is still legal */
#define	EXPOK		0x400	/* (float) exponent (e+3, etc) still legal */

#define	PFXOK		0x200	/* 0x prefix is (still) legal */
#define	NZDIGITS	0x400	/* no zero digits detected */

/*
 * Conversion types.
 */
#define	CT_CHAR		0	/* %c conversion */
#define	CT_CCL		1	/* %[...] conversion */
#define	CT_STRING	2	/* %s conversion */
#define	CT_INT		3	/* integer, i.e., strtoll or strtoull */
#define	CT_FLOAT	4	/* floating, i.e., strtod */

#define u_char unsigned char
#define u_long unsigned long

//static const u_char *__sccl __P((char *, const u_char *));


/*
 * vfscanf
 */
int
__svfscanf(FILE *fp, const char *fmt0, va_list ap)
{
	const u_char *fmt = (const u_char *)fmt0;
	int c;		/* character from format, or conversion */
	size_t width;	/* field width, or 0 */
	char *p;	/* points into all kinds of strings */
	int n;		/* handy integer */
	int flags;	/* flags as defined above */
	char *p0;	/* saves original value of p when necessary */
	int nassigned;		/* number of fields assigned */
	int nread;		/* number of characters consumed from fp */
	int base;		/* base argument to strtoll/strtoull */
	/* LONGLONG */
	unsigned long long int (*ccfn) __P((const char *, char **, int));
				/* conversion function (strtoll/strtoull) */
	char ccltab[256];	/* character class table for %[...] */
	char buf[BUF];		/* buffer for numeric conversions */

	/* `basefix' is used to avoid `if' tests in the integer scanner */
	static const short basefix[17] =
		{ 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };


	nassigned = 0;
	nread = 0;
	base = 0;		/* XXX just to keep gcc happy */
	ccfn = NULL;		/* XXX just to keep gcc happy */
	for (;;) {
		c = *fmt++;
		if (c == 0) {
			return (nassigned);
		}
		if (isspace(c)) {
			while ((fp->_r > 0 || __srefill(fp) == 0) &&
			    isspace(*fp->_p))
				nread++, fp->_r--, fp->_p++;
			continue;
		}
		if (c != '%')
			goto literal;
		width = 0;
		flags = 0;
		/*
		 * switch on the format.  continue if done;
		 * break once format type is derived.
		 */
again:		c = *fmt++;
		switch (c) {
		case '%':
literal:
			if (fp->_r <= 0 && __srefill(fp))
				goto input_failure;
			if (*fp->_p != c)
				goto match_failure;
			fp->_r--, fp->_p++;
			nread++;
			continue;

		case '*':
			flags |= SUPPRESS;
			goto again;
		case 'L':
			flags |= LONGDBL;
			goto again;
		case 'h':
			flags |= SHORT;
			goto again;
		case 'l':
			if (*fmt == 'l') {
				fmt++;
				flags |= LONGLONG;
			} else {
				flags |= LONG;
			}
			goto again;
		case 'q':
			flags |= QUAD;
			goto again;

		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			width = width * 10 + c - '0';
			goto again;

		/*
		 * Conversions.
		 * Those marked `compat' are for 4.[123]BSD compatibility.
		 *
		 * (According to ANSI, E and X formats are supposed
		 * to the same as e and x.  Sorry about that.)
		 */
		case 'D':	/* compat */
			flags |= LONG;
			/* FALLTHROUGH */
		case 'd':
			c = CT_INT;
			/* LONGLONG */
			ccfn = (unsigned long long int (*) __P((const char *, char **, int)))strtoll;
			base = 10;
			break;

		case 'i':
			c = CT_INT;
			/* LONGLONG */
			ccfn = (unsigned long long int (*) __P((const char *, char **, int)))strtoll;
			base = 0;
			break;

		case 'O':	/* compat */
			flags |= LONG;
			/* FALLTHROUGH */
		case 'o':
			c = CT_INT;
			ccfn = strtoull;
			base = 8;
			break;

		case 'u':
			c = CT_INT;
			ccfn = strtoull;
			base = 10;
			break;

		case 'X':
		case 'x':
			flags |= PFXOK;	/* enable 0x prefixing */
			c = CT_INT;
			ccfn = strtoull;
			base = 16;
			break;

		case 's':
			c = CT_STRING;
			break;

		case '[':
			fmt = __sccl(ccltab, fmt);
			flags |= NOSKIP;
			c = CT_CCL;
			break;

		case 'c':
			flags |= NOSKIP;
			c = CT_CHAR;
			break;

		case 'p':	/* pointer format is like hex */
			flags |= POINTER | PFXOK;
			c = CT_INT;
			ccfn = strtoull;
			base = 16;
			break;

		case 'n':
			if (flags & SUPPRESS)	/* ??? */
				continue;
			if (flags & SHORT)
				*va_arg(ap, short *) = nread;
			else if (flags & LONG)
				*va_arg(ap, long *) = nread;
			else
				*va_arg(ap, int *) = nread;
			continue;

		/*
		 * Disgusting backwards compatibility hacks.	XXX
		 */
		case '\0':	/* compat */
			return (EOF);

		default:	/* compat */
			if (isupper(c))
				flags |= LONG;
			c = CT_INT;
			/* LONGLONG */
			ccfn = (unsigned long long int (*) __P((const char *, char **, int)))strtoll;
			base = 10;
			break;
		}

		/*
		 * We have a conversion that requires input.
		 */
		if (fp->_r <= 0 && __srefill(fp))
			goto input_failure;

		/*
		 * Consume leading white space, except for formats
		 * that suppress this.
		 */
		if ((flags & NOSKIP) == 0) {
			while (isspace(*fp->_p)) {
				nread++;
				if (--fp->_r > 0)
					fp->_p++;
				else if (__srefill(fp))
					goto input_failure;
			}
			/*
			 * Note that there is at least one character in
			 * the buffer, so conversions that do not set NOSKIP
			 * ca no longer result in an input failure.
			 */
		}

		/*
		 * Do the conversion.
		 */
		switch (c) {

		case CT_CHAR:
			/* scan arbitrary characters (sets NOSKIP) */
			if (width == 0)
				width = 1;
			if (flags & SUPPRESS) {
				size_t sum = 0;
				for (;;) {
					if ((n = fp->_r) < width) {
						sum += n;
						width -= n;
						fp->_p += n;
						if (__srefill(fp)) {
							if (sum == 0)
							    goto input_failure;
							break;
						}
					} else {
						sum += width;
						fp->_r -= width;
						fp->_p += width;
						break;
					}
				}
				nread += sum;
			} else {
				size_t r = fread((void *)va_arg(ap, char *), 1,
				    width, fp);

				if (r == 0)
					goto input_failure;
				nread += r;
				nassigned++;
			}
			break;

		case CT_CCL:
			/* scan a (nonempty) character class (sets NOSKIP) */
			if (width == 0)
				width = ~0U;	/* `infinity' */
			/* take only those things in the class */
			if (flags & SUPPRESS) {
				n = 0;
				while (ccltab[*fp->_p]) {
					n++, fp->_r--, fp->_p++;
					if (--width == 0)
						break;
					if (fp->_r <= 0 && __srefill(fp)) {
						if (n == 0)
							goto input_failure;
						break;
					}
				}
				if (n == 0)
					goto match_failure;
			} else {
				p0 = p = va_arg(ap, char *);
				while (ccltab[*fp->_p]) {
					fp->_r--;
					*p++ = *fp->_p++;
					if (--width == 0)
						break;
					if (fp->_r <= 0 && __srefill(fp)) {
						if (p == p0)
							goto input_failure;
						break;
					}
				}
				n = p - p0;
				if (n == 0)
					goto match_failure;
				*p = 0;
				nassigned++;
			}
			nread += n;
			break;

		case CT_STRING:
			/* like CCL, but zero-length string OK, & no NOSKIP */
			if (width == 0)
				width = ~0U;
			if (flags & SUPPRESS) {
				n = 0;
				while (!isspace(*fp->_p)) {
					n++, fp->_r--, fp->_p++;
					if (--width == 0)
						break;
					if (fp->_r <= 0 && __srefill(fp))
						break;
				}
				nread += n;
			} else {
				p0 = p = va_arg(ap, char *);
				while (!isspace(*fp->_p)) {
					fp->_r--;
					*p++ = *fp->_p++;
					if (--width == 0)
						break;
					if (fp->_r <= 0 && __srefill(fp))
						break;
				}
				*p = 0;
				nread += p - p0;
				nassigned++;
			}
			continue;

		case CT_INT:
			/* scan an integer as if by strtoll/strtoull */
			/* size_t is unsigned, hence this optimisation */
			if (--width > sizeof(buf) - 2)
				width = sizeof(buf) - 2;
			width++;
			flags |= SIGNOK | NDIGITS | NZDIGITS;
			for (p = buf; width; width--) {
				c = *fp->_p;
				/*
				 * Switch on the character; `goto ok'
				 * if we accept it as a part of number.
				 */
				switch (c) {

				/*
				 * The digit 0 is always legal, but is
				 * special.  For %i conversions, if no
				 * digits (zero or nonzero) have been
				 * scanned (only signs), we will have
				 * base==0.  In that case, we should set
				 * it to 8 and enable 0x prefixing.
				 * Also, if we have not scanned zero digits
				 * before this, do not turn off prefixing
				 * (someone else will turn it off if we
				 * have scanned any nonzero digits).
				 */
				case '0':
					if (base == 0) {
						base = 8;
						flags |= PFXOK;
					}
					if (flags & NZDIGITS)
					    flags &= ~(SIGNOK|NZDIGITS|NDIGITS);
					else
					    flags &= ~(SIGNOK|PFXOK|NDIGITS);
					goto ok;

				/* 1 through 7 always legal */
				case '1': case '2': case '3':
				case '4': case '5': case '6': case '7':
					base = basefix[base];
					flags &= ~(SIGNOK | PFXOK | NDIGITS);
					goto ok;

				/* digits 8 and 9 ok iff decimal or hex */
				case '8': case '9':
					base = basefix[base];
					if (base <= 8)
						break;	/* not legal here */
					flags &= ~(SIGNOK | PFXOK | NDIGITS);
					goto ok;

				/* letters ok iff hex */
				case 'A': case 'B': case 'C':
				case 'D': case 'E': case 'F':
				case 'a': case 'b': case 'c':
				case 'd': case 'e': case 'f':
					/* no need to fix base here */
					if (base <= 10)
						break;	/* not legal here */
					flags &= ~(SIGNOK | PFXOK | NDIGITS);
					goto ok;

				/* sign ok only as first character */
				case '+': case '-':
					if (flags & SIGNOK) {
						flags &= ~SIGNOK;
						goto ok;
					}
					break;

				/* x ok iff flag still set & 2nd char */
				case 'x': case 'X':
					if (flags & PFXOK && p == buf + 1) {
						base = 16;	/* if %i */
						flags &= ~PFXOK;
						goto ok;
					}
					break;
				}

				/*
				 * If we got here, c is not a legal character
				 * for a number.  Stop accumulating digits.
				 */
				break;
		ok:
				/*
				 * c is legal: store it and look at the next.
				 */
				*p++ = c;
				if (--fp->_r > 0)
					fp->_p++;
				else if (__srefill(fp))
					break;		/* EOF */
			}
			/*
			 * If we had only a sign, it is no good; push
			 * back the sign.  If the number ends in `x',
			 * it was [sign] '0' 'x', so push back the x
			 * and treat it as [sign] '0'.
			 */
			if (flags & NDIGITS) {
				if (p > buf)
					(void) ungetc(*(u_char *)--p, fp);
				goto match_failure;
			}
			c = ((u_char *)p)[-1];
			if (c == 'x' || c == 'X') {
				--p;
				(void) ungetc(c, fp);
			}
			if ((flags & SUPPRESS) == 0) {
				/* LONGLONG */
				unsigned long long int res;

				*p = 0;
				res = (*ccfn)(buf, (char **)NULL, base);
				if (flags & POINTER)
					*va_arg(ap, void **) =
					    (void *)(long)res;
				else if (flags & LONGLONG)
					/* LONGLONG */
					*va_arg(ap, long long int *) = res;
				else if (flags & QUAD)
					*va_arg(ap, quad_t *) = (quad_t)res;
				else if (flags & LONG)
					*va_arg(ap, long *) = (long)res;
				else if (flags & SHORT)
					*va_arg(ap, short *) = (short)res;
				else
					*va_arg(ap, int *) = (int)res;
				nassigned++;
			}
			nread += p - buf;
			break;

		}
	}
input_failure:
	return (nassigned ? nassigned : EOF);
match_failure:
	return (nassigned);
}


#endif



