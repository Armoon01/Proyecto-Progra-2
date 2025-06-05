#include "MenuNominas.h"
#include "IngresoFactory.h"
#include "DeduccionFactory.h"
#include "NominaBuilder.h"
#include "ColillaBuilder.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <exception>
using namespace std;

MenuNominas::MenuNominas(Control* gestor, Colaborador* colaborador, Planillas* planillas)
    : Consola(), gestor(gestor), colaboradorActual(colaborador), planillas(planillas) {
    setTitulo("ADMINISTRACION DE NOMINAS");
    setInstrucciones("Seleccione una de las siguientes opciones.");
    agregarOpcion("Crear nomina");
    agregarOpcion("Listar nominas");
    agregarOpcion("Calcular salario neto");
    agregarOpcion("Volver");
}

void MenuNominas::setColaborador(Colaborador* colaborador) {
    colaboradorActual = colaborador;
}

void MenuNominas::lanzar(int opcion) {
    try {
        if (!colaboradorActual) {
            throw exception();
        }
        if (opcion == 1) {
            imprimir("\n--------------------------------------------------------------------");
            imprimir("                          CREAR NOMINA                              ");
            imprimir("--------------------------------------------------------------------");

            NominaBuilder nominaBuilder;

            // Agregar ingresos usando Factory
            int cantIngresos = leerEntero("Cuantos ingresos desea agregar? ");
            if (cantIngresos < 0) throw exception();
            for (int i = 0; i < cantIngresos; ++i) {
                imprimir("\nTipos de ingreso:\n  [1] Fijo\n  [2] Porcentaje\n  [3] Horas Extra");
                int tipo = leerEntero("Seleccione el tipo de ingreso: ");
                if (tipo < 1 || tipo > 3) throw exception();
                Ingreso* ingreso = nullptr;

                if (tipo == 1) {
                    float monto = leerDouble("  > Monto fijo: ");
                    if (monto < 0) throw exception();
                    ingreso = IngresoFactory::crearBonificacionFija(monto);
                }
                else if (tipo == 2) {
                    float porcentaje = leerDouble("  > Porcentaje: ");
                    if (porcentaje < 0) throw exception();
                    ingreso = IngresoFactory::crearBonificacionPorcentaje(porcentaje);
                }
                else if (tipo == 3) {
                    imprimir("Tipos de horas extra:\n  [1] Diurna\n  [2] Mixta\n  [3] Nocturna\n  [4] Feriado");
                    int tipoHE = leerEntero("Seleccione el tipo de hora extra: ");
                    if (tipoHE < 1 || tipoHE > 4) throw exception();
                    double horas = leerDouble("  > Cantidad de horas: ");
                    if (horas < 0) throw exception();
                    switch (tipoHE) {
                    case 1: ingreso = IngresoFactory::crearHorasExtraDiurna(horas); break;
                    case 2: ingreso = IngresoFactory::crearHorasExtraMixta(horas); break;
                    case 3: ingreso = IngresoFactory::crearHorasExtraNocturna(horas); break;
                    case 4: ingreso = IngresoFactory::crearHorasExtraFeriado(horas); break;
                    }
                }
                if (ingreso) {
                    nominaBuilder.agregarIngreso(ingreso);
                }
                else {
                    throw exception();
                }
            }

            // Agregar deducciones usando Factory
            int cantDeducciones = leerEntero("Cuantas deducciones desea agregar? ");
            if (cantDeducciones < 0) throw exception();
            for (int i = 0; i < cantDeducciones; ++i) {
                imprimir("\nTipos de deduccion:");
                imprimir("  [1] CCSS\n  [2] Renta\n  [3] Embargos\n  [4] Maternidad\n  [5] Fija\n  [6] Porcentaje");
                int tipo = leerEntero("Seleccione el tipo de deduccion: ");
                if (tipo < 1 || tipo > 6) throw exception();
                Deduccion* deduccion = nullptr;

                if (tipo == 1) {
                    float sem = leerDouble("  > Porcentaje SEM: ");
                    float ivm = leerDouble("  > Porcentaje IVM: ");
                    float lpt = leerDouble("  > Porcentaje LPT: ");
                    if (sem < 0 || ivm < 0 || lpt < 0) throw exception();
                    deduccion = DeduccionFactory::crearCCSS(sem, ivm, lpt);
                }
                else if (tipo == 2) {
                    deduccion = DeduccionFactory::crearRenta();
                }
                else if (tipo == 3) {
                    float monto = leerDouble("  > Monto de embargos: ");
                    if (monto < 0) throw exception();
                    deduccion = DeduccionFactory::crearEmbargos(monto);
                }
                else if (tipo == 4) {
                    float monto = leerDouble("  > Monto de maternidad: ");
                    if (monto < 0) throw exception();
                    deduccion = DeduccionFactory::crearMaternidad(monto);
                }
                else if (tipo == 5) {
                    float monto = leerDouble("  > Monto fijo: ");
                    if (monto < 0) throw exception();
                    deduccion = DeduccionFactory::crearFija(monto);
                }
                else if (tipo == 6) {
                    float porcentaje = leerDouble("  > Porcentaje: ");
                    if (porcentaje < 0) throw exception();
                    deduccion = DeduccionFactory::crearPorcentaje(porcentaje);
                }
                if (deduccion) {
                    nominaBuilder.agregarDeduccion(deduccion);
                }
                else {
                    throw exception();
                }
            }

            Nomina* nomina = nominaBuilder.build();

            // USO DEL BUILDER PARA COLILLA
            string periodo = leerString("  > Periodo: ");
            if (periodo.empty()) throw exception();
            string fecha = leerString("  > Fecha: ");
            if (fecha.empty()) throw exception();
            ColillaBuilder colillaBuilder;
            Colilla* colilla = colillaBuilder.setPeriodo(periodo)
                .setFecha(fecha)
                .setNomina(nomina)
                .setColaborador(colaboradorActual)
                .build();
            planillas->agregarColilla(colilla);

            imprimir("\nNomina y colilla creadas y asociadas correctamente.\n");
            enter();
            show();
        }
        else if (opcion == 2) {
            imprimir("\n--------------------------------------------------------------------");
            imprimir("                      LISTA DE NOMINAS                              ");
            imprimir("--------------------------------------------------------------------");
            Lista* colillas = planillas->obtenerColillasDeColaborador(colaboradorActual);
            if (!colillas) throw exception();
            if (colillas->size() > 0) {
                std::cout << std::left
                    << "| " << std::setw(5) << "#"
                    << "| " << std::setw(15) << "Periodo"
                    << "| " << std::setw(12) << "Fecha"
                    << "|\n";
                imprimir("--------------------------------------------------------------------");
                for (int i = 0; i < colillas->size(); ++i) {
                    Colilla* colilla = dynamic_cast<Colilla*>(colillas->get(i));
                    if (colilla) {
                        std::cout << "| " << std::setw(5) << (i + 1)
                            << "| " << std::setw(15) << colilla->getPeriodo()
                            << "| " << std::setw(12) << colilla->getFecha()
                            << "|\n";
                    }
                    else {
                        throw exception();
                    }
                }
                imprimir("--------------------------------------------------------------------");
            }
            else {
                imprimir("| No hay nominas asociadas.                                        |");
                imprimir("--------------------------------------------------------------------");
            }
            delete colillas;
            enter();
            show();
        }
        else if (opcion == 3) {
            imprimir("\n--------------------------------------------------------------------");
            imprimir("                   CALCULAR SALARIO NETO                            ");
            imprimir("--------------------------------------------------------------------");
            Lista* colillas = planillas->obtenerColillasDeColaborador(colaboradorActual);
            if (!colillas) throw exception();
            if (colillas->size() > 0) {
                Colilla* colilla = dynamic_cast<Colilla*>(colillas->get(colillas->size() - 1));
                if (colilla) {
                    float neto = colilla->getNomina()->calcularSalarioNeto(colaboradorActual->getSalarioBase());
                    std::cout << "| Salario neto de la ultima nomina: " << std::fixed << std::setprecision(2) << neto << std::endl;
                    imprimir("--------------------------------------------------------------------");
                }
                else {
                    throw exception();
                }
            }
            else {
                imprimir("| No hay nominas para calcular.                                    |");
                imprimir("--------------------------------------------------------------------");
            }
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