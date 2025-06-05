#include "HorasExtraDiurna.h"

HorasExtraDiurna::HorasExtraDiurna(double cantidadHoras)
	: cantidadHoras(cantidadHoras) {}

double HorasExtraDiurna::Calcular(double SalarioBase) const {
	return cantidadHoras * (SalarioBase/240) * 3 / 2;
}
string HorasExtraDiurna::toString() const {
	stringstream ss;
	ss << "Horas Extra Diurna: " << cantidadHoras << " horas";
	return ss.str();
}