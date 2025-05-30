#include "HorasExtraFeriado.h"
HorasExtraFeriado::HorasExtraFeriado(HorasExtra* base) : HorasExtra(base) {}

double HorasExtraFeriado::Calcular(double SalarioBase) const {
    return base->Calcular(SalarioBase);
}