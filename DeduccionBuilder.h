#pragma once
#include "Deduccion.h"
#include <iostream>
#include "CCSS.h"
#include "Renta.h"
#include "Embargos.h"
#include "Maternidad.h"
#include "DeduccionFija.h"
#include "DeduccionPorcentaje.h"
class DeduccionBuilder {
public:
    static Deduccion* crearCCSS(float porcentajeSEM, float porcentajeIVM, float porcentajeLPT);
    static Deduccion* crearRenta(float porcentaje);
    static Deduccion* crearEmbargos(float porcentaje);
    static Deduccion* crearMaternidad(float porcentaje);
    static Deduccion* crearFija(float monto);
    static Deduccion* crearPorcentaje(float porcentaje);
};