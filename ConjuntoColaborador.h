#pragma once
#include "Lista.h"
#include "Colilla.h"
#include "Colaborador.h"
#include <sstream>
class ConjuntoColaborador {
private:
    Lista* listaPersonas; // Lista de Colaborador*
public:
    ConjuntoColaborador();
    ~ConjuntoColaborador();
    void agregarColaborador(Colaborador* c);
    Lista* getListaPersonas() const;
    IIterador* getIterador() const;          
    Colaborador* buscar(const string& cedula) const; 
    void remover(const string& cedula);
    string listarColaboradores() const;
};

