#pragma once
#include "Deduccion.h"

class Renta : public Deduccion {
private:
    mutable float ultimoImpuesto; // Se permite modificar en método const
public:
    Renta();
    float calcular(float salarioBase) const override;
    string toString() const override;
};