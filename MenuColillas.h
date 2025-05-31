#pragma once
#include "Control.h"
#include "Colaborador.h"
#include "Colilla.h"
#include "Consola.h"

class Control; // Forward declaration

class MenuColillas : public Consola {
private:
    Control* gestor;
    Colaborador* colaboradorActual;
public:
    MenuColillas(Control* gestor, Colaborador* colaborador);
    void lanzar(int opcion) override;
    void setColaborador(Colaborador* colaborador);
};
