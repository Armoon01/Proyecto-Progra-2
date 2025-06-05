#pragma once
#include "ObjectAdaptador.h"
class Ingreso : public ObjectAdaptador
{

public:
    virtual ~Ingreso() {}
    virtual double Calcular( double salarioBase) const = 0;
    virtual string toString() const = 0;
};

