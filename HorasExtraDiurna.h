#pragma once
#include "HorasExtra.h"
class HorasExtraDiurna : public HorasExtra
{
public:
    HorasExtraDiurna(HorasExtra*);
    double Calcular(double SalarioBase) const override;
};

