#include "MenuReporte.h"
#include <exception>

MenuReporte::MenuReporte(Control* gestor, Planillas* planillas) {
    this->gestor = gestor;
    this->planillas = planillas;
    setTitulo("REPORTE DE COLILLAS");
    setInstrucciones("Seleccione una opci�n para exportar los reportes:");
    agregarOpcion("Generar reportes");
    agregarOpcion("Regresar al men� principal");
}

void MenuReporte::lanzar(int opcion) {
    try {
        switch (opcion) {
        case 1:
            Consola::imprimir("Generando reportes...");
            if (!gestor || !planillas) throw exception();
            if (!gestor->getColaboradores()) throw exception();
            SistemaNomina::getInstance(planillas)->agregarListaColaborador(gestor->getColaboradores());
            SistemaNomina::getInstance(planillas)->generarPlanilla();
            Consola::enter();
            show();
            break;
        case 2:
            if (!gestor) throw exception();
            gestor->mostrarMenuPrincipal();
            break;
        default:
            Consola::imprimir("Opci�n no v�lida.");
            Consola::enter();
            show();
        }
    }
    catch (const exception&) {
        Consola::imprimir("Ha ocurrido un error en la operaci�n.");
        Consola::enter();
        show();
    }
}