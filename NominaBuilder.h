#pragma once
#include "Nomina.h"
#include "Ingreso.h"
#include "Deduccion.h"

class NominaBuilder {
private:
    Lista* ingresos;
    Lista* deducciones;
public:
    NominaBuilder();
    ~NominaBuilder();

    NominaBuilder& agregarIngreso(Ingreso* ingreso);
    NominaBuilder& agregarDeduccion(Deduccion* deduccion);

    Nomina* build(); // Devuelve una Nomina* con los ingresos/deducciones agregados
};