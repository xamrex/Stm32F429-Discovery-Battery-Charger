/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREENGRAPHVIEWBASE_HPP
#define SCREENGRAPHVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screengraph_screen/ScreenGraphPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/graph/GraphScroll.hpp>
#include <touchgfx/widgets/graph/GraphElements.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/widgets/graph/GraphLabels.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class ScreenGraphViewBase : public touchgfx::View<ScreenGraphPresenter>
{
public:
    ScreenGraphViewBase();
    virtual ~ScreenGraphViewBase() {}
    virtual void setupScreen();

    /*
     * Custom Actions
     */
    virtual void action1();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Image Background;
    touchgfx::BoxWithBorder boxWithBorder1;
    touchgfx::Button button1;
    touchgfx::GraphScroll<600> dynamicGraph2;
    touchgfx::GraphElementLine dynamicGraph2Line1;
    touchgfx::PainterRGB565 dynamicGraph2Line1Painter;
    touchgfx::GraphElementGridX dynamicGraph2MinorXAxisGrid;
    touchgfx::GraphElementGridY dynamicGraph2MinorYAxisGrid;
    touchgfx::GraphElementGridX dynamicGraph2MajorXAxisGrid;
    touchgfx::GraphElementGridY dynamicGraph2MajorYAxisGrid;
    touchgfx::GraphLabelsX dynamicGraph2MajorXAxisLabel;
    touchgfx::GraphLabelsY dynamicGraph2MajorYAxisLabel;
    touchgfx::GraphScroll<60> dynamicGraph1;
    touchgfx::GraphElementLine dynamicGraph1Line1;
    touchgfx::PainterRGB565 dynamicGraph1Line1Painter;
    touchgfx::GraphElementGridX dynamicGraph1MinorXAxisGrid;
    touchgfx::GraphElementGridY dynamicGraph1MinorYAxisGrid;
    touchgfx::GraphElementGridX dynamicGraph1MajorXAxisGrid;
    touchgfx::GraphElementGridY dynamicGraph1MajorYAxisGrid;
    touchgfx::GraphLabelsY dynamicGraph1MajorYAxisLabel;
    touchgfx::ToggleButton toggleButton1;
    touchgfx::TextArea txtShowWholeGraph;
    touchgfx::TextAreaWithOneWildcard txtLastValue;
    touchgfx::TextAreaWithOneWildcard txtMaxValue;
    touchgfx::TextAreaWithOneWildcard textChargingTme;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TXTLASTVALUE_SIZE = 8;
    touchgfx::Unicode::UnicodeChar txtLastValueBuffer[TXTLASTVALUE_SIZE];
    static const uint16_t TXTMAXVALUE_SIZE = 8;
    touchgfx::Unicode::UnicodeChar txtMaxValueBuffer[TXTMAXVALUE_SIZE];
    static const uint16_t TEXTCHARGINGTME_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textChargingTmeBuffer[TEXTCHARGINGTME_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<ScreenGraphViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 4800;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // SCREENGRAPHVIEWBASE_HPP
