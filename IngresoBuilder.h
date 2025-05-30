#pragma once
#include "Ingreso.h"
#include <iostream>
using namespace std;

class IngresoBuilder {
protected:
    string tipo;
    int cantidad;
public:
    IngresoBuilder& setTipo(const string& tipo);
    IngresoBuilder& setCantidad(int cantidad);
    virtual Ingreso* build() = 0;
    virtual ~IngresoBuilder() {}
};

