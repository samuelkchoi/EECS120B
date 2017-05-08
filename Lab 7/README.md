# Exercises

# 1. 
*Connect LEDs to PB0, PB1, PB2, and PB3. In one state machine (Three LEDs), output to a shared variable (threeLEDs) the following behavior: set only bit 0 to 1, then only bit 1, then only bit 2 in sequence for 1 second each. In a second state machine (Blinking LED), output to a shared variable (bilnkingLED) the following behavior: set bit 3 to 1 for 1 second, then 0 for 1 second. In a third state machine (Combine LEDs), combine both shared variables and output to the PORTB. Note: only one SM is writing to outputs.*

# 2. 
*Modify the above example so the three LEDs light for 300 ms, while PB3's LED still blinks 1 second on and 1 second off.*

# 3. 
*To the previous exercise's implementation, connect your speaker's red wire to PB4 and black wire to ground. Add a third task that toggles PB4 on for 2 ms and off for 2 ms as long as a switch on PA2 is in the on position. *
 
