#pragma once
#include "Deduccion.h"
#include "CCSS.h"
#include "Renta.h"
#include "Embargos.h"
#include "Maternidad.h"
#include "DeduccionFija.h"
#include "DeduccionPorcentaje.h"
class DeduccionFactory {
public:
    static Deduccion* crearCCSS(float sem, float ivm, float lpt);
    static Deduccion* crearRenta();
    static Deduccion* crearFija(float monto);
    static Deduccion* crearPorcentaje(float porcentaje);
    static Deduccion* crearEmbargos(float montoFijo);
    static Deduccion* crearMaternidad(float montoFijo);

};

