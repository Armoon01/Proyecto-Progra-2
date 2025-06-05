#pragma once
#include "DeduccionFija.h"
#include <iomanip>

class Embargos : public DeduccionFija {
public:
    Embargos(float montoFijo);
    string toString() const override;
};
