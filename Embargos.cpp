#include "Embargos.h"

Embargos::Embargos(float porcentaje)
    : DeduccionPorcentaje(porcentaje) {}

float Embargos::calcular(float salarioBase) const {
    // Agregar reglas del embargo
    return DeduccionPorcentaje::calcular(salarioBase);
}