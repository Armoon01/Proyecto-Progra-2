#include "CCSS.h"
CCSS::CCSS(float sem, float ivm, float lpt)
    : porcentajeSEM(sem), porcentajeIVM(ivm), porcentajeLPT(lpt) {}

float CCSS::calcular(float salarioBase) const {
    return salarioBase * (porcentajeSEM + porcentajeIVM + porcentajeLPT);
}