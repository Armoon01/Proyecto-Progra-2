#pragma once
#include "HorasExtra.h"

class HorasExtraMixta : public HorasExtra {
public:
    HorasExtraMixta(HorasExtra* base);
    double Calcular() const override;
};
