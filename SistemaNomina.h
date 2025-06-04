#pragma once
#include "Lista.h"
#include "Colaborador.h"
#include <iostream>
#include <fstream>
#include <iostream>
class SistemaNomina
{
private:
    static SistemaNomina* instancia;
    Lista* colaboradores; // Lista de Colaborador*
    SistemaNomina(); // constructor privado para Singleton
public:
    static SistemaNomina* getInstance();
    ~SistemaNomina();
    void registrarColaborador(Colaborador* e);
	void agregarListaColaborador(Lista* e);
    void generarPlanilla();
    void exportarReporte();
    Lista* getColaboradores() const;
};

