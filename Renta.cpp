#include "Renta.h"

Renta::Renta(float porcentaje)
    : DeduccionPorcentaje(porcentaje) {}

float Renta::calcular(float salarioBase) const {
    // Puedes agregar reglas especiales aquí si tienes alguna
    return DeduccionPorcentaje::calcular(salarioBase);
}