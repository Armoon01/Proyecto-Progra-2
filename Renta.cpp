#include "Renta.h"

Renta::Renta(float porcentaje)
    : DeduccionPorcentaje(porcentaje) {}

float Renta::calcular(float salarioBase) const {
    // Puedes agregar reglas especiales aqu� si tienes alguna
    return DeduccionPorcentaje::calcular(salarioBase);
}