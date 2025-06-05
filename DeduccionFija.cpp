#include "DeduccionFija.h"

DeduccionFija::DeduccionFija(float monto)
    : monto(monto) {}

float DeduccionFija::calcular(float /*salarioBase*/) const {
    return monto;
}

string DeduccionFija::toString() const {
	return "Deduccion Fija: " + to_string(monto);
}