#pragma once
#include "Ingreso.h"
#include <sstream>

class HorasExtraDiurna : public Ingreso {
public:
    HorasExtraDiurna(double cantidadHoras);
    double Calcular(double salarioBase) const override;
    string toString() const override;

private:
    double cantidadHoras;
};
