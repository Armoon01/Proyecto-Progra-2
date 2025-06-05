#pragma once
#include "Control.h"
#include "Colaborador.h"
#include "Nomina.h"
#include "Consola.h"
#include "Planillas.h"
class Control; // Forward declaration

class MenuNominas : public Consola {
private:
    Control* gestor;
    Colaborador* colaboradorActual;
    Planillas* planillas;

public:
    MenuNominas(Control* gestor, Colaborador* colaborador, Planillas* planillas);
    void lanzar(int opcion) override;
    void setColaborador(Colaborador* colaborador);
};

