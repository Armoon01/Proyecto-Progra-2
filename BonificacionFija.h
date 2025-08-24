#pragma once
#include "Ingreso.h"
class BonificacionFija : public Ingreso {
    float monto;
public:
    BonificacionFija(float monto) : monto(monto) {}
    double Calcular(double salarioBase) const override {
        return monto;
    }
};
