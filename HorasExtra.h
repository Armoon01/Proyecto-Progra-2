#pragma once
#include "Ingreso.h"
#include <iostream>
using namespace std;
class HorasExtra : public Ingreso
{
protected:
    HorasExtra* base; // Decorador base
public:
    HorasExtra(HorasExtra* base = nullptr);
    virtual ~HorasExtra();
    virtual double Calcular(double SalarioBase) const = 0;
};

