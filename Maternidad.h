#pragma once
#include "DeduccionPorcentaje.h"

class Maternidad : public DeduccionPorcentaje {
public:
    Maternidad(float porcentaje);
    float calcular(float salarioBase) const override;
};