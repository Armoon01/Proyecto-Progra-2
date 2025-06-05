#include "MenuColillas.h"
#include <iostream>
using namespace std;

MenuColillas::MenuColillas(Control* gestor, Colaborador* colaborador, Planillas* planillas)
    : Consola(), gestor(gestor), colaboradorActual(colaborador), planillas(planillas) {
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
        // Listar colillas usando Planillas
        Lista* colillas = planillas->obtenerColillasDeColaborador(colaboradorActual);
        imprimir("Colillas del colaborador:");

        for (int i = 0; i < colillas->size(); ++i) {
            Colilla* colilla = dynamic_cast<Colilla*>(colillas->get(i));
            if (colilla) {
                imprimir(to_string(i) + ". " + colilla->toString());
            }
        }

        delete colillas;
        enter();
        show();
    }
    else if (opcion == 2) {
        // Ver detalles de una colilla usando Planillas
        Lista* colillas = planillas->obtenerColillasDeColaborador(colaboradorActual);
        int idx = leerEntero("Índice de la colilla a consultar: ");
        if (idx >= 0 && idx < colillas->size()) {
            Colilla* colilla = dynamic_cast<Colilla*>(colillas->get(idx));
            if (colilla) {
                // Si quieres mostrar detalles de la nómina:
                imprimir(colilla->getNomina()->toString(colaboradorActual->getSalarioBase()));
            }
        }
        else {
            imprimir("Índice inválido.");
        }
        delete colillas;
        enter();
        show();
    }
    else if (opcion == 3) {
        // Eliminar colilla usando Planillas
        Lista* colillas = planillas->obtenerColillasDeColaborador(colaboradorActual);
        int idx = leerEntero("Índice de la colilla a eliminar: ");
        if (idx >= 0 && idx < colillas->size()) {
            Colilla* colilla = dynamic_cast<Colilla*>(colillas->get(idx));
            if (colilla) {
                // Remover de la lista general de colillas en Planillas
                planillas->obtenerColillas()->remover(colilla);
                imprimir("Colilla eliminada.");
            }
        }
        else {
            imprimir("Índice inválido.");
        }
        delete colillas;
        enter();
        show();
    }
    else if (opcion == 4) {
        gestor->mostrarMenuColaboradores();
    }
}