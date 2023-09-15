/*
  Tell DCS-BIOS to use a serial connection and use interrupt-driven
  communication. The main program will be interrupted to prioritize
  processing incoming data.
  
  This should work on any Arduino that has an ATMega328 controller
  (Uno, Pro Mini, many others).
 */
#define DCSBIOS_IRQ_SERIAL

#include "DcsBios.h"

//========================================================================================
//========================================================================================
//Powrót do panelu przepustnicy 
//Ground Power Switch 2, A ON/AUTO/B ON
DcsBios::Switch3Pos gndPwr2Sw("GND_PWR_2_SW", 3, 2);

//Ground Power Switch 1, A ON/AUTO/B ON
DcsBios::Switch3Pos gndPwr1Sw("GND_PWR_1_SW", 5, 4);

//=========================================================================================
//=========================================================================================
//Panel Vertical Left
//LDG/TAXI LIGHT Switch
DcsBios::Switch2Pos ldgTaxiSw("LDG_TAXI_SW", 6,true);

//Anti Skid
DcsBios::Switch2Pos antiSkidSw("ANTI_SKID_SW", 7,true);

//FLAP Switch, AUTO/HALF/FULL
DcsBios::Switch3Pos flapSw("FLAP_SW", 8, 9);

//Launch Bar
DcsBios::Switch2Pos launchBarSw("LAUNCH_BAR_SW", 10);

//Selective Jettison Pushbutton
DcsBios::Switch2Pos selJettBtn("SEL_JETT_BTN", 11);

//Selective Jettison Knob, L FUS MSL/SAFE/R FUS MSL/ RACK/LCHR /STORES
const byte selJettKnobPins[9] = {12, 13, A0, A1, A2};
DcsBios::SwitchMultiPos selJettKnob("SEL_JETT_KNOB", selJettKnobPins, 6);

//Canopy Jettison Handle Unlock Button - Press to unlock
DcsBios::Switch2Pos canopyJettHandleUnlock("CANOPY_JETT_HANDLE_UNLOCK", A3);

//Canopy Jettison Handle Unlock Button - Press to jettison
DcsBios::Switch2Pos canopyJettHandlePull("CANOPY_JETT_HANDLE_PULL", A4,true);

void setup() {
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();
  delay(50);
}
