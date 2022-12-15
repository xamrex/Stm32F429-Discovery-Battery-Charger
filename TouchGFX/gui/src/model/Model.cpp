#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
int PradLadowania=400; //ustawienie na sztywno pradu ladowania
extern int LoadingCurrent;
extern int narysujPunktNaWykresie;
int licznik;
Model::Model() : modelListener(0)
{

}

void Model::tick()
{
//	licznik++;
//	if (licznik>1000 )licznik =0;
//
//	if (licznik%100) modelListener->UpdateBatteryVoltage();

modelListener->UpdateBatteryVoltage();
#ifndef SIMULATOR
if(narysujPunktNaWykresie){
	modelListener->DrawPoint();
	narysujPunktNaWykresie=0;
}
#endif
}
