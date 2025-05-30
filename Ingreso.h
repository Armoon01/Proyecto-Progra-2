#pragma once
class Ingreso
{
public:
    virtual ~Ingreso() {}
    virtual float calcular(float salarioBase) const = 0;
};

