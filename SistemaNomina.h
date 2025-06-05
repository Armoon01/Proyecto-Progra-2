#pragma once
#include "Lista.h"
#include "Colaborador.h"
#include "Planillas.h"
#include <iostream>
#include <fstream>
#include <iomanip>

class SistemaNomina
{
private:
    static SistemaNomina* instancia;
    Lista* colaboradores; // Lista de Colaborador*
    Planillas* planillas; // <-- NUEVO: referencia a la instancia de Planillas
    SistemaNomina(Planillas* planillas); // constructor privado para Singleton
public:
    static SistemaNomina* getInstance(Planillas* planillas);
    ~SistemaNomina();
    void registrarColaborador(Colaborador* e);
    void agregarListaColaborador(Lista* e);
    void generarPlanilla();
    void exportarReporte();
    Lista* getColaboradores() const;
};