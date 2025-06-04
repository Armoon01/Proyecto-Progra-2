#pragma once
#include "Consola.h"
#include "SistemaNomina.h"
#include "Control.h"
#include <iostream>
using namespace std;



class MenuReporte : public Consola {

private:
    Control* gestor;

public:
    MenuReporte(Control* gestor);
    virtual void lanzar(int opcion) override;
};