
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


#if !defined(_PLFAPIMUTE_INTERNAL_H_)
#define _PLFAPIMUTE_INTERNAL_H_
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
} muteitfGetAvailableInterfaces;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vmtGetActualMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int red; //out,  
    int green; //out,  
    int blue; //out,  
} vmtGetActualMuteColor;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vmtGetAutoMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vmtGetMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int red; //out,  
    int green; //out,  
    int blue; //out,  
} vmtGetMuteColor;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vmtIsAutoMuteSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int red; //in,  
    int green; //in,  
    int blue; //in,  
    Bool retval; //out,  
} vmtIsMuteColorSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vmtIsMuteSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool mode; //in,  
} vmtSetAutoMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool mode; //in,  
    Bool retval; //out,  
} vmtSetMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int red; //in,  
    int green; //in,  
    int blue; //in,  
} vmtSetMuteColor;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vvmtGetActualMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int red; //out,  
    int green; //out,  
    int blue; //out,  
} vvmtGetActualMuteColor;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vvmtGetAutoMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vvmtGetMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int red; //out,  
    int green; //out,  
    int blue; //out,  
} vvmtGetMuteColor;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vvmtIsAutoMuteSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int red; //in,  
    int green; //in,  
    int blue; //in,  
    Bool retval; //out,  
} vvmtIsMuteColorSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vvmtIsMuteSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool mode; //in,  
} vvmtSetAutoMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool mode; //in,  
    Bool retval; //out,  
} vvmtSetMute;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int red; //in,  
    int green; //in,  
    int blue; //in,  
} vvmtSetMuteColor;

/* argument structures for notifications (requires) */
typedef struct {
    int nbrgroups; //in,  
    Nat32 * ids; //in, data ( sizeof( Nat32 ) * nbrgroups ), dynamic ( sizeof( Nat32 ) * nbrgroups ), 
} muteitfNOnAvailabilityChanged;

#endif /* _PLFAPIMUTE_INTERNAL_H_ */

