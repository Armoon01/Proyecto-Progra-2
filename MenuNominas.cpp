#include "MenuNominas.h"
#include "IngresoBuilder.h"
#include "IngresoFactory.h"
#include "DeduccionBuilder.h"
#include "DeduccionFactory.h"
#include <iostream>
using namespace std;

MenuNominas::MenuNominas(Control* gestor, Colaborador* colaborador)
    : Consola(), gestor(gestor), colaboradorActual(colaborador) {
    agregarOpcion("Crear nómina");
    agregarOpcion("Listar nóminas");
    agregarOpcion("Calcular salario neto");
    agregarOpcion("Volver");
}

void MenuNominas::setColaborador(Colaborador* colaborador) {
    colaboradorActual = colaborador;
}

void MenuNominas::lanzar(int opcion) {
    if (!colaboradorActual) {
        imprimir("No hay colaborador seleccionado.");
        return;
    }
    if (opcion == 1) {
        Nomina* nomina = new Nomina();

        // Agregar ingresos
        int cantIngresos = leerEntero("¿Cuántos ingresos desea agregar?");
        for (int i = 0; i < cantIngresos; ++i) {
            imprimir("Tipos de ingreso:\n1. Fijo\n2. Porcentaje\n3. Horas Extra");
            int tipo = leerEntero("Seleccione el tipo de ingreso: ");
            Ingreso* ingreso = nullptr;
            if (tipo == 1) {
                float monto = leerDouble("Monto fijo: ");
                ingreso = IngresoBuilder::crearFijo(monto);
            }
            else if (tipo == 2) {
                float porcentaje = leerDouble("Porcentaje: ");
                ingreso = IngresoBuilder::crearPorcentaje(porcentaje);
            }
            else if (tipo == 3) {
                imprimir("Tipos de horas extra:\n1. Diurna\n2. Mixta\n3. Nocturna\n4. Feriado");
                int tipoHE = leerEntero("Seleccione el tipo de hora extra: ");
                string tipoHEstr;
                switch (tipoHE) {
                case 1: tipoHEstr = "Diurna"; break;
                case 2: tipoHEstr = "Mixta"; break;
                case 3: tipoHEstr = "Nocturna"; break;
                case 4: tipoHEstr = "Feriado"; break;
                default: tipoHEstr = "Diurna";
                }
                ingreso = IngresoBuilder::crearHorasExtra(tipoHEstr);
            }
            if (ingreso) {
                nomina->getIngresos()->agregar(ingreso);
            }
        }

        // Agregar deducciones
        int cantDeducciones = leerEntero("¿Cuántas deducciones desea agregar?");
        for (int i = 0; i < cantDeducciones; ++i) {
            imprimir("Tipos de deducción:\n1. CCSS\n2. Renta\n3. Embargos\n4. Maternidad\n5. Fija\n6. Porcentaje");
            int tipo = leerEntero("Seleccione el tipo de deducción: ");
            Deduccion* deduccion = nullptr;
            if (tipo == 1) {
                float sem = leerDouble("Porcentaje SEM: ");
                float ivm = leerDouble("Porcentaje IVM: ");
                float lpt = leerDouble("Porcentaje LPT: ");
                deduccion = DeduccionBuilder::crearCCSS(sem, ivm, lpt);
            }
            else if (tipo == 2) {
                float porcentaje = leerDouble("Porcentaje de renta: ");
                deduccion = DeduccionBuilder::crearRenta(porcentaje);
            }
            else if (tipo == 3) {
                float porcentaje = leerDouble("Porcentaje de embargos: ");
                deduccion = DeduccionBuilder::crearEmbargos(porcentaje);
            }
            else if (tipo == 4) {
                float porcentaje = leerDouble("Porcentaje de maternidad: ");
                deduccion = DeduccionBuilder::crearMaternidad(porcentaje);
            }
            else if (tipo == 5) {
                float monto = leerDouble("Monto fijo: ");
                deduccion = DeduccionBuilder::crearFija(monto);
            }
            else if (tipo == 6) {
                float porcentaje = leerDouble("Porcentaje: ");
                deduccion = DeduccionBuilder::crearPorcentaje(porcentaje);
            }
            if (deduccion) {
                nomina->getDeducciones()->agregar(deduccion);
            }
        }

        // Crear colilla y asociar la nómina
        string periodo = leerString("Periodo: ");
        string fecha = leerString("Fecha: ");
        Colilla* colilla = new Colilla(periodo, fecha, nomina);
        colaboradorActual->agregarColilla(colilla);

        imprimir("Nómina y colilla creadas y asociadas.");
        enter();
        show();
    }
    else if (opcion == 2) {
        // Listar nóminas (en este diseño, nóminas están en las colillas)
        Lista* colillas = colaboradorActual->getColillas();
        if (colillas->size() > 0) {
            for (int i = 0; i < colillas->size(); ++i) {
                Colilla* colilla = dynamic_cast<Colilla*>(colillas->get(i));
                if (colilla) {
                    imprimir("Colilla " + to_string(i + 1) + ": " + colilla->getPeriodo() + " - " + colilla->getFecha());
                }
            }
        }
        else {
            imprimir("No hay nóminas asociadas.");
        }
        enter();
        show();
    }
    else if (opcion == 3) {
        // Calcular salario neto de la última nómina
        Lista* colillas = colaboradorActual->getColillas();
        if (colillas->size() > 0) {
            Colilla* colilla = dynamic_cast<Colilla*>(colillas->get(colillas->size() - 1));
            if (colilla) {
                float neto = colilla->getNomina()->calcularSalarioNeto(colaboradorActual->getSalarioBase());
                imprimir("Salario neto de la última nómina: " + to_string(neto));
            }
        }
        else {
            imprimir("No hay nóminas para calcular.");
        }
        enter();
        show();
    }
    else if (opcion == 4) {
        gestor->mostrarMenuColaboradores();
    }
}