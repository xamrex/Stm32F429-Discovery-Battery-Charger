#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Utils.hpp>
Screen1View::Screen1View()
{
PradLadowania=400;
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
void Screen1View::ButtonUpClicked()
{

	PradLadowania=PradLadowania+10;
	if (PradLadowania >400){
	PradLadowania=400;}
	Unicode::snprintf(txtPradLadowaniaBuffer,TXTPRADLADOWANIA_SIZE,"%d",PradLadowania);
	txtPradLadowania.invalidate();
}
void Screen1View::ButtonDownClicked()
{
	PradLadowania=PradLadowania-10;
    if (PradLadowania <10){
	PradLadowania=10;}
	Unicode::snprintf(txtPradLadowaniaBuffer,TXTPRADLADOWANIA_SIZE,"%d",PradLadowania);
	txtPradLadowania.invalidate();
}
