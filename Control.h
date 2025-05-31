#pragma once
#include "Modelo.h"
#include "MenuColaboradores.h"
#include "MenuPrincipal.h"




class MenuColaboradores;
class MenuPrincipal;

 class Control{
 private:
	 Modelo* datos;
	 MenuColaboradores* menuColaboradores;
	 MenuPrincipal* menuPrincipal;
 public:
	 Control();
	 virtual void agregar(Colaborador*);
	 virtual Colaborador* buscarColaborador(string);
	 virtual void mostrarMenuColaboradores();
	 virtual void mostrarMenuPrincipal();

};

