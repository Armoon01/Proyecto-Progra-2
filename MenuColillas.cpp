#include "MenuColillas.h"
#include <iostream>
#include <exception>
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
    try {
        if (!colaboradorActual) {
            throw exception();
        }
        if (opcion == 1) {
            // Listar colillas usando Planillas
            Lista* colillas = planillas->obtenerColillasDeColaborador(colaboradorActual);
            if (!colillas) throw exception();
            imprimir("Colillas del colaborador:\n");

            if (colillas->size() == 0) {
                imprimir("No hay colillas registradas.");
            }
            else {
                for (int i = 0; i < colillas->size(); ++i) {
                    Colilla* colilla = dynamic_cast<Colilla*>(colillas->get(i));
                    if (colilla) {
                        // Formato personalizado
                        string detalle =
                            "==================== Colilla #" + to_string(i) + " ====================\n" +
                            "Periodo   : " + colilla->getPeriodo() + "\n" +
                            "Fecha     : " + colilla->getFecha() + "\n" +
                            "Colaborador: " + colilla->getColaborador()->getNombre() + " | Cédula: " + colilla->getColaborador()->getCedula() + "\n" +
                            "----------------------------------------\n" +
                            "Ingresos:\n" + colilla->getNomina()->listarIngresos() + // Debes implementar listarIngresos() en tu clase Nomina
                            "Deducciones:\n" + colilla->getNomina()->listarDeducciones(colaboradorActual->getSalarioBase()) + // Debes implementar listarDeducciones() en tu clase Nomina
                            "----------------------------------------\n" +
                            "Salario base: " + to_string(colilla->getColaborador()->getSalarioBase()) + "\n" +
                            "Salario neto: " + to_string(colilla->getNomina()->calcularSalarioNeto(colilla->getColaborador()->getSalarioBase())) + "\n" +
                            "========================================\n";
                        imprimir(detalle);
                    }
                    else {
                        throw exception();
                    }
                }
            }

            delete colillas;
            enter();
            show();
        }
        else if (opcion == 2) {
            // Ver detalles de una colilla usando Planillas
            Lista* colillas = planillas->obtenerColillasDeColaborador(colaboradorActual);
            if (!colillas) throw exception();
            int idx = leerEntero("Índice de la colilla a consultar: ");
            if (idx < 0 || idx >= colillas->size()) throw exception();
            Colilla* colilla = dynamic_cast<Colilla*>(colillas->get(idx));
            if (!colilla) throw exception();

            std::ostringstream detalle;
            detalle << "================= Detalle de la Colilla =================\n";
            detalle << "Colaborador : " << colaboradorActual->getNombre()
                << " | Cédula: " << colaboradorActual->getCedula() << "\n";
            detalle << "Periodo     : " << colilla->getPeriodo()
                << " | Fecha: " << colilla->getFecha() << "\n";
            detalle << "--------------------------------------------------------\n";
            detalle << "Ingresos:\n" << colilla->getNomina()->listarIngresos();
            detalle << "Deducciones:\n" << colilla->getNomina()->listarDeducciones(colaboradorActual->getSalarioBase());
            detalle << "--------------------------------------------------------\n";
            detalle << "Salario Neto: " << std::fixed << std::setprecision(2)
                << colilla->getNomina()->calcularSalarioNeto(colaboradorActual->getSalarioBase()) << "\n";
            detalle << "========================================================\n";

            imprimir(detalle.str());
            delete colillas;
            enter();
            show();
        }
        else if (opcion == 3) {
            // Eliminar colilla usando Planillas
            Lista* colillas = planillas->obtenerColillasDeColaborador(colaboradorActual);
            if (!colillas) throw exception();
            int idx = leerEntero("Índice de la colilla a eliminar: ");
            if (idx < 0 || idx >= colillas->size()) throw exception();
            Colilla* colilla = dynamic_cast<Colilla*>(colillas->get(idx));
            if (!colilla) throw exception();
            planillas->obtenerColillas()->remover(colilla);
            imprimir("Colilla eliminada.");
            delete colillas;
            enter();
            show();
        }
        else if (opcion == 4) {
            gestor->mostrarMenuColaboradores();
        }
        else {
            throw exception();
        }
    }
    catch (const exception&) {
        imprimir("Ha ocurrido un error en la operación.");
        enter();
        show();
    }
}