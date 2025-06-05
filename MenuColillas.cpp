#include "MenuColillas.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <exception>
using namespace std;

MenuColillas::MenuColillas(Control* gestor, Colaborador* colaborador, Planillas* planillas)
    : Consola(), gestor(gestor), colaboradorActual(colaborador), planillas(planillas) {
    setTitulo("ADMINISTRACION DE COLILLAS");
    setInstrucciones("Seleccione una de las siguientes opciones.");
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
            imprimir("\n--------------------------------------------------------------------");
            imprimir("                       LISTA DE COLILLAS                            ");
            imprimir("--------------------------------------------------------------------");
            Lista* colillas = planillas->obtenerColillasDeColaborador(colaboradorActual);
            if (!colillas) throw exception();

            if (colillas->size() == 0) {
                imprimir("| No hay colillas registradas.                                     |");
                imprimir("--------------------------------------------------------------------");
            }
            else {
                // Encabezado de la tabla
                cout << left
                    << "| " << setw(5) << "Idx"
                    << "| " << setw(15) << "Periodo"
                    << "| " << setw(12) << "Fecha"
                    << "| " << setw(12) << "Salario Neto"
                    << "|\n";
                imprimir("--------------------------------------------------------------------");
                for (int i = 0; i < colillas->size(); ++i) {
                    Colilla* colilla = dynamic_cast<Colilla*>(colillas->get(i));
                    if (colilla) {
                        cout << "| " << setw(5) << i
                            << "| " << setw(15) << colilla->getPeriodo()
                            << "| " << setw(12) << colilla->getFecha()
                            << "| " << setw(12) << fixed << setprecision(2)
                            << colilla->getNomina()->calcularSalarioNeto(colaboradorActual->getSalarioBase())
                            << "|\n";
                    }
                    else {
                        throw exception();
                    }
                }
                imprimir("--------------------------------------------------------------------");
            }

            delete colillas;
            enter();
            show();
        }
        else if (opcion == 2) {
            imprimir("\n--------------------------------------------------------------------");
            imprimir("                   DETALLES DE UNA COLILLA                          ");
            imprimir("--------------------------------------------------------------------");
            Lista* colillas = planillas->obtenerColillasDeColaborador(colaboradorActual);
            if (!colillas) throw exception();
            int idx = leerEntero("Indice de la colilla a consultar: ");
            if (idx < 0 || idx >= colillas->size()) throw exception();
            Colilla* colilla = dynamic_cast<Colilla*>(colillas->get(idx));
            if (!colilla) throw exception();

            ostringstream detalle;
            detalle << "--------------------------------------------------------------------\n";
            detalle << "Colaborador : " << colaboradorActual->getNombre()
                << " | Cedula: " << colaboradorActual->getCedula() << "\n";
            detalle << "Periodo     : " << colilla->getPeriodo()
                << " | Fecha: " << colilla->getFecha() << "\n";
            detalle << "--------------------------------------------------------------------\n";
            detalle << "Ingresos:\n" << colilla->getNomina()->listarIngresos();
            detalle << "Deducciones:\n" << colilla->getNomina()->listarDeducciones(colaboradorActual->getSalarioBase());
            detalle << "--------------------------------------------------------------------\n";
            detalle << "Salario Neto: " << fixed << setprecision(2)
                << colilla->getNomina()->calcularSalarioNeto(colaboradorActual->getSalarioBase()) << "\n";
            detalle << "--------------------------------------------------------------------\n";

            imprimir(detalle.str());
            delete colillas;
            enter();
            show();
        }
        else if (opcion == 3) {
            imprimir("\n--------------------------------------------------------------------");
            imprimir("                        ELIMINAR COLILLA                            ");
            imprimir("--------------------------------------------------------------------");
            Lista* colillas = planillas->obtenerColillasDeColaborador(colaboradorActual);
            if (!colillas) throw exception();
            int idx = leerEntero("Indice de la colilla a eliminar: ");
            if (idx < 0 || idx >= colillas->size()) throw exception();
            Colilla* colilla = dynamic_cast<Colilla*>(colillas->get(idx));
            if (!colilla) throw exception();
            planillas->obtenerColillas()->remover(colilla);
            imprimir("\nColilla eliminada correctamente.");
            imprimir("--------------------------------------------------------------------");
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
        imprimir("\n[!] Ha ocurrido un error en la operacion. Verifique los datos e intente de nuevo.\n");
        enter();
        show();
    }
}