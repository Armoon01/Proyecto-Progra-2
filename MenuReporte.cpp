#include "MenuReporte.h"    

MenuReporte::MenuReporte(Control* gestor) {
    this->gestor = gestor;
    setTitulo("REPORTE DE COLILLAS");
    setInstrucciones("Seleccione una opción para exportar los reportes:");
    agregarOpcion("Generar reportes");
    agregarOpcion("Regresar al menú principal");
}


void MenuReporte::lanzar(int opcion) {
    switch (opcion) {
    case 1:
        Consola::imprimir("Generando reportes...");
		SistemaNomina::getInstance()->agregarListaColaborador(gestor->getColaboradores());
		SistemaNomina::getInstance()->generarPlanilla();
        Consola::enter();
        show();
        break;
    case 2:
        gestor->mostrarMenuPrincipal();
        break;
    default:
        Consola::imprimir("Opción no válida.");
        Consola::enter();
        show();
    }
}