#pragma once
#include "DeduccionFija.h"

class Maternidad : public DeduccionFija {
public:
    Maternidad(float montoFijo);
    string toString() const override;
};