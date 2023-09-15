#include <Joystick.h>
#include <CD74HC4067.h>

// Ustawienia przycisków
const int numButtons = 160; 
int buttonState[numButtons];
int lastButtonState[numButtons];

// Ustawienia enkoderów
const int numEncoders = 10;
int encoderState[numEncoders];
int lastEncoderState[numEncoders];
int encoderPins[numEncoders][2] = {
  {0, 1},
  {2, 3},
  {4, 5},
  {6, 7},
  {8, 9},
  {10, 11},
  {12, 13},
  {14, 15},
  {16, 17},
  {18, 19}
};

// Ustawienia multiplexera
const int numMuxPins = 6;
const int muxPins[numMuxPins] = {2, 3, 4, 5, 6, 7};
const int muxChannels = 16;
CD74HC4067 buttonMux(numMuxPins, muxPins);
CD74HC4067 encoderMux(numMuxPins, muxPins);

// Ustawienia interfejsu HID
Joystick_ Joystick(0x01, JOYSTICK_TYPE_GAMEPAD,
  numButtons, 0,                   // Liczba przycisków, brak osi
  false, false, false,             // Brak X, Y, Z osi
  false, false, false,             // Brak Rx, Ry, Rz osi
  false, false,                    // Brak rudder, throttle
  false, false, false);            // Brak accelerator, brake, steering

void setup() {
  // Ustawienie pinów multiplexera dla przycisków
  for (int i = 0; i < numMuxPins; i++) {
    pinMode(muxPins[i], OUTPUT);
    digitalWrite(muxPins[i], LOW);
  }
  
  // Ustawienie pinów multiplexera dla enkoderów
  for (int i = 0; i < numEncoders; i++) {
    pinMode(encoderPins[i][0], INPUT_PULLUP);
    pinMode(encoderPins[i][1], INPUT_PULLUP);
  }
  
  // Inicjalizacja multiplexera dla przycisków i enkoderów
  buttonMux.channel(0);
  buttonMux.initialize();
  encoderMux.channel(0);
  encoderMux.initialize();
  
  // Ustawienie początkowych wartości przycisków i enkoderów
  for (int i = 0; i < numButtons; i++) {
    buttonState[i] = 0;
    lastButtonState[i] = 0;
  }
  for (int i = 0; i < numEncoders; i++) {
    encoderState[i] = 0;
    lastEncoderState[i] = 0;



  }
}


void loop() {
  // Odczytujemy wartości klawiszy
  for (int i = 0; i < 160; i++) {
    int buttonValue = buttonMux.read(i);
    if (buttonValue != lastButtonValues[i]) {
      // Zapisujemy nową wartość klawisza
      lastButtonValues[i] = buttonValue;
      
      // Przetwarzamy wartość klawisza i wysyłamy do systemu
      int keyNumber = i + 1;
      if (buttonValue == 1) {
        Joystick.setButton(keyNumber, 1);
      } else {
        Joystick.setButton(keyNumber, 0);
      }
    }
  }

  // Odczytujemy wartości enkoderów
  for (int i = 0; i < 10; i++) {
    int encoderValue = encoderMux.read(i);
    int delta = encoderValue - lastEncoderValues[i];
    if (delta != 0) {
      // Zapisujemy nową wartość enkodera
      lastEncoderValues[i] = encoderValue;
      
      // Przetwarzamy wartość enkodera i wysyłamy do systemu
      int axisNumber = i * 2;
      if (delta < 0) {
        Joystick.setAxis(axisNumber, -1);
        Joystick.setAxis(axisNumber + 1, 0);
      } else if (delta > 0) {
        Joystick.setAxis(axisNumber, 1);
        Joystick.setAxis(axisNumber + 1, 0);
      } else {
        Joystick.setAxis(axisNumber, 0);
        Joystick.setAxis(axisNumber + 1, 0);
      }
    }
  }
  
  // Odstęp między odczytami
  delay(10);