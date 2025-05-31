#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal(Control* _gestor) {
	gestor = _gestor;
	setTitulo("SISTEMA DE ADMINISTRACION DE COLABORADORES");
	setInstrucciones("Ver 2025.05.22");

	agregarOpcion("Ingrear al menu de colaboradores");
	agregarOpcion("Salir del sistema");
}

void MenuPrincipal::lanzar(int pos) {
	if (pos == 1) {
		gestor->mostrarMenuColaboradores();
	}
}

