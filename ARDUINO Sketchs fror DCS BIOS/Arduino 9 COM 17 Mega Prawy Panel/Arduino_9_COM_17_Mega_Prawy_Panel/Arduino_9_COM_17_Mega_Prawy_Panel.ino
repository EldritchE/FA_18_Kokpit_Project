/*
  Tell DCS-BIOS to use a serial connection and use interrupt-driven
  communication. The main program will be interrupted to prioritize
  processing incoming data.
  
  This should work on any Arduino that has an ATMega328 controller
  (Uno, Pro Mini, many others).
 */
#define DCSBIOS_IRQ_SERIAL

#include "DcsBios.h"

// 25 wolne !!!!!!!!!
//--------------------------------------------------------
//========================================================
//VErtical Panel 
//Hook Lever
DcsBios::Switch2Pos hookLever("HOOK_LEVER", 2);

//Push to Test Switch
DcsBios::Switch2Pos radaltTestSw("RADALT_TEST_SW", 3);

//Set low altitude pointer
DcsBios::RotaryEncoder radaltHeight("RADALT_HEIGHT", "-3200", "+3200", 4, 5);

//AV COOL Switch, NORM/EMERG
DcsBios::Switch2Pos avCoolSw("AV_COOL_SW", 6);

//Wing Fold Control Handle Pull
DcsBios::Switch2Pos wingFoldPull("WING_FOLD_PULL", 7);

//Wing Fold Control Handle, FOLD/HOLD/UNFOLD
DcsBios::Switch3Pos wingFoldRotate("WING_FOLD_ROTATE", 8, 9);

//============================================================
//Dodatkowe Panele 
//============================================================

//------------------------------------------------------------
//Ejection Seat SAFE/ARMED Handle, SAFE/ARMED
DcsBios::Switch2Pos ejectionSeatArmed("EJECTION_SEAT_ARMED", 10);

//Ejection Seat Manual Override Handle, PULL/PUSH
DcsBios::Switch2Pos ejectionSeatMnlOvrd("EJECTION_SEAT_MNL_OVRD", 11,true);

//Canopy Control Switch, OPEN/HOLD/CLOSE
DcsBios::Switch3Pos canopySw("CANOPY_SW", 12, 13);

//FCS BIT Switch
DcsBios::Switch2Pos fcsBitSw("FCS_BIT_SW", 14);

///CB FCS CHAN 3, ON/OFF
DcsBios::Switch2Pos cbFcsChan3("CB_FCS_CHAN3", 15);

//CB FCS CHAN 4, ON/OFF
DcsBios::Switch2Pos cbFcsChan4("CB_FCS_CHAN4", 16);

//CB HOOK, ON/OFF
DcsBios::Switch2Pos cbHoook("CB_HOOOK", 17);

//CB LG, ON/OFF
DcsBios::Switch2Pos cbLg("CB_LG", 18);

//==============================================================
//KY Panel
//==============================================================`1

//KY-58 Volume Control Knob
DcsBios::RotaryEncoder ky58Volume("KY58_VOLUME", "-3200", "+3200", 19, 22);

//KY-58 Power Select Knob, OFF/ON/TD
DcsBios::Switch3Pos ky58PowerSelect("KY58_POWER_SELECT", 20, 21);

//KY-58 Mode Select Knob, P/C/LD/RV
DcsBios::RotaryEncoder ky58ModeSelect("KY58_MODE_SELECT", "DEC", "INC", 23, 24);

//KY-58 Fill Select Knob, Z 1-5/1/2/3/4/5/6/Z ALL
DcsBios::RotaryEncoder ky58FillSelect("KY58_FILL_SELECT", "DEC", "INC", 27, 26);

//=============================================================
//SNSR Panel
//=============================================================

//RADAR Switch Change ,OFF/STBY/OPR/EMERG(PULL)
DcsBios::RotaryEncoder radarSw("RADAR_SW", "DEC", "INC", 29, 28);

//RADAR Switch Pull (MW to pull), OFF/STBY/OPR/EMERG(PULL)
DcsBios::Switch2Pos radarSwPull("RADAR_SW_PULL", 30);

//FLIR Switch, ON/STBY/OFF
DcsBios::Switch3Pos flirSw("FLIR_SW", 32, 31);

//INS Switch, OFF/CV/GND/NAV/IFA/GYRO/GB/TEST
DcsBios::RotaryEncoder insSw("INS_SW", "DEC", "INC", 33, 34);

//UWAGA TU SA  POMIESZANE KOMENDY !!!!!!!!!!

//LST/NFLR Switch, ON/OFF
DcsBios::Switch2Pos lstNflrSw("LST_NFLR_SW", 35);

//LTD/R Switch, ---/SAFE/AFT
DcsBios::Switch3Pos ltdRSw("LTD_R_SW", 25, 36 );

//===========================================================
//AntiIce Panel
//===========================================================

//Defog Handle
DcsBios::RotaryEncoder defogHandle("DEFOG_HANDLE", "-11200", "+11200", 37, 38);

//Windshield Anti-Ice/Rain Switch, ANTI ICE/OFF/RAIN
DcsBios::Switch3Pos wshieldAntiIceSw("WSHIELD_ANTI_ICE_SW", 40, 39);

//==================================================================
//RIGHT LIGHT Panel
//==================================================================

//WARN/CAUTION Light Dimmer
DcsBios::RotaryEncoder warnCautionDimmer("WARN_CAUTION_DIMMER", "-3200", "+3200", 41, 42);

//MODE Switch, NVG/NITE/DAY
DcsBios::Switch3Pos cockkpitLightModeSw("COCKKPIT_LIGHT_MODE_SW", 44, 43);

//Lights Test Switch, TEST/OFF
DcsBios::Switch2Pos lightsTestSw("LIGHTS_TEST_SW", 45);

//INST PNL Dimmer
DcsBios::RotaryEncoder instPnlDimmer("INST_PNL_DIMMER", "-3200", "+3200", 47, 46);

//FLOOD Light Dimmer
DcsBios::RotaryEncoder floodDimmer("FLOOD_DIMMER", "-3200", "+3200", 49, 48);

//CONSOLES Lights Dimmer
DcsBios::RotaryEncoder consolesDimmer("CONSOLES_DIMMER", "-3200", "+3200", 51, 50);

//CHART Light Dimmer
DcsBios::RotaryEncoder chartDimmer("CHART_DIMMER", "-3200", "+3200", 52, 53);

//==============================================================================
//ECS Panel
//===============================================================================

//Bleed Air Knob, AUG PULL
DcsBios::Switch2Pos bleedAirPull("BLEED_AIR_PULL", A2);

//Bleed Air Knob, R OFF/NORM/L OFF/OFF
DcsBios::RotaryEncoder bleedAirKnob("BLEED_AIR_KNOB", "DEC", "INC", A0, A1);

//Cabin Pressure Switch, NORM/DUMP/ RAM/DUMP
DcsBios::Switch3Pos cabinPressSw("CABIN_PRESS_SW", A3, A4);

//Cabin Temperature Knob
DcsBios::PotentiometerEWMA<5, 128, 5> cabinTemp("CABIN_TEMP", A5 );

//Suit Temperature Knob
DcsBios::PotentiometerEWMA<5, 128, 5> suitTemp("SUIT_TEMP", A6 );

//Pitot Heater Switch, ON/AUTO
DcsBios::Switch2Pos pitotHeatSw("PITOT_HEAT_SW", A7);\

//Engine Anti-Ice Switch, ON/OFF/TEST
DcsBios::Switch3Pos engAntiiceSw("ENG_ANTIICE_SW", A9, A8);

//ECS Mode Switch, AUTO/MAN/ OFF/RAM
DcsBios::Switch3Pos ecsModeSw("ECS_MODE_SW", A10, A11);

//==========================================================================
//BATT Panel
//==========================================================================

//Battery Switch, ON/OFF/ORIDE
DcsBios::Switch3Pos batterySw("BATTERY_SW", A12, A13);

//Left Generator Control Switch, NORM/OFF
DcsBios::Switch2Pos lGenSw("L_GEN_SW", A14);

//Right Generator Control Switch, NORM/OFF
DcsBios::Switch2Pos rGenSw("R_GEN_SW", A15);









void setup() {
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();

}
