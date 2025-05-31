#pragma once
#include "DeduccionPorcentaje.h"

class Renta : public DeduccionPorcentaje {
public:
    Renta(float porcentaje);
    float calcular(float salarioBase) const override;
};