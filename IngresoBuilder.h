#pragma once
#include "Ingreso.h"
#include "BonificacionFija.h"
#include "BonificacionPorcentaje.h"
#include "HorasExtraDiurna.h"
#include "HorasExtraMixta.h"
#include "HorasExtraNocturna.h"
#include "HorasExtraFeriado.h"
using namespace std;

class IngresoBuilder {
public:
    static Ingreso* crearFijo(float monto);
    static Ingreso* crearPorcentaje(float porcentaje);
    static Ingreso* crearHorasExtra(const string& tipo, HorasExtra* base = nullptr);
};