#include "Control.h"

Control::Control(Planillas* planillas) {
	datos = Modelo::getInstancia();
	this->planillas = planillas;
	menuColaboradores = new MenuColaboradores(this, planillas);
	menuPrincipal = new MenuPrincipal(this);
	menuColillas = nullptr;
	menuNominas = nullptr;
	menuReporte = nullptr;
}

void Control::agregar(Colaborador* c) {
	datos->agregar(c);
}

Colaborador* Control::buscarColaborador(string cedula) {
	return datos->buscarColaborador(cedula);
}

void Control::eliminarColaborador(string cedula) {
	datos->eliminarColaborador(cedula);
}

string Control::listarColaboradores() {
	return datos->listarColaboradores();
}

void Control::mostrarMenuColaboradores() {
	menuColaboradores->show();
}

void Control::mostrarMenuPrincipal() {
	menuPrincipal->show();
}

void Control::mostrarMenuColillas(Colaborador* colaborador, Planillas* planillas) {
	if (!menuColillas) {
		menuColillas = new MenuColillas(this, colaborador, planillas);
	}
	else {
		menuColillas->setColaborador(colaborador);
	}
	menuColillas->show();
}

void Control::mostrarMenuNominas(Colaborador* colaborador, Planillas* planillas) {
	if (!menuNominas) {
		menuNominas = new MenuNominas(this, colaborador, planillas);
	}
	else {
		menuNominas->setColaborador(colaborador);
	}
	menuNominas->show();
}

void Control::mostrarMenuReporte() {
	if (!menuReporte) {
		menuReporte = new MenuReporte(this, planillas);
	}
	menuReporte->show();
}

Lista* Control::getColaboradores() {
	return datos->getColaboradores();
}