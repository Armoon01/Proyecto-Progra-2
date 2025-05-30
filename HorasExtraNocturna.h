#pragma once
#include "HorasExtra.h"

class HorasExtraNocturna : public HorasExtra {
public:
    HorasExtraNocturna(HorasExtra* base);
    double Calcular() const override;
};

