#pragma once
#include "Ingreso.h"

class IngresoBuilder {
public:
    IngresoBuilder& Tipo(const string& tipo);
    IngresoBuilder& CantidadHoras(double horas);
    IngresoBuilder& Valor(double valor);
    Ingreso* Build();

private:
    string tipo;
    double cantidadHoras = 0;
    double valor = 0;
};