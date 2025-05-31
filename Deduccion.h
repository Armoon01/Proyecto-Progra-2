#pragma once

class Deduccion {
public:
    virtual ~Deduccion() {}
    virtual float calcular(float salarioBase) const = 0;
};
