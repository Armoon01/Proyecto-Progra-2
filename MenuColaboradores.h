#pragma once
#include "Consola.h"
#include "Control.h"

class Control;

class MenuColaboradores : public Consola {
private:
	Control* gestor;
public:
	MenuColaboradores(Control*);
	virtual void lanzar(int) override;
};

