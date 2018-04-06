# HomeAutomation:

Just some centralized controlled home automation project... :)
**Note:** the folder `src` contains unrelated items


## Philips Hue:
[Hue API reference](https://www.developers.meethue.com/philips-hue-api)

* Bridges
* Lights
* Sensors


## Philips Smart Tv
[jointspace API reference v1.0 (legancy)](http://jointspace.sourceforge.net/projectdata/documentation/jasonApi/)

Philips 55PFS8209/12 (v5)

  JSON: 
  
  * /activities/tv
  * /ambilight/cached
  * /ambilight/lounge
  * /ambilight/mode
  * /ambilight/measured
  * /ambilight/processed
  * /applications
  * /audio/volume
  * /channeldb/tv
  * /context
  * /input/key
  * /input/pointer
  * /powerstate
  * /system
  * /system/epgsource
  * /system/serialnumber_encrypted
  * /system/nettvversion
  * /system/name
  * /system/model_encrypted
  * /system/menulanguage
  * /system/softwareversion_encrypted
  * /system/deviceid_encrypted
  * /system/country

  GET-Example: GET http://localip:1925/5/activities/tv


  XML:
  * http://localip:49154/nmsDescription.xml
  * http://localip:49154/nmrAVTransport.xml
  * http://localip:49154/nmsContentDirectorySCPD.xml
  * http://localip:49154/nmrConnectionManager.xml
  * http://localip:49154/nmrRenderingControl.xml


## Raspberry Pi:
[pigpio API reference](http://abyz.me.uk/rpi/pigpio/pigpiod.html)

- Ledstrip connected by GPIO 
- Remote controlled by PigPio 


## Harman Kardon:
[API reference](https://github.com/KarimGeiger/HKAPI)

- Avr171s
- Remote controlled with xml/php










## Todo's :

  FOLDERS:
    - doc (Documents)
    - inf (Information)
    - lib (Libraries)
    - res (Resources)
    - src (Sources)
    - tst (Test)

  TESTING:
   POST /upnp/control/RenderingControl1 HTTP/1.1
   HOST: 10.0.0.112:49153
   CONTENT-LENGTH: 290
   CONTENT-TYPE: text/xml; charset="utf-8"
   SOAPACTION: "urn:schemas-upnp-org:service:RenderingControl:3#GetMute"
   USER-AGENT: Windows2000/0.0 UPnP/1.0 PhilipsIntelSDK/1.4 DLNADOC/1.50
   <s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/"
   s:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/">
   <s:Body><u:GetMute    xmlns:u="urn:schemas-upnp-org:service:RenderingControl:3"><InstanceID>0</InstanceID><Channel>Master</Channel></u:   GetMute></s:Body></s:Envelope>
   HTTP/1.1 200 OK
   CONTENT-LENGTH: 281
   CONTENT-TYPE: text/xml; charset="utf-8"
   DATE: Fri, 04 Mar 2016 22:25:48 GMT
   EXT: Connection: close
   SERVER: Linux2.6/0.0 UPnP/1.0 PhilipsIntelSDK/1.4 DLNADOC/1.50
   X-User-Agent: redsonic
      <s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/" s:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/">
   <s:Body><u:GetMuteResponse xmlns:u="urn:schemas-upnp-org:service:RenderingControl:3"><CurrentMute>0</CurrentMute></u:GetMuteResponse></s:Body></s:Envelope>

  GET/POST