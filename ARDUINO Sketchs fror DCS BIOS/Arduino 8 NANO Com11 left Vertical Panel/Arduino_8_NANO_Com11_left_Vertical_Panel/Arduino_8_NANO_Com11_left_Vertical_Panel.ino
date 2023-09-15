/*
  Tell DCS-BIOS to use a serial connection and use interrupt-driven
  communication. The main program will be interrupted to prioritize
  processing incoming data.
  
  This should work on any Arduino that has an ATMega328 controller
  (Uno, Pro Mini, many others).
 */
#define DCSBIOS_IRQ_SERIAL

#include "DcsBios.h"

//==================================================================
//==================================================================
//Left Vertical Panel UP
//=================================================================
//
//Emergency/Parking Brake Rotate
DcsBios::Switch2Pos emergencyParkingBrakeRotate("EMERGENCY_PARKING_BRAKE_ROTATE", 3);

//Emergency/Parking Brake Pull
DcsBios::Switch2Pos emergencyParkingBrakePull("EMERGENCY_PARKING_BRAKE_PULL", 4,true);

//Emergency Gear Rotate
DcsBios::Switch2Pos emergencyGearRotate("EMERGENCY_GEAR_ROTATE", 5);

//Gear Lever
DcsBios::Switch2Pos gearLever("GEAR_LEVER", 6,true);

//Landing Gear Override
DcsBios::Switch2Pos gearDownlockOverrideBtn("GEAR_DOWNLOCK_OVERRIDE_BTN", 7);

//Warning Tone Silence Button - Push to silence
DcsBios::Switch2Pos gearSilenceBtn("GEAR_SILENCE_BTN", 8);

//====================================================================
//====================================================================
//Pilot chair
//====================================================================

//Seat Height Adjustment Switch, UP/HOLD/DOWN
DcsBios::Switch3Pos seatHeightSw("SEAT_HEIGHT_SW", 9, 10);

//Shoulder Harness Control Handle, LOCK/UNLOCK
DcsBios::Switch2Pos shldrHarnessSw("SHLDR_HARNESS_SW", 11);

//Ejection Control Handle
DcsBios::Switch2Pos ejectionHandleSw("EJECTION_HANDLE_SW", 12);

void setup() {
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();
}
