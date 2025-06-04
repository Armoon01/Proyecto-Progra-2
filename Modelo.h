#pragma once
#include "ConjuntoColaborador.h"


class Modelo{
private:
	ConjuntoColaborador* Colaboradores;
	static Modelo* _instancia;
	Modelo();

public:
	static Modelo* getInstancia();
	virtual void agregar(Colaborador*);
	virtual Colaborador* buscarColaborador(string);
	virtual void eliminarColaborador(string);
	virtual string listarColaboradores();
	Lista* getColaboradores() const;
}; 




