# PUSH-BUTTON-COUNTER

*COMPANY*: CODTECH IT SOLUTIONS

*NAME*: MAHALAKSHMI A

*INTERN ID*: CT04DA198

*DOMAIN*: EMBEDDED SYSTEMS

*DURATION*: 4 WEEKS

*MENTOR*: NEELA SANTOSH

*DESCRIPTION*:
      Implemented a simple push button counter using a PIC microcontroller (PIC16F877A). A digital push button is connected to pin RC5 and every time the button is pressed, the count is incremented and displayed on an LCD screen which is connected to the PORTD.

*KEY FEATURES*:
     ➤ Reads input from a push button (RC5).
     ➤ Displays the count of presses on a 16x2 LCD.
     ➤ Debouncing logic using a button_pressed flag to prevent multiple counts on a single press.
     ➤ Count resets only on power reset; it’s not stored in EEPROM.
     ➤ LCD command/data functions are modular for reusability.
     ➤ Used Funtion sprintf() to convert integer to string for display.
     ➤ All required microcontroller configuration bits are set at the top of the code for proper operation.

*PERIPHERALS USED*:
     • LCD 16x2 display (connected to PORTD)
     • Push Button (connected to RC5)
     • Control Pins for LCD: RS – RC0, EN – RC1
