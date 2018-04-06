/****************************************************************************
* Purpose : Widget interface
* Module  : Widgets
* Author  : J-M Harvengt
* History : 10/08/97 Creation
****************************************************************************/
#ifndef _WIDGETS
#define _WIDGETS


/****************************************************************************
* Macros / typedefs
****************************************************************************/
typedef enum
{
  WIDTYPE_UNDEFINED                 = 0,
  WIDTYPE_MENU                      = 1,
  WIDTYPE_PANEL                     = 2,
  WIDTYPE_DOCK                      = 3,
  WIDTYPE_BUTTON                    = 4,
  WIDTYPE_LIST                      = 5,
} WidType;


typedef enum
{
  WIDEVENT_UNDEFINED                 = 0,
  WIDEVENT_OPEN                      = 1,
  WIDEVENT_CLOSE                     = 2,
  WIDEVENT_ENTER                     = 3,
  WIDEVENT_LEAVE                     = 4,
  WIDEVENT_PAINT                     = 5,
  WIDEVENT_KEYUP                     = 6,
  WIDEVENT_KEYDOWN                   = 7,
  WIDEVENT_SWIPE                     = 8,
} WidEvent;


typedef enum
{
  WIDCALL_UNDEFINED                  = 0,
  WIDCALL_PROPDATA                   = 1,
  WIDCALL_PROPLEN                    = 2,
  WIDCALL_PROPNEXT                   = 3,
  WIDCALL_PROPPREV                   = 4,
  WIDCALL_PROPGET                    = 5,
  WIDCALL_PROPSET                    = 6,
  WIDCALL_PRESSED                    = 7,
  WIDCALL_RELEASED                   = 8,
} WidCallback;


typedef enum
{
  WIDATTR_UNDEFINED                 = 0x0000,

  WIDATTR_FULLWIDTH                 = 0x0001,
  WIDATTR_FULLHEIGHT                = 0x0002,
  WIDATTR_TEXTURED                  = 0x0004,

  WIDATTR_ALIGNTOP                  = 0x0100+0x00,
  WIDATTR_ALIGNBOTTOM               = 0x0100+0x01,
  WIDATTR_ALIGNLEFT                 = 0x0100+0x02,
  WIDATTR_ALIGNRIGHT                = 0x0100+0x03,

  WIDATTR_LABELRIGHT                = 0x0140+0x00,
  WIDATTR_LABELLEFT                 = 0x0140+0x01,
  WIDATTR_LABELBOTTOM               = 0x0140+0x02,
  WIDATTR_LABELTOP                  = 0x0140+0x03,
} WidAttribute;


#define WIDPARAM_NULL               0,0,0
#define WIDPARAM_1(a)               a,0,0
#define WIDPARAM_4(a,b,c,d)         a, (b<<16) | c, (d<<16) | e 
#define WIDPARAM_5(a,b,c,d,e)       a, (b<<16) | c, (d<<16) | e 

/****************************************************************************
* Exported procedures
****************************************************************************/
extern void wid_Init( char * path );
extern int  wid_CreateParent(int type, char *label, int attributes, int availability, int nbitems, int callback, int param1, int param2, int param3, long link );
extern int  wid_AddChild(int type, char *label, int attributes, int availability, int nbitems, int callback, int param1, int param2, int param3, long link );
extern int  wid_SelectParent(int node);

extern int  wid_Show(int wid);
extern int  wid_SendEvent(int wid, int event, int param);


#endif
