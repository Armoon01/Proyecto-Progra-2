#pragma once
#include "ObjectAdaptador.h"

class IIterador {
public:
	virtual bool hasMore() const = 0;
	virtual ObjectAdaptador* next() = 0;
};

