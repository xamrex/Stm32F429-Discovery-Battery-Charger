#include <gui/screengraph_screen/ScreenGraphView.hpp>
#ifndef SIMULATOR
#ifndef SIMULATOR
#include "Charger.h"
extern LadowarkaStruct ladowarka;
#endif
#endif
ScreenGraphView::ScreenGraphView()
{

}

void ScreenGraphView::setupScreen()
{
    ScreenGraphViewBase::setupScreen();
    // touchgfx_printf("klkikneto button\n");
     dynamicGraph1MajorYAxisLabel.setInterval(0.10f); //labelki co 0.1
     dynamicGraph1MajorYAxisGrid.setInterval(0.10f); // major horizontal grid lines co 0.1
     dynamicGraph1MinorYAxisGrid.setInterval(0.05f); //minor horizontal grid lines

     dynamicGraph2MajorYAxisLabel.setInterval(0.10f); //labelki co 0.1
     dynamicGraph2MajorYAxisGrid.setInterval(0.10f); // major horizontal grid lines co 0.1
     dynamicGraph2MinorYAxisGrid.setInterval(0.05f); //minor horizontal grid lines

     dynamicGraph1.invalidate();
     dynamicGraph2.invalidate();
}

void ScreenGraphView::tearDownScreen()
{
    ScreenGraphViewBase::tearDownScreen();
}

void ScreenGraphView::DrawPoint2(){
#ifndef SIMULATOR
	dynamicGraph1.addDataPoint(ladowarka.BatteryVoltage);
#endif
}
void ScreenGraphView::DrawPoint2Min(){
#ifndef SIMULATOR
	dynamicGraph2.addDataPoint(ladowarka.NapiecieBaterii[ladowarka.CzsasLadowaniaWSec/60]);
	//1 -> czas ladowania od 9 do 59min
	if (ladowarka.CzsasLadowaniaWSec>9*60 && ladowarka.CzsasLadowaniaWSec <59*60){ //jesli czas jest >9min i <59 min
		dynamicGraph2.setGraphRangeX(0,60);
			dynamicGraph2MajorXAxisGrid.setInterval(10); //major horizontal grid lines
			dynamicGraph2MinorXAxisGrid.setInterval(2); //minor horizontal grid lines
			dynamicGraph2MajorXAxisLabel.setInterval(10); //labelki co 10
	}

#endif
}
void ScreenGraphView::DisplayLastAndMaxVlt2(){
#ifndef SIMULATOR
	Unicode::snprintfFloat(txtLastValueBuffer,TXTLASTVALUE_SIZE,"%.3f",ladowarka.BatteryVoltage);
	Unicode::snprintfFloat(txtMaxValueBuffer,TXTMAXVALUE_SIZE,"%.3f",ladowarka.MaxBatteryVoltage);
	txtMaxValue.invalidate();
	txtLastValue.invalidate();
#endif
}

void ScreenGraphView::DisplayRunningTime2(){
#ifndef SIMULATOR
	int sec, h, m, s;
	sec=ladowarka.CzsasLadowaniaWSec;
	h = (sec/3600);
	m = (sec -(3600*h))/60;
	s = (sec -(3600*h)-(m*60));

	Unicode::snprintf(textChargingTmeBuffer,TEXTCHARGINGTME_SIZE,"%02d:%02d:%02d\n",h,m,s);
	textChargingTme.invalidate();
#endif
}
