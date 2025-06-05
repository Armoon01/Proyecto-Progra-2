#pragma once
#include "Ingreso.h"
#include "HorasExtraDiurna.h"
#include "HorasExtraMixta.h"
#include "HorasExtraNocturna.h"
#include "HorasExtraFeriado.h"
#include "BonificacionFija.h"
#include "BonificacionPorcentaje.h"

class IngresoFactory {
public:
    static Ingreso* crearHorasExtraDiurna(double cantidadHoras);
    static Ingreso* crearHorasExtraMixta(double cantidadHoras);
    static Ingreso* crearHorasExtraNocturna(double cantidadHoras);
    static Ingreso* crearHorasExtraFeriado(double cantidadHoras);
    static Ingreso* crearBonificacionFija(double valor);
    static Ingreso* crearBonificacionPorcentaje(double porcentaje);
};