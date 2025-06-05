#include "MenuColaboradores.h"

MenuColaboradores::MenuColaboradores(Control* nuevoGestor, Planillas* planillas) {
	gestor = nuevoGestor;
	this->planillas = planillas;

	Consola::setTitulo("ADMINISTRACION DE Colaboradores");
	Consola::setInstrucciones("Por favor, leer con cuidado las siguientes opciones.");

	agregarOpcion(new OpcionMenu("Crear Colaborador"));
	agregarOpcion(new OpcionMenu("Editar Colaborador"));
	agregarOpcion(new OpcionMenu("Listar Colaboradores"));
	agregarOpcion(new OpcionMenu("Colillas del Colaborador"));
	agregarOpcion(new OpcionMenu("Colillas asociadas"));
	agregarOpcion(new OpcionMenu("Agregar Nominas"));
	agregarOpcion(new OpcionMenu("Regresar al menu"));
}

void MenuColaboradores::lanzar(int posicion) {
	if (posicion == 1) {
		try {
			imprimir("Creando Colaborador");
			string cedula = leerString("Por favor, digitar cedula:");
			string nombre = leerString("Por favor, digitar Nombre:");
			float salario = leerDouble("Por favor, digitar Salario:");
			gestor->agregar(new Colaborador(nombre, cedula, salario));
			imprimir("Colaborador creado correctamente.");
			enter();
		}
		catch (exception& ex) {
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
		string cedula = leerString("Cedula del Colaborador: ");
		Colaborador* encontrada = gestor->buscarColaborador(cedula);
		if (encontrada != NULL) {
			imprimir("Colaborador encontrado: " + encontrada->toString());
			// Obtener colillas desde la instancia de Planillas, no desde el colaborador
			Lista* colillas = planillas->obtenerColillasDeColaborador(encontrada);
			if (colillas->size() > 0) {
				imprimir("Colillas asociadas:");
				imprimir(colillas->toString());
				enter();
			}
			else {
				imprimir("No hay colillas asociadas a este colaborador.");
				enter();
			}
			delete colillas;
		}
		else {
			imprimir("Colaborador no encontrado.");
			enter();
		}
		show();
	}
	else if (posicion == 5) {
		string cedula = leerString("Cedula del Colaborador: ");
		Colaborador* encontrada = gestor->buscarColaborador(cedula);
		if (encontrada != NULL) {
			// Ahora pasar también la instancia de planillas
			gestor->mostrarMenuColillas(encontrada, planillas);
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
			// Ahora pasar también la instancia de planillas
			gestor->mostrarMenuNominas(encontrada, planillas);
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