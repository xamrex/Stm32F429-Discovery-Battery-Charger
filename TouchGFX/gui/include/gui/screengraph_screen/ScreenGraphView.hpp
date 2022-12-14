#ifndef SCREENGRAPHVIEW_HPP
#define SCREENGRAPHVIEW_HPP

#include <gui_generated/screengraph_screen/ScreenGraphViewBase.hpp>
#include <gui/screengraph_screen/ScreenGraphPresenter.hpp>

class ScreenGraphView : public ScreenGraphViewBase
{
public:
    ScreenGraphView();
    virtual ~ScreenGraphView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
};

#endif // SCREENGRAPHVIEW_HPP
