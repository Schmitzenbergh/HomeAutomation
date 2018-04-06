
/*
 * (c) 2010 Koninklijke Philips Electronics N.V., All rights reserved
 * 
 * This source code and any compilation or derivative thereof is the
 * proprietary information of Koninklijke Philips Electronics N.V. and is
 * confidential in nature.
 * Under no circumstances is this software to be exposed to or placed under an
 * Open Source License of any type without the expressed written permission of
 * Koninklijke Philips Electronics N.V.
 */


#if !defined(_PLFAPISCALE_INTERNAL_H_)
#define _PLFAPISCALE_INTERNAL_H_
#if defined(USE_WEAK_NOTIFICATIONS)
#define WEAK __attribute__((weak))
#else
#define WEAK /* nothing */
#endif

/*  argument structures for calls (provides) */
typedef struct {
    unsigned int callcookie;
    int nbrgroups; //out,  
    Nat32 ids[5]; //out, data ( sizeof( Nat32 ) * 5 ), 
} scaleitfGetAvailableInterfaces;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int videox; //in,  
    int videoy; //in,  
    int graphicsx; //out,  
    int graphicsy; //out,  
} vscConvertVideoToGraphicsPosition;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vscGetMaxHorScalingFactor;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vscGetMaxVerScalingFactor;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vscGetMinHorScalingFactor;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vscGetMinInputHeight;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vscGetMinInputWidth;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vscGetMinOutputHeight;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vscGetMinOutputWidth;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vscGetMinVerScalingFactor;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int inputx; //in,  
    int inputy; //in,  
    int inputwidth; //in,  
    int inputheight; //in,  
    int outputx; //in,  
    int outputy; //in,  
    int outputwidth; //in,  
    int outputheight; //in,  
    int wss; //in,  
    int action; //in,  
    Bool retval; //out,  
} vscIsVideoPositionAllowed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int inputx; //in,  
    int inputy; //in,  
    int inputwidth; //in,  
    int inputheight; //in,  
    int outputx; //in,  
    int outputy; //in,  
    int outputwidth; //in,  
    int outputheight; //in,  
    int wss; //in,  
    int action; //in,  
    Bool retval; //out,  
} vscIsVideoPositionSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int inputx; //in,  
    int inputy; //in,  
    int inputwidth; //in,  
    int inputheight; //in,  
    int outputx; //in,  
    int outputy; //in,  
    int outputwidth; //in,  
    int outputheight; //in,  
    int wss; //in,  
    int action; //in,  
    Bool retval; //out,  
} vscSetVideoPosition;

/* argument structures for notifications (requires) */
typedef struct {
    int nbrgroups; //in,  
    Nat32 * ids; //in, data ( sizeof( Nat32 ) * nbrgroups ), dynamic ( sizeof( Nat32 ) * nbrgroups ), 
} scaleitfNOnAvailabilityChanged;

#endif /* _PLFAPISCALE_INTERNAL_H_ */

