# Exercises

### 1. 
*Using the ATmega1284’s PWM functionality, design a system that uses three buttons to select one of three tones to be generated on the speaker. When a button is pressed, the tone mapped to it is generated on the speaker.*  
**Criteria:**
  * *Use the tones C4, D4, and E4 from the table in the introduction section.*
  * *When a button is pressed and held, the tone mapped to it is generated on the speaker.*
  * *When more than one button is pressed simultaneously, the speaker remains silent.*
  * *When no buttons are pressed, the speaker remains silent.*

### 2. 
*Using the ATmega1284’s PWM functionality, design a system where the notes: C4, D, E, F, G, A, B, and C5,  from the table at the top of the lab, can be generated on the speaker by scaling up or down the eight note scale. Three buttons are used to control the system. One button toggles sound on/off. The other two buttons scale up, or down, the eight note scale.*  
**Criteria:**
  * *The system should scale up/down one note per button press.*
  * *When scaling down, the system should not scale below a C.*
  * *When scaling up, the system should not scale above a C.*

### 3. 
*Using the ATmega1284’s built in PWM functionality, design a system where a short, five-second melody, is played when a button is pressed. NOTE: The melody must be somewhat complex (scaling from C to B is NOT complex).*  
**Criteria:**
  * *When the button is pressed, the melody should play until completion.*
  * *Pressing the button again in the middle of the melody should do nothing.*
  * *If the button is pressed and held, when the melody finishes, it should not repeat until the button is released and pressed again.*

