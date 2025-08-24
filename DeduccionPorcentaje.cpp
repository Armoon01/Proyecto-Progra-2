#include "DeduccionPorcentaje.h"

DeduccionPorcentaje::DeduccionPorcentaje(float porcentaje)
    : porcentaje(porcentaje) {}

float DeduccionPorcentaje::calcular(float salarioBase) const {
    return salarioBase * porcentaje;
}