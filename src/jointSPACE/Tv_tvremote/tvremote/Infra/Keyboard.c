/****************************************************************************
* Purpose : Keyboard input driver.
* Module  : Keyboard
* Author  : J-M Harvengt
* History : 10/08/97 Creation
****************************************************************************/
#include "keyboard.h"

/**************************************
* Local macros/typedef
**************************************/
typedef struct
{
  int source;
  int key;
  int keyPressed;
} keyEntry;

#define SWIPE_THRESHOLD   30


/***************************************
* Local procedures definition
***************************************/

/***************************************
* Global data
***************************************/

/***************************************
* Local data
***************************************/
static keyEntry keyQueue[256];
static int keyIn;
static int keyOut;
static int keyb_key;
static int old_j_key; 
static int j_key; 
static int mouseX;
static int mouseY;
static int mouseB;
static int oldmouseB;
static int originmouseX;
static int originmouseY;
static int firstmouseM;

static int  (*notifyKeyUp)(int aSource, int aKey);
static int  (*notifyKeyDown)(int aSource, int aKey);

/***************************************
* Exported procedures
***************************************/
/***************************************
* Purpose : Initialization.
***************************************/
void key_Init(void)
{
  keyIn        = 0;
  keyOut       = 0;
  keyb_key     = 0;
  old_j_key    = 0; 
  j_key        = 0; 
  mouseX       = 0;
  mouseY       = 0;
  mouseB       = 0;
  oldmouseB    = 0;
  originmouseX = 0;
  originmouseY = 0;
  firstmouseM  = 0;
  notifyKeyUp  = 0;
  notifyKeyDown= 0;
}


/***************************************
* Purpose : Other.
***************************************/
/**************************************/
void key_OnKeyDown(int aSource, int aKey)
/**************************************
 * Parameters : None
 * Purpose    : 
 **************************************/
{
  if (aSource == SOURCE_KEYB) switch(aKey)
  {
    case KEY_LEFT:
     j_key = j_key | JKEY_PLEFT;
     break;
    case KEY_RIGHT:
     j_key = j_key | JKEY_PRIGHT;
     break;
    case KEY_UP:
     j_key = j_key | JKEY_PUP;
     break;
    case KEY_DOWN:
     j_key = j_key | JKEY_PDOWN;
     break;
    case KEY_SPACE: 
     j_key = j_key | JKEY_PSPACE;
     break;
    case KEY_FZERO:
     j_key = j_key | JKEY_PZERO;
     break;
    case KEY_FONE:
     j_key = j_key | JKEY_PONE;
     break;
    case KEY_FTWO:
     j_key = j_key | JKEY_PTWO;
     break;
    case KEY_FTHREE:
     j_key = j_key | JKEY_PTHREE;
     break;
    case KEY_FFOUR:
     j_key = j_key | JKEY_PFOUR;
     break;
    case KEY_FFIVE:
     j_key = j_key | JKEY_PFIVE;
     break;
    case KEY_FSIX:
     j_key = j_key | JKEY_PSIX;
     break;
    case KEY_FSEVEN:
     j_key = j_key | JKEY_PSEVEN;
     break;
    case KEY_FEIGHT:
     j_key = j_key | JKEY_PEIGHT;
     break;
    case KEY_FNINE:
     j_key = j_key | JKEY_PNINE;
     break;
	default:
	 break;
  }
  if (aKey != KEY_UNKNOWN)
  {
    keyQueue[keyIn].key        = aKey;
    keyQueue[keyIn].source     = aSource;
    keyQueue[keyIn].keyPressed = 1;
    keyIn++; keyIn &= 255; 
  }
}

/**************************************/
void key_OnKeyUp(int aSource, int aKey)
/**************************************
 * Parameters : None
 * Purpose    : 
 **************************************/
{
#if ( (VIPER) && (!LINUX) )
	j_key = 0;
#else
  if (aSource == SOURCE_KEYB) switch(aKey)
  {
    case KEY_LEFT:
     j_key = j_key & ~JKEY_PLEFT;
     break;
    case KEY_RIGHT:
     j_key = j_key & ~JKEY_PRIGHT;
     break;
    case KEY_UP:
     j_key = j_key & ~JKEY_PUP;
     break;
    case KEY_DOWN:
     j_key = j_key & ~JKEY_PDOWN;
     break;
    case KEY_SPACE: 
     j_key = j_key & ~JKEY_PSPACE;
     break;
    case KEY_ZERO:
     j_key = j_key & ~JKEY_PZERO;
     break;
    case KEY_FONE:
     j_key = j_key & ~JKEY_PONE;
     break;
    case KEY_FTWO:
     j_key = j_key & ~JKEY_PTWO;
     break;
    case KEY_FTHREE:
     j_key = j_key & ~JKEY_PTHREE;
     break;
    case KEY_FFOUR:
     j_key = j_key & ~JKEY_PFOUR;
     break;
    case KEY_FFIVE:
     j_key = j_key & ~JKEY_PFIVE;
     break;
    case KEY_FSIX:
     j_key = j_key & ~JKEY_PSIX;
     break;
    case KEY_FSEVEN:
     j_key = j_key & ~JKEY_PSEVEN;
     break;
    case KEY_FEIGHT:
     j_key = j_key & ~JKEY_PEIGHT;
     break;
    case KEY_FNINE:
     j_key = j_key & ~JKEY_PNINE;
     break;
	default:
	 break;
  }
#endif
  if (aKey != KEY_UNKNOWN)
  {
    keyQueue[keyIn].key        = aKey;
    keyQueue[keyIn].source     = aSource;
    keyQueue[keyIn].keyPressed = 0;
    keyIn++; keyIn &= 255;
  }
}

/**************************************/
void key_SubscribeKeyUp( void * callback)
/**************************************
 * Parameters : None
 * Purpose    :
 **************************************/
{
  notifyKeyUp = callback;
}

/**************************************/
void key_SubscribeKeyDown( void * callback)
/**************************************
 * Parameters : None
 * Purpose    :
 **************************************/
{
  notifyKeyDown = callback;
}

/**************************************/
int key_OnKeyTimer(void)
/**************************************
 * Parameters : None
 * Purpose    :
 **************************************/
{
  int retval = 0;
  int temp; 

  temp = ((j_key ^ old_j_key) & j_key);
  old_j_key = j_key;
  keyb_key = (temp << 16) | j_key;

  if (keyIn != keyOut)
  {
    if (keyQueue[keyOut].keyPressed)
    {
      if (notifyKeyDown)
        retval = notifyKeyDown( keyQueue[keyOut].source, keyQueue[keyOut].key );
    }
    else
    {
      if (notifyKeyUp)
        retval = notifyKeyUp( keyQueue[keyOut].source, keyQueue[keyOut].key );
    }
    keyOut++; keyOut &= 255;
  }

  return(retval);
}

/**************************************/
int key_GetKeyPad(void)
/**************************************
 * Parameters : None
 * Purpose    :
 **************************************/
{
  return(keyb_key);
}



void key_OnMouseMove(int x, int y, int b)
{
	int	dir=TOUCH_SWIPE_UNDEFINED;
	int	swipestep = 0;
	int dx;
	int dy;
	mouseX=x;
	mouseY=y;
	mouseB=b;

	if ( (!oldmouseB) && (b) ) /* Set origin at touch/click */
	{
		firstmouseM++;
		originmouseX = x;
		originmouseY = y;
//printf("Pressed\n");
	}
	else if ( (oldmouseB) && (!b) ) /* Get swipe length at release */
	{
//printf("Released\n");
		firstmouseM = 0;
        dir=TOUCH_SWIPE_UNDEFINED;
		swipestep = 0;
		dx = x-originmouseX;
		dy = y-originmouseY;
		if (dx > 0)
		{
			if (dy > 0)
			{
				if (dy > dx) {dir = TOUCH_SWIPE_DOWN; swipestep = dy;}
				else {dir = TOUCH_SWIPE_RIGHT; swipestep = dx;}
			}
			else
			{
				if (-dy > dx) {dir = TOUCH_SWIPE_UP; swipestep = -dy;}
				else {dir = TOUCH_SWIPE_RIGHT; swipestep = dx;}
			}
		}
		else
		{
			if (dy > 0)
			{
				if (dy > -dx) {dir = TOUCH_SWIPE_DOWN; swipestep = dy;}
				else {dir = TOUCH_SWIPE_LEFT; swipestep = -dx;}
			}
			else
			{
				if (-dy > -dx) {dir = TOUCH_SWIPE_UP; swipestep = -dy;}
				else {dir = TOUCH_SWIPE_LEFT; swipestep = -dx;}
			}
		}


        if ( (dir != TOUCH_SWIPE_UNDEFINED) && (swipestep > SWIPE_THRESHOLD) ) 
			key_OnKeyDown(SOURCE_TOUCH, (swipestep<<16)|dir);
		else
			key_OnKeyDown(SOURCE_TOUCH, TOUCH_SWIPE_TOUCH);
	}
	else if (firstmouseM == 1) /* First motion after touch/click (fix if motion only available after touch)  */
	{
//printf("Moved\n");
		firstmouseM = 0;
		originmouseX = x;
		originmouseY = y;
	}

	oldmouseB = b;
}


void key_GetMouseMove(int *x, int *y, int *b)
{
	*x=mouseX;
	*y=mouseY;
	*b=mouseB;
}

