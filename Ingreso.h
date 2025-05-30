#pragma once
class Ingreso
{
public:
    virtual ~Ingreso() {}
    virtual double Calcular() const = 0;
};

