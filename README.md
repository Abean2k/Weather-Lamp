# Weather-Lamp

<img width="640" height="512" alt="WeatherLamp" src="https://github.com/user-attachments/assets/3f4f7111-9195-4dd4-81e7-4f9aac081856" />


A lamp with 5 RGB LED's that connects to the weather to display the "mood" outside. Made for STASIS. 

## Design:
I wanted this lamp to be small and unique. This is why I choose to make a more difficult, but better looking crystal/geode lamp. I also wanted to have an OLED to convey the exact temperature which was something the rgb lamp could not. For the base of the design I tried to keep it as minimalist as possible, which led to it essentially wrapping around the circular pcb, with a flat front surface for the oled. 

## PCB:
I made my 2 layered pcb for this project on kicad. I choose to use a pcb for this project in order to keep the lamp internals neat and professional looking. The design of this pcb keeps the LEDs in a circle with one in the center and the microcontroller and capacitor on the back side. For the OLED a header allows me to connect and solder the wires to the pcb to the OLED while allowing the OLED to be in a different direction from my LEDs and microcontroller.

### Schematic
<img width="752" height="642" alt="1776021340577-kuo91q" src="https://github.com/user-attachments/assets/dc116f24-9be4-4f96-b6b4-36053ce2b655" />

### PCB Layout
<img width="502" height="457" alt="1776021296768-2o2wdi" src="https://github.com/user-attachments/assets/984c5f7c-0170-482d-a0b4-d3692f463a33" />



## Firmware:
The firmware for this project was made in arduino in c++. It tells the microcontroller how to fetch data from OpenWeather and use the temperature and weather code data from that to light up the LEDs and display the temperature on the OLED in fahrenheit. 

## BOM:
<img width="292" height="258" alt="image" src="https://github.com/user-attachments/assets/8a9bff82-8bac-4212-93fa-e9cf2437f915" />
Note: For items with more than my reqired amount it is due to min order limits. 
