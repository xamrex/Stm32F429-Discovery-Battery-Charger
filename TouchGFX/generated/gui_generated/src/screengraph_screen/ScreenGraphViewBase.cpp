/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screengraph_screen/ScreenGraphViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>


ScreenGraphViewBase::ScreenGraphViewBase() :
    buttonCallback(this, &ScreenGraphViewBase::buttonCallbackHandler)
{

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    __background.setPosition(0, 0, 320, 240);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    box1.setPosition(0, 0, 320, 240);
    box1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    button1.setXY(75, 180);
    button1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    button1.setAction(buttonCallback);

    dynamicGraph1.setScale(1000);
    dynamicGraph1.setPosition(0, 2, 320, 178);
    dynamicGraph1.setGraphAreaMargin(10, 30, 0, 20);
    dynamicGraph1.setGraphAreaPadding(0, 0, 0, 0);
    dynamicGraph1.setGraphRangeY(1.0f, 1.5f);

    dynamicGraph1MinorYAxisGrid.setScale(1000);
    dynamicGraph1MinorYAxisGrid.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    dynamicGraph1MinorYAxisGrid.setInterval(0.5f);
    dynamicGraph1MinorYAxisGrid.setLineWidth(1);
    dynamicGraph1MinorYAxisGrid.setMajorGrid(dynamicGraph1MajorYAxisGrid);
    dynamicGraph1.addGraphElement(dynamicGraph1MinorYAxisGrid);

    dynamicGraph1MajorXAxisGrid.setScale(1000);
    dynamicGraph1MajorXAxisGrid.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    dynamicGraph1MajorXAxisGrid.setInterval(10);
    dynamicGraph1MajorXAxisGrid.setLineWidth(1);
    dynamicGraph1.addGraphElement(dynamicGraph1MajorXAxisGrid);

    dynamicGraph1MajorYAxisGrid.setScale(1000);
    dynamicGraph1MajorYAxisGrid.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    dynamicGraph1MajorYAxisGrid.setInterval(1);
    dynamicGraph1MajorYAxisGrid.setLineWidth(2);
    dynamicGraph1.addGraphElement(dynamicGraph1MajorYAxisGrid);

    dynamicGraph1MajorYAxisLabel.setScale(1000);
    dynamicGraph1MajorYAxisLabel.setInterval(0.15f);
    dynamicGraph1MajorYAxisLabel.setLabelTypedText(touchgfx::TypedText(T___SINGLEUSE_CBWT));
    dynamicGraph1MajorYAxisLabel.setLabelDecimals(1);
    dynamicGraph1MajorYAxisLabel.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    dynamicGraph1.addLeftElement(dynamicGraph1MajorYAxisLabel);

    dynamicGraph1Line1Painter.setColor(touchgfx::Color::getColorFromRGB(22, 36, 196));
    dynamicGraph1Line1.setPainter(dynamicGraph1Line1Painter);
    dynamicGraph1Line1.setLineWidth(2);
    dynamicGraph1.addGraphElement(dynamicGraph1Line1);

    add(__background);
    add(box1);
    add(button1);
    add(dynamicGraph1);
}

void ScreenGraphViewBase::setupScreen()
{

}

void ScreenGraphViewBase::action1()
{

}

void ScreenGraphViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &button1)
    {
        //Interaction1
        //When button1 clicked change screen to Screen1
        //Go to Screen1 with screen transition towards East
        application().gotoScreen1ScreenWipeTransitionEast();
    }
}
