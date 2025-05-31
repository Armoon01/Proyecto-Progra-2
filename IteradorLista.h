#pragma once
#include "IIterador.h"
#include "Nodo.h"

class IteradorLista : public IIterador {
private:
	Nodo* actual;
public:
	IteradorLista(Nodo*);
	virtual bool hasMore() const;
	virtual ObjectAdaptador* next();
};

