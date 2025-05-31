#include "MenuColillas.h"
#include <iostream>
using namespace std;

MenuColillas::MenuColillas(Control* gestor, Colaborador* colaborador)
    : Consola(), gestor(gestor), colaboradorActual(colaborador) {
    agregarOpcion("Listar colillas");
    agregarOpcion("Ver detalles de una colilla");
    agregarOpcion("Eliminar colilla");
    agregarOpcion("Volver");
}

void MenuColillas::setColaborador(Colaborador* colaborador) {
    colaboradorActual = colaborador;
}

void MenuColillas::lanzar(int opcion) {
    if (!colaboradorActual) {
        imprimir("No hay colaborador seleccionado.");
        return;
    }
    if (opcion == 1) {
        // Listar colillas
        imprimir("Colillas del colaborador:");
        imprimir(colaboradorActual->getColillas()->toString());
        enter();
        show();
    }
    else if (opcion == 2) {
        // Ver detalles de una colilla
        int idx = leerEntero("Índice de la colilla a consultar: ");
        Lista* colillas = colaboradorActual->getColillas();
        if (idx >= 0 && idx < colillas->size()) {
            Colilla* colilla = dynamic_cast<Colilla*>(colillas->get(idx));
            if (colilla) {
                imprimir(colilla->toString());
                // Si quieres mostrar detalles de la nómina:
                imprimir(colilla->getNomina()->toString());
            }
        }
        else {
            imprimir("Índice inválido.");
        }
        enter();
        show();
    }
    else if (opcion == 3) {
        // Eliminar colilla
        int idx = leerEntero("Índice de la colilla a eliminar: ");
        Lista* colillas = colaboradorActual->getColillas();
        if (idx >= 0 && idx < colillas->size()) {
            ObjectAdaptador* colilla = colillas->get(idx);
            colillas->remover(colilla);
            imprimir("Colilla eliminada.");
        }
        else {
            imprimir("Índice inválido.");
        }
        enter();
        show();
    }
    else if (opcion == 4) {
        gestor->mostrarMenuColaboradores();
    }
}