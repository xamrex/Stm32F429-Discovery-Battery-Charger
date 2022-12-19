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
    virtual void DisplayLastAndMaxVlt() {} ;
    virtual void DisplayRunningTime() {} ;

    void bind(Model* m)
    {
        model = m;
    }
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
