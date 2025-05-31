#include "DeduccionFactory.h"

Deduccion* DeduccionFactory::crearCCSS(float sem, float ivm, float lpt) {
    return new CCSS(sem, ivm, lpt);
}

Deduccion* DeduccionFactory::crearRenta(float porcentaje) {
    return new Renta(porcentaje);
}

Deduccion* DeduccionFactory::crearFija(float monto) {
    return new DeduccionFija(monto);
}

Deduccion* DeduccionFactory::crearPorcentaje(float porcentaje) {
    return new DeduccionPorcentaje(porcentaje);
}
