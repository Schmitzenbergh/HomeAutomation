
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


int idaudonlyActivate = 0;
int idaudonlyDisable = 1;
int idaudonlyEnable = 2;
int idaudonlyIsActive = 3;
int idaudonlyIsEnabled = 4;
int idaudonlySetDestLogicalAddress = 5;
int idaudonlySetForwardRcCecKeys = 6;
int idaudonlySetListenAudioKey = 7;
int idaudonly2Activate = 8;
int idaudonly2AddForwardCecKey = 9;
int idaudonly2ClearForwardCecKeys = 10;
int idaudonly2Disable = 11;
int idaudonly2Enable = 12;
int idaudonly2IsActive = 13;
int idaudonly2IsDisabled = 14;
int idaudonly2SetDestLogicalAddress = 15;
int idaudonly2SetListenAudioKey = 16;
int idaudonly2SetStandbyKey = 17;
int idauthCheck = 18;
int idauthCheckFile = 19;
int idauthCheckFileFromFile = 20;
int idauthGetTDFPublicKey = 21;
int idauthIsProductAuthenticationRequired = 22;
int idauthSign = 23;
int idauthSignFile = 24;
int idauthSignFileToFile = 25;
int idbffsClose = 26;
int idbffsDelete = 27;
int idbffsGetFileSize = 28;
int idbffsGetVolumeName = 29;
int idbffsOpen = 30;
int idbffsRead = 31;
int idbffsSeek = 32;
int idbffsWrite = 33;
int idbootloaderGetEnvironmentVariable = 34;
int idbootloaderResetBootCounter = 35;
int idbootloaderSetEnvironmentVariable = 36;
int idcecackMessageProcessed = 37;
int idcecctrlCancel = 38;
int idcecctrlCausedWakeup = 39;
int idcecctrlDisable = 40;
int idcecctrlDisableReceive = 41;
int idcecctrlDisableTransmitStatus = 42;
int idcecctrlEnable = 43;
int idcecctrlEnableReceive = 44;
int idcecctrlEnableTransmitStatus = 45;
int idcecctrlGetBufferedMsg = 46;
int idcecctrlGetDeviceVendorID = 47;
int idcecctrlGetLogicalAddress = 48;
int idcecctrlGetOSDName = 49;
int idcecctrlGetVersion = 50;
int idcecctrlPreview = 51;
int idcecctrlSetDeviceVendorID = 52;
int idcecctrlSetLogicalAddress = 53;
int idcecctrlSetOSDName = 54;
int idcecctrlSetVersion = 55;
int idcecctrlSetWakeupMode = 56;
int idcectxTransmit = 57;
int idclkAlarmIsSet = 58;
int idclkCancelAlarm = 59;
int idclkCausedWakeup = 60;
int idclkClockIsSet = 61;
int idclkGetAlarm = 62;
int idclkGetLocalTime = 63;
int idclkGetLocalTimeOffset = 64;
int idclkGetUniversalTime = 65;
int idclkRunDuringStandby = 66;
int idclkSecondsSinceWakeup = 67;
int idclkSetAlarm = 68;
int idclkSetClock = 69;
int idclkSetWakeupMode = 70;
int idcryptCrypt = 71;
int iddbbrwseGetPacket = 72;
int iddbbrwseGetPacketLength = 73;
int iddbtfHasLastFileAccessSucceeded = 74;
int iddbtfIsFilePresent = 75;
int iddbtfSendData = 76;
int iddbtfciGetId = 77;
int iddbtfciHasLastFileAccessSucceeded = 78;
int iddbtfciIsFilePresent = 79;
int iddbtfciSendData = 80;
int iddmpctrDisableMagicKeys = 81;
int iddmpctrEnableMagicKeys = 82;
int iddmpctrMakeDebugDump = 83;
int idevlogctrClearLog = 84;
int idevlogctrGetHwLogRecord = 85;
int idevlogctrGetLastAlign = 86;
int idevlogctrGetLastLogCleared = 87;
int idevlogctrGetLoggedEvents = 88;
int idevlogctrGetLogRecord = 89;
int idevlogctrGetNumReboots = 90;
int idevlogctrGetNvmIntegCheck = 91;
int idevlogctrGetSwVersion = 92;
int idevlogctrHwClearLog = 93;
int idevlogctrHwGetLastLogCleared = 94;
int idevlogctrHwGetLoggedEvents = 95;
int idevlogctrSetLastKey = 96;
int idevlogctrSetLastKeyUp = 97;
int idevlogctrSetLastSrc = 98;
int idevlogctrSetNvmIntegCheck = 99;
int idevlogctrSetSwVersion = 100;
int idfopsIsPartitionMounted = 101;
int idfopsPartitionMount = 102;
int idfopsPartitionUnmount = 103;
int idgioPinGetAlt = 104;
int idgioPinGetLatch = 105;
int idgioPinGetLine = 106;
int idgioPinGetMode = 107;
int idgioPinSetAlt = 108;
int idgioPinSetLatch = 109;
int idgioPinSetMode = 110;
int idgioPortGetLatch = 111;
int idgioPortGetLine = 112;
int idgioPortSetAlt = 113;
int idgioPortSetLatch = 114;
int idgioPortSetMode = 115;
int idi2ccBlockBus = 116;
int idi2ccEnterIdleMode = 117;
int idi2ccGetBlocked = 118;
int idi2ccGetControlWord = 119;
int idi2ccGetIdle = 120;
int idi2ccGetMasterEnabled = 121;
int idi2ccGetSlaveEnabled = 122;
int idi2ccLeaveIdleMode = 123;
int idi2ccMasterDisable = 124;
int idi2ccMasterEnable = 125;
int idi2ccSetBitRate = 126;
int idi2ccSetMasterTimeout = 127;
int idi2ccSlaveDisable = 128;
int idi2ccSlaveEnable = 129;
int idi2ccUnblockBus = 130;
int idi2cmRead = 131;
int idi2cmWrite = 132;
int idi2cmWriteRead = 133;
int idinfraitfGetAvailableInterfaces = 134;
int idishaFinish = 135;
int idishaInit = 136;
int idishaUpdate = 137;
int idkeyiDown = 138;
int idkeyiUp = 139;
int idledDisablePlfLedControl = 140;
int idledEnablePlfLedControl = 141;
int idledGetIntensity = 142;
int idledIntensitySupported = 143;
int idledIsPlfLedControlEnabled = 144;
int idledSetBlinking = 145;
int idledSetFlash = 146;
int idledSetIntensity = 147;
int idledSetLightGuide = 148;
int idledSetPermanent = 149;
int idncdMem = 150;
int idnetCheckDnsStatus = 151;
int idnetConfigInterfaceAutomatic = 152;
int idnetConfigInterfaceStatic = 153;
int idnetEnableNetworkInterface = 154;
int idnetGetEnabledNetworkInterface = 155;
int idnetGetEnabledNetworkInterfaceStatus = 156;
int idnetGetInterfaceConfig = 157;
int idnetgetMaxNoOfAutomaticWirelessDevicesSupported = 158;
int idnetgetMaxNoOfManualWirelessDevicesSupported = 159;
int idnetgetMaxNoOfNetworkinterfacesSupported = 160;
int idnetGetNetworkConfigMode = 161;
int idnetGetNetworkInterfaceConfigStatus = 162;
int idnetGetNetworkInterfaceMacAddress = 163;
int idnetGetNetworkInterfaceName = 164;
int idnetGetNetworkInterfacePhysicalStatus = 165;
int idnetGetNetworkInterfaceThroughput = 166;
int idnetGetNetworkInterfaceType = 167;
int idnetGetNetworkInterfaceVersion = 168;
int idnetGetNumberOfNetworkInterfaces = 169;
int idnetGetNumberOfWifiDevices = 170;
int idnetGetSelectedWiFiDevice = 171;
int idnetGetStoredStaticInterfaceConfig = 172;
int idnetIsInitializationDone = 173;
int idnetIsNetworkModeVirgin = 174;
int idnetSelectWiFiDevice = 175;
int idnetSetNetworkToModeVirgin = 176;
int idnetWifiGetChannel = 177;
int idnetWifiGetChannelWifiDevice = 178;
int idnetWifiGetEffectiveSignalStrength = 179;
int idnetWifiGetEffectiveThroughput = 180;
int idnetWifiGetEncryptionMode = 181;
int idnetWifiGetEncryptionModeWifiDevice = 182;
int idnetWifiGetKey = 183;
int idnetWifiGetPortType = 184;
int idnetWifiGetPortTypeWifiDevice = 185;
int idnetWifiGetSignalStrengthWifiDevice = 186;
int idnetWifiGetSsidWifiDevice = 187;
int idnetWifiGetThroughputWifiDevice = 188;
int idnetWifiSetChannel = 189;
int idnetWifiSetEncryptionMode = 190;
int idnetWifiSetKey = 191;
int idnetWifiSetPortType = 192;
int idnet2CheckDnsStatus = 193;
int idnet2ConfigInterfaceAutomatic = 194;
int idnet2ConfigInterfaceStatic = 195;
int idnet2EnableNetworkInterface = 196;
int idnet2GetEnabledNetworkInterface = 197;
int idnet2GetInterfaceConfig = 198;
int idnet2getMaxNoOfAutomaticWirelessDevicesSupported = 199;
int idnet2getMaxNoOfManualWirelessDevicesSupported = 200;
int idnet2getMaxNoOfNetworkinterfacesSupported = 201;
int idnet2GetNetworkConfigMode = 202;
int idnet2GetNetworkInterfaceConfigStatus = 203;
int idnet2GetNetworkInterfaceMacAddress = 204;
int idnet2GetNetworkInterfaceName = 205;
int idnet2GetNetworkInterfacePhysicalStatus = 206;
int idnet2GetNetworkInterfaceThroughput = 207;
int idnet2GetNetworkInterfaceType = 208;
int idnet2GetNetworkInterfaceVersion = 209;
int idnet2GetNumberOfNetworkInterfaces = 210;
int idnet2GetNumberOfWifiDevices = 211;
int idnet2GetStoredStaticInterfaceConfig = 212;
int idnet2IsInitializationDone = 213;
int idnet2IsNetworkModeVirgin = 214;
int idnet2SelectWifiAntennas = 215;
int idnet2SetNetworkToModeVirgin = 216;
int idnet2WifiFindManualSsid = 217;
int idnet2WifiGenerateWpsPin = 218;
int idnet2WifiGetChannel = 219;
int idnet2WifiGetChannelWifiDevice = 220;
int idnet2WifiGetEffectiveSignalStrength = 221;
int idnet2WifiGetEffectiveThroughput = 222;
int idnet2WifiGetEncryptionMode = 223;
int idnet2WifiGetEncryptionModeWifiDevice = 224;
int idnet2WifiGetKey = 225;
int idnet2WifiGetMacAddress = 226;
int idnet2WifiGetMacAddressWifiDevice = 227;
int idnet2WifiGetPortType = 228;
int idnet2WifiGetPortTypeWifiDevice = 229;
int idnet2WifiGetSignalStrengthWifiDevice = 230;
int idnet2WifiGetSsid = 231;
int idnet2WifiGetSsidWifiDevice = 232;
int idnet2WifiGetThroughputWifiDevice = 233;
int idnet2WifiGetWpsModeWifiDevice = 234;
int idnet2WifiScanWifiDevices = 235;
int idnet2WifiSetChannel = 236;
int idnet2WifiSetEncryptionMode = 237;
int idnet2WifiSetKey = 238;
int idnet2WifiSetPortType = 239;
int idnet2WifiSetSsid = 240;
int idnet2WifiStartWpsConnection = 241;
int idp2pacNOnExecutionCompleted = 242;
int idp2pacNOnTransmissionCompleted = 243;
int idp2pahWriteASync = 244;
int idp2pahWriteASyncNoRetry = 245;
int idp2pahWriteCharASync = 246;
int idp2pahWriteCharASyncNoRetry = 247;
int idp2pahWriteCharNoSync = 248;
int idp2pahWriteCharNoSyncNoRetry = 249;
int idp2pahWriteNoSync = 250;
int idp2pahWriteNoSyncNoRetry = 251;
int idresmgrAcquire = 252;
int idresmgrRelease = 253;
int idsecstoCheck = 254;
int idsecstoGetPacket = 255;
int idsecstoGetPacketLength = 256;
int idsecstoLoad = 257;
int idsecstoStore = 258;
int idsecstoUnload = 259;
int idshmemCacheFlush = 260;
int idshmemCacheInvalidate = 261;
int idshmemFree = 262;
int idshmemMalloc = 263;
int idshmemMallocAlign = 264;
int idshmemMmspCreate = 265;
int idshmemMmspDelete = 266;
int iduartctlSetBaudRate = 267;
int iduartprintDisable = 268;
int iduartprintEnable = 269;
int iduartprintIsEnabled = 270;
int iduidGetSoCUniqueID = 271;
int idupginfGetCurrentTvSwDescription = 272;
int idupginfGetUpgHeaderSize = 273;
int idupginfGetUpgInfo = 274;
int idupginf2GetCurrentTvSwDescription = 275;
int idupginf2GetUpgInfo = 276;
int idupginf3GetCurrentTvSwDescription = 277;
int idupginf3GetUpgInfo = 278;
int idupgtoolGetUpgLoadingProgress = 279;
int idupgtoolGetUpgLoadingStatus = 280;
int idupgtoolGetUpgProgrammingProgress = 281;
int idupgtoolGetUpgProgrammingStatus = 282;
int idupgtoolGetUpgValidationProgress = 283;
int idupgtoolGetUpgValidationStatus = 284;
int idupgtoolStartUpgLoading = 285;
int idupgtoolStartUpgProgramming = 286;
int idupgtoolStartUpgValidation = 287;
int idupgtoolStopUpgLoading = 288;
int idupgtoolStopUpgProgramming = 289;
int idupgtoolStopUpgValidation = 290;
int idupgtool2GetUpgLoadingProgress = 291;
int idupgtool2GetUpgLoadingStatus = 292;
int idupgtool2GetUpgProgrammingProgress = 293;
int idupgtool2GetUpgProgrammingStatus = 294;
int idupgtool2GetUpgValidationProgress = 295;
int idupgtool2GetUpgValidationStatus = 296;
int idupgtool2StartUpgLoading = 297;
int idupgtool2StartUpgProgramming = 298;
int idupgtool2StartUpgValidation = 299;
int idupgtool2StopUpgLoading = 300;
int idupgtool2StopUpgProgramming = 301;
int idupgtool2StopUpgValidation = 302;
int idusbdevGetActiveDevicesList = 303;
int idusbdevGetDeviceInfo = 304;
int idusbdevGetPhysDeviceMemberList = 305;
int idusbdevGetPhysDevicesList = 306;
int idusbdevGetUsbMaxDevices = 307;
int idusbdevGetUsbMaxPartitionsPerDevice = 308;
int idusbdev2GetActiveDevicesList = 309;
int idusbdev2GetDeviceInfo = 310;
int idusbdev2GetPhysDeviceMemberList = 311;
int idusbdev2GetPhysDevicesList = 312;
int idusbdev2GetUsbMaxDevices = 313;
int idusbdev2GetUsbMaxPartitionsPerDevice = 314;
int idusbdev2IsInitializationDone = 315;
int idvidstorFormat = 316;
int idvidstorGetFreeSize = 317;
int idvidstorGetSize = 318;
int idvidstorGetSpeedClass = 319;
int idvidstorGetState = 320;
int idvidstorGetWriteProtected = 321;
int idvidstorIsInitialisationDone = 322;
int idvidstor2Format = 323;
int idvidstor2GetFreeSize = 324;
int idvidstor2GetMountPoint = 325;
int idvidstor2GetSize = 326;
int idvidstor2GetSpeedClass = 327;
int idvidstor2GetState = 328;
int idvidstor2GetWriteProtected = 329;
int idvidstor2IsInitialisationDone = 330;
int plfapiinfraMethodID_Last = 331;


int idcecrxntfOnReceived = 0;
int idcectxntfOnTransmitCompleted = 1;
int idclkntfOnAlarm = 2;
int idclkntfOnClockChanged = 3;
int idclkntfxOnAlarm = 4;
int idclkntfxOnAlarmCancelled = 5;
int idclkntfxOnClockChanged = 6;
int idfopsNOnPartitionMounted = 7;
int idfopsNOnPartitionMountFailed = 8;
int idfopsNOnPartitionUnmounted = 9;
int idinfraitfNOnAvailabilityChanged = 10;
int idnet2exexNOnDnsStatusChecked = 11;
int idnet2exexNOnInitializationDone = 12;
int idnet2exexNOnNetworkInterfaceConfigStatusChanged = 13;
int idnet2exexNOnNetworkInterfacePhysicalStatusChanged = 14;
int idnet2exexNOnWifiManualSsidFound = 15;
int idnet2exexNOnWifiScanWifiDevicesCompleted = 16;
int idnet2exexNOnWifiSignalFound = 17;
int idnet2exexNOnWifiSignalLost = 18;
int idnet2exexNOnWpsConnectionFinished = 19;
int idnet2exNOnDnsStatusChecked = 20;
int idnet2exNOnInitializationDone = 21;
int idnet2exNOnNetworkInterfaceConfigStatusChanged = 22;
int idnet2exNOnNetworkInterfacePhysicalStatusChanged = 23;
int idnet2exNOnWifiManualSsidFound = 24;
int idnet2exNOnWifiScanWifiDevicesCompleted = 25;
int idnet2exNOnWifiSignalFound = 26;
int idnet2exNOnWifiSignalLost = 27;
int idnet2NOnDnsStatusChecked = 28;
int idnet2NOnInitializationDone = 29;
int idnet2NOnNetworkInterfaceConfigStatusChanged = 30;
int idnet2NOnNetworkInterfacePhysicalStatusChanged = 31;
int idnet2NOnWifiManualSsidFound = 32;
int idnet2NOnWifiSignalFound = 33;
int idnet2NOnWifiSignalLost = 34;
int idnetexexNOnDnsStatusChecked = 35;
int idnetexexNOnIpConfigurationConflict = 36;
int idnetexexNOnNetworkInterfaceConfigStatusChanged = 37;
int idnetexexNOnNetworkInterfacePhysicalStatusChanged = 38;
int idnetexexNOnSelectedWifiDeviceDisappeared = 39;
int idnetexexNOnWifiSelectionCompleted = 40;
int idnetexNOnDnsStatusChecked = 41;
int idnetexNOnIpConfigurationConflict = 42;
int idnetexNOnNetworkInterfaceConfigStatusChanged = 43;
int idnetexNOnNetworkInterfacePhysicalStatusChanged = 44;
int idnetNOnIpConfigurationConflict = 45;
int idnetNOnNetworkInterfaceConfigStatusChanged = 46;
int idnetNOnNetworkInterfacePhysicalStatusChanged = 47;
int idp2pacWriteASync = 48;
int idp2pacWriteASyncNoRetry = 49;
int idp2pacWriteNoSync = 50;
int idp2pacWriteNoSyncNoRetry = 51;
int idp2pacxWriteASync = 52;
int idp2pacxWriteASyncNoRetry = 53;
int idp2pacxWriteCharASync = 54;
int idp2pacxWriteCharASyncNoRetry = 55;
int idp2pacxWriteCharNoSync = 56;
int idp2pacxWriteCharNoSyncNoRetry = 57;
int idp2pacxWriteNoSync = 58;
int idp2pacxWriteNoSyncNoRetry = 59;
int idp2pahNOnExecutionCompleted = 60;
int idp2pahNOnTransmissionCompleted = 61;
int idupgtoolNOnProgrammingMessage = 62;
int idupgtoolNOnUpgradeLoaded = 63;
int idupgtoolNOnUpgradeProgrammed = 64;
int idupgtoolNOnUpgradeValidated = 65;
int idusbdevexNOnDeviceError = 66;
int idusbdevexNOnDeviceInfoChanged = 67;
int idusbdevexNOnDeviceRemoved = 68;
int idusbdevexNOnDriveMounted = 69;
int idusbdevexNOnDriveUnmounted = 70;
int idusbdevexNOnInitializationDone = 71;
int idusbdevexNOnNewDevice = 72;
int idusbdevexNOnPhysicalDeviceConnected = 73;
int idusbdevexNOnPhysicalDeviceDisconnected = 74;
int idusbdevNOnDeviceError = 75;
int idusbdevNOnDeviceInfoChanged = 76;
int idusbdevNOnDeviceRemoved = 77;
int idusbdevNOnDriveMounted = 78;
int idusbdevNOnDriveUnmounted = 79;
int idusbdevNOnNewDevice = 80;
int idusbdevNOnPhysicalDeviceConnected = 81;
int idusbdevNOnPhysicalDeviceDisconnected = 82;
int idvidstorNOnInitialisationDone = 83;
int idvidstorNOnSDCardFormatProgress = 84;
int idvidstorNOnSDCardFormatted = 85;
int idvidstorNOnSDCardInserted = 86;
int idvidstorNOnSDCardMounted = 87;
int idvidstorNOnSDCardMountFailed = 88;
int idvidstorNOnSDCardRemoved = 89;
int idvidstorNOnSDCardUnmounted = 90;
int idvidstorNOnSDCardUnmountFailed = 91;
int plfapiinfraNotificationID_Last = 92;

char *plfapiinfraIpcVersion = "1.16.201003231652";
