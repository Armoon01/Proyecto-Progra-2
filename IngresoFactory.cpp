#include "IngresoFactory.h"


Ingreso* IngresoFactory::crearIngreso(const string& tipo, HorasExtra* base) {
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