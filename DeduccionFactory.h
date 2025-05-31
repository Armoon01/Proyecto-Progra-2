#pragma once
#include "Deduccion.h"
#include "CCSS.h"
#include "Renta.h"
#include "DeduccionFija.h"
#include "DeduccionPorcentaje.h"
class DeduccionFactory {
public:
    static Deduccion* crearCCSS(float sem, float ivm, float lpt);
    static Deduccion* crearRenta(float porcentaje);
    static Deduccion* crearFija(float monto);
    static Deduccion* crearPorcentaje(float porcentaje);
};

