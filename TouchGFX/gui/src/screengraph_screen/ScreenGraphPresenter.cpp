#include <gui/screengraph_screen/ScreenGraphView.hpp>
#include <gui/screengraph_screen/ScreenGraphPresenter.hpp>

ScreenGraphPresenter::ScreenGraphPresenter(ScreenGraphView& v)
    : view(v)
{

}

void ScreenGraphPresenter::activate()
{

}

void ScreenGraphPresenter::deactivate()
{

}
void ScreenGraphPresenter::DrawPoint()
{
	view.DrawPoint2();
}
void ScreenGraphPresenter::DrawPointMin()
{
	view.DrawPoint2Min();
}
void ScreenGraphPresenter::DisplayLastAndMaxVlt()
{
	view.DisplayLastAndMaxVlt2();
}
void ScreenGraphPresenter::DisplayRunningTime()
{
	view.DisplayRunningTime2();
}
