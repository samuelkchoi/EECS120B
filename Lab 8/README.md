# Exercises

## Prelab
*Wire accordingly*  
**INPUT:**  
  * *PA[0] connected to potentiometer.*  
**OUTPUT:**  
  * *PB[7:0] connected to LEDs PD[1:0] connected to LEDs.*

## 1. 
*Make sure your breadboard is wired according to the prelab. The potentiometer is used to adjust the voltage supplied to the microcontroller for ADC . Design a system that reads the 10-bit ADC result from the ADC register, and displays the result on a bank of 10 LEDs.*

## 2. 
*Revise Part 1 by replacing the potentiometer with a photoresistor and 330 
ohm resistor. Take note of the highest ADC value displayed when the photoresistor is exposed to light, and the lowest ADC value displayed when the photoresistor is deprived of all light. These values will be used for the remaining lab exercises.*

## 3. 
*Design a system where an LED is illuminated if enough light is detected from the photo resistor.*  
**Criteria**
  * *If the result of the ADC is >= MAX/2, the LED is illuminated.*
  * *If the result of the ADC is < MAX/2, the LED is turned off.*

 
