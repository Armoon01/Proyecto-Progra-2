#pragma once
#include "IIterador.h"
#include "ObjectAdaptador.h"

class IColeccion {
public:
	virtual void agregar(ObjectAdaptador*) = 0;
	virtual void remover(ObjectAdaptador*) = 0;
	virtual bool removerInicio() = 0;
	virtual void clear() = 0; // limpia todo
	virtual int size() const = 0;
	virtual ObjectAdaptador* get(int) const = 0;
};

