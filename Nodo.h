#pragma once
#include <string>
#include "ObjectAdaptador.h"

class Nodo : public ObjectAdaptador {
private:
	Nodo* _siguiente;
	ObjectAdaptador* _dato;
public:
	Nodo(ObjectAdaptador*, Nodo* = NULL);
	virtual void setSiguiente(Nodo*);
	virtual void setDato(ObjectAdaptador*);
	virtual Nodo* getSiguiente() const;
	virtual ObjectAdaptador* getDato() const;
};

