#pragma once
#include "Ingreso.h"
#include <sstream>
#include <iomanip>

class BonificacionFija : public Ingreso {
    float monto;
public:
    BonificacionFija(float monto) : monto(monto) {}

    double Calcular(double salarioBase) const override {
        return monto;
    }

    string toString() const override {
        stringstream ss;
        ss << fixed << setprecision(2); // Mostrar 2 decimales, sin notación científica
        ss << "Bonificacion Fija: " << monto;
        return ss.str();
    }
};