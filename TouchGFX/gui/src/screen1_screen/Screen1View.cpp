#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Utils.hpp>
extern float BatteryVoltage; //zmienna z mian.c
extern int PradLadowania;
extern int LoadingCurrent; //zmienna z main.c

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
	Unicode::snprintfFloat(txtNapiecieBateriiBuffer,TXTNAPIECIEBATERII_SIZE,"%.3f",BatteryVoltage);
	txtNapiecieBaterii.invalidate();
#endif
}

void Screen1View::ButtonStartClicked()
{
#ifndef SIMULATOR
 LoadingCurrent=PradLadowania;
#endif
}



