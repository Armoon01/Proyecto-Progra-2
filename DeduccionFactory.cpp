#include "DeduccionFactory.h"

Deduccion* DeduccionFactory::crearCCSS(float sem, float ivm, float lpt) {
    return new CCSS(sem, ivm, lpt);
}

Deduccion* DeduccionFactory::crearRenta() {
    return new Renta();
}

Deduccion* DeduccionFactory::crearFija(float monto) {
    return new DeduccionFija(monto);
}

Deduccion* DeduccionFactory::crearPorcentaje(float porcentaje) {
    return new DeduccionPorcentaje(porcentaje);
}

Deduccion* DeduccionFactory::crearEmbargos(float montoFijo) {
	return new Embargos(montoFijo);
}

Deduccion* DeduccionFactory::crearMaternidad(float montoFijo) {
	return new Maternidad(montoFijo);
}