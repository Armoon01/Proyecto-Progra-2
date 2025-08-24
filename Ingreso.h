#pragma once
class Ingreso
{

public:
    virtual ~Ingreso() {}
    virtual double Calcular( double salarioBase) const = 0;
};

