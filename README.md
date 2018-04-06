# HomeAutomation:

Just some centralized controlled home automation project... :)


## Philips Hue:
[Hue API reference](https://www.developers.meethue.com/philips-hue-api)

- Bridges
- Lights
- Sensors


## Philips Smart Tv
[jointspace API reference](http://jointspace.sourceforge.net/projectdata/documentation/jasonApi/)

Tested:
Some example : 
Input Key
Methode : POST 
http://10.10.10.50:1925/5/input/key
Example of argument : 
{"key": "WatchTV"}

Change Channels
Methode : GET 
http://10.10.10.50:1925/5/activities/tv
Methode : POST 
http://10.10.10.50:1925/5/activities/tv
Example of argument : 
{"channelList":{"id":"alltv","version":"6"},"channel":{"name":"France 4","preset":14,"ccid":26}}

Active Lounge Light
Methode : POST 
http://10.10.10.50:1925/5/ambilight/mode
Example of argument : 
{"current" : "lounge"}

Modify loung light
Methode : POST 
http://10.10.10.50:1925/5/ambilight/lounge
Example of argument : 
{"color":{"hue":242,"saturation":224,"brightness":255},"colordelta":{"hue":50,"saturation":26,"brightnesss":255},"speed":100,"mode":"Default"}

Active / Stop Ambilight
Methode : POST 
http://10.10.10.50:1925/5/ambilight/power
Example of argument : 
{"power" : "Off"}


Temp notes:

    POST /upnp/control/RenderingControl1 HTTP/1.1
    HOST: 10.0.0.112:49153
    CONTENT-LENGTH: 290
    CONTENT-TYPE: text/xml; charset="utf-8"
    SOAPACTION: "urn:schemas-upnp-org:service:RenderingControl:3#GetMute"
    USER-AGENT: Windows2000/0.0 UPnP/1.0 PhilipsIntelSDK/1.4 DLNADOC/1.50

    <s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/"
    s:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/">
    <s:Body>
    <u:GetMute    xmlns:u="urn:schemas-upnp-org:service:RenderingControl:3"><InstanceID>0</InstanceID><Channel>Master</Channel></u:   GetMute></s:Body>
    </s:Envelope>


    HTTP/1.1 200 OK
    CONTENT-LENGTH: 281
    CONTENT-TYPE: text/xml; charset="utf-8"
    DATE: Fri, 04 Mar 2016 22:25:48 GMT
    EXT:
    Connection: close
    SERVER: Linux2.6/0.0 UPnP/1.0 PhilipsIntelSDK/1.4 DLNADOC/1.50
    X-User-Agent: redsonic
    
    <s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/" s:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/">
    <s:Body><u:GetMuteResponse xmlns:u="urn:schemas-upnp-org:service:RenderingControl:3"><CurrentMute>0</CurrentMute></u:GetMuteResponse></s:Body></s:Envelope>



    GET:

    http://192.168.0.97:49154/nmsDescription.xml
    http://192.168.0.97:49154/nmrAVTransport.xml
    http://192.168.0.97:49154/nmsContentDirectorySCPD.xml
    http://192.168.0.97:49154/nmrConnectionManager.xml
    http://192.168.0.97:49154/nmrRenderingControl.xml

    POST:

    Standby
    Back
    Find
    RedColour
    GreenColour
    YellowColour
    BlueColour
    Home
    VolumeUp
    VolumeDown
    Mute
    Options
    Dot
    Digit0
    Digit1
    Digit2
    Digit3
    Digit4
    Digit5
    Digit6
    Digit7
    Digit8
    Digit9
    Info
    CursorUp
    CursorDown
    CursorLeft
    CursorRight
    Confirm
    Next
    Previous
    Adjust
    WatchTV
    Viewmode
    Teletext
    Subtitle
    ChannelStepUp
    ChannelStepDown
    Source
    AmbilightOnOff
    PlayPause
    Pause
    FastForward
    Stop
    Rewind
    Record
    Online



## Raspberry Pi:
[pigpio API reference](http://abyz.me.uk/rpi/pigpio/pigpiod.html)

- Ledstrip connected by GPIO driven and by PigPio 


## Harman Kardon:
[API reference](https://github.com/KarimGeiger/HKAPI)

- avr171s remote controlled with xml/php


## Todo's :

    - doc (Documents)
    - inf (Information)
    - lib (Libraries)
    - res (Resources)
    - src (Sources)
    - tst (Test)

