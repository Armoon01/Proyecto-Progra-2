#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal(Control* _gestor) {
	gestor = _gestor;
	setTitulo("SISTEMA DE ADMINISTRACION DE COLABORADORES");
	setInstrucciones("Ver 2025.05.22");

	agregarOpcion("Ingrear al menu de colaboradores");
	agregarOpcion("Ir al menu de reportes");
	agregarOpcion("Salir del sistema");
}

void MenuPrincipal::lanzar(int pos) {
	if (pos == 1) {
		gestor->mostrarMenuColaboradores();
	}
    else if (pos == 2) {
        gestor->mostrarMenuReporte();
    }
    else if (pos == 3) {
        Consola::imprimir("Saliendo del sistema...");
        exit(0);
    }
    else {
        Consola::imprimir("Opción no válida.");
        Consola::enter();
        show();
    }
}

