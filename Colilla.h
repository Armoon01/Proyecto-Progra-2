#pragma once
#include <iostream>
#include "Nomina.h"
#include "ObjectAdaptador.h"
using namespace std;
class Colilla : public ObjectAdaptador {
private:
    string periodo;
    string fecha;
    Nomina* nomina;
public:
    Colilla(const string& periodo, const string& fecha, Nomina* nomina);
    ~Colilla();
    void mostrarResumen();
    // Getters
    string getPeriodo() const;
    string getFecha() const;
    Nomina* getNomina() const;
};

