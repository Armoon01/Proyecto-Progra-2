#pragma once
#include "ObjectAdaptador.h"
#include "Lista.h"
#include "OpcionMenu.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;



class Consola : public ObjectAdaptador {

private:
	Lista* listaOpciones;
	string titulo;
	string instrucciones;
public:
	Consola();
	virtual void setTitulo(string);
	virtual void setInstrucciones(string);
	virtual void agregarOpcion(OpcionMenu*);
	virtual void agregarOpcion(string);
	virtual void show();
	virtual void lanzar(int) = 0;

	static void imprimir(string mensaje, bool = true);
	static void enter();
	static void limpiar();



	static int leerEntero(string mensaje);
	static int leerEntero(string mensaje, int, int);
	static double leerDouble(string mensaje);
	static string leerString(string mensaje);
};

