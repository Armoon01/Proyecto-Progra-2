#include "Nomina.h"
#include <sstream>

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

string Nomina::toString(float salarioBase) {
    std::ostringstream oss;
    oss << "Ingresos:\n";
    for (int i = 0; i < ingresos->size(); ++i) {
        Ingreso* ingreso = dynamic_cast<Ingreso*>(ingresos->get(i));
        if (ingreso) {
            oss << "  - " << ingreso->toString() << "\n";
        }
    }
    oss << "Deducciones:\n";
    for (int i = 0; i < deducciones->size(); ++i) {
        Deduccion* deduccion = dynamic_cast<Deduccion*>(deducciones->get(i));
        if (deduccion) {
            oss << "  - " << deduccion->toString() << "\n";
        }
    }
    // Mostrar salario neto con dos decimales usando stringstream básico
    float neto = calcularSalarioNeto(salarioBase);
    int parteEntera = static_cast<int>(neto);
    int parteDecimal = static_cast<int>((neto - parteEntera) * 100);
    oss << "Salario neto: " << parteEntera << "."
        << (parteDecimal < 10 ? "0" : "") << parteDecimal << "\n";
    return oss.str();
}