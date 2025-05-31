#include "IngresoBuilder.h"

Ingreso* IngresoBuilder::crearFijo(float monto) {
    return new BonificacionFija(monto);
}

Ingreso* IngresoBuilder::crearPorcentaje(float porcentaje) {
    return new BonificacionPorcentaje(porcentaje);
}

Ingreso* IngresoBuilder::crearHorasExtra(const string& tipo, HorasExtra* base) {
    if (tipo == "diurna") {
        return new HorasExtraDiurna(base);
    }
    else if (tipo == "mixta") {
        return new HorasExtraMixta(base);
    }
    else if (tipo == "nocturna") {
        return new HorasExtraNocturna(base);
    }
    else if (tipo == "feriado") {
        return new HorasExtraFeriado(base);
    }
    return nullptr;
}