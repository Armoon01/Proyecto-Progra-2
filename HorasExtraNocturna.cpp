#include "HorasExtraNocturna.h"

// Constructor
HorasExtraNocturna::HorasExtraNocturna(HorasExtra* base) : HorasExtra(base) {}

// Calcular
double HorasExtraNocturna::Calcular() const {
    return base->Calcular() * (3 / 2) * (8 / 6);
}