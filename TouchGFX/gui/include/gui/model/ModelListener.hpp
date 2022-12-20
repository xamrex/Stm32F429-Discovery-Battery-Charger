#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>


class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}
    virtual void UpdateBatteryVoltage () {};
    virtual void DrawPoint () {};
    virtual void DrawPointMin () {};
    virtual void DisplayLastAndMaxVlt() {} ;
    virtual void DisplayRunningTime() {} ;
    virtual void DisplayCurrentValue() {};
    virtual void DisplayChargingFinished() {};

    void bind(Model* m)
    {
        model = m;
    }
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
