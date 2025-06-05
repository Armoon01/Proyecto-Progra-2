#include "HorasExtraNocturna.h"

// Constructor
HorasExtraNocturna::HorasExtraNocturna(double cantidadHoras) : cantidadHoras(cantidadHoras) {}

// Calcular
double HorasExtraNocturna::Calcular(double SalarioBase) const {
    return cantidadHoras * (SalarioBase / 240) * (3 / 2) * (8 / 6);
}

string HorasExtraNocturna::toString() const {
	stringstream ss;
	ss << "Horas Extra Nocturnas: " << cantidadHoras << " horas";
	return ss.str();
}