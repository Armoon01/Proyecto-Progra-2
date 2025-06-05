#include "HorasExtraFeriado.h"
HorasExtraFeriado::HorasExtraFeriado(double cantidadHoras)
	: cantidadHoras(cantidadHoras) {}

double HorasExtraFeriado::Calcular(double SalarioBase) const {
    return cantidadHoras * (SalarioBase / 240) * 3;
}

string HorasExtraFeriado::toString() const {
	stringstream ss;
	ss << "Horas Extra Feriado: " << cantidadHoras << " horas";
	return ss.str();
}
