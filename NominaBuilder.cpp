#include "NominaBuilder.h"

NominaBuilder::NominaBuilder() {
    ingresos = new Lista();
    deducciones = new Lista();
}

NominaBuilder::~NominaBuilder() {
    // Liberar solo si no han sido transferidos a la Nomina final
    if (ingresos) delete ingresos;
    if (deducciones) delete deducciones;
}

NominaBuilder& NominaBuilder::agregarIngreso(Ingreso* ingreso) {
    ingresos->agregar(ingreso);
    return *this;
}

NominaBuilder& NominaBuilder::agregarDeduccion(Deduccion* deduccion) {
    deducciones->agregar(deduccion);
    return *this;
}

Nomina* NominaBuilder::build() {
    Nomina* nomina = new Nomina();
    // Transferimos los objetos a la Nomina
    for (int i = 0; i < ingresos->size(); ++i) {
        nomina->getIngresos()->agregar(ingresos->get(i));
    }
    for (int i = 0; i < deducciones->size(); ++i) {
        nomina->getDeducciones()->agregar(deducciones->get(i));
    }
    // Limpiar las listas internas para evitar doble liberación
    delete ingresos;
    delete deducciones;
    ingresos = nullptr;
    deducciones = nullptr;
    return nomina;
}