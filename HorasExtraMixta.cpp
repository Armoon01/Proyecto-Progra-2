#include "HorasExtraMixta.h"
// Constructor
HorasExtraMixta::HorasExtraMixta(HorasExtra* base) : HorasExtra(base) {}

// Calcular 
double HorasExtraMixta::Calcular() const {
    return base->Calcular() * (3 / 2) * (8 / 7);
}