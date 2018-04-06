
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


#if !defined(_PLFAPIXRAY_INTERNAL_H_)
#define _PLFAPIXRAY_INTERNAL_H_
#if defined(USE_WEAK_NOTIFICATIONS)
#define WEAK __attribute__((weak))
#else
#define WEAK /* nothing */
#endif

/*  argument structures for calls (provides) */
typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    int a; //in,  
    int b; //in,  
    FunctionIntInt callback; //in,  
} adcConfigureMonitor;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    int a; //in,  
    int b; //in,  
    Bool retval; //out,  
} adcContainsAnalogueValue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    int retval; //out,  
} adcGetAnalogueValue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} adcGetMaxValue;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} adcGetMaxVoltage;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    int a; //out,  
    int b; //out,  
    FunctionIntInt callback; //out,  
} adcGetMonitorConfiguration;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    Bool retval; //out,  
} adcIsBeingMonitored;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
} adcStartMonitor;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
} adcStopMonitor;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmRegisterItem_t item; //in,  
    int retval; //out,  
} halGet;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmRegisterItem_t item; //in,  
    int ax; //in,  
    int retval; //out,  
} halGetAx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmRegisterItem_t item; //in,  
    int ax; //in,  
    int bx; //in,  
    int retval; //out,  
} halGetAxBx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmRegisterItem_t item; //in,  
    int retval; //out,  
} halGetEx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmRegisterItem_t item; //in,  
    int val; //in,  
} halSet;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmRegisterItem_t item; //in,  
    int ax; //in,  
    int val; //in,  
} halSetAx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmRegisterItem_t item; //in,  
    int ax; //in,  
    int bx; //in,  
    int val; //in,  
} halSetAxBx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmRegisterItem_t item; //in,  
    int val; //in,  
} halSetEx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmRegisterItem_t item; //in,  
    int val; //in,  
    int retval; //out,  
} halUnpack;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmRegisterItem_t item; //in,  
    int rval; //in,  
    int val; //in,  
    int retval; //out,  
} halUpdate;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmRegisterItem_t item; //in,  
    int retval; //out,  
} hal5xx0Get;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmRegisterItem_t item; //in,  
    int ax; //in,  
    int retval; //out,  
} hal5xx0GetAx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmRegisterItem_t item; //in,  
    int ax; //in,  
    int bx; //in,  
    int retval; //out,  
} hal5xx0GetAxBx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmRegisterItem_t item; //in,  
    int retval; //out,  
} hal5xx0GetEx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmRegisterItem_t item; //in,  
    int val; //in,  
} hal5xx0Set;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmRegisterItem_t item; //in,  
    int ax; //in,  
    int val; //in,  
} hal5xx0SetAx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmRegisterItem_t item; //in,  
    int ax; //in,  
    int bx; //in,  
    int val; //in,  
} hal5xx0SetAxBx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmRegisterItem_t item; //in,  
    int val; //in,  
} hal5xx0SetEx;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmRegisterItem_t item; //in,  
    int val; //in,  
    int retval; //out,  
} hal5xx0Unpack;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    tmRegisterItem_t item; //in,  
    int rval; //in,  
    int val; //in,  
    int retval; //out,  
} hal5xx0Update;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool enable; //in,  
    Nat32 bus; //in,  
    Nat32 * deviceaddr; //in, data ( sizeof( Nat32 ) * nrofaddr ), dynamic ( sizeof( Nat32 ) * nrofaddr ), 
    Nat32 nrofaddr; //in,  
} hwreglogI2cLogging;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool enable; //in,  
    Nat32 device; //in,  
    Nat32 startaddr; //in,  
    Nat32 stopaddr; //in,  
} hwreglogMmioLogging;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int usecshi; //in,  
    int usecslo; //in,  
} pwm0Start;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} pwm0Stop;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int usecshi; //in,  
    int usecslo; //in,  
} pwm1Start;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} pwm1Stop;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 from_offset; //in,  
    Nat8 * buffer; //out, data ( sizeof( Nat8 ) * size ), dynamic ( sizeof( Nat8 ) * size ), 
    int size; //in,  
    FResult retval; //out,  
} udmaRead;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 to_offset; //in,  
    Nat8 * buffer; //in, data ( sizeof( Nat8 ) * size ), dynamic ( sizeof( Nat8 ) * size ), 
    int size; //in,  
    FResult retval; //out,  
} udmaWrite;

typedef struct {
    unsigned int callcookie;
    int deviceindex; //in,  
    char name[30]; //out, string,  
} xrayGetDeviceName;

typedef struct {
    unsigned int callcookie;
    int deviceindex; //in,  
    int registerindex; //in,  
    char name[30]; //out, string,  
} xrayGetDeviceRegisterName;

typedef struct {
    unsigned int callcookie;
    int deviceindex; //in,  
    int registerindex; //in,  
    int val; //out,  
} xrayGetDeviceRegisterValue;

typedef struct {
    unsigned int callcookie;
    int deviceindex; //in,  
    int wrnr; //out,  
    int rdnr; //out,  
} xrayGetNumberOfDeviceRegisters;

typedef struct {
    unsigned int callcookie;
    int nr; //out,  
} xrayGetNumberOfDevices;

typedef struct {
    unsigned int callcookie;
    int deviceindex; //in,  
    int registerindex; //in,  
    int value; //in,  
} xraySetDeviceRegisterValue;

typedef struct {
    unsigned int callcookie;
    int nbrgroups; //out,  
    Nat32 ids[5]; //out, data ( sizeof( Nat32 ) * 5 ), 
} xrayitfGetAvailableInterfaces;

/* argument structures for notifications (requires) */
typedef struct {
    Nat32 action; //in,  
    Nat32 bus; //in,  
    Nat32 address; //in,  
    Nat8 * readdata; //in, data ( sizeof( Nat8 ) * readlen ), dynamic ( sizeof( Nat8 ) * readlen ), 
    Nat8 * writedata; //in, data ( sizeof( Nat8 ) * writelen ), dynamic ( sizeof( Nat8 ) * writelen ), 
    Nat32 readlen; //in,  
    Nat32 writelen; //in,  
} hwreglogNOnI2cAccessed;

typedef struct {
    Nat32 action; //in,  
    Nat32 device; //in,  
    Nat32 address; //in,  
    Nat32 mmiodata; //in,  
} hwreglogNOnMmioAccessed;

typedef struct {
    int nbrgroups; //in,  
    Nat32 * ids; //in, data ( sizeof( Nat32 ) * nbrgroups ), dynamic ( sizeof( Nat32 ) * nbrgroups ), 
} xrayitfNOnAvailabilityChanged;

#endif /* _PLFAPIXRAY_INTERNAL_H_ */

