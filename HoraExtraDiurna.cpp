#include "HoraExtraDiurna.h"

//Constructor
HorasExtraDiurna::HorasExtraDiurna(HorasExtra* base) : HorasExtra(base) {}
//Calcular 
double HorasExtraDiurna::Calcular() const {
	if (base) {
		return base->Calcular() * 3 / 2;
	}
	return 0.0; // Si no hay base, retorna 0
}