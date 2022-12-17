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
void ScreenGraphPresenter::DisplayLastAndMaxVlt()
{
	view.DisplayLastAndMaxVlt2();
}
