#pragma once
#include "HorasExtra.h"

class HorasExtraBase : public HorasExtra {
    int cantidadHoras;
    double valorHora;
public:
    HorasExtraBase(int cantidadHoras, double valorHora);
    double Calcular(double SalarioBase) const override;
};
