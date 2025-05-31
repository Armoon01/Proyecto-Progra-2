#include "HorasExtraNocturna.h"

// Constructor
HorasExtraNocturna::HorasExtraNocturna(HorasExtra* base) : HorasExtra(base) {}

// Calcular
double HorasExtraNocturna::Calcular(double SalarioBase) const {
    return base->Calcular(SalarioBase) * (3 / 2) * (8 / 6);
}