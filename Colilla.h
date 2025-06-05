#pragma once
#include <iostream>
#include "Nomina.h"
#include "Colaborador.h"
#include "ObjectAdaptador.h"
#include "sstream"
using namespace std;
class Colilla : public ObjectAdaptador {
private:
    string periodo;
    string fecha;
    Nomina* nomina;
    Colaborador* colaborador;
public:
    Colilla(const string& periodo, const string& fecha, Nomina* nomina, Colaborador* colaborador);
    ~Colilla();
    void mostrarResumen();
    // Getters
    string getPeriodo() const;
    string getFecha() const;
    Nomina* getNomina() const;
    Colaborador* getColaborador() const;
    string toString() const override;
};

