#pragma once
#include "HorasExtra.h"

class HorasExtraNocturna : public HorasExtra {
public:
    HorasExtraNocturna(HorasExtra* base);
    double Calcular(double SalarioBase) const override;
};

