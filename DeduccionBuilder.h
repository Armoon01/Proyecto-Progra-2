#pragma once
#include "Deduccion.h"
#include <string>

class DeduccionBuilder {
public:
    DeduccionBuilder& Tipo(const string& tipo); // "CCSS", "Renta", "Embargos", "Maternidad", "Fija", "Porcentaje"
    DeduccionBuilder& PorcentajeSEM(float porcentaje);
    DeduccionBuilder& PorcentajeIVM(float porcentaje);
    DeduccionBuilder& PorcentajeLPT(float porcentaje);
    DeduccionBuilder& Porcentaje(float porcentaje);
    DeduccionBuilder& Monto(float monto);

    Deduccion* Build();

private:
    string tipo;
    float porcentajeSEM = 0.0f;
    float porcentajeIVM = 0.0f;
    float porcentajeLPT = 0.0f;
    float porcentaje = 0.0f;
    float monto = 0.0f;
};