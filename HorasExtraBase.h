#pragma onceAdd commentMore actions
#include "HorasExtra.h"

class HorasExtraBase : public HorasExtra {
    int cantidadHoras;
    double valorHora;
public:
    HorasExtraBase(int cantidadHoras, double valorHora);
    double Calcular() const override;
};
