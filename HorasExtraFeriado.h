#pragma once
#include "Ingreso.h"
#include <sstream>
class HorasExtraFeriado : public Ingreso {
public:
    HorasExtraFeriado(double cantidadHoras);

    double Calcular(double salarioBase) const override;
    string toString() const override;

private:
    double cantidadHoras;
};