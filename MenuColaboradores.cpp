#include "MenuColaboradores.h"

MenuColaboradores::MenuColaboradores(Control* nuevoGestor){
	gestor = nuevoGestor;

	Consola::setTitulo("ADMINISTRACION DE Colaboradores");
	Consola::setInstrucciones("Por favor, leer con cuidado las siguinetes opciones.");

	agregarOpcion(new OpcionMenu("Crear Colaborador"));
	agregarOpcion(new OpcionMenu("Editar Colaborador"));
	agregarOpcion(new OpcionMenu("Listar Colaborador"));
	agregarOpcion(new OpcionMenu("Agregar Colilla"));
	agregarOpcion(new OpcionMenu("Colaborador asociados"));
	agregarOpcion(new OpcionMenu("Agregar Nominas"));
	agregarOpcion(new OpcionMenu("Regresar al menu"));
}

void MenuColaboradores::lanzar(int posicion){
	if (posicion == 1) {
		try {
			imprimir("Creando Colaborador");
			string cedula = leerString("Por favor, digitar cedula:");
			string nombre = leerString("Por favor, digitar Nombre:");
			float salario = leerDouble("Por favor, digitar Salario:");
			gestor->agregar(new Colaborador(nombre, cedula, salario ));
			imprimir("Colaborador creado correctamente.");
			enter();
		}
		catch (exception ex) {
			imprimir(ex.what());
			enter();
		}
		show();
	}
	else if (posicion == 2) {
		imprimir("Editando Colaborador");
		string cedula = leerString("Cedula del Colaborador a editar: ");
		Colaborador* encontrada = gestor->buscarColaborador(cedula);
		if (encontrada != NULL) {
			string nombre = leerString("Nuevo Nombre: ");
			float salario = leerDouble("Nuevo Salario: ");
			encontrada->setNombre(nombre);
			encontrada->setSalarioBase(salario);
			imprimir("Colaborador editado correctamente.");
			enter();
		}
		else {
			imprimir("Colaborador no encontrado.");
		}
		show();
	}
	else if (posicion == 3) {
		imprimir("Listando");
		imprimir("Colaboradores registrados:");
		imprimir(gestor->listarColaboradores());
		enter();
		show();
	}
	else if (posicion == 4) {
		string cedula = leerString("Cedula de la Colaborador: ");
		Colaborador* encontrada = gestor->buscarColaborador(cedula);
		if (encontrada != NULL) {
			imprimir("Colaborador encontrado: " + encontrada->toString());
			Lista* colillas = encontrada->getColillas();
			if (colillas->size() > 0) {
				imprimir("Colillas asociadas:");
				imprimir(colillas->toString());
				enter();
			} else {
				imprimir("No hay colillas asociadas a este colaborador.");
				enter();
			}
		} else {
			imprimir("Colaborador no encontrado.");
			enter();
		}
		show();
	}
	else if (posicion == 5) {
		string cedula = leerString("Cedula del Colaborador: ");
		Colaborador* encontrada = gestor->buscarColaborador(cedula);
		if (encontrada != NULL) {
			gestor->mostrarMenuColillas(encontrada);
		}
		else {
			imprimir("Colaborador no encontrado.");
			enter();
			show();
		}
	}
	else if (posicion == 6) { 
		string cedula = leerString("Cedula del Colaborador: ");
		Colaborador* encontrada = gestor->buscarColaborador(cedula);
		if (encontrada != NULL) {
			gestor->mostrarMenuNominas(encontrada);
		}
		else {
			imprimir("Colaborador no encontrado.");
			enter();
			show();
		}
	}
	else if (posicion == 7) {
		gestor->mostrarMenuPrincipal();

	}
}
