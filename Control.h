#pragma once
#include "Modelo.h"
#include "MenuColaboradores.h"
#include "MenuPrincipal.h"
#include "MenuColillas.h"
#include "MenuNominas.h"
#include "MenuReporte.h"
#include "Planillas.h"

class MenuColaboradores;
class MenuPrincipal;
class MenuColillas;
class MenuNominas;
class MenuReporte;

class Control {
private:
	Modelo* datos;
	Planillas* planillas;
	MenuColaboradores* menuColaboradores;
	MenuPrincipal* menuPrincipal;
	MenuColillas* menuColillas;
	MenuNominas* menuNominas;
	MenuReporte* menuReporte;
public:
	Control(Planillas* planillas);
	virtual void agregar(Colaborador*);
	virtual Colaborador* buscarColaborador(string);
	virtual void eliminarColaborador(string);
	virtual string listarColaboradores();
	virtual void mostrarMenuColaboradores();
	virtual void mostrarMenuPrincipal();
	void mostrarMenuColillas(Colaborador* colaborador, Planillas* planillas);
	void mostrarMenuNominas(Colaborador* colaborador, Planillas* planillas);
	virtual void mostrarMenuReporte();
	Lista* getColaboradores();
};