#include "DeduccionBuilder.h"
#include "CCSS.h"
#include "Renta.h"
#include "Embargos.h"
#include "Maternidad.h"
#include "DeduccionFija.h"
#include "DeduccionPorcentaje.h"

DeduccionBuilder& DeduccionBuilder::Tipo(const std::string& t) {
    tipo = t;
    return *this;
}
DeduccionBuilder& DeduccionBuilder::PorcentajeSEM(float p) {
    porcentajeSEM = p;
    return *this;
}
DeduccionBuilder& DeduccionBuilder::PorcentajeIVM(float p) {
    porcentajeIVM = p;
    return *this;
}
DeduccionBuilder& DeduccionBuilder::PorcentajeLPT(float p) {
    porcentajeLPT = p;
    return *this;
}
DeduccionBuilder& DeduccionBuilder::Porcentaje(float p) {
    porcentaje = p;
    return *this;
}
DeduccionBuilder& DeduccionBuilder::Monto(float m) {
    monto = m;
    return *this;
}

Deduccion* DeduccionBuilder::Build() {
    if (tipo == "CCSS") {
        return new CCSS(porcentajeSEM, porcentajeIVM, porcentajeLPT);
    }
    else if (tipo == "Renta") {
        return new Renta();
    }
    else if (tipo == "Embargos") {
        return new Embargos(monto);
    }
    else if (tipo == "Maternidad") {
        return new Maternidad(monto);
    }
    else if (tipo == "Fija") {
        return new DeduccionFija(monto);
    }
    else if (tipo == "Porcentaje") {
        return new DeduccionPorcentaje(porcentaje);
    }
    return nullptr;
}