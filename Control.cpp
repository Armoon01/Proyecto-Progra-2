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

void Control::mostrarMenuColaboradores(){
	menuColaboradores->show();
}

void Control::mostrarMenuPrincipal(){
	menuPrincipal->show();
}

