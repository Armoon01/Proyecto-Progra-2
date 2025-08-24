#include "HorasExtraDiurna.h"

//Constructor
HorasExtraDiurna::HorasExtraDiurna(HorasExtra* base) : HorasExtra(base) {}
//Calcular 
double HorasExtraDiurna::Calcular(double SalarioBase) const {
	if (base) {
		return base->Calcular(SalarioBase) * 3 / 2;
	}
	return 0.0; // Si no hay base, retorna 0
}