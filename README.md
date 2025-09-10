# SaberOS_V1
The first C++ iteration of my lightsaber OS (Pre university) 

The project was done using C++ code on an arduino Nano V1. The entire system (electronics) was also developed by me. 

The blade itself uses WS2812B LEDs.

The chassis is ran by a Arduino nano, powered by a 30Amp 18650 samsung battery with its own charging chip (Used in battery banks). This same chip also does help with the voltage boostup from 3v to 5v. The system is controlled using the tactile momentary push button.

The momentary push button if pressed fast (less than 0.5sec) the blade ignites fast or retracts fast. If pressed and held for over 0.5sec, will ignite or retract slowely. This works as a pseudo gesture control and will be itterated on once i expand the functionality. 
