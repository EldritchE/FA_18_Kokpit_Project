//MicroUSBButtonBox by Les O'Reilly
//
//Arduino IDE 1.6.6 (or above) !
//
//
//This Makes a ZERO Axis with 56 Button USB Controller (Game pad)
//Keypad will configure the Buttons 0-55 

//A3,A2,A1,A0 Are the Row Pins for the Keypad D0-D10,D14-D16 are the Column Pins
//Button 0 wires as A3+D16 Where A3 is Row and D13 is Column, Button 13 - A3+D0
//Button 14 wires as A2+D16 ...Button 27 A2+D0
//Button 28 wires as A1+D16...Button 41 A1+D0
//Button 42 wires as A0+D16....Button 55 A0+D0


#include <Keypad.h>
#include <Joystick.h>


#define NUMBUTTONS 56
#define NUMROWS 4
#define NUMCOLS 14


//define the symbols on the buttons of the keypads
byte buttons[NUMROWS][NUMCOLS] = {
  {0,1,2,3,4,5,6,7,8,9,10,11,12,13},
  {14,15,16,17,18,19,20,21,22,23,24,25,26,27},
  {28,29,20,31,32,33,34,35,36,37,38,39,40,41},
  {42,43,44,45,46,47,48,49,50,51,52,53,54,55},
};


byte rowPins[NUMROWS] = {21,20,19,18}; //connect to the row pinouts of the keypad
byte colPins[NUMCOLS] = {16,15,14,10,9,8,7,6,5,4,3,2,1,0}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad buttbx = Keypad( makeKeymap(buttons), rowPins, colPins, NUMROWS, NUMCOLS); 

//initialize an Joystick with 56 buttons;
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, 
  JOYSTICK_TYPE_JOYSTICK, 56, 0,
  false, false, false, false, false, false,
  false, false, false, false, false);


void setup() {
  Joystick.begin();
}


void loop() { 
  CheckAllButtons();
delay(0);
}


void CheckAllButtons(void) {
      if (buttbx.getKeys())
    {
       for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
           if ( buttbx.key[i].stateChanged )   // Only find keys that have changed state.
            {
            switch (buttbx.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                    case HOLD:
                              Joystick.setButton(buttbx.key[i].kchar, 1);
                              break;
                    case RELEASED:
                    case IDLE:
                              Joystick.setButton(buttbx.key[i].kchar, 0);
                              break;
            }
           }   
         }
         
     }
}
