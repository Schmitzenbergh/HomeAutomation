/* 
 * Copyright © 2009, Koninklijke Philips Electronics N.V.
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 * -	Redistributions of source code must retain the above copyright notice, 
 *      this list of conditions and the following disclaimer.
 * -	Redistributions in binary form must reproduce the above copyright 
 *      notice, this list of conditions and the following disclaimer in the 
 *      documentation and/or other materials provided with the distribution.
 * -	Neither the name of the Koninklijke Philips Electronics N.V. nor the 
 *      names of its contributors may be used to endorse or promote products 
 *      derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct/util.h>
#include <jslibrc_client.h>


/**************************************
* Local macros/typedef
**************************************/
#define LINE_LENGTH          256
#define FILENAME_LENGTH      128

// Local enumeration for Hotkeys
#define HK_HOMESCREEN_START     (0x1000+1) 
#define HK_HOMESCREEN_STOP      (0x1000+2) 
#define HK_WATCHTV_START        (0x1000+3) 
#define HK_WATCHTV_STOP         (0x1000+4) 
#define HK_CB_USB_START         (0x1000+5) 
#define HK_CB_USB_STOP          (0x1000+6) 
#define HK_CB_DLNA_START        (0x1000+7) 
#define HK_CB_DLNA_STOP         (0x1000+8) 
#define HK_NETTV_START          (0x1000+9) 
#define HK_NETTV_STOP           (0x1000+10) 
#define HK_DFU_START            (0x1000+11) 
#define HK_DFU_STOP             (0x1000+12) 
#define HK_TELETEXT_START       (0x1000+13) 
#define HK_TELETEXT_STOP        (0x1000+14) 
#define HK_REMOTEAPP_START      (0x1000+15) 
#define HK_REMOTEAPP_STOP       (0x1000+16) 


/***************************************
* Local data
***************************************/
static void * rcButtonMatrix[]={
	(void *)"Red",(void *)"Green",(void *)"Yellow",(void *)"Blue",(void *)"Standby",
	(void *)NULL, (void *)"Back", (void *)"Home",  (void *)"Options",(void *)NULL,
	(void *)NULL, (void *)NULL,   (void *)"Up",    (void *)NULL,  (void *)NULL,
	(void *)"Mute", (void *)"Left", (void *)"OK",    (void *)"Right",(void *)NULL,
	(void *)"VolUp",(void *)NULL, (void *)"Down",  (void *)NULL,  (void *)"PgUp",
	(void *)"VolDn",(void *)"1",  (void *)"2",     (void *)"3",   (void *)"PgDn",
	(void *)NULL, (void *)"4",    (void *)"5",     (void *)"6",   (void *)NULL,
	(void *)NULL, (void *)"7",    (void *)"8",     (void *)"9",   (void *)NULL,
	(void *)NULL, (void *)"Subt.",(void *)"0",     (void *)"Source",(void *)NULL,
	(void *)NULL, (void *)"EPG",  (void *)"Ambi",  (void *)"Info",(void *)NULL,
	(void *)"HK_HOMESCREEN_START",  (void *)"HK_WATCHTV_START",  (void *)"HK_CB_USB_START",  (void *)"HK_CB_DLNA_START", (void *)"HK_NETTV_START",
	(void *)"HK_DFU_START", (void *)"HK_TELETEXT_START", (void *)"HK_REMOTEAPP_START", (void *)NULL, (void *)NULL,
	(void *)"HK_HOMESCREEN_STOP",  (void *)"HK_WATCHTV_STOP",  (void *)"HK_CB_USB_STOP",  (void *)"HK_CB_DLNA_STOP", (void *)"HK_NETTV_STOP",
	(void *)"HK_DFU_STOP", (void *)"HK_TELETEXT_STOP", (void *)"HK_REMOTEAPP_STOP", (void *)NULL, (void *)NULL   };

static int rcButtonMapping[]={
    rc6S0Red, rc6S0Green, rc6S0Yellow, rc6S0Cyan, rc6S0Standby,
    -1, rc6S0PreviousProgram, rc6S0MenuOn, rc6S0Options, -1,
    -1, -1, rc6S0StepUp, -1, -1,
    rc6S0MuteDemute, rc6S0StepLeft, rc6S0Acknowledge, rc6S0StepRight, -1,
    rc6S0VolumeUp, -1, rc6S0StepDown, -1, rc6S0Next,
    rc6S0VolumeDown, 1, 2, 3, rc6S0Previous,
    -1, 4, 5, 6, -1,
    -1, 7, 8, 9, -1,
    -1, rc6S0TvTextSubtitle, 0, rc6S0NextSource, -1,
    -1, rc6S0EpgGuide, rc6S0AmbLightOnOffDim, rc6S0Display, -1,
	HK_HOMESCREEN_START,  HK_WATCHTV_START,  HK_CB_USB_START,  HK_CB_DLNA_START, HK_NETTV_START,
	HK_DFU_START, HK_TELETEXT_START, HK_REMOTEAPP_START, -1, -1,
	HK_HOMESCREEN_STOP,  HK_WATCHTV_STOP,  HK_CB_USB_STOP,  HK_CB_DLNA_STOP, HK_NETTV_STOP,
	HK_DFU_STOP, HK_TELETEXT_STOP, HK_REMOTEAPP_STOP, -1, -1   };



/***************************************
* Local procedures
***************************************/
static int IsNumStr(const char * pStr)
{
    if (*pStr == '-' || *pStr == '+') pStr++;
    return (*pStr >= '0' && *pStr <= '9');
}

static int ReadDimsArg(const char * pArg, int * width, int * height)
{
    int nWidth=1;
    int nHeight=1;

    if (IsNumStr(pArg))                     nWidth  = strtol(pArg, (char **) &pArg, 10); else return 0;
    if ('x' == *pArg++ && IsNumStr(pArg))   nHeight = strtol(pArg, (char **) &pArg, 10); else return 0;
    if (*pArg != '\0') return 0;
    if (nWidth <= 0 || nHeight <= 0) return 0;
    *width = nWidth;
    *height = nHeight;
    return 1;
}

static int ReadNumberArg(const char * pArg, int * value)
{
    int val=0;

    if (IsNumStr(pArg)) val  = strtol(pArg, (char **) &pArg, 10); else return 0;
    *value = val;
    return 1;
}


static int
LookupCommand( const char *name )
{
    int i;

    for (i=0; i<D_ARRAY_SIZE(rcButtonMatrix); i++) {
        if (!rcButtonMatrix[i])
            continue;

        if (!strncasecmp( name, rcButtonMatrix[i], strlen(name) ))
            return rcButtonMapping[i];
    }

    return 0;
}


static void
CleanLine( char *line )
{
	while ( (*line != '\r') && (*line != '\n') && (*line != ';'))
	{
		line++;
	}
	*line = 0;
}


static void 
ExecuteCommand(int command)
{
	switch(command)
	{
	  case HK_HOMESCREEN_START:
	    jslibrc_RequestActivity( amLib_ACT_HomeScreen, amLib_ACT_Start, 0 );
	    break;
	  case HK_HOMESCREEN_STOP:
	    jslibrc_RequestActivity( amLib_ACT_HomeScreen, amLib_ACT_Stop, 0 );
	    break;
	  case HK_WATCHTV_START:
	    jslibrc_RequestActivity( amLib_ACT_WatchTV, amLib_ACT_Start, 0 );
	    break;
	  case HK_WATCHTV_STOP:
	    jslibrc_RequestActivity( amLib_ACT_WatchTV, amLib_ACT_Stop, 0 );
	    break;
	  case HK_CB_USB_START:
	    jslibrc_RequestActivity( amLib_ACT_BrowseUSB, amLib_ACT_Start, 0 );
	    break;
	  case HK_CB_USB_STOP:
	    jslibrc_RequestActivity( amLib_ACT_BrowseUSB, amLib_ACT_Stop, 0 );
	    break;
	  case HK_CB_DLNA_START:
	    jslibrc_RequestActivity( amLib_ACT_BrowseDLNA, amLib_ACT_Start, 0 );
	    break;
	  case HK_CB_DLNA_STOP:
	    jslibrc_RequestActivity( amLib_ACT_BrowseDLNA, amLib_ACT_Stop, 0 );
	    break;
	  case HK_NETTV_START:
	    jslibrc_RequestActivity( amLib_ACT_NetTV, amLib_ACT_Start, 0 );
	    break;
	  case HK_NETTV_STOP:
	    jslibrc_RequestActivity( amLib_ACT_NetTV, amLib_ACT_Stop, 0 );
	    break;
	  case HK_DFU_START:
	    jslibrc_RequestActivity( amLib_ACT_Dfu, amLib_ACT_Start, 0 );
	    break;
	  case HK_DFU_STOP:
	    jslibrc_RequestActivity( amLib_ACT_Dfu, amLib_ACT_Stop, 0 );
	    break;
	  case HK_TELETEXT_START:
	    jslibrc_RequestActivity( amLib_ACT_Teletext, amLib_ACT_Start, 0 );
	    break;
	  case HK_TELETEXT_STOP:
	    jslibrc_RequestActivity( amLib_ACT_Teletext, amLib_ACT_Stop, 0 );
	    break;
	  case HK_REMOTEAPP_START:
	    jslibrc_RequestActivity( amLib_ACT_RemoteApp, amLib_ACT_Start, 0 );
	    break;
	  case HK_REMOTEAPP_STOP:
	    jslibrc_RequestActivity( amLib_ACT_RemoteApp, amLib_ACT_Stop, 0 );
	    break;
	  default:
	    jslibrc_KeyDown( keySourceRc6, 0, command );
	    jslibrc_KeyUp( keySourceRc6, 0, command );
	    break;
	}
}


/***************************************
* Main procedure
***************************************/
int
main (int argc, char *argv[])
{
    int   i,k;
	int   bParseOK = 1;
	char  filename[FILENAME_LENGTH]={'\0'};
    char  line[LINE_LENGTH+1];
	int   timeout;
	FILE  *f;

    jslibrc_Init( &argc, &argv );

	// Print ussage
	printf("\n\n");
	printf("Usage: remco [--keycommandfile <file>] keycommand keycommand ...\n\n");
	printf("Supported key commands:\n");
	k=0;
    for (i=0; i<D_ARRAY_SIZE(rcButtonMatrix); i++) {
        if (!rcButtonMatrix[i])
            continue;
	    printf("'%s' ", rcButtonMatrix[i]);
		k++;
		if ( !(k%4) ) printf("\n");
    }
	printf("\n\n");


	// Parse arguments
    for (i = 1; i < argc && bParseOK; i++)
    {
        const char * pArg = argv[i];
        if ('-' == *pArg++ && '-' == *pArg++)
        {
			if ((0 == strcmp(pArg, "keycommandfile")) && (i + 1 < argc))
            {
                strncpy (filename, argv[i+1], sizeof(filename) );
			    printf("Reading commands from %s\n\n", filename);
			}
            else
            {
                bParseOK = 0;
            }
		}
	}
	if (!bParseOK) exit;


	if (filename[0])
	{
      // Use file as input
      if (f = fopen(filename,"r"))
	  {
        while (fgets(line, LINE_LENGTH, f))
		{
		  if ( (line[0] != 0) && (line[0] != ';') && (line[0] != '#') )
		  {
		    CleanLine(line);
		    printf("%s\n", line);
			if (!strncmp(line, "sleep", 5))
			{
				sscanf(&line[5], "%d", &timeout);	
				sleep(timeout);
			}
			else
			{
		      int command = LookupCommand(line);
              if (command == -1) 
			  {
                printf( "Unknown key command '%s'\n", line );
                continue;
			  }
              ExecuteCommand(command);
			}
		  }
		} 
	    fclose(f);
	  }
	  else
	  {
        printf( "File not found!\n");
	  }
	}
	else
	{
      // Use ARGVs
      for (i=1; i<argc; i++) 
	  {
        int command = LookupCommand( argv[i] );
        if (command == -1) 
		{
            printf( "Unknown key command '%s'!\n", argv[i] );
            continue;
		}
        ExecuteCommand(command);
	  }
	}

    jslibrc_Exit();

    return 0;
}

