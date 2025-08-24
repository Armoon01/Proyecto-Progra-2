#pragma once
#include "ObjectAdaptador.h"
class OpcionMenu : public ObjectAdaptador{
private:
	string titulo;
public:
	OpcionMenu(string);
	virtual string toString() const override;
};

