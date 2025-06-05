#pragma once
#include "Control.h"
#include "Colaborador.h"
#include "Colilla.h"
#include "Consola.h"
#include "Planillas.h"

class Control; // Forward declaration

class MenuColillas : public Consola {
private:
    Control* gestor;
    Colaborador* colaboradorActual;
    Planillas* planillas;
public:
    MenuColillas(Control* gestor, Colaborador* colaborador, Planillas* planilla);
    void lanzar(int opcion) override;
    void setColaborador(Colaborador* colaborador);
};
