#pragma once
#include "DeduccionPorcentaje.h"

class Embargos : public DeduccionPorcentaje {
public:
    Embargos(float porcentaje);
    float calcular(float salarioBase) const override;
};
