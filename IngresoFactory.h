#pragma once
#include "Ingreso.h"
#include "HorasExtraDiurna.h"
#include "HorasExtraMixta.h"
#include "HorasExtraNocturna.h"
#include "HorasExtraFeriado.h"
#include "HorasExtraBase.h"
#include <iostream>
using namespace std;

class IngresoFactory {
public:
    static Ingreso* crearIngreso(const string& tipo, HorasExtra* base);
};

