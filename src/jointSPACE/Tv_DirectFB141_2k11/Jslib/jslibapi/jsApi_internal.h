
/*
 * (c) 2011 Koninklijke Philips Electronics N.V., All rights reserved
 * 
 * This source code and any compilation or derivative thereof is the
 * proprietary information of Koninklijke Philips Electronics N.V. and is
 * confidential in nature.
 * Under no circumstances is this software to be exposed to or placed under an
 * Open Source License of any type without the expressed written permission of
 * Koninklijke Philips Electronics N.V.
 */


#if !defined(_JSAPI_INTERNAL_H_)
#define _JSAPI_INTERNAL_H_
#if defined(USE_WEAK_NOTIFICATIONS)
#define WEAK __attribute__((weak))
#else
#define WEAK /* nothing */
#endif

/*  argument structures for calls (provides) */
typedef struct {
    unsigned int callcookie;
    int topology; //out,  
    int nbrofsegmentsx; //out,  
    int nbrofsegmentsy; //out,  
    int nbrofsegmentsz; //out,  
    int version; //out,  
} jsAmbiGetConfiguration;

typedef struct {
    unsigned int callcookie;
    int mode; //out,  
} jsAmbiGetMode;

typedef struct {
    unsigned int callcookie;
    int side; //in,  
    int nbrofpixels; //out,  
} jsAmbiGetNbrOfPixelsPerSide;

typedef struct {
    unsigned int callcookie;
    int side; //in,  
    int index; //in,  
    int red; //out,  
    int green; //out,  
    int blue; //out,  
} jsAmbiGetPixel;

typedef struct {
    unsigned int callcookie;
    int side; //in,  
    int startindex; //in,  
    int size; //in,  
    int * red; //out, data ( sizeof( int ) * size ), dynamic ( sizeof( int ) * size ), 
    int * green; //out, data ( sizeof( int ) * size ), dynamic ( sizeof( int ) * size ), 
    int * blue; //out, data ( sizeof( int ) * size ), dynamic ( sizeof( int ) * size ), 
} jsAmbiGetPixelArray;

typedef struct {
    unsigned int callcookie;
    int side; //in,  
    int index; //in,  
    int red; //out,  
    int green; //out,  
    int blue; //out,  
} jsAmbiGetRawPixel;

typedef struct {
    unsigned int callcookie;
    int side; //in,  
    int startindex; //in,  
    int size; //in,  
    int * red; //out, data ( sizeof( int ) * size ), dynamic ( sizeof( int ) * size ), 
    int * green; //out, data ( sizeof( int ) * size ), dynamic ( sizeof( int ) * size ), 
    int * blue; //out, data ( sizeof( int ) * size ), dynamic ( sizeof( int ) * size ), 
} jsAmbiGetRawPixelArray;

typedef struct {
    unsigned int callcookie;
    int mode; //in,  
    Bool retval; //out,  
} jsAmbiIsModeSupported;

typedef struct {
    unsigned int callcookie;
    int mode; //in,  
} jsAmbiSetMode;

typedef struct {
    unsigned int callcookie;
    int side; //in,  
    int index; //in,  
    int red; //in,  
    int green; //in,  
    int blue; //in,  
} jsAmbiSetPixel;

typedef struct {
    unsigned int callcookie;
    int side; //in,  
    int startindex; //in,  
    int size; //in,  
    int * red; //in, data ( sizeof( int ) * size ), dynamic ( sizeof( int ) * size ), 
    int * green; //in, data ( sizeof( int ) * size ), dynamic ( sizeof( int ) * size ), 
    int * blue; //in, data ( sizeof( int ) * size ), dynamic ( sizeof( int ) * size ), 
} jsAmbiSetPixelArray;

typedef struct {
    unsigned int callcookie;
    int value; //in,  
} jsAudioGetBass;

typedef struct {
    unsigned int callcookie;
    int value; //in,  
} jsAudioGetTreble;

typedef struct {
    unsigned int callcookie;
    int value; //in,  
} jsAudioGetVolume;

typedef struct {
    unsigned int callcookie;
    int value; //in,  
} jsAudioSetBass;

typedef struct {
    unsigned int callcookie;
    int value; //in,  
} jsAudioSetTreble;

typedef struct {
    unsigned int callcookie;
    int value; //in,  
} jsAudioSetVolume;

/* argument structures for notifications (requires) */
#endif /* _JSAPI_INTERNAL_H_ */

