#pragma once
#include "Consola.h"
#include "Control.h"


class Control;

class MenuPrincipal : public Consola {
private:
	Control* gestor;
public:
	MenuPrincipal(Control*);
	virtual void lanzar(int) override;

};

