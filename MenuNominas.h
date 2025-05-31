#pragma once
#include "Control.h"
#include "Colaborador.h"
#include "Nomina.h"
#include "Consola.h"

class Control; // Forward declaration

class MenuNominas : public Consola {
private:
    Control* gestor;
    Colaborador* colaboradorActual;
public:
    MenuNominas(Control* gestor, Colaborador* colaborador);
    void lanzar(int opcion) override;
    void setColaborador(Colaborador* colaborador);
};

