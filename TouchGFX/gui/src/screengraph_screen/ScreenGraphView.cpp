#include <gui/screengraph_screen/ScreenGraphView.hpp>
#ifndef SIMULATOR
extern float BatteryVoltage; //zmienna z mian.c
#endif
ScreenGraphView::ScreenGraphView()
{

}

void ScreenGraphView::setupScreen()
{
    ScreenGraphViewBase::setupScreen();
    // touchgfx_printf("klkikneto button\n");
     dynamicGraph1MajorYAxisLabel.setInterval(0.10f); //labelki co 0.1
     //	 dynamicGraph1MajorYAxisLabel.setInterval(0.5f); //usunac to
     dynamicGraph1MajorYAxisGrid.setInterval(0.10f); // major horizontal grid lines co 0.1
     	// dynamicGraph1MajorYAxisGrid.setInterval(0.50f); // Usunaca to
     dynamicGraph1MinorYAxisGrid.setInterval(0.05f); //minor horizontal grid lines
     	// dynamicGraph1MinorYAxisGrid.setInterval(0.1f); //usnac to
     dynamicGraph1.invalidate();
}

void ScreenGraphView::tearDownScreen()
{
    ScreenGraphViewBase::tearDownScreen();
}

void ScreenGraphView::DrawPoint2(){
#ifndef SIMULATOR
	dynamicGraph1.addDataPoint(BatteryVoltage);
#endif
}
