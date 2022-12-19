#ifndef SCREENGRAPHPRESENTER_HPP
#define SCREENGRAPHPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ScreenGraphView;

class ScreenGraphPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ScreenGraphPresenter(ScreenGraphView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~ScreenGraphPresenter() {};
    virtual void DrawPoint();
    virtual void DisplayLastAndMaxVlt();
    virtual void DisplayRunningTime();

private:
    ScreenGraphPresenter();

    ScreenGraphView& view;
};

#endif // SCREENGRAPHPRESENTER_HPP
