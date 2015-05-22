# PacketRxOk detection #

For PacketRxOk detection there is a little soldering necessary on the MinimOSD and the used RC receiver.

PacketRxOk detection is the digital version of RSSI.

It uses the green LED on 2.4GHz RC receiver which blinks when packets are lost.

It works well with the LED behavior of the Simprop GigaScan receiver (FASST).

The Futaba FASST receivers begin to blink too late, just before total loss.



---



Only do this if you have some good soldering skills, especially soldering on the RC receiver.

Also only do this if you have the knowledge of what you are doing.

Bad soldering or less knowledge can risk your aerial vehicle and even lives!



---



Because the ATmega 328p needs a level of > 2 volt for detecting a high at input pin (when powered at 5V) we can't solder directly at the green LED.

We have to solder between the output of the receiver MCU pin and the series resistor of the LED.

On the Simprop GigaScan 5 LX this is pin 5 of the Atmel chip.



---



First of all remove the lacquer on the PCB:

![http://minoposd.googlecode.com/svn/wiki/images/PacketRxOk_001.jpg](http://minoposd.googlecode.com/svn/wiki/images/PacketRxOk_001.jpg)

after that tin-coat it:

![http://minoposd.googlecode.com/svn/wiki/images/PacketRxOk_002.jpg](http://minoposd.googlecode.com/svn/wiki/images/PacketRxOk_002.jpg)

then solder a short cable:

![http://minoposd.googlecode.com/svn/wiki/images/PacketRxOk_003.jpg](http://minoposd.googlecode.com/svn/wiki/images/PacketRxOk_003.jpg)

and heat-shrink the receiver:

![http://minoposd.googlecode.com/svn/wiki/images/PacketRxOk_004.jpg](http://minoposd.googlecode.com/svn/wiki/images/PacketRxOk_004.jpg)



---



Since the PAL detection solder-jumper on the MinimOSD isn't used with the new firmware, we can use this pin because it is directly connected to the INT1 input:

![http://minoposd.googlecode.com/svn/wiki/images/PacketRxOk_005.jpg](http://minoposd.googlecode.com/svn/wiki/images/PacketRxOk_005.jpg)

![http://minoposd.googlecode.com/svn/wiki/images/PacketRxOk_006.jpg](http://minoposd.googlecode.com/svn/wiki/images/PacketRxOk_006.jpg)



---



More info will follow on demand.



---
