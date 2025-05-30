#pragma onceAdd commentMore actions
#include "HorasExtra.h"

class HorasExtraFeriado : public HorasExtra {
public:
    HorasExtraFeriado(HorasExtra* base);
    double Calcular(double SalarioBase) const override;
};

