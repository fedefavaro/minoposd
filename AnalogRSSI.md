# Analog RSSI on MinimOSD #

Since there are quite some Analog ports available on the MinimOSD is is relatively easy to get Analog RSSI displayed on MinOPOSD.

## Hardware ##

Just like the FlightBatt implementation you have to solder a wire directly on one of the ATmega328p pins. See the FlightBatt page for pictures.

Analog ports A0 to A5 are free to use, these are pins 23-28 on the ATmega 328p (See [this page](http://avrprogrammers.com/atmega328bd.php) for the pinout).
Pin 24 or 25 (A1 or A2) are a good choice as they are more accessible for soldering.

### Case 1: Receiver provides Analog RSSI ###
Connect your receiver RSSI output to the selected port on the ATmega 328p **through a voltage divider**. The divider needs to be calculated to deliver 1.1V at maximum RSSI.

Example: if your RSSI signal delivered by the receiver is 0-3.3V, you can use the following divider (values from a standard E12 set):
|    | **value** |
|:---|:----------|
| [R1](https://code.google.com/p/minoposd/source/detail?r=1) | 100kOhm   |
| [R2](https://code.google.com/p/minoposd/source/detail?r=2) |  47kOhm   |
(You can add a 100nF capacitor to act as filter).

### Case 2: Receiver provides PWM RSSI ###
Some [FrSky](http://www.frsky-rc.com) receivers (D4R-II, D8R-XP, ...) provide RSSI as a PWM signal. The issue is that the frequency of the signal is way to high to be decoded by the ATmeg328 (110 kHz).

There is however a simple solution to this: one can easily convert the PWM signal to an analog voltage using and RC filter.

Just as for the pure analog case we still have to divide the voltage to end in the 0-1.1V range.

Here is an RC filter / divider which works nicely for the [FrSky](http://www.frsky-rc.com) receivers:

![http://minoposd.googlecode.com/svn/wiki/images/AnalogRSSI_001.png](http://minoposd.googlecode.com/svn/wiki/images/AnalogRSSI_001.png)
|    | **value** |
|:---|:----------|
| [R4](https://code.google.com/p/minoposd/source/detail?r=4) | 110kOhm   |
| [R8](https://code.google.com/p/minoposd/source/detail?r=8) |  47kOhm   |
| C4 | 100nF     |

If the PWM frequency or the output voltage of your receiver is not the same, the filter needs to be recalculated.

## MinOPOSD (Firmware) ##
By default Analog RSSI support is disabled in the MinOPOSD firmware.

You need to enable it -- in OSD\_Config.h:
```
// JRChange: PacketRxOk on MinimOSD:
// #define PACKETRXOK_ON_MINIMOSD
// Amedee: Analog RSSI on MinimOSD:
#define ANALOG_RSSI_ON_MINIMOSD
```
(Disable `PACKETRXOK_ON_MINIMOSD` if it is enabled)

Check as well you are using the right port on the ATmega328p -- in AnalogRSSI.h:
```
#define RSSI_PIN			1			// A1 is pin 24
```

Compile, upload on your board and your are good to go! (See [Compiling the source](Compiling.md) for more details.)

## Calibrating (Software) ##
Calibration is done through the Configuration Tool.

First you need to **check** the 'RSSI Enable Raw' check box

![http://minoposd.googlecode.com/svn/wiki/images/AnalogRSSI_002.png](http://minoposd.googlecode.com/svn/wiki/images/AnalogRSSI_002.png)

This will show in the OSD the raw value of the signal (0-255 range).
Save the tab, connect the OSD and note down the minimum (radio off) and the maximum (radio on) values.

Go back to the Config Tool, enter these values in the 'RSS Min Value' / 'RSSI Max Value' fields, uncheck the 'RSSI Enable Raw' check box and save again to your board.

You should now be able to see the RSSI in percent in the OSD.
(Be careful it is **not** linear)

Enjoy!