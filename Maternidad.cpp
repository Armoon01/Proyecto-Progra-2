#include "Maternidad.h"

Maternidad::Maternidad(float porcentaje)
    : DeduccionPorcentaje(porcentaje) {}

float Maternidad::calcular(float salarioBase) const {
    // Puedes agregar reglas especiales aquí si tienes alguna
    return DeduccionPorcentaje::calcular(salarioBase);
}
