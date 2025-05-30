#include "HorasExtraFeriado.h"
HorasExtraFeriado::HorasExtraFeriado(HorasExtra* base) : HorasExtra(base) {}

double HorasExtraFeriado::Calcular() const {
    return base->Calcular();
}