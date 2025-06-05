#pragma once
#include "Ingreso.h"
#include <sstream>
#include <iomanip>

class BonificacionPorcentaje : public Ingreso {
    float porcentaje;
public:
    BonificacionPorcentaje(float porcentaje) : porcentaje(porcentaje) {}
    double Calcular(double salarioBase) const override {
        return salarioBase * porcentaje / 100.0f;
    }
    string toString() const override {
		stringstream ss;
        ss << fixed << setprecision(2);
		ss << "Bonificacion Porcentaje: " << porcentaje << "%";
		return ss.str();
	}
};
