#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Utils.hpp>
#ifndef SIMULATOR
#include "Charger.h"
extern LadowarkaStruct ladowarka;
#endif
extern int PradLadowania; // z GIU to charger.h
extern int ChargingTime; // z GIU to charger.h

Screen1View::Screen1View()
{
	//dodane do oczytywnaia


Unicode::snprintf(txtPradLadowaniaBuffer,TXTPRADLADOWANIA_SIZE,"%d",PradLadowania);
	txtPradLadowania.invalidate();
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}
void Screen1View::ButtonUpClicked() //zwiekszenie wartosci pradu ladowania
{

	PradLadowania=PradLadowania+100;
	if (PradLadowania >400){
	PradLadowania=400;}
	Unicode::snprintf(txtPradLadowaniaBuffer,TXTPRADLADOWANIA_SIZE,"%d",PradLadowania);
	txtPradLadowania.invalidate();
}
void Screen1View::ButtonDownClicked() //zwiekszenie wartosci pradu ladowania
{
	PradLadowania=PradLadowania-100;
    if (PradLadowania <100){
	PradLadowania=100;}
	Unicode::snprintf(txtPradLadowaniaBuffer,TXTPRADLADOWANIA_SIZE,"%d",PradLadowania);
	txtPradLadowania.invalidate();
}
void Screen1View::ButtonUpTimeClicked() //zwiekszenie wartosci pradu ladowania
{

	ChargingTime=ChargingTime+1;
	if (ChargingTime >10){
		ChargingTime=10;}
	Unicode::snprintf(txtChargingTimeBuffer,TXTCHARGINGTIME_SIZE,"%d",ChargingTime);
	txtChargingTime.invalidate();
}
void Screen1View::ButtonDownTimeClicked() //zwiekszenie wartosci pradu ladowania
{
	ChargingTime=ChargingTime-1;
    if (ChargingTime <1){
    	ChargingTime=1;}
	Unicode::snprintf(txtChargingTimeBuffer,TXTCHARGINGTIME_SIZE,"%d",ChargingTime);
	txtChargingTime.invalidate();
}

void Screen1View::DisplayBatteryVoltage(){
#ifndef SIMULATOR
	Unicode::snprintfFloat(txtNapiecieBateriiBuffer,TXTNAPIECIEBATERII_SIZE,"%.3f",ladowarka.BatteryVoltage);
	txtNapiecieBaterii.invalidate();
#endif
}

void Screen1View::ButtonStartClicked()
{
#ifndef SIMULATOR
 ladowarka.LoadingCurrent=PradLadowania;
 ladowarka.ChargeStarted=1;
 ladowarka.ChargingTime=ChargingTime;
#endif
}



