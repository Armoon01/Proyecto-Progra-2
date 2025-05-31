#include "MenuColaboradores.h"

MenuColaboradores::MenuColaboradores(Control* nuevoGestor){
	gestor = nuevoGestor;

	Consola::setTitulo("ADMINISTRACION DE Colaboradores");
	Consola::setInstrucciones("Por favor, leer con cuidado las siguinetes opciones.");

	agregarOpcion(new OpcionMenu("Crear Colaborador"));
	agregarOpcion(new OpcionMenu("Editar Colaborador"));
	agregarOpcion(new OpcionMenu("Listar Colaborador"));
	agregarOpcion(new OpcionMenu("Colaborador asociados"));
	agregarOpcion(new OpcionMenu("Regresar al menu"));
}

void MenuColaboradores::lanzar(int posicion){
	if (posicion == 1) {
		try {
			imprimir("Creando Colaborador");
			string cedula = leerString("Por favor, digitar cedula:");
			string nombre = leerString("Por favor, digitar Nombre:");
			float salario = leerDouble("Por favor, digitar Salario:");
			gestor->agregar(new Colaborador(cedula, nombre, salario ));
		}
		catch (exception ex) {
			imprimir(ex.what());
			enter();
		}
		show();
	}
	else if (posicion == 2) {
		imprimir("Editando Colaborador");
	}
	else if (posicion == 3) {
		imprimir("Listando");

	}
	else if (posicion == 4) {
		string cedula = leerString("Cedula de la Colaborador: ");
		Colaborador* encontrada = gestor->buscarColaborador(cedula);
	/*	gestor->mostrarMenuRenta(encontrada);*/

	}
	else if (posicion == 5) {
		gestor->mostrarMenuPrincipal();
	}
}
