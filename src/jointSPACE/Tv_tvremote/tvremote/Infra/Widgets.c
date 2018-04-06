/****************************************************************************
* Purpose : Widget interface
* Module  : Widgets
* Author  : J-M Harvengt
* History : 10/08/97 Creation
****************************************************************************/
#include <gui.h>
#include <ttfdec.h>
#include <std.h>
#include "widgets.h"
#include "keyboard.h"

/***************************************
* Macros/Typedef
***************************************/
#define WID_POOL_SIZE         (256*128)      /* > 128 bytes per widget */

#define DOTSIZE               (16)
#define DOTSTEP               (20) 
#define FONT_SMALL_H          (15)
#define FONT_BIG_H            (30)
#define MARGIN                (16)

#define SCROLL_SPEED5         (16)
#define SCROLL_SPEED4         (8)
#define SCROLL_SPEED3         (4)
#define SCROLL_SPEED2         (2)
#define SCROLL_SPEED1         (1)
#define SCROLL_SPEED0         (0)

#define COL_WIDBACKGROUND     0x00,0x00,0x20, 0xff /* RGBA */

#define BPRESS_DELAY          (5)

typedef struct
{
  int			type;
  char  		*label;
  int			attributes;
  int			(*callback)();
  int			parent;
  int			nbitems;
  int			link;
  int			uid;
  int			available;
  int           param1;
  int           param2;
  int           param3;
  int			x;
  int			y;
  int			w;
  int			h;
  int			(*handler)();
  int			next;
  int			prev;
  int			curitem;
  int           targetscroll;
  int           scroll;
  int           scrollacc;
  int           updated;
} WidgetHeader;

#define WIDGET_HEADER_SIZE (sizeof(WidgetHeader))

typedef struct
{
  int			type;
  char  		*label;
  int			attributes;
  int			(*callback)();
  int			parent;
  int			nbitems;
  int			link;
  int			uid;
  int			available;
  int           param1;
  int           param2;
  int           param3;
  int			x;
  int			y;
  int			w;
  int			h;
  int			(*handler)();
  int			next;
  int			prev;
  int			curitem;
  int           targetscroll;
  int           scroll;
  int           scrollacc;
  int           updated;
  int           itemPt[0];
} Widget;

/***************************************
* Local procedures declaration
***************************************/


/***************************************
* Local variables
***************************************/
/* Menu constructors */
static unsigned char   widgetPool[WID_POOL_SIZE];
static unsigned char   * poolPt = widgetPool; 
static int             * itemPt;
static int             * prevChildPt;
static int             curChild;
static WidgetHeader    * curWidgetPt;


static char            datapath[256]; 
static char            filename[256]; 
static GuiBitmap       *frameBuffer;
static GuiBitmap       dot;
static GuiBitmap       dotSelected;
static GuiBitmap       separator;
static GTTFnt          fontsmallwhite, fontsmallblack;



/***************************************
* Local procedures
***************************************/
static int menuHandler(Widget * wptr, WidEvent event, int param)
{
	Widget * childwptr;
	GuiRect rectangle;
	int i;
	int xoffset;
	int retval = 0;

	switch(event)
	{
		case WIDEVENT_PAINT:
			wptr->updated = 0;
			if (wptr->nbitems)
			{
//printf("PAINT menu\n");
				childwptr = (Widget *)wptr->itemPt[wptr->curitem];
                wptr->updated = childwptr->handler(childwptr, WIDEVENT_PAINT,0);
				rectangle.y=frameBuffer->h-DOTSIZE-MARGIN;
				xoffset = (frameBuffer->w - DOTSTEP*wptr->nbitems)/2;
				for (i=0; i<wptr->nbitems; i++)
				{
					rectangle.x=xoffset+i*DOTSTEP;
					if (i == wptr->curitem)
					{
						gui_BitmapBlit(GUIBLF_COLORKEYED, frameBuffer, &dotSelected, &rectangle );
					}
					else
					{
						gui_BitmapBlit(GUIBLF_COLORKEYED, frameBuffer, &dot, &rectangle );
					}
				}
				retval = wptr->updated;
			}
			break;
		case WIDEVENT_KEYDOWN:
			if (wptr->nbitems) 
			{
//printf("EVENT menu\n");
				switch(param)
				{
					case KEY_RIGHT:
						if (wptr->curitem < (wptr->nbitems-1))
						{
							wptr->curitem++;
							retval = 1;
						}
						break;
					case KEY_LEFT:
						if (wptr->curitem)
						{
							wptr->curitem--;
							retval = 1;
						}
						break;
					default:
						/* Pass to child */
						childwptr = (Widget *)wptr->itemPt[wptr->curitem];
						retval = childwptr->handler(childwptr, event,param);
						break;
				}
				wptr->updated = retval;
			}
			break;
		case WIDEVENT_SWIPE:
			if (wptr->nbitems) 
			{
//printf("EVENT menu\n");
				/* Pass to child */
				childwptr = (Widget *)wptr->itemPt[wptr->curitem];
				retval = childwptr->handler(childwptr, event,param);
				if (!retval) switch(param & 0xffff)
				{
					case TOUCH_SWIPE_LEFT:
						if (wptr->curitem < (wptr->nbitems-1))
						{
							wptr->curitem++;
							retval = 1;
						}
						break;
					case TOUCH_SWIPE_RIGHT:
						if (wptr->curitem)
						{
							wptr->curitem--;
							retval = 1;
						}
						break;
					default:
						break;
				}
				wptr->updated = retval;
			}
			break;
		default:
			break;
	}
	return(retval);
}
static int panelHandler(Widget * wptr, WidEvent event, int param)
{
	int retval = 0;
	Widget * childwptr;
	int i;

	switch(event)
	{
		case WIDEVENT_PAINT:
//printf("PAINT panel\n");
			gui_BitmapClear(frameBuffer, COL_WIDBACKGROUND);
			wptr->updated = 0;
			for (i=0; i<wptr->nbitems; i++)
			{
				childwptr = (Widget *)wptr->itemPt[i];
                wptr->updated |= childwptr->handler(childwptr, WIDEVENT_PAINT,0);
			}
			break;
		case WIDEVENT_SWIPE:
			wptr->updated = 0;
			i=0;
			while ( (!wptr->updated) && (i<wptr->nbitems) )
			{
				childwptr = (Widget *)wptr->itemPt[i];
                wptr->updated = childwptr->handler(childwptr, WIDEVENT_SWIPE, param);
				i++;
			}
			break;

		default:
			break;
	}
	retval = wptr->updated;
	return(retval);
}
static int dockHandler(Widget * wptr, WidEvent event, int param)
{
	int retval = 0;

	return(retval);
}
static int buttonHandler(Widget * wptr, WidEvent event, int param)
{
	int retval = 0;
	GuiRect rectangle;
	int x,y,b;

	switch(event)
	{
		case WIDEVENT_PAINT:
//printf("PAINT button %d\n",wptr->param1);
			rectangle.x = wptr->param2 >> 16;
			rectangle.y = wptr->param2 & 0xffff;
			rectangle.w = 0;
			rectangle.h = 0;
			if (wptr->curitem)
			{
				gui_BitmapBlit(GUIBLF_COLORKEYED, frameBuffer, gui_BitmapGetFromCache(wptr->param1+1, wptr->param3 >> 16, wptr->param3 & 0xffff, frameBuffer->format), &rectangle );
				wptr->curitem -= 1;
			    wptr->updated = 1;
                retval = 1;
			}
			else
			{
	            gui_BitmapBlit(GUIBLF_COLORKEYED, frameBuffer, gui_BitmapGetFromCache(wptr->param1, wptr->param3 >> 16, wptr->param3 & 0xffff, frameBuffer->format), &rectangle );
			}
			break;
		case WIDEVENT_SWIPE:
            rectangle.x = wptr->param2 >> 16;
            rectangle.y = wptr->param2 & 0xffff;
			rectangle.w = wptr->param3 >> 16;
			rectangle.h = wptr->param3 & 0xffff;
			key_GetMouseMove(&x,&y,&b);
			if (  ( x > rectangle.x ) && ( x <= (rectangle.x + rectangle.w) )
					&&( y > rectangle.y ) && ( y <= (rectangle.y + rectangle.h) ) && (wptr->callback) )
			{
				if ( (param & 0xffff) == TOUCH_SWIPE_TOUCH )
				{
//printf("SWIPE button %d\n",wptr->param1);
						wptr->callback(WIDCALL_PROPSET,wptr->param1);
						wptr->updated = 1;
						wptr->curitem = BPRESS_DELAY;
						retval = 1;
				}
				else
				{
					if ( wptr->callback(WIDCALL_PROPGET, wptr->param1<<16 | (param & 0xffff) ) )
						retval = 1;
				}
			}
			break;
		default:
			break;
	}

	return(retval);
}
static int listHandler(Widget * wptr, WidEvent event, int param)
{
	int retval = 0;
	char * * listData;
	char * emptyData;
	GuiRect rectangle;
	int listIndex;
	int listLen;
	int nbRow;
	int i,j;
	int y,h;
	int x,b;
	int delta;

	switch(event)
	{
		case WIDEVENT_PAINT:
//printf("PAINT list\n");
			if (wptr->callback)
			{
			    wptr->updated = 1;
//			    gui_BitmapClear(frameBuffer, COL_WIDBACKGROUND);
				emptyData = wptr->callback(WIDCALL_UNDEFINED,0);
				listData  = wptr->callback(WIDCALL_PROPDATA,0);
				listLen   = wptr->callback(WIDCALL_PROPLEN,0);
				listIndex = wptr->callback(WIDCALL_PROPGET,0);
				nbRow     = wptr->param1;

				delta = wptr->targetscroll - wptr->scroll;
				if (!delta)
				{
					wptr->scrollacc = SCROLL_SPEED0;
					wptr->updated = 0;
				}
				else
				{
					if (delta < 0)
					{
						delta = -delta;
						wptr->scroll -= wptr->scrollacc;
						if (wptr->scroll < wptr->targetscroll) wptr->scroll = wptr->targetscroll;
					}
					else
					{
						wptr->scroll += wptr->scrollacc;
						if (wptr->scroll > wptr->targetscroll) wptr->scroll = wptr->targetscroll;
					}
					if (delta <= 8)
					{
						wptr->scrollacc = SCROLL_SPEED1;
					} else if (delta <= 16)
					{
						wptr->scrollacc = SCROLL_SPEED2;
					} else if (delta <= 32)
					{
						wptr->scrollacc = SCROLL_SPEED3;
					} else if (delta <= 64)
					{
						wptr->scrollacc = SCROLL_SPEED4;
					}
				}  
				if (listLen)
				{
					// Draw visible items
					j = (wptr->scroll * nbRow)/frameBuffer->h;
					if (j) j--;
					for(i=j; i<listLen; i++)
					{
						y = (i*frameBuffer->h)/nbRow;
						h = ((i+1)*frameBuffer->h)/nbRow-y;
						y -= wptr->scroll;
						if (y > frameBuffer->h) break;
						j++;
						rectangle.x = 0;
						rectangle.y = y;
						rectangle.h = h;
						rectangle.w = frameBuffer->w;
						if (i == listIndex )
						{
							gui_BitmapFillRectangle(frameBuffer, &rectangle, 0xff,0xff,0xff, 0xff);
						    ttf_FontDrawString(MARGIN, y+(h-FONT_SMALL_H)/2,listData[i], &fontsmallblack, frameBuffer);
						}
						else
						{
							gui_BitmapFillRectangle(frameBuffer, &rectangle, COL_WIDBACKGROUND);
						    ttf_FontDrawString(MARGIN, y+(h-FONT_SMALL_H)/2,listData[i], &fontsmallwhite, frameBuffer);
							rectangle.x = (frameBuffer->w-separator.w)/2;
							rectangle.y = y+h-2;
							//rectangle.h = h;
							//rectangle.w = frameBuffer->w;
							gui_BitmapBlit(GUIBLF_COLORKEYED, frameBuffer, &separator, &rectangle );
						}
					}
					// Clear the rest
					while (j<nbRow)
					{
						y = (i*frameBuffer->h)/nbRow;
						h = ((i+1)*frameBuffer->h)/nbRow-y;
						y -= wptr->scroll;
						if (y > frameBuffer->h) break;
						rectangle.x = 0;
						rectangle.y = y;
						rectangle.h = h;
						rectangle.w = frameBuffer->w;
						gui_BitmapFillRectangle(frameBuffer, &rectangle, COL_WIDBACKGROUND);
						j++;
						i++;
					}
				}
				else
				{
			        gui_BitmapClear(frameBuffer, COL_WIDBACKGROUND);
					if (emptyData)
					  ttf_FontDrawString(MARGIN, MARGIN, emptyData, &fontsmallwhite, frameBuffer);
				}
				retval = wptr->updated;
			}
			break;
		case WIDEVENT_KEYDOWN:
			if (wptr->callback) 
			{	
//printf("EVENT list\n");
				listLen   = wptr->callback(WIDCALL_PROPLEN,0);
				nbRow     = wptr->param1;
				switch(param)
				{
					case KEY_UP:
						retval = wptr->callback(WIDCALL_PROPPREV,0);
						if (retval)
						{
							listIndex = wptr->callback(WIDCALL_PROPGET,0);
							if ( (listLen > nbRow) && ( (listIndex+nbRow) <= listLen) )
							{
								wptr->targetscroll = (frameBuffer->h*listIndex)/nbRow;
							}
							wptr->scrollacc = SCROLL_SPEED5;
						}
						break;
					case KEY_DOWN:
						retval = wptr->callback(WIDCALL_PROPNEXT,0);
						if (retval)
						{
							listIndex = wptr->callback(WIDCALL_PROPGET,0);
							if ( (listLen > nbRow) && ( (listIndex+nbRow) <= listLen) )
							{
								wptr->targetscroll = (frameBuffer->h*listIndex)/nbRow;
							}
							wptr->scrollacc = SCROLL_SPEED5;
						}
						break;
					default:
						break;
				}
				wptr->updated = retval;
			}
			break;
		case WIDEVENT_SWIPE:
			if (wptr->callback) 
			{	
				listLen   = wptr->callback(WIDCALL_PROPLEN,0);
				nbRow     = wptr->param1;
				switch(param & 0xffff)
				{
					case TOUCH_SWIPE_UP:
						if (listLen > nbRow)
						{
							wptr->targetscroll = wptr->scroll + frameBuffer->h;
							if (wptr->targetscroll >= ((frameBuffer->h*listLen)/nbRow-frameBuffer->h))
							{
								wptr->targetscroll = (frameBuffer->h*listLen)/nbRow-frameBuffer->h;
							}
							wptr->scrollacc = SCROLL_SPEED5;
							retval = 1;
						}
						break;
					case TOUCH_SWIPE_DOWN:
						if (listLen > nbRow)
						{
							wptr->targetscroll = wptr->scroll - frameBuffer->h;
							if (wptr->targetscroll < 0)
							{
								wptr->targetscroll = 0;
							}
							wptr->scrollacc = SCROLL_SPEED5;
							retval = 1;
						}
						break;
					case TOUCH_SWIPE_TOUCH:
						key_GetMouseMove(&x,&y,&b);
						if ( (((wptr->scroll + y)*nbRow)/(frameBuffer->h)) < listLen )
						{
							wptr->callback(WIDCALL_PROPSET,((wptr->scroll + y)*nbRow)/(frameBuffer->h));
							retval = 1;
						}
						break;
					default:
						break;
				}
				wptr->updated = retval;
			}
			break;
		default:
			break;
	}
	return(retval);
}



/***************************************
* Exported procedures
***************************************/
void wid_Init( char * path )
{
	memset((void*)widgetPool, 0, WID_POOL_SIZE);
	poolPt = widgetPool;
	if (path) std_strcpy(datapath, path);
    gui_BitmapGetFramebuffer(&frameBuffer);
	std_strcpy(filename, datapath);
	std_strcat(filename,"dots.png");
    gui_BitmapCreate (GUIBIF_CREATEFROMFILE, DOTSIZE,DOTSIZE, 0, frameBuffer->format, filename, &dotSelected);
	std_strcpy(filename, datapath);
	std_strcat(filename,"dot.png");
    gui_BitmapCreate (GUIBIF_CREATEFROMFILE, DOTSIZE,DOTSIZE, 0, frameBuffer->format, filename, &dot);
	std_strcpy(filename, datapath);
	std_strcat(filename,"separator.png");
    gui_BitmapCreate (GUIBIF_CREATEFROMFILE, (frameBuffer->w*4)/5,2, 0, frameBuffer->format, filename, &separator);
	std_strcpy(filename, datapath);
	std_strcat(filename,"decker.ttf");
	ttf_FontCreate(filename, FONT_SMALL_H, FONT_SMALL_H, FONT_SMALL_H, frameBuffer->format, 0xff, 0xff,0xff,0xff, &fontsmallwhite );
	ttf_FontCreate(filename, FONT_SMALL_H, FONT_SMALL_H, FONT_SMALL_H, frameBuffer->format, 0xff, 0x00,0x00,0xff, &fontsmallblack );
}






int wid_CreateParent(int type, char *label, int attributes, int availability, int nbitems, 
					 int callback, int param1, int param2, int param3,  long link )
{
  curWidgetPt             = (WidgetHeader *)poolPt;
  curWidgetPt->type       = type;
  curWidgetPt->label      = label;
  curWidgetPt->attributes = attributes;
  curWidgetPt->callback   = callback;
  curWidgetPt->available  = availability;
  curWidgetPt->nbitems    = nbitems;
  curWidgetPt->parent     = 0;
  curWidgetPt->param1     = param1;
  curWidgetPt->param2     = param2;
  curWidgetPt->param3     = param3;
  curWidgetPt->link       = link;
  curWidgetPt->curitem    = 0;
  switch (type)
  {
      case WIDTYPE_MENU:
          curWidgetPt->handler = menuHandler;
          break;
      case WIDTYPE_PANEL:
          curWidgetPt->handler = panelHandler;
          break;
      case WIDTYPE_DOCK:
          curWidgetPt->handler = dockHandler;
          break;
      case WIDTYPE_BUTTON:
          curWidgetPt->handler = buttonHandler;
          break;
      case WIDTYPE_LIST:
          curWidgetPt->handler = listHandler;
          break;
  }
  curWidgetPt->prev       = 0;
  curWidgetPt->next       = 0;
  poolPt += WIDGET_HEADER_SIZE;
  itemPt = (int *)poolPt;
  poolPt += (nbitems*sizeof(int));
  curChild=0;
  return((int)curWidgetPt);
}


int wid_SelectParent(int node)
{
  curWidgetPt = (WidgetHeader *)node;
  itemPt = (int *)((unsigned char *)curWidgetPt + WIDGET_HEADER_SIZE);
  curChild=0;
  return((int)curWidgetPt);
}


int wid_AddChild(int type, char *label, int attributes, int availability, int nbitems, 
			     int callback, int param1, int param2, int param3, long link )

{
  WidgetHeader * thisWidget;
  thisWidget             = (WidgetHeader *)poolPt;
  thisWidget->type       = type;
  thisWidget->label      = label;
  thisWidget->attributes = attributes;
  thisWidget->callback   = callback;
  thisWidget->available  = availability;
  thisWidget->nbitems    = nbitems;
  thisWidget->parent     = (int)curWidgetPt;
  thisWidget->param1     = param1;
  thisWidget->param2     = param2;
  thisWidget->param3     = param3;
  thisWidget->link       = link;
  thisWidget->curitem    = 0;
  switch (type)
  {
      case WIDTYPE_MENU:
          thisWidget->handler = menuHandler;
          break;
      case WIDTYPE_PANEL:
          thisWidget->handler = panelHandler;
          break;
      case WIDTYPE_DOCK:
          thisWidget->handler = dockHandler;
          break;
      case WIDTYPE_BUTTON:
          thisWidget->handler = buttonHandler;
          break;
      case WIDTYPE_LIST:
          thisWidget->handler = listHandler;
          break;
  }
  if (curChild)
	thisWidget->prev     = (int)prevChildPt;
  else
	thisWidget->prev     = 0;
  *itemPt = (int)thisWidget;
  itemPt++;
  prevChildPt = (int *)thisWidget;
  poolPt += (WIDGET_HEADER_SIZE + nbitems*sizeof(int));
  curChild++;
  if (curChild != curWidgetPt->nbitems)
    thisWidget->next     = (int)poolPt;
  else
    thisWidget->next     = 0;
  return((int)thisWidget);
}


int wid_Show(int wid)
{
  Widget * wptr = (Widget*)wid;
  int retval;

  retval = wptr->handler(wptr, WIDEVENT_PAINT,0);

  return(retval);

//  return(wptr->handler(wptr, WIDEVENT_PAINT,0));
}

int wid_SendEvent(int wid, int event, int param)
{
  Widget * wptr = (Widget*)wid;

  return(wptr->handler(wptr, event,param));
}











