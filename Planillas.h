#pragma once
#include "Lista.h"
#include "Colilla.h"

class Planillas {
public:
    Planillas();
    ~Planillas();

    void agregarColilla(Colilla* colilla);
    Lista* obtenerColillas();
    Lista* obtenerColillasDeColaborador(const ObjectAdaptador* colaborador) const;

private:
    Lista* colillas; // Lista de todas las colillas
};