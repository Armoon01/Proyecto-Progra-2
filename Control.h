#pragma once
#include "Modelo.h"
#include "MenuColaboradores.h"
#include "MenuPrincipal.h"
#include "MenuColillas.h"
#include "MenuNominas.h"
#include "MenuReporte.h"

class MenuColaboradores;
class MenuPrincipal;
class MenuColillas;
class MenuNominas;
class MenuReporte;

 class Control{
 private:
	 Modelo* datos;
	 MenuColaboradores* menuColaboradores;
	 MenuPrincipal* menuPrincipal;
	 MenuColillas* menuColillas;
	 MenuNominas* menuNominas;
	 MenuReporte* menuReporte;
 public:
	 Control();
	 virtual void agregar(Colaborador*);
	 virtual Colaborador* buscarColaborador(string);
	 virtual void eliminarColaborador(string);
	 virtual string listarColaboradores();
	 virtual void mostrarMenuColaboradores();
	 virtual void mostrarMenuPrincipal();
	 void mostrarMenuColillas(Colaborador* colaborador);
	 void mostrarMenuNominas(Colaborador* colaborador);
	 virtual void mostrarMenuReporte();
	 Lista* getColaboradores();
};