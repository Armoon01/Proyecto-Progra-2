#include "HorasExtraMixta.h"
// Constructor
HorasExtraMixta::HorasExtraMixta(HorasExtra* base) : HorasExtra(base) {}

// Calcular 
double HorasExtraMixta::Calcular(double SalarioBase) const {
    return base->Calcular(SalarioBase) * (3 / 2) * (8 / 7);
}