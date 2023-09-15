/*
  Tell DCS-BIOS to use a serial connection and use the default Arduino Serial
  library. This will work on the vast majority of Arduino-compatible boards,
  but you can get corrupted data if you have too many or too slow outputs
  (e.g. when you have multiple character displays), because the receive
  buffer can fill up if the sketch spends too much time updating them.
  
  If you can, use the IRQ Serial connection instead.
*/
#define DCSBIOS_DEFAULT_SERIAL

#include "DcsBios.h"

/* paste code snippets from the reference documentation here */

//wszystkie mają PIN 0

//---------------------------------------------------------------------------------------------------------------------------
//LEFT DDI
//Encoder Lewy DDI BRT  2 
DcsBios::RotaryEncoder leftDdiBrtCtl("LEFT_DDI_BRT_CTL", "-1600", "+1600", 3, 2, DcsBios::ONE_STEP_PER_DETENT);

//Encoder Lewy DDI CONT 3
DcsBios::RotaryEncoder leftDdiContCtl("LEFT_DDI_CONT_CTL", "-1600", "+1600", 4, 5, DcsBios::ONE_STEP_PER_DETENT);

//Encoder Lewy DDI Night/Day 4
DcsBios::RotaryEncoder leftDdiBrtSelect("LEFT_DDI_BRT_SELECT", "DEC", "INC", 6, 7);
//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
//RIGHT DDI
//Encoder Prawy DDI BRT 5
DcsBios::RotaryEncoder rightDdiBrtCtl("RIGHT_DDI_BRT_CTL", "-1600", "+1600", 9, 8);

//Encoder Prawy DDI CONT  6
DcsBios::RotaryEncoder rightDdiContCtl("RIGHT_DDI_CONT_CTL", "-1600", "+1600", 10, 16);
//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
//UNDER REAL HUD Panel
DcsBios::Switch2Pos hudVideoBit("HUD_VIDEO_BIT", A2);
//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
//Spin recovery Panel
DcsBios::Switch2Pos spinRecoveryCover("SPIN_RECOVERY_COVER", A3, true);
//-----------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------
//Master Arm Switch
const byte masterArmSwPins[3] = {A1, A0};
DcsBios::SwitchMultiPos masterArmSw("MASTER_ARM_SW", masterArmSwPins, 3);

void setup() {
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();
}
