# Embedded_System_Lab10

Basic 1: Implement a traffic light

The traffic light will set the green LED on for 4 sec,

then the yellow LED on for 2 sec, and the red LED on for 6 sec, and repeat. 

The traffic light will change to the green light when there is an ambulance passing,

which is represented by a buzzer.

The buzzer will be turned on for 4 sec at 2 Hz (0.5 sec on and 0.5 sec off),

indicating that the ambulance will need 4 sec to pass the cross road.

The starting time is set randomly between 7 and 12 sec.

During the 4 sec that the buzzer sounds, the traffic light will be turned to the green LED. 

After the 4 sec, the traffic light returns to normal. 

Set the priority of the tasks properly.

Show the current state and duration of the state on the LCD.

For example: if the green light is on for three seconds,

then show the string “green light” and the number “3” on the LCD.

Basic 2: Implement a simple Screensaver

Silent mode:

The backlight is off.

If the input from the hex keypad is ‘*’, then go to the unlock mode.

Unlock mode:

Turn on the backlight and print “Enter password:”

If the user enters the correct password (at least 3 characters),

then go back to the silent mode. Otherwise, stay in the unlock mode.
