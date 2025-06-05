#include "HorasExtraMixta.h"
// Constructor
HorasExtraMixta::HorasExtraMixta(double cantidadHoras) : cantidadHoras(cantidadHoras) {}

// Calcular 
double HorasExtraMixta::Calcular(double SalarioBase) const {
    return cantidadHoras * (SalarioBase / 240) * (3 / 2) * (8 / 7);
}

string HorasExtraMixta::toString() const {
	stringstream ss;
	ss << "Horas Extra Mixta: " << cantidadHoras << " horas";
	return ss.str();
}