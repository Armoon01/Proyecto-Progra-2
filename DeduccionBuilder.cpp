#include "DeduccionBuilder.h"

Deduccion* DeduccionBuilder::crearCCSS(float porcentajeSEM, float porcentajeIVM, float porcentajeLPT) {
    return new CCSS(porcentajeSEM, porcentajeIVM, porcentajeLPT);
}

Deduccion* DeduccionBuilder::crearRenta(float porcentaje) {
    return new Renta(porcentaje);
}

Deduccion* DeduccionBuilder::crearEmbargos(float porcentaje) {
    return new Embargos(porcentaje);
}

Deduccion* DeduccionBuilder::crearMaternidad(float porcentaje) {
    return new Maternidad(porcentaje);
}

Deduccion* DeduccionBuilder::crearFija(float monto) {
    return new DeduccionFija(monto);
}

Deduccion* DeduccionBuilder::crearPorcentaje(float porcentaje) {
    return new DeduccionPorcentaje(porcentaje);
}