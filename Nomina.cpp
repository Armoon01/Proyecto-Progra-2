#include "Nomina.h"
#include "Renta.h"
#include <sstream>
#include <iomanip> 
Nomina::Nomina() {
    ingresos = new Lista();
    deducciones = new Lista();
}

Nomina::~Nomina() {
    delete ingresos;
    delete deducciones;
}

float Nomina::calcularSalarioBruto(float salarioBase) {
    float total = salarioBase;
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
    ostringstream oss;
    oss << fixed << setprecision(2); // para que todo tenga 2 decimales

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
            // Si es Renta, calculamos explícitamente con salarioBase
            Renta* renta = dynamic_cast<Renta*>(deduccion);
            if (renta) {
                float impuesto = renta->calcular(salarioBase);
                oss << "  - Renta: " << impuesto << "\n";
            }
            else if (CCSS* ccss = dynamic_cast<CCSS*>(deduccion)) {
                float monto = ccss->calcular(salarioBase);
                oss << "  - CCSS: " << monto << "\n";
            }
            else {
                oss << "  - " << deduccion->toString() << "\n";
            }
        }
    }

    float neto = calcularSalarioNeto(salarioBase);
    oss << "Salario neto: " << neto << "\n";
    return oss.str();
}

string Nomina::listarIngresos() const {
    ostringstream oss;
    oss << fixed << setprecision(2);
    for (int i = 0; i < ingresos->size(); ++i) {
        Ingreso* ingreso = dynamic_cast<Ingreso*>(ingresos->get(i));
        if (ingreso) {
            oss << "    - " << ingreso->toString() << "\n";
        }
    }
    if (ingresos->size() == 0) {
        oss << "    (Sin ingresos)\n";
    }
    return oss.str();
}

// Recibe salarioBase para calcular bien los montos.
string Nomina::listarDeducciones(float salarioBase) const {
    ostringstream oss;
    oss << fixed << setprecision(2);
    for (int i = 0; i < deducciones->size(); ++i) {
        Deduccion* deduccion = dynamic_cast<Deduccion*>(deducciones->get(i));
        if (deduccion) {
            Renta* renta = dynamic_cast<Renta*>(deduccion);
            if (renta) {
                float impuesto = renta->calcular(salarioBase);
                oss << "    - Renta: " << impuesto << "\n";
            }
            else if (CCSS* ccss = dynamic_cast<CCSS*>(deduccion)) {
                float monto = ccss->calcular(salarioBase);
                oss << "    - CCSS: " << monto << "\n";
            }
            else {
                oss << "    - " << deduccion->toString() << "\n";
            }
        }
    }
    if (deducciones->size() == 0) {
        oss << "    (Sin deducciones)\n";
    }
    return oss.str();
}