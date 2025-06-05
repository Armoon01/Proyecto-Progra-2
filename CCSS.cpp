#include "CCSS.h"
CCSS::CCSS(float sem, float ivm, float lpt)
    : porcentajeSEM(sem/100.0), porcentajeIVM(ivm/100.0), porcentajeLPT(lpt/100.0) {}

float CCSS::calcular(float salarioBase) const {
    return salarioBase * (porcentajeSEM + porcentajeIVM + porcentajeLPT);
}

string CCSS::toString() const {
	return "CCSS: SEM=" + to_string(porcentajeSEM * 100) + "%, IVM=" + to_string(porcentajeIVM * 100) + "%, LPT=" + to_string(porcentajeLPT * 100) + "%";
}