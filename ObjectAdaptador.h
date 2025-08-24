#pragma once
#include "IObjecto.h"
class ObjectAdaptador : public IObjecto{ 
public:
    virtual string toString() const override; 
    virtual bool equals(IObjecto*) override;
    virtual string getType() const override;
};