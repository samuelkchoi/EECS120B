# Exercises

# 1. 
*A car has a fuel-level sensor that sets PA3..PA0 to a value between 0 (empty) and 15 (full). A series of LEDs connected to PB5..PB0 should light to graphically indicate the fuel level. If the fuel level is 1 or 2, PB5 lights. If the level is 3 or 4, PB5 and PB4 light. 5-6 lights PB5..PB3. 7-9 lights PB5..PB2. 10-12 lights PB5..PB1. 13-15 lights PB5..PB0. Also, PB6 connects to a "Low fuel" icon, which should light if the level is 4 or less. Use buttons on PA3..PA0 and mimic the fuel-level sensor with presses.*

*Now implemented using LEDs*
  
# 2. 
*Buttons are connected to PA0 and PA1. Output for PORTB is initially 0. Pressing PA0 increments PORTB (stopping at 9). Pressing PA1 decrements PORTB (stopping at 0). If both buttons are depressed (even if not initially simultaneously), PORTB resets to 0. If a reset occurs, both buttons should be fully released before additional increments or decrements are allowed to happen. Use LEDs (and resistors) on PORTB. Use a state machine (not synchronous) captured in C.*

*Now implemented using LEDs*

# 3.
*Create your own festive lights display with 6 LEDs connected to port PB5..PB0, lighting in some attractive sequence. Pressing the button on PA0 changes the lights to the next configuration in the sequence.  Use a state machine (not synchronous) captured in C.*
