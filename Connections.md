# Hardware connections using OpenPilot with MinimOSD #

All about connecting a GPS to OpenPilot can be found in the OpenPilot wiki http://wiki.openpilot.org/display/Doc/GPS+Add-on

But be aware: If you are using a 3.3V GPS don't connect it directly to the 5V of the OpenPilot JST (FlexiPort) connector.
Use a step down converter instead.


For connecting the OpenPilot with the MinimOSD you have to connect the OpenPilot JST (MainPort) with the MinimOSD as follows:


| **OpenPilot JST** | **MinimOSD** |
|:------------------|:-------------|
| GND               | GND          |
| PWR               | +5V          |
| TX                | RX           |
| RX                | TX           |


But be aware, that the OpenPilot is powered by max. 5V, so the output PWR from OpenPilot only carries 5V.