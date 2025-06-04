#include "CCSS.h"
CCSS::CCSS(float sem, float ivm, float lpt)
    : porcentajeSEM(sem/100.0), porcentajeIVM(ivm/100.0), porcentajeLPT(lpt/100.0) {}

float CCSS::calcular(float salarioBase) const {
    return salarioBase * (porcentajeSEM + porcentajeIVM + porcentajeLPT);
}