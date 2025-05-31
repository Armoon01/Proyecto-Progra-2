#pragma once
#include "Deduccion.h"

class CCSS : public Deduccion {
    float porcentajeSEM;
    float porcentajeIVM;
    float porcentajeLPT;
public:
    CCSS(float sem, float ivm, float lpt);
    virtual float calcular(float salarioBase) const override;
};