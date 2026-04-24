# Weather-Lamp

<img width="640" height="512" alt="WeatherLamp" src="https://github.com/user-attachments/assets/3f4f7111-9195-4dd4-81e7-4f9aac081856" />


A lamp with 5 RGB LED's that connects to the weather usign ESP32 to display the "mood" outside. Made for STASIS. 

## Assembly Guide
### Items you need (Besides the PCB and 3D Printed Parts):
2 M3 6mm-12mm screws
2 M4 6mm-12mm screws

First take the base and slide in the oled screen. Keep the wires up like in the picture so that they line up with the cutout in the base. 
<img width="685" height="637" alt="image" src="https://github.com/user-attachments/assets/cdf47ba9-38de-4929-8c2e-a23fc46220cd" />
Next use the 2 M3 screws to screw the base to the PCB. Make sure to keep the usb on the esp 32 facing the cutout. Also keep LEDs up.
<img width="693" height="538" alt="image" src="https://github.com/user-attachments/assets/14d0435b-ce48-4142-bd3a-1ae64aa430ff" />
Then prepare the top cover by glueing the the translusent petg crystle to the lip of the top cover usign super glue or hotglue. Be careful while handeling the crystle as 1 layered 3d prints are fragile. 
<img width="508" height="689" alt="image" src="https://github.com/user-attachments/assets/889e7063-6810-46d3-8572-2119ca40c74a" />
Finally, take the top cover with the crystle on it and screw it into the base with the 2 M4 screws. 
<img width="305" height="323" alt="image" src="https://github.com/user-attachments/assets/da0908ae-d16e-4e91-8c5f-fd2202e04131" />

That's it, now just ubload firmware and you are good to go :)

## Design:
I wanted this lamp to be small and unique. This is why I choose to make a more difficult, but better looking crystal/geode lamp. I also wanted to have an OLED to convey the exact temperature which was something the rgb lamp could not. For the base of the design I tried to keep it as minimalist as possible, which led to it essentially wrapping around the circular pcb, with a flat front surface for the oled. 

The bottom two peices; bottom case, and top cover will be printed using pla in gray or black and the crystle will be a vase mode print with clear/transulcent PETG. PCB will be assembled by hand.  

## PCB:
I made my 2 layered pcb for this project on kicad. I choose to use a pcb for this project in order to keep the lamp internals neat and professional looking. The design of this pcb keeps the LEDs in a circle with one in the center and the microcontroller and capacitor on the back side. For the OLED a header allows me to connect and solder the wires to the pcb to the OLED while allowing the OLED to be in a different direction from my LEDs and microcontroller.

### Schematic
<img width="752" height="642" alt="1776021340577-kuo91q" src="https://github.com/user-attachments/assets/dc116f24-9be4-4f96-b6b4-36053ce2b655" />

### PCB Layout
<img width="502" height="457" alt="1776021296768-2o2wdi" src="https://github.com/user-attachments/assets/984c5f7c-0170-482d-a0b4-d3692f463a33" />



## Firmware:
The firmware for this project was made in arduino in c++. It tells the microcontroller how to fetch data from OpenWeather and use the temperature and weather code data from that to light up the LEDs and display the temperature on the OLED in fahrenheit. 

#### How to Upload: Plug in usb through the large opening and upload through arudino ide.

## BOM:
<img width="292" height="258" alt="image" src="https://github.com/user-attachments/assets/8a9bff82-8bac-4212-93fa-e9cf2437f915" />
Note: For items with more than my reqired amount it is due to min order limits. 
