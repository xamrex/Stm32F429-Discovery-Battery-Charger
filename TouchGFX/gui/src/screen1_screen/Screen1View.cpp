#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Utils.hpp>
#ifndef SIMULATOR
#include "Charger.h"
extern LadowarkaStruct ladowarka;
#endif
extern int PradLadowania; // z GIU do charger.h

//BatteryVoltage; //zmienna z charger.h
//LoadingCurrent; //zmienna z charger.h
// ChargeStarted; //zmienna z charger.h

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

	PradLadowania=PradLadowania+10;
	if (PradLadowania >400){
	PradLadowania=400;}
	Unicode::snprintf(txtPradLadowaniaBuffer,TXTPRADLADOWANIA_SIZE,"%d",PradLadowania);
	txtPradLadowania.invalidate();
}
void Screen1View::ButtonDownClicked() //zwiekszenie wartosci pradu ladowania
{
	PradLadowania=PradLadowania-10;
    if (PradLadowania <10){
	PradLadowania=10;}
	Unicode::snprintf(txtPradLadowaniaBuffer,TXTPRADLADOWANIA_SIZE,"%d",PradLadowania);
	txtPradLadowania.invalidate();
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
#endif
}



