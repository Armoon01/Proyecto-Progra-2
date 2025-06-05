#include "Embargos.h"
#include <sstream>
Embargos::Embargos(float montoFijo)
    : DeduccionFija(montoFijo) {}

string Embargos::toString() const {
    stringstream ss;
	ss << fixed << setprecision(2);
	ss << "Embargo: " << monto;
	return ss.str();
}