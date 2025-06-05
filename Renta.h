#pragma once
#include "Deduccion.h"

class Renta : public Deduccion {
private:
    mutable float ultimoImpuesto; // Se permite modificar en m�todo const
public:
    Renta();
    float calcular(float salarioBase) const override;
    string toString() const override;
};