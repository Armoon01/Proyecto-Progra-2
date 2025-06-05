#include "Renta.h"
#include <sstream>
#include <iomanip>

Renta::Renta() : ultimoImpuesto(0.0f) {}

float Renta::calcular(float salarioBase) const {
    float impuesto = 0.0;
    const float EXENTO = 922000;
    const float LIM_10 = 1352000;
    const float LIM_15 = 2373000;
    const float LIM_20 = 4745000;

    if (salarioBase > EXENTO) {
        float monto10 = salarioBase > LIM_10 ? LIM_10 - EXENTO : salarioBase - EXENTO;
        if (monto10 > 0)
            impuesto += monto10 * 0.10;
    }
    if (salarioBase > LIM_10) {
        float monto15 = salarioBase > LIM_15 ? LIM_15 - LIM_10 : salarioBase - LIM_10;
        if (monto15 > 0)
            impuesto += monto15 * 0.15;
    }
    if (salarioBase > LIM_15) {
        float monto20 = salarioBase > LIM_20 ? LIM_20 - LIM_15 : salarioBase - LIM_15;
        if (monto20 > 0)
            impuesto += monto20 * 0.20;
    }
    if (salarioBase > LIM_20) {
        float monto25 = salarioBase - LIM_20;
        if (monto25 > 0)
            impuesto += monto25 * 0.25;
    }

    ultimoImpuesto = impuesto;
    return impuesto;
}

string Renta::toString() const {
    ostringstream oss;
    oss << fixed << setprecision(2);
    oss << "Renta: " << ultimoImpuesto;
    return oss.str();
}