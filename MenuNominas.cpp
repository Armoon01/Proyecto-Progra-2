#include "MenuNominas.h"
#include "IngresoBuilder.h"
#include "IngresoFactory.h"
#include "DeduccionBuilder.h"
#include "DeduccionFactory.h"
#include <iostream>
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
    if (!colaboradorActual) {
        imprimir("No hay colaborador seleccionado.");
        return;
    }
    if (opcion == 1) {
        Nomina* nomina = new Nomina();

        // Agregar ingresos (mezcla de Builder y Factory)
        int cantIngresos = leerEntero("¿Cuántos ingresos desea agregar?");
        for (int i = 0; i < cantIngresos; ++i) {
            imprimir("Tipos de ingreso:\n1. Fijo\n2. Porcentaje\n3. Horas Extra");
            int tipo = leerEntero("Seleccione el tipo de ingreso: ");
            Ingreso* ingreso = nullptr;

            if (tipo == 1) { // Fijo - Builder
                float monto = leerDouble("Monto fijo: ");
                ingreso = IngresoBuilder().Tipo("Fijo").Valor(monto).Build();
            }
            else if (tipo == 2) { // Porcentaje - Builder
                float porcentaje = leerDouble("Porcentaje: ");
                ingreso = IngresoBuilder().Tipo("Porcentual").Valor(porcentaje).Build();
            }
            else if (tipo == 3) { // Horas Extra - Factory
                imprimir("Tipos de horas extra:\n1. Diurna\n2. Mixta\n3. Nocturna\n4. Feriado");
                int tipoHE = leerEntero("Seleccione el tipo de hora extra: ");
                double horas = leerDouble("Cantidad de horas: ");
                switch (tipoHE) {
                case 1: ingreso = IngresoFactory::crearHorasExtraDiurna(horas); break;
                case 2: ingreso = IngresoFactory::crearHorasExtraMixta(horas); break;
                case 3: ingreso = IngresoFactory::crearHorasExtraNocturna(horas); break;
                case 4: ingreso = IngresoFactory::crearHorasExtraFeriado(horas); break;
                default: ingreso = IngresoFactory::crearHorasExtraDiurna(horas);
                }
            }
            if (ingreso) {
                nomina->getIngresos()->agregar(ingreso);
            }
        }

        // Agregar deducciones (principalmente Factory)
        int cantDeducciones = leerEntero("¿Cuántas deducciones desea agregar?");
        for (int i = 0; i < cantDeducciones; ++i) {
            imprimir("Tipos de deducción:\n1. CCSS\n2. Renta\n3. Embargos\n4. Maternidad\n5. Fija\n6. Porcentaje");
            int tipo = leerEntero("Seleccione el tipo de deducción: ");
            Deduccion* deduccion = nullptr;

            if (tipo == 1) { // CCSS - Factory
                float sem = leerDouble("Porcentaje SEM: ");
                float ivm = leerDouble("Porcentaje IVM: ");
                float lpt = leerDouble("Porcentaje LPT: ");
                deduccion = DeduccionFactory::crearCCSS(sem, ivm, lpt);
            }
            else if (tipo == 2) { // Renta - Factory
                deduccion = DeduccionFactory::crearRenta();
            }
            else if (tipo == 3) { // Embargos - Builder (ejemplo de flexibilidad futura)
                float porcentaje = leerDouble("Monto de embargos: ");
                deduccion = DeduccionBuilder().Tipo("Embargos").Monto(porcentaje).Build();
            }
            else if (tipo == 4) { // Maternidad - Builder (ejemplo de flexibilidad futura)
                float monto = leerDouble("Monto de maternidad: ");
                deduccion = DeduccionBuilder().Tipo("Maternidad").Monto(monto).Build();
            }
            else if (tipo == 5) { // Fija - Factory
                float monto = leerDouble("Monto fijo: ");
                deduccion = DeduccionFactory::crearFija(monto);
            }
            else if (tipo == 6) { // Porcentaje - Factory
                float porcentaje = leerDouble("Porcentaje: ");
                deduccion = DeduccionFactory::crearPorcentaje(porcentaje);
            }
            if (deduccion) {
                nomina->getDeducciones()->agregar(deduccion);
            }
        }

        // Crear colilla y asociarla a Planillas
        string periodo = leerString("Periodo: ");
        string fecha = leerString("Fecha: ");
        Colilla* colilla = new Colilla(periodo, fecha, nomina, colaboradorActual);
        planillas->agregarColilla(colilla);

        imprimir("Nómina y colilla creadas y asociadas.");
        enter();
        show();
    }
    else if (opcion == 2) {
        Lista* colillas = planillas->obtenerColillasDeColaborador(colaboradorActual);
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
        delete colillas;
        enter();
        show();
    }
    else if (opcion == 3) {
        Lista* colillas = planillas->obtenerColillasDeColaborador(colaboradorActual);
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
        delete colillas;
        enter();
        show();
    }
    else if (opcion == 4) {
        gestor->mostrarMenuColaboradores();
    }
}