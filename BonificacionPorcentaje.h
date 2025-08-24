#pragma once
#include "Ingreso.h"

class BonificacionPorcentaje : public Ingreso {
    float porcentaje;
public:
    BonificacionPorcentaje(float porcentaje) : porcentaje(porcentaje) {}
    double Calcular(double salarioBase) const override {
        return salarioBase * porcentaje / 100.0f;
    }
};
