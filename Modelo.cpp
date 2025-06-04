#include "Modelo.h"

Modelo* Modelo::_instancia = NULL;

Modelo::Modelo() {
	Colaboradores = new ConjuntoColaborador();
}

Modelo* Modelo::getInstancia() {
	if (_instancia == NULL) {
		_instancia = new Modelo();
	}
	return _instancia;
}

void Modelo::agregar(Colaborador* c) {
	Colaboradores->agregarColaborador(c);
}






Colaborador* Modelo::buscarColaborador(string cedula) {
	return Colaboradores->buscar(cedula);
}

void Modelo::eliminarColaborador(string cedula) {
	Colaboradores->remover(cedula);
}

string Modelo::listarColaboradores() {
	return Colaboradores->getListaPersonas()->toString();
}

Lista* Modelo::getColaboradores() const {
	return Colaboradores->getListaPersonas();
}
