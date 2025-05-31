#pragma once
#include "Lista.h"
#include "Ingreso.h"
#include "Deduccion.h"
class Nomina {
private:
    Lista* ingresos;     // Lista de Ingreso*
    Lista* deducciones;  // Lista de Deduccion*
public:
    Nomina();
    ~Nomina();
    float calcularSalarioBruto(float salarioBase);
    float calcularDeducciones(float salarioBase);
    float calcularSalarioNeto(float salarioBase);
    Lista* getIngresos() const;
    Lista* getDeducciones() const;
};

