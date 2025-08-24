#pragma once
#include "Deduccion.h"

class DeduccionFija : public Deduccion {
protected:
    float monto;
public:
    DeduccionFija(float monto);
    virtual float calcular(float salarioBase) const override;
};
