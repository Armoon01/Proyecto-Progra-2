#include "MenuNominas.h"
#include "IngresoBuilder.h"
#include "IngresoFactory.h"
#include "DeduccionBuilder.h"
#include "DeduccionFactory.h"
#include <iostream>
#include <exception>
using namespace std;

MenuNominas::MenuNominas(Control* gestor, Colaborador* colaborador, Planillas* planillas)
    : Consola(), gestor(gestor), colaboradorActual(colaborador), planillas(planillas) {
    agregarOpcion("Crear nómina");
    agregarOpcion("Listar nóminas");
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
            Nomina* nomina = new Nomina();

            // Agregar ingresos (mezcla de Builder y Factory)
            int cantIngresos = leerEntero("¿Cuántos ingresos desea agregar?");
            if (cantIngresos < 0) throw exception();
            for (int i = 0; i < cantIngresos; ++i) {
                imprimir("Tipos de ingreso:\n1. Fijo\n2. Porcentaje\n3. Horas Extra");
                int tipo = leerEntero("Seleccione el tipo de ingreso: ");
                if (tipo < 1 || tipo > 3) throw exception();
                Ingreso* ingreso = nullptr;

                if (tipo == 1) { // Fijo - Builder
                    float monto = leerDouble("Monto fijo: ");
                    if (monto < 0) throw exception();
                    ingreso = IngresoBuilder().Tipo("Fijo").Valor(monto).Build();
                }
                else if (tipo == 2) { // Porcentaje - Builder
                    float porcentaje = leerDouble("Porcentaje: ");
                    if (porcentaje < 0) throw exception();
                    ingreso = IngresoBuilder().Tipo("Porcentual").Valor(porcentaje).Build();
                }
                else if (tipo == 3) { // Horas Extra - Factory
                    imprimir("Tipos de horas extra:\n1. Diurna\n2. Mixta\n3. Nocturna\n4. Feriado");
                    int tipoHE = leerEntero("Seleccione el tipo de hora extra: ");
                    if (tipoHE < 1 || tipoHE > 4) throw exception();
                    double horas = leerDouble("Cantidad de horas: ");
                    if (horas < 0) throw exception();
                    switch (tipoHE) {
                    case 1: ingreso = IngresoFactory::crearHorasExtraDiurna(horas); break;
                    case 2: ingreso = IngresoFactory::crearHorasExtraMixta(horas); break;
                    case 3: ingreso = IngresoFactory::crearHorasExtraNocturna(horas); break;
                    case 4: ingreso = IngresoFactory::crearHorasExtraFeriado(horas); break;
                    }
                }
                if (ingreso) {
                    nomina->getIngresos()->agregar(ingreso);
                }
                else {
                    throw exception();
                }
            }

            // Agregar deducciones (principalmente Factory)
            int cantDeducciones = leerEntero("¿Cuántas deducciones desea agregar?");
            if (cantDeducciones < 0) throw exception();
            for (int i = 0; i < cantDeducciones; ++i) {
                imprimir("Tipos de deducción:\n1. CCSS\n2. Renta\n3. Embargos\n4. Maternidad\n5. Fija\n6. Porcentaje");
                int tipo = leerEntero("Seleccione el tipo de deducción: ");
                if (tipo < 1 || tipo > 6) throw exception();
                Deduccion* deduccion = nullptr;

                if (tipo == 1) { // CCSS - Factory
                    float sem = leerDouble("Porcentaje SEM: ");
                    float ivm = leerDouble("Porcentaje IVM: ");
                    float lpt = leerDouble("Porcentaje LPT: ");
                    if (sem < 0 || ivm < 0 || lpt < 0) throw exception();
                    deduccion = DeduccionFactory::crearCCSS(sem, ivm, lpt);
                }
                else if (tipo == 2) { // Renta - Factory
                    deduccion = DeduccionFactory::crearRenta();
                }
                else if (tipo == 3) { // Embargos - Builder
                    float porcentaje = leerDouble("Monto de embargos: ");
                    if (porcentaje < 0) throw exception();
                    deduccion = DeduccionBuilder().Tipo("Embargos").Monto(porcentaje).Build();
                }
                else if (tipo == 4) { // Maternidad - Builder
                    float monto = leerDouble("Monto de maternidad: ");
                    if (monto < 0) throw exception();
                    deduccion = DeduccionBuilder().Tipo("Maternidad").Monto(monto).Build();
                }
                else if (tipo == 5) { // Fija - Factory
                    float monto = leerDouble("Monto fijo: ");
                    if (monto < 0) throw exception();
                    deduccion = DeduccionFactory::crearFija(monto);
                }
                else if (tipo == 6) { // Porcentaje - Factory
                    float porcentaje = leerDouble("Porcentaje: ");
                    if (porcentaje < 0) throw exception();
                    deduccion = DeduccionFactory::crearPorcentaje(porcentaje);
                }
                if (deduccion) {
                    nomina->getDeducciones()->agregar(deduccion);
                }
                else {
                    throw exception();
                }
            }

            // Crear colilla y asociarla a Planillas
            string periodo = leerString("Periodo: ");
            if (periodo.empty()) throw exception();
            string fecha = leerString("Fecha: ");
            if (fecha.empty()) throw exception();
            Colilla* colilla = new Colilla(periodo, fecha, nomina, colaboradorActual);
            planillas->agregarColilla(colilla);

            imprimir("Nómina y colilla creadas y asociadas.");
            enter();
            show();
        }
        else if (opcion == 2) {
            Lista* colillas = planillas->obtenerColillasDeColaborador(colaboradorActual);
            if (!colillas) throw exception();
            if (colillas->size() > 0) {
                for (int i = 0; i < colillas->size(); ++i) {
                    Colilla* colilla = dynamic_cast<Colilla*>(colillas->get(i));
                    if (colilla) {
                        imprimir("Colilla " + to_string(i + 1) + ": " + colilla->getPeriodo() + " - " + colilla->getFecha());
                    }
                    else {
                        throw exception();
                    }
                }
            }
            else {
                imprimir("No hay nóminas asociadas.");
            }
            delete colillas;
            enter();
            show();
        }
        else if (opcion == 3) {
            Lista* colillas = planillas->obtenerColillasDeColaborador(colaboradorActual);
            if (!colillas) throw exception();
            if (colillas->size() > 0) {
                Colilla* colilla = dynamic_cast<Colilla*>(colillas->get(colillas->size() - 1));
                if (colilla) {
                    float neto = colilla->getNomina()->calcularSalarioNeto(colaboradorActual->getSalarioBase());
                    imprimir("Salario neto de la última nómina: " + to_string(neto));
                }
                else {
                    throw exception();
                }
            }
            else {
                imprimir("No hay nóminas para calcular.");
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
        imprimir("Ha ocurrido un error en la operación.");
        enter();
        show();
    }
}