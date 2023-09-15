/*
  Tell DCS-BIOS to use a serial connection and use interrupt-driven
  communication. The main program will be interrupted to prioritize
  processing incoming data.
  
  This should work on any Arduino that has an ATMega328 controller
  (Uno, Pro Mini, many others).
 */
#define DCSBIOS_IRQ_SERIAL

#include "DcsBios.h"
//TESTY TESTY _TESTY 



//TESTY TESTY TEStY 

//----------------------------------------------------------------------------------
// Fuel Panel Lower
//Mode Selector Switch, MAN/OFF/AUTO Fuel Panel Lower
DcsBios::Switch3Pos modeSelectorSw("MODE_SELECTOR_SW", 2, 3);

//Selector Switch, HUD/LDIR/RDDIFA Fuel Panel Lower
DcsBios::Switch3Pos selectHudLddiRddi("SELECT_HUD_LDDI_RDDI", 5, 4);

//Selector Switch, HMD/LDDI/RDDI Fuel Panel Lower
DcsBios::Switch3Pos selectHmdLddiRddi("SELECT_HMD_LDDI_RDDI", 7, 6);

//End Fuel Panel Lower
//------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------
//IFEI PANEL
//Encoder IFEI panel paliwowy pin 1
DcsBios::RotaryEncoder ifei("IFEI", "-1600", "+1600", A1, A0, DcsBios::ONE_STEP_PER_DETENT);
//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
//Spin Recovery Panel
//IR Cooling Switch, ORIDE/NORM/OFF
DcsBios::Switch3Pos irCoolSw("IR_COOL_SW", A2, A3);

//HMD OFF/BRT Knob
DcsBios::RotaryEncoder hmdOffBrt("HMD_OFF_BRT", "-3200", "+3200", A4, A5);

//Spin Recovery Switch, RCVY/NORM
DcsBios::Switch2Pos spinRecoverySw("SPIN_RECOVERY_SW", A6);

//APU Fire Warning/Extinguisher Light
DcsBios::Switch2Pos apuFireBtn("APU_FIRE_BTN", A7);
//--------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------
//RDDI 
//Brightness Selector Knob, OFF/NIGHT/DAY
DcsBios::RotaryEncoder rightDdiBrtSelect("RIGHT_DDI_BRT_SELECT", "DEC", "INC", A9, A8);
//--------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------
//POTENCJOMETRY  Przenioesieone z leonardo
//Potencjometry 3 szt
//AMPCD Brightness Control Knob
DcsBios::PotentiometerEWMA<5, 128, 5> ampcdBrtCtl("AMPCD_BRT_CTL", A10);

//RWR Intensity Knob (boczny prawy panel zegarów)
DcsBios::PotentiometerEWMA<5, 128, 5> rwrRwrIntesity("RWR_RWR_INTESITY", A11);

//ALR-67 DMR Control Knob 
DcsBios::PotentiometerEWMA<5, 128, 5> rwrDmrCtrl("RWR_DMR_CTRL", A12);
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//UFC góra
//ADF Function Select Switch, 1/OFF/2
DcsBios::Switch3Pos ufcAdf("UFC_ADF", 8, 9);

//ufc COMM 1 Volume Control Knob
DcsBios::RotaryEncoder ufcComm1Vol("UFC_COMM1_VOL", "-1600", "+1600", 10 , 11);

//ufc Brightness Control Knob
DcsBios::RotaryEncoder ufcBrt("UFC_BRT", "-1600", "+1600", 12, 13);

//UFC Emission Control (EM) Pushbutton
DcsBios::Switch2Pos ufcEmcon("UFC_EMCON", 14);

//UFC COMM 2 Volume Control Knob
DcsBios::RotaryEncoder ufcComm2Vol("UFC_COMM2_VOL", "-1600", "+1600", 15, 16);

//-----------------------------
//UFC NUM PAD
//-----------------------------
//UFC Keyboard Pushbutton, CLR
DcsBios::Switch2Pos ufcClr("UFC_CLR", 17);

//UFC Keyboard Pushbutton, ENT
DcsBios::Switch2Pos ufcEnt("UFC_ENT", 18);

//UFC Keyboard Pushbutton, 0
DcsBios::Switch2Pos ufc0("UFC_0", 19);

//UFC Keyboard Pushbutton, 1
DcsBios::Switch2Pos ufc1("UFC_1", 20);

//UFC Keyboard Pushbutton, 2
DcsBios::Switch2Pos ufc2("UFC_2", 21);

//UFC Keyboard Pushbutton, 3
DcsBios::Switch2Pos ufc3("UFC_3", 22);

//UFC Keyboard Pushbutton, 4
DcsBios::Switch2Pos ufc4("UFC_4", 23);

//UFC Keyboard Pushbutton, 5
DcsBios::Switch2Pos ufc5("UFC_5", 24);

//UFC Keyboard Pushbutton, 6
DcsBios::Switch2Pos ufc6("UFC_6", 25);

//UFC Keyboard Pushbutton, 7
DcsBios::Switch2Pos ufc7("UFC_7", 26);

//UFC Keyboard Pushbutton, 8
DcsBios::Switch2Pos ufc8("UFC_8", 27);

//UFC Keyboard Pushbutton, 9
DcsBios::Switch2Pos ufc9("UFC_9", 28);

//UFC DOWN HUD PANEL
//UFC COMM 1 Channel Select KnobFA
DcsBios::RotaryEncoder ufcComm1ChannelSelect("UFC_COMM1_CHANNEL_SELECT", "DEC", "INC", 29, 30);

//UFC COMM 1 Channel Selector Knob Pull
DcsBios::Switch2Pos ufcComm1Pull("UFC_COMM1_PULL", 31);

//UFC COMM 2 Channel Select Knob
DcsBios::RotaryEncoder ufcComm2ChannelSelect("UFC_COMM2_CHANNEL_SELECT", "DEC", "INC", 33, 32);

//UFC COMM 2 Channel Selector Knob Pull
DcsBios::Switch2Pos ufcComm2Pull("UFC_COMM2_PULL", 34);
//---------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------
//HUD pod UFC
//---------------------------------------------------------------------------------------------------------------
//HUD Symbology Reject Switch, NORM/REJ 1/REJ 2
DcsBios::Switch3Pos hudSymRejSw("HUD_SYM_REJ_SW", 35, 36);

//HUD Symbology Brightness Control Knob
DcsBios::RotaryEncoder hudSymBrt("HUD_SYM_BRT", "-1600", "+1600", 37, 38);

//HUD Symbology Brightness Selector Knob, DAY/NIGHT
DcsBios::Switch2Pos hudSymBrtSelect("HUD_SYM_BRT_SELECT", 39 ,true);

//Black Level Control Knob
DcsBios::RotaryEncoder hudBlackLvl("HUD_BLACK_LVL", "-1600", "+1600", 40, 41);

//HUD Video Control Switch, W/B /VID/OFF
DcsBios::Switch3Pos hudVideoControlSw("HUD_VIDEO_CONTROL_SW", 43, 42);

//HUD Balance Control Knob
DcsBios::RotaryEncoder hudBalance("HUD_BALANCE", "-1600", "+1600", 45, 44);

//AOA Indexer Control Knob
DcsBios::RotaryEncoder hudAoaIndexer("HUD_AOA_INDEXER", "-1600", "+1600", 47, 46);

//Altitude Switch, BARO/RDR
DcsBios::Switch2Pos hudAltSw("HUD_ALT_SW", 48);

//Attitude Selector Switch, INS/AUTO/STBY
DcsBios::Switch3Pos hudAttSw("HUD_ATT_SW", 50, 49);

//---------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------




void setup() {
  DcsBios::setup();


}
void loop() {
  DcsBios::loop();
}
