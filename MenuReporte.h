#pragma once
#include "Consola.h"
#include "SistemaNomina.h"
#include "Control.h"
#include "Planillas.h"
#include <iostream>
using namespace std;

class MenuReporte : public Consola {
private:
    Control* gestor;
    Planillas* planillas; // NUEVO: referencia a planillas

public:
    MenuReporte(Control* gestor, Planillas* planillas);
    virtual void lanzar(int opcion) override;
};