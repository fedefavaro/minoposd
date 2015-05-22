# Setting OpenPilot to communicate with MinimOSD #


Everything about OpenPilot can be found here: http://www.openpilot.org/



---



On this page you can find the information what you have to configure to use the MinimOSD with CC3D or Revo.


Over all hardware settings:

| **Port** | **External** |
|:---------|:-------------|
| FlexiPort | GPS          |
| MainPort | Telemetry    |
| RcvrPort | whatever you are using |


![http://minoposd.googlecode.com/svn/wiki/images/HWsettingsGPSTelemetry.jpg](http://minoposd.googlecode.com/svn/wiki/images/HWsettingsGPSTelemetry.jpg)


Currently the best results for GPS were found using 38400 baud and an update rate of 5Hz.
With higher update rates the OpenPilot gets event warnings and CPU overloads!



---



All about using GPS at CC3D can be found in the OpenPilot wiki http://wiki.openpilot.org/display/Doc/GPS+Add-on

For using the GPS you have to choose the DataProtocol type of your GPS.

In this example I'm using NMEA for the LOCOSYS LS20033 GPS. If you are using the u-blox NEO-6M or OpenPilot GPS, then choose UBX.

(find a config file for the u-blox NEO-6M here: http://code.google.com/p/minoposd/source/browse/#svn%2Ftrunk%2Fconfigs )

![http://minoposd.googlecode.com/svn/wiki/images/GPSSettings.jpg](http://minoposd.googlecode.com/svn/wiki/images/GPSSettings.jpg)

You also have to enable GPS under HWSettings OptionalModules.

It is a good idea to enable the ComUsbBridge at this stage, so you can configure your GPS using the CC3D as virtual com port later.

![http://minoposd.googlecode.com/svn/wiki/images/HWsettingsOptionalModules.jpg](http://minoposd.googlecode.com/svn/wiki/images/HWsettingsOptionalModules.jpg)



---



Double check if the AttitudeActual Flight Telemetry Update Period is 100ms.

![http://minoposd.googlecode.com/svn/wiki/images/AttitudeActual.jpg](http://minoposd.googlecode.com/svn/wiki/images/AttitudeActual.jpg)



---



To have a faster response to your RC inputs you have to change the ManualControlCommand Flight Telemetry Update Period to 500ms.

![http://minoposd.googlecode.com/svn/wiki/images/ManualControlCommand.jpg](http://minoposd.googlecode.com/svn/wiki/images/ManualControlCommand.jpg)



---



If you like a faster OSD panel update of GPS position changes you can change the GPSPosition Flight Telemetry Update Period to 200ms.

![http://minoposd.googlecode.com/svn/wiki/images/GPSPosition.jpg](http://minoposd.googlecode.com/svn/wiki/images/GPSPosition.jpg)



---



If you like a faster OSD panel update of GPS velocity changes you can change the GPSVelocity Flight Telemetry Update Period to 200ms.

![http://minoposd.googlecode.com/svn/wiki/images/GPSVelocity.jpg](http://minoposd.googlecode.com/svn/wiki/images/GPSVelocity.jpg)



---



When you have to configure your GPS you can **temporarily** configure ComBridge, but don't forget to **change it back** as shown in the first picture!

More about using ComBridge of CC3D can be found in the OpenPilot wiki http://wiki.openpilot.org/display/Doc/Hardware+Settings#HardwareSettings-VirtualCommPortConfiguration

Set the ComUsbBridge speed to the speed your GPS is using.

![http://minoposd.googlecode.com/svn/wiki/images/HWsettingsComBridge.jpg](http://minoposd.googlecode.com/svn/wiki/images/HWsettingsComBridge.jpg)