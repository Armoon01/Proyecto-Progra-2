#include "IngresoFactory.h"

Ingreso* IngresoFactory::crearHorasExtraDiurna(double cantidadHoras) {
    return new HorasExtraDiurna(cantidadHoras);
}

Ingreso* IngresoFactory::crearHorasExtraMixta(double cantidadHoras) {
    return new HorasExtraMixta(cantidadHoras);
}

Ingreso* IngresoFactory::crearHorasExtraNocturna(double cantidadHoras) {
    return new HorasExtraNocturna(cantidadHoras);
}

Ingreso* IngresoFactory::crearHorasExtraFeriado(double cantidadHoras) {
    return new HorasExtraFeriado(cantidadHoras);
}

Ingreso* IngresoFactory::crearBonificacionFija(double valor) {
	return new BonificacionFija(valor);
}

Ingreso* IngresoFactory::crearBonificacionPorcentaje(double porcentaje) {
	return new BonificacionPorcentaje(porcentaje);
}