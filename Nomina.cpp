#include "Nomina.h"
Nomina::Nomina() {
    ingresos = new Lista();
    deducciones = new Lista();
}

Nomina::~Nomina() {
    delete ingresos;
    delete deducciones;
}

float Nomina::calcularSalarioBruto(float salarioBase) {
    float total = 0.0;
    for (int i = 0; i < ingresos->size(); ++i) {
        Ingreso* ingreso = dynamic_cast<Ingreso*>(ingresos->get(i));
        if (ingreso) {
            total += ingreso->Calcular(salarioBase);
        }
    }
    return total;
}

float Nomina::calcularDeducciones(float salarioBase) {
    float total = 0.0;
    for (int i = 0; i < deducciones->size(); ++i) {
        Deduccion* deduccion = dynamic_cast<Deduccion*>(deducciones->get(i));
        if (deduccion) {
            total += deduccion->calcular(salarioBase);
        }
    }
    return total;
}

float Nomina::calcularSalarioNeto(float salarioBase) {
    return calcularSalarioBruto(salarioBase) - calcularDeducciones(salarioBase);
}

Lista* Nomina::getIngresos() const {
    return ingresos;
}

Lista* Nomina::getDeducciones() const {
    return deducciones;
}