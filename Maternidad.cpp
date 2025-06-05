#include "Maternidad.h"
#include <sstream>
#include <iomanip>
Maternidad::Maternidad(float montoFijo)
    : DeduccionFija(montoFijo) {}

string Maternidad::toString() const {
    stringstream ss;
	ss << fixed << setprecision(2);
	ss << "Maternidad: " << monto;
	return ss.str();
}