
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


#if !defined(_PLFAPIINFRA_INTERNAL_H_)
#define _PLFAPIINFRA_INTERNAL_H_
#if defined(USE_WEAK_NOTIFICATIONS)
#define WEAK __attribute__((weak))
#else
#define WEAK /* nothing */
#endif

/*  argument structures for calls (provides) */
typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    FResult retval; //out,  
} audonlyActivate;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    FResult retval; //out,  
} audonlyDisable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    FResult retval; //out,  
} audonlyEnable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} audonlyIsActive;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} audonlyIsEnabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int address; //in,  
} audonlySetDestLogicalAddress;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int nbrkeys; //in,  
    int source; //out,  
    int system; //out,  
    int command; //out,  
    int usercontrolcode; //out,  
} audonlySetForwardRcCecKeys;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int source; //in,  
    int system; //in,  
    int command; //in,  
} audonlySetListenAudioKey;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} audonly2Activate;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int source; //in,  
    int system; //in,  
    int command; //in,  
    int cecaddress; //in,  
    Nat8 cecusercontrolcode; //in,  
    int cecoperandsize; //in,  
    Nat8 cecoperand; //in,  
} audonly2AddForwardCecKey;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} audonly2ClearForwardCecKeys;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} audonly2Disable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} audonly2Enable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} audonly2IsActive;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} audonly2IsDisabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int address; //in,  
    FResult retval; //out,  
} audonly2SetDestLogicalAddress;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int source; //in,  
    int system; //in,  
    int command; //in,  
} audonly2SetListenAudioKey;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int source; //in,  
    int system; //in,  
    int command; //in,  
} audonly2SetStandbyKey;

typedef struct {
    unsigned int callcookie;
    void * addr; //in, data ( sizeof( void ) * size ), dynamic ( sizeof( void ) * size ), 
    int size; //in,  
    void * key; //in, data ( sizeof( void ) * keysize ), dynamic ( sizeof( void ) * keysize ), 
    int keysize; //in,  
    void * sig; //in, data ( sizeof( void ) * sigsize ), dynamic ( sizeof( void ) * sigsize ), 
    int sigsize; //in,  
    int retval; //out,  
} authCheck;

typedef struct {
    unsigned int callcookie;
    char * fname; //in, string,  dynamic ( ( fname == NULL ? 0 : strlen( fname ) ) + 1 ), 
    void * key; //in, data ( sizeof( void ) * keysize ), dynamic ( sizeof( void ) * keysize ), 
    int keysize; //in,  
    void * sig; //in, data ( sizeof( void ) * sigsize ), dynamic ( sizeof( void ) * sigsize ), 
    int sigsize; //in,  
    int retval; //out,  
} authCheckFile;

typedef struct {
    unsigned int callcookie;
    char * fname; //in, string,  dynamic ( ( fname == NULL ? 0 : strlen( fname ) ) + 1 ), 
    void * key; //in, data ( sizeof( void ) * keysize ), dynamic ( sizeof( void ) * keysize ), 
    int keysize; //in,  
    char * sigfname; //in, string,  dynamic ( ( sigfname == NULL ? 0 : strlen( sigfname ) ) + 1 ), 
    int retval; //out,  
} authCheckFileFromFile;

typedef struct {
    unsigned int callcookie;
    void * key; //out, data ( sizeof( void ) * keysize ), dynamic ( sizeof( void ) * keysize ), 
    int keysize; //in,  
} authGetTDFPublicKey;

typedef struct {
    unsigned int callcookie;
    Bool retval; //out,  
} authIsProductAuthenticationRequired;

typedef struct {
    unsigned int callcookie;
    void * addr; //in, data ( sizeof( void ) * size ), dynamic ( sizeof( void ) * size ), 
    int size; //in,  
    void * key; //in, data ( sizeof( void ) * keysize ), dynamic ( sizeof( void ) * keysize ), 
    int keysize; //in,  
    void * sig; //out, data ( sizeof( void ) * sigsize ), dynamic ( sizeof( void ) * sigsize ), 
    int sigsize; //in,  
    int retval; //out,  
} authSign;

typedef struct {
    unsigned int callcookie;
    char * fname; //in, string,  dynamic ( ( fname == NULL ? 0 : strlen( fname ) ) + 1 ), 
    void * key; //in, data ( sizeof( void ) * keysize ), dynamic ( sizeof( void ) * keysize ), 
    int keysize; //in,  
    void * sig; //out, data ( sizeof( void ) * sigsize ), dynamic ( sizeof( void ) * sigsize ), 
    int sigsize; //in,  
    int retval; //out,  
} authSignFile;

typedef struct {
    unsigned int callcookie;
    char * fname; //in, string,  dynamic ( ( fname == NULL ? 0 : strlen( fname ) ) + 1 ), 
    void * key; //in, data ( sizeof( void ) * keysize ), dynamic ( sizeof( void ) * keysize ), 
    int keysize; //in,  
    char * sigfname; //in, string,  dynamic ( ( sigfname == NULL ? 0 : strlen( sigfname ) ) + 1 ), 
    int retval; //out,  
} authSignFileToFile;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int fd; //in,  
    int retval; //out,  
} bffsClose;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * filepath; //in, string,  dynamic ( ( filepath == NULL ? 0 : strlen( filepath ) ) + 1 ), 
    int retval; //out,  
} bffsDelete;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * filepath; //in, string,  dynamic ( ( filepath == NULL ? 0 : strlen( filepath ) ) + 1 ), 
    int size; //out,  
    int retval; //out,  
} bffsGetFileSize;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int volume; //in,  
    char * buf; //out, data ( sizeof( char ) * size ), dynamic ( sizeof( char ) * size ), 
    int size; //in,  
    int retval; //out,  
} bffsGetVolumeName;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * filepath; //in, string,  dynamic ( ( filepath == NULL ? 0 : strlen( filepath ) ) + 1 ), 
    int fmode; //in,  
    int fd; //out,  
    int retval; //out,  
} bffsOpen;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int fd; //in,  
    char * fbuff; //out, data ( sizeof( char ) * ( *nbytes ) ), dynamic ( sizeof( char ) * ( *nbytes ) ), 
    int nbytes; //in, out,  
    int retval; //out,  
} bffsRead;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int fd; //in,  
    int offset; //in,  
    int smode; //in,  
    int retval; //out,  
} bffsSeek;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int fd; //in,  
    char * fbuff; //in, data ( sizeof( char ) * ( *nbytes ) ), dynamic ( sizeof( char ) * ( *nbytes ) ), 
    int nbytes; //in, out,  
    int retval; //out,  
} bffsWrite;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * name; //in, string,  dynamic ( ( name == NULL ? 0 : strlen( name ) ) + 1 ), 
    char * value; //out, data ( sizeof( char ) * size ), dynamic ( sizeof( char ) * size ), 
    int size; //in,  
    Bool retval; //out,  
} bootloaderGetEnvironmentVariable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} bootloaderResetBootCounter;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * name; //in, string,  dynamic ( ( name == NULL ? 0 : strlen( name ) ) + 1 ), 
    char * value; //in, string,  dynamic ( ( value == NULL ? 0 : strlen( value ) ) + 1 ), 
    Bool retval; //out,  
} bootloaderSetEnvironmentVariable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} cecackMessageProcessed;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} cecctrlCancel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} cecctrlCausedWakeup;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} cecctrlDisable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} cecctrlDisableReceive;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} cecctrlDisableTransmitStatus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} cecctrlEnable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} cecctrlEnableReceive;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} cecctrlEnableTransmitStatus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat8 * cec_message; //out, data ( sizeof( Nat8 ) * ( *msg_length ) ), dynamic ( sizeof( Nat8 ) * ( *msg_length ) ), 
    Nat8 msg_length; //in, out,  
} cecctrlGetBufferedMsg;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat8 * vendor_id; //out, data ( sizeof( Nat8 ) * ( *length ) ), dynamic ( sizeof( Nat8 ) * ( *length ) ), 
    int length; //in, out,  
} cecctrlGetDeviceVendorID;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CecLogicalAddress retval; //out,  
} cecctrlGetLogicalAddress;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * osd_name; //out, data ( sizeof( char ) * ( *length ) ), dynamic ( sizeof( char ) * ( *length ) ), 
    int length; //in, out,  
} cecctrlGetOSDName;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CecVersion retval; //out,  
} cecctrlGetVersion;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat8 * pMessage; //out, data ( sizeof( Nat8 ) * size ), dynamic ( sizeof( Nat8 ) * size ), 
    int size; //in,  
} cecctrlPreview;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat8 * vendor_id; //in, data ( sizeof( Nat8 ) * length ), dynamic ( sizeof( Nat8 ) * length ), 
    int length; //in,  
} cecctrlSetDeviceVendorID;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CecLogicalAddress address; //in,  
} cecctrlSetLogicalAddress;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * osd_name; //in, data ( sizeof( char ) * length ), dynamic ( sizeof( char ) * length ), 
    int length; //in,  
} cecctrlSetOSDName;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CecVersion version; //in,  
} cecctrlSetVersion;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    CecOpcode * wkp_code; //in, data ( sizeof( CecOpcode ) * size ), dynamic ( sizeof( CecOpcode ) * size ), 
    int size; //in,  
} cecctrlSetWakeupMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int size; //in,  
    Nat8 * msg; //in, data ( sizeof( Nat8 ) * size ), dynamic ( sizeof( Nat8 ) * size ), 
    Bool retval; //out,  
} cectxTransmit;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} clkAlarmIsSet;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} clkCancelAlarm;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} clkCausedWakeup;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} clkClockIsSet;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    DateTime retval; //out,  
} clkGetAlarm;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    DateTime retval; //out,  
} clkGetLocalTime;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    DateTime retval; //out,  
} clkGetLocalTimeOffset;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    DateTime retval; //out,  
} clkGetUniversalTime;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool enable; //in,  
} clkRunDuringStandby;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} clkSecondsSinceWakeup;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    DateTime alarm; //in,  
} clkSetAlarm;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    DateTime utc; //in,  
    DateTime lto; //in,  
} clkSetClock;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool enable; //in,  
} clkSetWakeupMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat8 Key[256]; //in, data ( sizeof( Nat8 ) * 256 ), 
    Nat8 Buffer[256]; //in, out, data ( sizeof( Nat8 ) * 256 ), 
    FResult retval; //out,  
} cryptCrypt;

typedef struct {
    unsigned int callcookie;
    char pub[32]; //in, data ( sizeof( char ) * 32 ), 
    char * label; //in, string,  dynamic ( ( label == NULL ? 0 : strlen( label ) ) + 1 ), 
    Nat8 * bag; //in, data ( sizeof( Nat8 ) * baglength ), dynamic ( sizeof( Nat8 ) * baglength ), 
    int baglength; //in,  
    Nat8 * packet; //out, data ( sizeof( Nat8 ) * packetlength ), dynamic ( sizeof( Nat8 ) * packetlength ), 
    int packetlength; //in,  
} dbbrwseGetPacket;

typedef struct {
    unsigned int callcookie;
    char pub[32]; //in, data ( sizeof( char ) * 32 ), 
    char * label; //in, string,  dynamic ( ( label == NULL ? 0 : strlen( label ) ) + 1 ), 
    Nat8 * bag; //in, data ( sizeof( Nat8 ) * baglength ), dynamic ( sizeof( Nat8 ) * baglength ), 
    int baglength; //in,  
    int retval; //out,  
} dbbrwseGetPacketLength;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} dbtfHasLastFileAccessSucceeded;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} dbtfIsFilePresent;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    void * bag; //in, data ( sizeof( void ) * length ), dynamic ( sizeof( void ) * length ), 
    int length; //in,  
    Nat16 Crc; //out,  
    int retval; //out,  
} dbtfSendData;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat8 * id; //out, data ( sizeof( Nat8 ) * ( *idlen ) ), dynamic ( sizeof( Nat8 ) * ( *idlen ) ), 
    Nat32 idlen; //in, out,  
    Bool retval; //out,  
} dbtfciGetId;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} dbtfciHasLastFileAccessSucceeded;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} dbtfciIsFilePresent;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    void * bag; //in, data ( sizeof( void ) * length ), dynamic ( sizeof( void ) * length ), 
    int length; //in,  
    Nat16 Crc; //out,  
    int retval; //out,  
} dbtfciSendData;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} dmpctrDisableMagicKeys;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} dmpctrEnableMagicKeys;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool fatal; //in,  
    char * debugdata; //in, data ( sizeof( char ) * len ), dynamic ( sizeof( char ) * len ), 
    int len; //in,  
    Nat32 options; //in,  
} dmpctrMakeDebugDump;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} evlogctrClearLog;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int BackwardRef; //in,  
    PlfApiEventLogEntry log; //out,  
    Bool retval; //out,  
} evlogctrGetHwLogRecord;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} evlogctrGetLastAlign;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} evlogctrGetLastLogCleared;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 retval; //out,  
} evlogctrGetLoggedEvents;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int BackwardRef; //in,  
    PlfApiEventLogEntry log; //out,  
    Bool retval; //out,  
} evlogctrGetLogRecord;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 retval; //out,  
} evlogctrGetNumReboots;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} evlogctrGetNvmIntegCheck;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char swver[33]; //out, data ( sizeof( char ) * 33 ), 
} evlogctrGetSwVersion;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} evlogctrHwClearLog;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 retval; //out,  
} evlogctrHwGetLastLogCleared;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat16 retval; //out,  
} evlogctrHwGetLoggedEvents;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    KeySource source; //in,  
    Bool Toggle; //in,  
    KeySystem system; //in,  
    KeyCommand command; //in,  
    int TimeStamp; //in,  
} evlogctrSetLastKey;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    KeySystem sys; //in,  
    KeyCommand command; //in,  
} evlogctrSetLastKeyUp;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat8 src; //in,  
} evlogctrSetLastSrc;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 value; //in,  
} evlogctrSetNvmIntegCheck;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * swver; //in, string,  dynamic ( ( swver == NULL ? 0 : strlen( swver ) ) + 1 ), 
} evlogctrSetSwVersion;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * mountpoint; //in, string,  dynamic ( ( mountpoint == NULL ? 0 : strlen( mountpoint ) ) + 1 ), 
    Bool retval; //out,  
} fopsIsPartitionMounted;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * partitionname; //in, string,  dynamic ( ( partitionname == NULL ? 0 : strlen( partitionname ) ) + 1 ), 
    char * mountpoint; //in, string,  dynamic ( ( mountpoint == NULL ? 0 : strlen( mountpoint ) ) + 1 ), 
    char * fstype; //in, string,  dynamic ( ( fstype == NULL ? 0 : strlen( fstype ) ) + 1 ), 
    Nat32 mountflags; //in,  
    char * options; //in, string,  dynamic ( ( options == NULL ? 0 : strlen( options ) ) + 1 ), 
    FResult retval; //out,  
} fopsPartitionMount;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * mountpoint; //in, string,  dynamic ( ( mountpoint == NULL ? 0 : strlen( mountpoint ) ) + 1 ), 
    FResult retval; //out,  
} fopsPartitionUnmount;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int pinid; //in,  
    int retval; //out,  
} gioPinGetAlt;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int pinid; //in,  
    int retval; //out,  
} gioPinGetLatch;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int pinid; //in,  
    int retval; //out,  
} gioPinGetLine;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int pinid; //in,  
    int retval; //out,  
} gioPinGetMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int pinid; //in,  
    int alt; //in,  
} gioPinSetAlt;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int pinid; //in,  
    int value; //in,  
} gioPinSetLatch;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int pinid; //in,  
    int mode; //in,  
} gioPinSetMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int port; //in,  
    int retval; //out,  
} gioPortGetLatch;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int port; //in,  
    int retval; //out,  
} gioPortGetLine;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int port; //in,  
    int mask; //in,  
    int alt; //in,  
} gioPortSetAlt;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int port; //in,  
    int mask; //in,  
    int value; //in,  
} gioPortSetLatch;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int port; //in,  
    int mask; //in,  
    int mode; //in,  
} gioPortSetMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int bus; //in,  
    Bool retval; //out,  
} i2ccBlockBus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int bus; //in,  
    Bool retval; //out,  
} i2ccEnterIdleMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} i2ccGetBlocked;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int bus; //in,  
    int retval; //out,  
} i2ccGetControlWord;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} i2ccGetIdle;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} i2ccGetMasterEnabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} i2ccGetSlaveEnabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int bus; //in,  
    Bool retval; //out,  
} i2ccLeaveIdleMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int bus; //in,  
    Bool retval; //out,  
} i2ccMasterDisable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int bus; //in,  
    Bool retval; //out,  
} i2ccMasterEnable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int bus; //in,  
    int bitrate; //in,  
    FResult retval; //out,  
} i2ccSetBitRate;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int bus; //in,  
    int timeout; //in,  
    FResult retval; //out,  
} i2ccSetMasterTimeout;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int bus; //in,  
    Bool retval; //out,  
} i2ccSlaveDisable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int address; //in,  
    Nat8 * buf; //in, out, data ( sizeof( Nat8 ) * size ), dynamic ( sizeof( Nat8 ) * size ), 
    int size; //in,  
    Bool retval; //out,  
} i2ccSlaveEnable;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int bus; //in,  
    Bool retval; //out,  
} i2ccUnblockBus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int address; //in,  
    Nat8 * msg; //out, data ( sizeof( Nat8 ) * len ), dynamic ( sizeof( Nat8 ) * len ), 
    int len; //in,  
    FResult retval; //out,  
} i2cmRead;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int address; //in,  
    Nat8 * msg; //in, data ( sizeof( Nat8 ) * len ), dynamic ( sizeof( Nat8 ) * len ), 
    int len; //in,  
    FResult retval; //out,  
} i2cmWrite;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int address; //in,  
    Nat8 * msgw; //in, data ( sizeof( Nat8 ) * lenw ), dynamic ( sizeof( Nat8 ) * lenw ), 
    int lenw; //in,  
    Nat8 * msgr; //out, data ( sizeof( Nat8 ) * lenr ), dynamic ( sizeof( Nat8 ) * lenr ), 
    int lenr; //in,  
    FResult retval; //out,  
} i2cmWriteRead;

typedef struct {
    unsigned int callcookie;
    int nbrgroups; //out,  
    Nat32 ids[5]; //out, data ( sizeof( Nat32 ) * 5 ), 
} infraitfGetAvailableInterfaces;

typedef struct {
    unsigned int callcookie;
    Nat32 context; //in,  
    Nat8 digest[20]; //out, data ( sizeof( Nat8 ) * 20 ), 
} ishaFinish;

typedef struct {
    unsigned int callcookie;
    Nat32 context; //out,  
} ishaInit;

typedef struct {
    unsigned int callcookie;
    Nat32 context; //in,  
    Nat8 * buffer; //in, data ( sizeof( Nat8 ) * len ), dynamic ( sizeof( Nat8 ) * len ), 
    Nat32 len; //in,  
} ishaUpdate;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    KeySource source; //in,  
    KeySystem system; //in,  
    KeyCommand command; //in,  
    Bool retval; //out,  
} keyiDown;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    KeySource source; //in,  
    KeySystem system; //in,  
    KeyCommand command; //in,  
    Bool retval; //out,  
} keyiUp;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} ledDisablePlfLedControl;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
} ledEnablePlfLedControl;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int led; //in,  
    Nat8 retval; //out,  
} ledGetIntensity;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int led; //in,  
    Bool retval; //out,  
} ledIntensitySupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} ledIsPlfLedControlEnabled;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int led; //in,  
    int msecson; //in,  
    int msecsoff; //in,  
} ledSetBlinking;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int led; //in,  
    int msecs; //in,  
} ledSetFlash;

typedef struct {
    unsigned int callcookie;
    int windid; //in,  
    int led; //in,  
    Nat8 intensity; //in,  
} ledSetIntensity;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int led; //in,  
    Bool turnon; //in,  
} ledSetLightGuide;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int led; //in,  
    Bool offon; //in,  
} ledSetPermanent;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 key; //in,  
    Nat32 size; //in,  
    Address address; //out,  
    FResult retval; //out,  
} ncdMem;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    FResult retval; //out,  
} netCheckDnsStatus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    FResult retval; //out,  
} netConfigInterfaceAutomatic;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 ipaddress; //in,  
    Nat32 ipmask; //in,  
    Nat32 gateway; //in,  
    Nat32 dns1; //in,  
    Nat32 dns2; //in,  
    FResult retval; //out,  
} netConfigInterfaceStatic;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int intfhandle; //in,  
    FResult retval; //out,  
} netEnableNetworkInterface;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} netGetEnabledNetworkInterface;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} netGetEnabledNetworkInterfaceStatus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 ipaddress; //out,  
    Nat32 ipmask; //out,  
    Nat32 gateway; //out,  
    Nat32 dns1; //out,  
    Nat32 dns2; //out,  
} netGetInterfaceConfig;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} netgetMaxNoOfAutomaticWirelessDevicesSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} netgetMaxNoOfManualWirelessDevicesSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} netgetMaxNoOfNetworkinterfacesSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} netGetNetworkConfigMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} netGetNetworkInterfaceConfigStatus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int intfhandle; //in,  
    int length; //in,  
    char * retval; //out, data ( sizeof( char ) * length ), dynamic ( sizeof( char ) * length ), 
} netGetNetworkInterfaceMacAddress;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int intfhandle; //in,  
    int length; //in,  
    char * retval; //out, data ( sizeof( char ) * length ), dynamic ( sizeof( char ) * length ), 
} netGetNetworkInterfaceName;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int intfhandle; //in,  
    Bool retval; //out,  
} netGetNetworkInterfacePhysicalStatus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int intfhandle; //in,  
    int retval; //out,  
} netGetNetworkInterfaceThroughput;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int intfhandle; //in,  
    int retval; //out,  
} netGetNetworkInterfaceType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int intfhandle; //in,  
    int length; //in,  
    char * retval; //out, data ( sizeof( char ) * length ), dynamic ( sizeof( char ) * length ), 
} netGetNetworkInterfaceVersion;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} netGetNumberOfNetworkInterfaces;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} netGetNumberOfWifiDevices;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int selconfigmode; //out,  
    int wifidev; //out,  
    char ssid[33]; //out, string,  
} netGetSelectedWiFiDevice;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 ipaddress; //out,  
    Nat32 ipmask; //out,  
    Nat32 gateway; //out,  
    Nat32 dns1; //out,  
    Nat32 dns2; //out,  
} netGetStoredStaticInterfaceConfig;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} netIsInitializationDone;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} netIsNetworkModeVirgin;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int selconfigmode; //in,  
    int wifidev; //in,  
    char * ssid; //in, string,  dynamic ( ( ssid == NULL ? 0 : strlen( ssid ) ) + 1 ), 
    FResult retval; //out,  
} netSelectWiFiDevice;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    FResult retval; //out,  
} netSetNetworkToModeVirgin;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} netWifiGetChannel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int wifidev; //in,  
    int retval; //out,  
} netWifiGetChannelWifiDevice;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} netWifiGetEffectiveSignalStrength;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} netWifiGetEffectiveThroughput;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //out,  
    int auth; //out,  
} netWifiGetEncryptionMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int wifidev; //in,  
    int retval; //out,  
} netWifiGetEncryptionModeWifiDevice;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat8 * key; //out, data ( sizeof( Nat8 ) * ( *len ) ), dynamic ( sizeof( Nat8 ) * ( *len ) ), 
    int len; //in, out,  
} netWifiGetKey;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} netWifiGetPortType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int wifidev; //in,  
    int retval; //out,  
} netWifiGetPortTypeWifiDevice;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int wifidev; //in,  
    int retval; //out,  
} netWifiGetSignalStrengthWifiDevice;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int wifidev; //in,  
    char retval[33]; //out, string,  
} netWifiGetSsidWifiDevice;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int wifidev; //in,  
    int retval; //out,  
} netWifiGetThroughputWifiDevice;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    FResult retval; //out,  
} netWifiSetChannel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    int auth; //in,  
    FResult retval; //out,  
} netWifiSetEncryptionMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat8 * key; //in, data ( sizeof( Nat8 ) * len ), dynamic ( sizeof( Nat8 ) * len ), 
    int len; //in,  
    FResult retval; //in,  
} netWifiSetKey;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int porttype; //in,  
    FResult retval; //out,  
} netWifiSetPortType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    FResult retval; //out,  
} net2CheckDnsStatus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    FResult retval; //out,  
} net2ConfigInterfaceAutomatic;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 ipaddress; //in,  
    Nat32 ipmask; //in,  
    Nat32 gateway; //in,  
    Nat32 dns1; //in,  
    Nat32 dns2; //in,  
    FResult retval; //out,  
} net2ConfigInterfaceStatic;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int intfhandle; //in,  
    FResult retval; //out,  
} net2EnableNetworkInterface;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} net2GetEnabledNetworkInterface;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 ipaddress; //out,  
    Nat32 ipmask; //out,  
    Nat32 gateway; //out,  
    Nat32 dns1; //out,  
    Nat32 dns2; //out,  
} net2GetInterfaceConfig;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} net2getMaxNoOfAutomaticWirelessDevicesSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} net2getMaxNoOfManualWirelessDevicesSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} net2getMaxNoOfNetworkinterfacesSupported;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} net2GetNetworkConfigMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} net2GetNetworkInterfaceConfigStatus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int intfhandle; //in,  
    int length; //in,  
    char * retval; //out, data ( sizeof( char ) * length ), dynamic ( sizeof( char ) * length ), 
} net2GetNetworkInterfaceMacAddress;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int intfhandle; //in,  
    int length; //in,  
    char * retval; //out, data ( sizeof( char ) * length ), dynamic ( sizeof( char ) * length ), 
} net2GetNetworkInterfaceName;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int intfhandle; //in,  
    Bool retval; //out,  
} net2GetNetworkInterfacePhysicalStatus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int intfhandle; //in,  
    int retval; //out,  
} net2GetNetworkInterfaceThroughput;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int intfhandle; //in,  
    int retval; //out,  
} net2GetNetworkInterfaceType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int intfhandle; //in,  
    int length; //in,  
    char * retval; //out, data ( sizeof( char ) * length ), dynamic ( sizeof( char ) * length ), 
} net2GetNetworkInterfaceVersion;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} net2GetNumberOfNetworkInterfaces;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} net2GetNumberOfWifiDevices;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 ipaddress; //out,  
    Nat32 ipmask; //out,  
    Nat32 gateway; //out,  
    Nat32 dns1; //out,  
    Nat32 dns2; //out,  
} net2GetStoredStaticInterfaceConfig;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} net2IsInitializationDone;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} net2IsNetworkModeVirgin;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int selection; //in,  
    FResult retval; //out,  
} net2SelectWifiAntennas;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    FResult retval; //out,  
} net2SetNetworkToModeVirgin;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    FResult retval; //out,  
} net2WifiFindManualSsid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * pin; //out, data ( sizeof( char ) * pinsize ), dynamic ( sizeof( char ) * pinsize ), 
    int pinsize; //in,  
} net2WifiGenerateWpsPin;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} net2WifiGetChannel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int wifidev; //in,  
    int retval; //out,  
} net2WifiGetChannelWifiDevice;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //in, out,  
} net2WifiGetEffectiveSignalStrength;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} net2WifiGetEffectiveThroughput;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //out,  
    int auth; //out,  
} net2WifiGetEncryptionMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int wifidev; //in,  
    int retval; //out,  
} net2WifiGetEncryptionModeWifiDevice;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * key; //out, data ( sizeof( char ) * ( *len ) ), dynamic ( sizeof( char ) * ( *len ) ), 
    int len; //in, out,  
} net2WifiGetKey;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char macaddr[18]; //out, string,  
} net2WifiGetMacAddress;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int wifidev; //in,  
    char macaddr[18]; //out, string,  
} net2WifiGetMacAddressWifiDevice;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} net2WifiGetPortType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int wifidev; //in,  
    int retval; //out,  
} net2WifiGetPortTypeWifiDevice;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int wifidev; //in,  
    int retval; //out,  
} net2WifiGetSignalStrengthWifiDevice;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char ssid[33]; //out, string,  
} net2WifiGetSsid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int wifidev; //in,  
    char retval[33]; //out, string,  
} net2WifiGetSsidWifiDevice;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int wifidev; //in,  
    int retval; //out,  
} net2WifiGetThroughputWifiDevice;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int wifidev; //in,  
    int mode; //in, out,  
} net2WifiGetWpsModeWifiDevice;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    FResult retval; //out,  
} net2WifiScanWifiDevices;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int channel; //in,  
    FResult retval; //out,  
} net2WifiSetChannel;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    int auth; //in,  
    FResult retval; //out,  
} net2WifiSetEncryptionMode;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * key; //in, data ( sizeof( char ) * len ), dynamic ( sizeof( char ) * len ), 
    int len; //in,  
    FResult retval; //out,  
} net2WifiSetKey;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int porttype; //in,  
    FResult retval; //out,  
} net2WifiSetPortType;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * ssid; //in, string,  dynamic ( ( ssid == NULL ? 0 : strlen( ssid ) ) + 1 ), 
    FResult retval; //out,  
} net2WifiSetSsid;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int mode; //in,  
    char * pin; //in, string,  dynamic ( ( pin == NULL ? 0 : strlen( pin ) ) + 1 ), 
} net2WifiStartWpsConnection;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int appid; //in,  
} p2pacNOnExecutionCompleted;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int appid; //in,  
    Bool success; //in,  
} p2pacNOnTransmissionCompleted;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int appid; //in,  
    int bus; //in,  
    void * buf; //in, data ( sizeof( void ) * size ), dynamic ( sizeof( void ) * size ), 
    int size; //in,  
    FResult retval; //out,  
} p2pahWriteASync;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int appid; //in,  
    int bus; //in,  
    void * buf; //in, data ( sizeof( void ) * size ), dynamic ( sizeof( void ) * size ), 
    int size; //in,  
    FResult retval; //out,  
} p2pahWriteASyncNoRetry;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int appid; //in,  
    int bus; //in,  
    char * buf; //in, data ( sizeof( char ) * size ), dynamic ( sizeof( char ) * size ), 
    int size; //in,  
    FResult retval; //out,  
} p2pahWriteCharASync;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int appid; //in,  
    int bus; //in,  
    char * buf; //in, data ( sizeof( char ) * size ), dynamic ( sizeof( char ) * size ), 
    int size; //in,  
    FResult retval; //out,  
} p2pahWriteCharASyncNoRetry;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int appid; //in,  
    int bus; //in,  
    char * buf; //in, data ( sizeof( char ) * size ), dynamic ( sizeof( char ) * size ), 
    int size; //in,  
    FResult retval; //out,  
} p2pahWriteCharNoSync;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int appid; //in,  
    int bus; //in,  
    char * buf; //in, data ( sizeof( char ) * size ), dynamic ( sizeof( char ) * size ), 
    int size; //in,  
    FResult retval; //out,  
} p2pahWriteCharNoSyncNoRetry;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int appid; //in,  
    int bus; //in,  
    void * buf; //in, data ( sizeof( void ) * size ), dynamic ( sizeof( void ) * size ), 
    int size; //in,  
    FResult retval; //out,  
} p2pahWriteNoSync;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int appid; //in,  
    int bus; //in,  
    void * buf; //in, data ( sizeof( void ) * size ), dynamic ( sizeof( void ) * size ), 
    int size; //in,  
    FResult retval; //out,  
} p2pahWriteNoSyncNoRetry;

typedef struct {
    unsigned int callcookie;
    int resid; //in,  
    Address retval; //out,  
} resmgrAcquire;

typedef struct {
    unsigned int callcookie;
    int resid; //in,  
} resmgrRelease;

typedef struct {
    unsigned int callcookie;
    char * filename; //in, string,  dynamic ( ( filename == NULL ? 0 : strlen( filename ) ) + 1 ), 
    FResult retval; //out,  
} secstoCheck;

typedef struct {
    unsigned int callcookie;
    int handle; //in,  
    char * label; //in, string,  dynamic ( ( label == NULL ? 0 : strlen( label ) ) + 1 ), 
    int packetlength; //in,  
    Nat8 * packet; //out, data ( sizeof( Nat8 ) * packetlength ), dynamic ( sizeof( Nat8 ) * packetlength ), 
} secstoGetPacket;

typedef struct {
    unsigned int callcookie;
    int handle; //in,  
    char * label; //in, string,  dynamic ( ( label == NULL ? 0 : strlen( label ) ) + 1 ), 
    int retval; //out,  
} secstoGetPacketLength;

typedef struct {
    unsigned int callcookie;
    char * filename; //in, string,  dynamic ( ( filename == NULL ? 0 : strlen( filename ) ) + 1 ), 
    char pub[32]; //in, data ( sizeof( char ) * 32 ), 
    int handle; //out,  
    FResult retval; //out,  
} secstoLoad;

typedef struct {
    unsigned int callcookie;
    char * filename; //in, string,  dynamic ( ( filename == NULL ? 0 : strlen( filename ) ) + 1 ), 
    int baglen; //in,  
    Nat8 * bag; //in, data ( sizeof( Nat8 ) * baglen ), dynamic ( sizeof( Nat8 ) * baglen ), 
    int encrypt; //in,  
    FResult retval; //out,  
} secstoStore;

typedef struct {
    unsigned int callcookie;
    int handle; //in,  
} secstoUnload;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Address address; //in,  
    Nat32 size; //in,  
    FResult retval; //out,  
} shmemCacheFlush;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Address address; //in,  
    Nat32 size; //in,  
    FResult retval; //out,  
} shmemCacheInvalidate;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Address address; //in,  
    FResult retval; //out,  
} shmemFree;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 handle; //in,  
    Nat32 size; //in,  
    Address address; //out,  
    Nat32 flags; //in,  
    FResult retval; //out,  
} shmemMalloc;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 handle; //in,  
    Nat32 size; //in,  
    Address address; //out,  
    Nat32 flags; //in,  
    Nat32 alignment; //in,  
    FResult retval; //out,  
} shmemMallocAlign;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 handle; //out,  
    Nat32 size; //in,  
    FResult retval; //out,  
} shmemMmspCreate;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat32 handle; //in,  
    FResult retval; //out,  
} shmemMmspDelete;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int uart; //in,  
    int baudrate; //in,  
} uartctlSetBaudRate;

typedef struct {
    unsigned int callcookie;
} uartprintDisable;

typedef struct {
    unsigned int callcookie;
} uartprintEnable;

typedef struct {
    unsigned int callcookie;
    Bool retval; //out,  
} uartprintIsEnabled;

typedef struct {
    unsigned int callcookie;
    Nat64 retval; //out,  
} uidGetSoCUniqueID;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int descsize; //in,  
    char * desc; //out, data ( sizeof( char ) * descsize ), dynamic ( sizeof( char ) * descsize ), 
} upginfGetCurrentTvSwDescription;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int headersize; //out,  
} upginfGetUpgHeaderSize;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int buffersize; //in,  
    Nat8 * buffer; //in, data ( sizeof( Nat8 ) * buffersize ), dynamic ( sizeof( Nat8 ) * buffersize ), 
    Bool headervalid; //out,  
    Bool flashable; //out,  
    Bool executable; //out,  
    int executionaddress; //out,  
    int swidsize; //in,  
    char * swid; //out, data ( sizeof( char ) * swidsize ), dynamic ( sizeof( char ) * swidsize ), 
    int descriptionsize; //in,  
    char * description; //out, data ( sizeof( char ) * descriptionsize ), dynamic ( sizeof( char ) * descriptionsize ), 
    int exceptionitemindex; //in,  
    int exceptionitemsize; //in,  
    char * exceptionitem; //out, data ( sizeof( char ) * exceptionitemsize ), dynamic ( sizeof( char ) * exceptionitemsize ), 
} upginfGetUpgInfo;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int descsize; //in,  
    char * desc; //out, data ( sizeof( char ) * descsize ), dynamic ( sizeof( char ) * descsize ), 
} upginf2GetCurrentTvSwDescription;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * filePath; //in, string,  dynamic ( ( filePath == NULL ? 0 : strlen( filePath ) ) + 1 ), 
    Bool headervalid; //out,  
    Bool flashable; //out,  
    Bool executable; //out,  
    int executionaddress; //out,  
    int swidsize; //in,  
    char * swid; //out, data ( sizeof( char ) * swidsize ), dynamic ( sizeof( char ) * swidsize ), 
    int descriptionsize; //in,  
    char * description; //out, data ( sizeof( char ) * descriptionsize ), dynamic ( sizeof( char ) * descriptionsize ), 
    int exceptionitemindex; //in,  
    int exceptionitemsize; //in,  
    char * exceptionitem; //out, data ( sizeof( char ) * exceptionitemsize ), dynamic ( sizeof( char ) * exceptionitemsize ), 
} upginf2GetUpgInfo;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int descsize; //in,  
    char * desc; //out, data ( sizeof( char ) * descsize ), dynamic ( sizeof( char ) * descsize ), 
} upginf3GetCurrentTvSwDescription;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * filepath; //in, string,  dynamic ( ( filepath == NULL ? 0 : strlen( filepath ) ) + 1 ), 
    int fileoffset; //in,  
    Bool headervalid; //out,  
    Bool flashable; //out,  
    Bool executable; //out,  
    int executionaddress; //out,  
    int swidsize; //in,  
    char * swid; //out, data ( sizeof( char ) * swidsize ), dynamic ( sizeof( char ) * swidsize ), 
    int descriptionsize; //in,  
    char * description; //out, data ( sizeof( char ) * descriptionsize ), dynamic ( sizeof( char ) * descriptionsize ), 
    int exceptionitemindex; //in,  
    int exceptionitemsize; //in,  
    char * exceptionitem; //out, data ( sizeof( char ) * exceptionitemsize ), dynamic ( sizeof( char ) * exceptionitemsize ), 
} upginf3GetUpgInfo;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retVal; //out,  
} upgtoolGetUpgLoadingProgress;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retVal; //out,  
} upgtoolGetUpgLoadingStatus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retVal; //out,  
} upgtoolGetUpgProgrammingProgress;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retVal; //out,  
} upgtoolGetUpgProgrammingStatus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retVal; //out,  
} upgtoolGetUpgValidationProgress;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retVal; //out,  
} upgtoolGetUpgValidationStatus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * filePath; //in, string,  dynamic ( ( filePath == NULL ? 0 : strlen( filePath ) ) + 1 ), 
    Bool inPlaceDecrypt; //in,  
    Bool retVal; //out,  
} upgtoolStartUpgLoading;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retVal; //out,  
} upgtoolStartUpgProgramming;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retVal; //out,  
} upgtoolStartUpgValidation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retVal; //out,  
} upgtoolStopUpgLoading;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retVal; //out,  
} upgtoolStopUpgProgramming;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retVal; //out,  
} upgtoolStopUpgValidation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retVal; //out,  
} upgtool2GetUpgLoadingProgress;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retVal; //out,  
} upgtool2GetUpgLoadingStatus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retVal; //out,  
} upgtool2GetUpgProgrammingProgress;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retVal; //out,  
} upgtool2GetUpgProgrammingStatus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retVal; //out,  
} upgtool2GetUpgValidationProgress;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retVal; //out,  
} upgtool2GetUpgValidationStatus;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char * filePath; //in, string,  dynamic ( ( filePath == NULL ? 0 : strlen( filePath ) ) + 1 ), 
    int fileOffset; //in,  
    Bool inPlaceDecrypt; //in,  
    Bool retVal; //out,  
} upgtool2StartUpgLoading;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retVal; //out,  
} upgtool2StartUpgProgramming;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retVal; //out,  
} upgtool2StartUpgValidation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retVal; //out,  
} upgtool2StopUpgLoading;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retVal; //out,  
} upgtool2StopUpgProgramming;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retVal; //out,  
} upgtool2StopUpgValidation;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int nrofdevs; //in,  
    int * devices; //out, data ( sizeof( int ) * nrofdevs ), dynamic ( sizeof( int ) * nrofdevs ), 
    int activedevices; //out,  
} usbdevGetActiveDevicesList;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int devid; //in,  
    int manufstrlen; //in,  
    char * manufacturer; //out, data ( sizeof( char ) * manufstrlen ), dynamic ( sizeof( char ) * manufstrlen ), 
    int prodstrlen; //in,  
    char * product; //out, data ( sizeof( char ) * prodstrlen ), dynamic ( sizeof( char ) * prodstrlen ), 
    int revstrlen; //in,  
    char * revision; //out, data ( sizeof( char ) * revstrlen ), dynamic ( sizeof( char ) * revstrlen ), 
    int devicetype; //out,  
    Bool deviswriteprotected; //out,  
    Bool ismounted; //out,  
    int pathnamelength; //in,  
    char * pathname; //out, data ( sizeof( char ) * pathnamelength ), dynamic ( sizeof( char ) * pathnamelength ), 
    int physdevid; //out,  
} usbdevGetDeviceInfo;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int physdevid; //in,  
    int nrofdevs; //in,  
    int * devices; //out, data ( sizeof( int ) * nrofdevs ), dynamic ( sizeof( int ) * nrofdevs ), 
    int actualnrofdevs; //out,  
} usbdevGetPhysDeviceMemberList;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int nrofphysdevs; //in,  
    int * physdevices; //out, data ( sizeof( int ) * nrofphysdevs ), dynamic ( sizeof( int ) * nrofphysdevs ), 
    int activephysdevices; //out,  
} usbdevGetPhysDevicesList;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int maxdevs; //out,  
} usbdevGetUsbMaxDevices;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int maxparts; //out,  
} usbdevGetUsbMaxPartitionsPerDevice;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int nrofdevs; //in,  
    int * devices; //out, data ( sizeof( int ) * nrofdevs ), dynamic ( sizeof( int ) * nrofdevs ), 
    int activedevices; //out,  
    FResult fresult; //out,  
} usbdev2GetActiveDevicesList;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int devid; //in,  
    int manufstrlen; //in,  
    char * manufacturer; //out, data ( sizeof( char ) * manufstrlen ), dynamic ( sizeof( char ) * manufstrlen ), 
    int prodstrlen; //in,  
    char * product; //out, data ( sizeof( char ) * prodstrlen ), dynamic ( sizeof( char ) * prodstrlen ), 
    int revstrlen; //in,  
    char * revision; //out, data ( sizeof( char ) * revstrlen ), dynamic ( sizeof( char ) * revstrlen ), 
    int devicetype; //out,  
    Bool deviswriteprotected; //out,  
    Bool ismounted; //out,  
    int pathnamelength; //in,  
    char * pathname; //out, data ( sizeof( char ) * pathnamelength ), dynamic ( sizeof( char ) * pathnamelength ), 
    int physdevid; //out,  
    FResult fresult; //out,  
} usbdev2GetDeviceInfo;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int physdevid; //in,  
    int nrofdevs; //in,  
    int * devices; //out, data ( sizeof( int ) * nrofdevs ), dynamic ( sizeof( int ) * nrofdevs ), 
    int actualnrofdevs; //out,  
    FResult fresult; //out,  
} usbdev2GetPhysDeviceMemberList;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int nrofphysdevs; //in,  
    int * physdevices; //out, data ( sizeof( int ) * nrofphysdevs ), dynamic ( sizeof( int ) * nrofphysdevs ), 
    int activephysdevices; //out,  
    FResult fresult; //out,  
} usbdev2GetPhysDevicesList;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int maxdevs; //out,  
} usbdev2GetUsbMaxDevices;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int maxparts; //out,  
} usbdev2GetUsbMaxPartitionsPerDevice;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} usbdev2IsInitializationDone;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vidstorFormat;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat64 retval; //out,  
} vidstorGetFreeSize;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat64 retval; //out,  
    int error; //out,  
} vidstorGetSize;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vidstorGetSpeedClass;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vidstorGetState;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vidstorGetWriteProtected;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vidstorIsInitialisationDone;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vidstor2Format;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat64 retval; //out,  
    int error; //out,  
} vidstor2GetFreeSize;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    char retval[64]; //out, string,  
} vidstor2GetMountPoint;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Nat64 retval; //out,  
    int error; //out,  
} vidstor2GetSize;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vidstor2GetSpeedClass;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    int retval; //out,  
} vidstor2GetState;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vidstor2GetWriteProtected;

typedef struct {
    unsigned int callcookie;
    int winid; //in,  
    Bool retval; //out,  
} vidstor2IsInitialisationDone;

/* argument structures for notifications (requires) */
typedef struct {
    int size; //in,  
    Nat8 * pMsg; //in, data ( sizeof( Nat8 ) * size ), dynamic ( sizeof( Nat8 ) * size ), 
} cecrxntfOnReceived;

typedef struct {
    FResult result; //in,  
} cectxntfOnTransmitCompleted;

typedef struct {
    DateTime old; //in,  
    DateTime new; //in,  
} clkntfOnClockChanged;

typedef struct {
    DateTime old; //in,  
    DateTime new; //in,  
} clkntfxOnClockChanged;

typedef struct {
    char * mountpoint; //in, string,  dynamic ( ( mountpoint == NULL ? 0 : strlen( mountpoint ) ) + 1 ), 
} fopsNOnPartitionMounted;

typedef struct {
    char * mountpoint; //in, string,  dynamic ( ( mountpoint == NULL ? 0 : strlen( mountpoint ) ) + 1 ), 
} fopsNOnPartitionMountFailed;

typedef struct {
    char * mountpoint; //in, string,  dynamic ( ( mountpoint == NULL ? 0 : strlen( mountpoint ) ) + 1 ), 
} fopsNOnPartitionUnmounted;

typedef struct {
    int nbrgroups; //in,  
    Nat32 * ids; //in, data ( sizeof( Nat32 ) * nbrgroups ), dynamic ( sizeof( Nat32 ) * nbrgroups ), 
} infraitfNOnAvailabilityChanged;

typedef struct {
    Bool available; //in,  
} net2exexNOnDnsStatusChecked;

typedef struct {
    int intfhandle; //in,  
} net2exexNOnNetworkInterfacePhysicalStatusChanged;

typedef struct {
    Bool retval; //in,  
} net2exexNOnWifiManualSsidFound;

typedef struct {
    Bool success; //in,  
} net2exexNOnWpsConnectionFinished;

typedef struct {
    Bool available; //in,  
} net2exNOnDnsStatusChecked;

typedef struct {
    int intfhandle; //in,  
} net2exNOnNetworkInterfacePhysicalStatusChanged;

typedef struct {
    Bool retval; //in,  
} net2exNOnWifiManualSsidFound;

typedef struct {
    Bool available; //in,  
} net2NOnDnsStatusChecked;

typedef struct {
    int intfhandle; //in,  
} net2NOnNetworkInterfacePhysicalStatusChanged;

typedef struct {
    Bool retval; //in,  
} net2NOnWifiManualSsidFound;

typedef struct {
    Bool available; //in,  
} netexexNOnDnsStatusChecked;

typedef struct {
    int intfhandle; //in,  
} netexexNOnNetworkInterfacePhysicalStatusChanged;

typedef struct {
    FResult result; //in,  
} netexexNOnWifiSelectionCompleted;

typedef struct {
    Bool available; //in,  
} netexNOnDnsStatusChecked;

typedef struct {
    int intfhandle; //in,  
} netexNOnNetworkInterfacePhysicalStatusChanged;

typedef struct {
    int intfhandle; //in,  
} netNOnNetworkInterfacePhysicalStatusChanged;

typedef struct {
    int appid; //in,  
    int bus; //in,  
    void * buf; //in, data ( sizeof( void ) * size ), dynamic ( sizeof( void ) * size ), 
    int size; //in,  
} p2pacWriteASync;

typedef struct {
    int appid; //in,  
    int bus; //in,  
    void * buf; //in, data ( sizeof( void ) * size ), dynamic ( sizeof( void ) * size ), 
    int size; //in,  
} p2pacWriteASyncNoRetry;

typedef struct {
    int appid; //in,  
    int bus; //in,  
    void * buf; //in, data ( sizeof( void ) * size ), dynamic ( sizeof( void ) * size ), 
    int size; //in,  
} p2pacWriteNoSync;

typedef struct {
    int appid; //in,  
    int bus; //in,  
    void * buf; //in, data ( sizeof( void ) * size ), dynamic ( sizeof( void ) * size ), 
    int size; //in,  
} p2pacWriteNoSyncNoRetry;

typedef struct {
    int appid; //in,  
    int bus; //in,  
    void * buf; //in, data ( sizeof( void ) * size ), dynamic ( sizeof( void ) * size ), 
    int size; //in,  
} p2pacxWriteASync;

typedef struct {
    int appid; //in,  
    int bus; //in,  
    void * buf; //in, data ( sizeof( void ) * size ), dynamic ( sizeof( void ) * size ), 
    int size; //in,  
} p2pacxWriteASyncNoRetry;

typedef struct {
    int appid; //in,  
    int bus; //in,  
    char * buf; //in, data ( sizeof( char ) * size ), dynamic ( sizeof( char ) * size ), 
    int size; //in,  
} p2pacxWriteCharASync;

typedef struct {
    int appid; //in,  
    int bus; //in,  
    char * buf; //in, data ( sizeof( char ) * size ), dynamic ( sizeof( char ) * size ), 
    int size; //in,  
} p2pacxWriteCharASyncNoRetry;

typedef struct {
    int appid; //in,  
    int bus; //in,  
    char * buf; //in, data ( sizeof( char ) * size ), dynamic ( sizeof( char ) * size ), 
    int size; //in,  
} p2pacxWriteCharNoSync;

typedef struct {
    int appid; //in,  
    int bus; //in,  
    char * buf; //in, data ( sizeof( char ) * size ), dynamic ( sizeof( char ) * size ), 
    int size; //in,  
} p2pacxWriteCharNoSyncNoRetry;

typedef struct {
    int appid; //in,  
    int bus; //in,  
    void * buf; //in, data ( sizeof( void ) * size ), dynamic ( sizeof( void ) * size ), 
    int size; //in,  
} p2pacxWriteNoSync;

typedef struct {
    int appid; //in,  
    int bus; //in,  
    void * buf; //in, data ( sizeof( void ) * size ), dynamic ( sizeof( void ) * size ), 
    int size; //in,  
} p2pacxWriteNoSyncNoRetry;

typedef struct {
    int appid; //in,  
} p2pahNOnExecutionCompleted;

typedef struct {
    int appid; //in,  
    Bool success; //in,  
} p2pahNOnTransmissionCompleted;

typedef struct {
    char * message; //in, string,  dynamic ( ( message == NULL ? 0 : strlen( message ) ) + 1 ), 
} upgtoolNOnProgrammingMessage;

typedef struct {
    int errortype; //in,  
    int devid; //in,  
    int physdevid; //in,  
} usbdevexNOnDeviceError;

typedef struct {
    int devid; //in,  
    int physdevid; //in,  
} usbdevexNOnDeviceInfoChanged;

typedef struct {
    int devid; //in,  
    int physdevid; //in,  
} usbdevexNOnDeviceRemoved;

typedef struct {
    int devid; //in,  
    char * drivename; //in, string,  dynamic ( ( drivename == NULL ? 0 : strlen( drivename ) ) + 1 ), 
    int physdevid; //in,  
} usbdevexNOnDriveMounted;

typedef struct {
    int devid; //in,  
    char * drivename; //in, string,  dynamic ( ( drivename == NULL ? 0 : strlen( drivename ) ) + 1 ), 
    int physdevid; //in,  
} usbdevexNOnDriveUnmounted;

typedef struct {
    int devid; //in,  
    int physdevid; //in,  
} usbdevexNOnNewDevice;

typedef struct {
    int physdevid; //in,  
} usbdevexNOnPhysicalDeviceConnected;

typedef struct {
    int physdevid; //in,  
} usbdevexNOnPhysicalDeviceDisconnected;

typedef struct {
    int errortype; //in,  
    int devid; //in,  
    int physdevid; //in,  
} usbdevNOnDeviceError;

typedef struct {
    int devid; //in,  
    int physdevid; //in,  
} usbdevNOnDeviceInfoChanged;

typedef struct {
    int devid; //in,  
    int physdevid; //in,  
} usbdevNOnDeviceRemoved;

typedef struct {
    int devid; //in,  
    char * drivename; //in, string,  dynamic ( ( drivename == NULL ? 0 : strlen( drivename ) ) + 1 ), 
    int physdevid; //in,  
} usbdevNOnDriveMounted;

typedef struct {
    int devid; //in,  
    char * drivename; //in, string,  dynamic ( ( drivename == NULL ? 0 : strlen( drivename ) ) + 1 ), 
    int physdevid; //in,  
} usbdevNOnDriveUnmounted;

typedef struct {
    int devid; //in,  
    int physdevid; //in,  
} usbdevNOnNewDevice;

typedef struct {
    int physdevid; //in,  
} usbdevNOnPhysicalDeviceConnected;

typedef struct {
    int physdevid; //in,  
} usbdevNOnPhysicalDeviceDisconnected;

typedef struct {
    int progress; //in,  
} vidstorNOnSDCardFormatProgress;

typedef struct {
    Bool success; //in,  
} vidstorNOnSDCardFormatted;

typedef struct {
    char * mountpoint; //in, string,  dynamic ( ( mountpoint == NULL ? 0 : strlen( mountpoint ) ) + 1 ), 
} vidstorNOnSDCardMounted;

typedef struct {
    char * mountpoint; //in, string,  dynamic ( ( mountpoint == NULL ? 0 : strlen( mountpoint ) ) + 1 ), 
} vidstorNOnSDCardMountFailed;

typedef struct {
    char * mountpoint; //in, string,  dynamic ( ( mountpoint == NULL ? 0 : strlen( mountpoint ) ) + 1 ), 
} vidstorNOnSDCardUnmounted;

typedef struct {
    char * mountpoint; //in, string,  dynamic ( ( mountpoint == NULL ? 0 : strlen( mountpoint ) ) + 1 ), 
} vidstorNOnSDCardUnmountFailed;

#endif /* _PLFAPIINFRA_INTERNAL_H_ */

