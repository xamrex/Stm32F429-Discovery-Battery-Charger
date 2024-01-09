#include <gui/screengraph_screen/ScreenGraphView.hpp>
#ifndef SIMULATOR
#include "Charger.h"
#include "math.h"
extern LadowarkaStruct ladowarka;
#endif

ScreenGraphView::ScreenGraphView()
{

}

void ScreenGraphView::setupScreen()
{
    ScreenGraphViewBase::setupScreen();
    // touchgfx_printf("klkikneto button\n");
     dynamicGraph1MajorYAxisLabel.setInterval(0.01f); //labelki co 0.1
     dynamicGraph1MajorYAxisGrid.setInterval(0.01f); // major horizontal grid lines co 0.1
     dynamicGraph1MinorYAxisGrid.setInterval(0.005f); //minor horizontal grid lines

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

	/************ update min max on Y scale*******************/
    dynamicGraph1.setGraphRangeY(countMin(), countMax());

#endif
}
void ScreenGraphView::DrawPoint2Min(){
#ifndef SIMULATOR
	dynamicGraph2.addDataPoint(ladowarka.AverageFromLastMin);


	 dynamicGraph2.setGraphRangeY((floor(ladowarka.MinBatteryVotage*10)/10),(ceil(ladowarka.MaxBatteryVoltage*10)/10));

		/************ update min max on Y scale*******************/


	//1 -> czas ladowania od 9 do 59min
	if (ladowarka.ChargingTimeInSec>9*60 && ladowarka.ChargingTimeInSec <59*60){ //jesli czas jest >9min i <59 min
		dynamicGraph2.setGraphRangeX(0,60);
			dynamicGraph2MajorXAxisGrid.setInterval(10); //major horizontal grid lines
			dynamicGraph2MinorXAxisGrid.setInterval(2); //minor horizontal grid lines
			dynamicGraph2MajorXAxisLabel.setInterval(10); //labelki co 10
	}

	else if ((ladowarka.ChargingTimeInSec >59*60) && (ladowarka.ChargingCompleted==0) ){ //jesli czas jest >59 min
			dynamicGraph2.setGraphRangeX(0,ladowarka.ChargingTime*60);
			dynamicGraph2MajorXAxisGrid.setInterval(60); //major horizontal grid lines
			dynamicGraph2MinorXAxisGrid.setInterval(10); //minor horizontal grid lines
			dynamicGraph2MajorXAxisLabel.setInterval(60); //labelki co 10
	}

	else if(ladowarka.ChargingCompleted) 	{//maksymalna wartosc graphu keidy skonczy sie ladowanie oraz ustaw plot X,Y
				dynamicGraph2.setGraphRangeX(0,600);
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

void ScreenGraphView::DisplayCurrentValue2(){
#ifndef SIMULATOR
	Unicode::snprintfFloat(textChargingCurrentBuffer,TEXTCHARGINGCURRENT_SIZE,"%3f",ladowarka.ChargingCurrent);
	textChargingCurrent.invalidate();


	//calculate
	Unicode::snprintfFloat(textChargedBuffer,TEXTCHARGED_SIZE,"%.1f",ladowarka.Totalcharge);
	textCharged.invalidate();
#endif
}

void ScreenGraphView::DisplayChargingFinished2(){
	modalWindow1.setVisible(true);
	modalWindow1.invalidate();
}

void ScreenGraphView::DisplayRunningTime2(){
#ifndef SIMULATOR
	int sec, h, m, s;
	sec=ladowarka.ChargingTimeInSec;
	h = (sec/3600);
	m = (sec -(3600*h))/60;
	s = (sec -(3600*h)-(m*60));

	Unicode::snprintf(textChargingTmeBuffer,TEXTCHARGINGTME_SIZE,"%02d:%02d:%02d\n",h,m,s);
	textChargingTme.invalidate();
#endif
}

float ScreenGraphView::countMin(){
#ifndef SIMULATOR
	float results= ladowarka.MeasurementsEverySec[0]; //domyslna wartocs
	for (int i=0;i<59;i++){
		if ((ladowarka.MeasurementsEverySec[i] < results) && ladowarka.MeasurementsEverySec[i]!=0)  results=ladowarka.MeasurementsEverySec[i];
	}

	return (floor(results*100)/100);
#else
	return 1.5;
#endif
}
float ScreenGraphView::countMax(){
#ifndef SIMULATOR
	float results= 0; //domyslna wartocs
	for (int i=0;i<59;i++){
		if (ladowarka.MeasurementsEverySec[i] > results)  results=ladowarka.MeasurementsEverySec[i];
	}

	return (ceil(results*100)/100);


#else
	return 1.5;
#endif
}

