#include <gui/screengraph_screen/ScreenGraphView.hpp>

ScreenGraphView::ScreenGraphView()
{
	 // touchgfx_printf("klkikneto button\n");
	  dynamicGraph1MajorYAxisLabel.setInterval(0.10f); //labelki co 0.1
	  dynamicGraph1MajorYAxisGrid.setInterval(0.10f); //grid co 0.1
	  dynamicGraph1MinorYAxisGrid.setInterval(0.05f); //minor horizontal lines
	  dynamicGraph1.invalidate();
}

void ScreenGraphView::setupScreen()
{
    ScreenGraphViewBase::setupScreen();
    // touchgfx_printf("klkikneto button\n");
     dynamicGraph1MajorYAxisLabel.setInterval(0.10f); //labelki co 0.1
     dynamicGraph1MajorYAxisGrid.setInterval(0.10f); //grid co 0.1
     dynamicGraph1MinorYAxisGrid.setInterval(0.05f); //minor horizontal lines
     dynamicGraph1.invalidate();
}

void ScreenGraphView::tearDownScreen()
{
    ScreenGraphViewBase::tearDownScreen();
}

