#pragma once
#include "Ingreso.h"
#include <sstream>
class HorasExtraMixta : public Ingreso {
public:
    HorasExtraMixta(double cantidadHoras);

    double Calcular(double salarioBase) const override;

    string toString() const override;
private:
    double cantidadHoras;
};