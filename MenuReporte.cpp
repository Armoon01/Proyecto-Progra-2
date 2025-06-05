#include "MenuReporte.h"    

MenuReporte::MenuReporte(Control* gestor, Planillas* planillas) {
    this->gestor = gestor;
    this->planillas = planillas;
    setTitulo("REPORTE DE COLILLAS");
    setInstrucciones("Seleccione una opci�n para exportar los reportes:");
    agregarOpcion("Generar reportes");
    agregarOpcion("Regresar al men� principal");
}

void MenuReporte::lanzar(int opcion) {
    switch (opcion) {
    case 1:
        Consola::imprimir("Generando reportes...");
        SistemaNomina::getInstance(planillas)->agregarListaColaborador(gestor->getColaboradores());
        SistemaNomina::getInstance(planillas)->generarPlanilla();
        Consola::enter();
        show();
        break;
    case 2:
        gestor->mostrarMenuPrincipal();
        break;
    default:
        Consola::imprimir("Opci�n no v�lida.");
        Consola::enter();
        show();
    }
}