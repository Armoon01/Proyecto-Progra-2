#include "HorasExtraBase.h"

//Constructor
HorasExtraBase::HorasExtraBase(int cantidadHoras, double valorHora)
    : HorasExtra(nullptr), cantidadHoras(cantidadHoras), valorHora(valorHora) {}

// Método para calcular el valor de las horas extra
double HorasExtraBase::Calcular(double SalarioBase) const {
    return SalarioBase/240;
}