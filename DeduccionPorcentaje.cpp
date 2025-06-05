#include "DeduccionPorcentaje.h"

DeduccionPorcentaje::DeduccionPorcentaje(float porcentaje)
    : porcentaje(porcentaje) {}

float DeduccionPorcentaje::calcular(float salarioBase) const {
    return salarioBase * porcentaje;
}

string DeduccionPorcentaje::toString() const {
	return "Deduccion Porcentaje: " + to_string(porcentaje * 100) + "%";
}