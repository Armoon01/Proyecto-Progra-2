#include "Control.h"

Control::Control(){
	datos = Modelo::getInstancia();
	menuColaboradores = new MenuColaboradores(this);
	menuPrincipal = new MenuPrincipal(this);
}

void Control::agregar(Colaborador* c){
	datos->agregar(c);
}

Colaborador* Control::buscarColaborador(string cedula){

	return datos->buscarColaborador(cedula);
}

void Control::eliminarColaborador(string cedula){
	datos->eliminarColaborador(cedula);
}

string Control::listarColaboradores(){
	return datos->listarColaboradores();
}

void Control::mostrarMenuColaboradores(){
	menuColaboradores->show();
}

void Control::mostrarMenuPrincipal(){
	menuPrincipal->show();
}

void Control::mostrarMenuColillas(Colaborador* colaborador) {
	if (!menuColillas) {
		menuColillas = new MenuColillas(this, colaborador);
	}
	else {
		menuColillas->setColaborador(colaborador);
	}
	menuColillas->show();
}

void Control::mostrarMenuNominas(Colaborador* colaborador) {
	if (!menuNominas) {
		menuNominas = new MenuNominas(this, colaborador);
	}
	else {
		menuNominas->setColaborador(colaborador);
	}
	menuNominas->show();
}

void Control::mostrarMenuReporte() {
	menuReporte = new MenuReporte(this);
	menuReporte->show();
}

Lista* Control::getColaboradores() {
	return datos->getColaboradores();
}