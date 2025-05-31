#pragma once
#include "ObjectAdaptador.h"
class Deduccion : public ObjectAdaptador {
public:
    virtual ~Deduccion() {}
    virtual float calcular(float salarioBase) const = 0;
};
