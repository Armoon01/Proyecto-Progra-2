#pragma once
#include "IIterador.h"
class IEnumerable {
public:
	virtual IIterador* getIterador() const = 0;
};

