
#define DCSBIOS_IRQ_SERIAL

#include "DcsBios.h"

//----------------------------------------------------------------------------------
// OBOGOS / Hudraulic isolate PANEL
//OBOGS Control Switch, ON/OFF
DcsBios::Switch2Pos obogsSw("OBOGS_SW", 2);

//Hydraulic Isolate Override Switch, NORM/ORIDE
DcsBios::Switch2Pos hydIsolateOverrideSw("HYD_ISOLATE_OVERRIDE_SW", 3);

//MC Switch, 1 OFF/NORM/2 OFF
DcsBios::Switch3Pos mcSw("MC_SW", 5, 4);

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//IFF PANEL
//CRYPTO Switch, HOLD/NORM/ZERO
DcsBios::Switch3Pos comCryptoSw("COM_CRYPTO_SW", 6, 7);

//IFF Mode 4 Switch, DIS/AUD /DIS/OFF
DcsBios::Switch3Pos comIffMode4Sw("COM_IFF_MODE4_SW", 8, 9);

//IFF Master Switch, EMER/NORM
DcsBios::Switch2Pos comIffMasterSw("COM_IFF_MASTER_SW", 10 ,true);

//ILS Channel Selector Switch
DcsBios::RotaryEncoder comIlsChannelSw("COM_ILS_CHANNEL_SW", "DEC", "INC", 12, 11);

//ILS UFC/MAN Switch, UFC/MAN
DcsBios::Switch2Pos comIlsUfcManSw("COM_ILS_UFC_MAN_SW", 13);

//Comm Relay Switch, CIPHER/OFF/PLAIN
DcsBios::Switch3Pos comCommRelaySw("COM_COMM_RELAY_SW", 14, 15);

//COMM G XMT Switch, COMM 1/OFF/COMM 2
DcsBios::Switch3Pos comCommGXmtSw("COM_COMM_G_XMT_SW", 16, 17);

//ALE-39 CONTEMAESURES Dispenser Reset Switch Narazie nie działa 
//PIN 22

//Klapka ALE-39 CONTEMAESURES  Narazie nie działa  
// PIN 23
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//Antenna Select Panel
//COMM 1 Antenna Selector Switch, UPPER/AUTO/LOWER
DcsBios::Switch3Pos comm1AntSelectSw("COMM1_ANT_SELECT_SW", 18, 19);

//IFF Antenna Selector Switch, UPPER/BOTH/LOWER
DcsBios::Switch3Pos iffAntSelectSw("IFF_ANT_SELECT_SW", 20, 21);

//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//VOL Panel
//TACAN Volume Control Knob
DcsBios::RotaryEncoder comTacan("COM_TACAN", "-3200", "+3200", 37,36 );

//VOX Volume Control Knob
DcsBios::RotaryEncoder comVox("COM_VOX", "-3200", "+3200", 26, 27);
//RWR Volume Control Knob
DcsBios::RotaryEncoder comRwr("COM_RWR", "-3200", "+3200", 28, 29);

//WPN Volume Control Knob
DcsBios::RotaryEncoder comWpn("COM_WPN", "-3200", "+3200", 30, 31);

//MIDS A Volume Control Knob
DcsBios::RotaryEncoder comMidsA("COM_MIDS_A", "-3200", "+3200", 32, 33);

//MIDS B Volume Control Knob
DcsBios::RotaryEncoder comMidsB("COM_MIDS_B", "-3200", "+3200", 35, 34);

//ICS Volume Control Knob
DcsBios::RotaryEncoder comIcs("COM_ICS", "-3200", "+3200", 38, 39);

//AUX Volume Control Knob
DcsBios::RotaryEncoder comAux("COM_AUX", "-3200", "+3200", 24, 25);


//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
//FCS Panel
//FCS RESET Button
DcsBios::Switch2Pos fcsResetBtn("FCS_RESET_BTN", 40);

//GAIN Switch Cover
DcsBios::Switch2Pos gainSwitchCover("GAIN_SWITCH_COVER", 42 ,true);

//GAIN Switch
DcsBios::Switch2Pos gainSwitch("GAIN_SWITCH", 41 , true);

//RUD TRIM Control
DcsBios::RotaryEncoder rudTrim("RUD_TRIM", "-3200", "+3200", 43, 44);

//T/O TRIM Button
DcsBios::Switch2Pos toTrimBtn("TO_TRIM_BTN", 45);

//External Centerline Tank Fuel Control Switch, STOP/NORM/ORIDE
DcsBios::Switch3Pos extCntTankSw("EXT_CNT_TANK_SW", 47, 46);

//External Wing Tanks Fuel Control Switch, STOP/NORM/ORIDE
DcsBios::Switch3Pos extWngTankSw("EXT_WNG_TANK_SW", 48, 49);

//-----------------------------------------------------------------
//-----------------------------------------------------------------
//LIGHTS Panel 
//Strobe Lights Switch
DcsBios::Switch3Pos strobeSw("STROBE_SW", 51, 50);

//Position Lights Dimmer
DcsBios::RotaryEncoder positionDimmer("POSITION_DIMMER", "-3200", "+3200", 53, 52);

//Formation Lights Dimmer
DcsBios::RotaryEncoder formationDimmer("FORMATION_DIMMER", "-3200", "+3200", A0, A1);

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Generator Tie Control Switch PANEL
//Generator TIE Control Switch Cover, OPEN/CLOSE
DcsBios::Switch2Pos genTieCover("GEN_TIE_COVER", A2, true);

//Generator TIE Control Switch, NORM/RESET
DcsBios::Switch2Pos genTieSw("GEN_TIE_SW", A3, true);

//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
//Left WALL and Left Essential Circuit Breakers
//Dispense Button - Push to dispense flares and chaff
DcsBios::Switch2Pos cmsdDispenseBtn("CMSD_DISPENSE_BTN", A4);

//CB FCS CHAN 1, ON/OFF
DcsBios::Switch2Pos cbFcsChan1("CB_FCS_CHAN1", A5);

//CB FCS CHAN 2, ON/OFF
DcsBios::Switch2Pos cbFcsChan2("CB_FCS_CHAN2", A6);

//CB SPD BRK, ON/OFF
DcsBios::Switch2Pos cbSpdBrk("CB_SPD_BRK", A7);

//CB LAUNCH BAR, ON/OFF
DcsBios::Switch2Pos cbLaunchBar("CB_LAUNCH_BAR", A8);

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//Ground Power Panel
//External Power Switch, RESET/NORM/OFF
DcsBios::Switch3Pos extPwrSw("EXT_PWR_SW", A10, A9);

//Ground Power Switch 4, A ON/AUTO/B ON
DcsBios::Switch3Pos gndPwr4Sw("GND_PWR_4_SW", A11, A12);

//Ground Power Switch 3, A ON/AUTO/B ON
DcsBios::Switch3Pos gndPwr3Sw("GND_PWR_3_SW", A14, A13);

//===========================================================================
//===========================================================================
//Konsola Vertical Panel
//HOOK BYPASS Switch, FIELD/CARRIER
DcsBios::Switch2Pos hookBypassSw("HOOK_BYPASS_SW", A15 ,true);








void setup() {
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();
  delay(5);
}
