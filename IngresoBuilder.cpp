#include "IngresoBuilder.h"
#include "HorasExtraDiurna.h"
#include "HorasExtraNocturna.h"
#include "HorasExtraMixta.h"
#include "HorasExtraFeriado.h"
#include "BonificacionFija.h"
#include "BonificacionPorcentaje.h"

IngresoBuilder& IngresoBuilder::Tipo(const std::string& t) {
    tipo = t;
    return *this;
}

IngresoBuilder& IngresoBuilder::CantidadHoras(double horas) {
    cantidadHoras = horas;
    return *this;
}

IngresoBuilder& IngresoBuilder::Valor(double v) {
    valor = v;
    return *this;
}

Ingreso* IngresoBuilder::Build() {
    if (tipo == "HorasExtraDiurna") {
        return new HorasExtraDiurna(cantidadHoras);
    }
    else if (tipo == "HorasExtraNocturna") {
        return new HorasExtraNocturna(cantidadHoras);
    }
    else if (tipo == "HorasExtraMixta") {
        return new HorasExtraMixta(cantidadHoras);
    }
    else if (tipo == "HorasExtraFeriado") {
        return new HorasExtraFeriado(cantidadHoras);
    }
    else if (tipo == "Porcentual") {
        return new BonificacionPorcentaje(valor); // El constructor debería aceptar el porcentaje
    }
    else if (tipo == "Fijo") {
        return new BonificacionFija(valor); // El constructor debería aceptar el monto fijo
    }
    else {
        return nullptr;
    }
}