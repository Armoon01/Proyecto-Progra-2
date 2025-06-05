#pragma once
#include "Consola.h"
#include "Control.h"
#include "Planillas.h"

class Control;

class MenuColaboradores : public Consola {
private:
	Control* gestor;
	Planillas* planillas;
public:
	MenuColaboradores(Control* ,Planillas*);
	virtual void lanzar(int) override;
};

