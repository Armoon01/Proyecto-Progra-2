#pragma once
#include "Ingreso.h"
#include <sstream>
class HorasExtraNocturna : public Ingreso {
public:
    HorasExtraNocturna(double cantidadHoras);

    double Calcular(double salarioBase) const override;

    string toString() const override;
private:
    double cantidadHoras;
};