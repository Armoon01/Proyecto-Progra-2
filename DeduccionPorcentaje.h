#pragma once
#include "Deduccion.h"

class DeduccionPorcentaje : public Deduccion {
protected:
    float porcentaje;
public:
    DeduccionPorcentaje(float porcentaje);
    virtual float calcular(float salarioBase) const override;
    virtual string toString() const override;
};
