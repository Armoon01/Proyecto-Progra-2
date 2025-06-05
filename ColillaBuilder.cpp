#include "ColillaBuilder.h"

ColillaBuilder& ColillaBuilder::setPeriodo(const string& periodo) {
    this->periodo = periodo;
    return *this;
}

ColillaBuilder& ColillaBuilder::setFecha(const string& fecha) {
    this->fecha = fecha;
    return *this;
}

ColillaBuilder& ColillaBuilder::setNomina(Nomina* nomina) {
    this->nomina = nomina;
    return *this;
}

ColillaBuilder& ColillaBuilder::setColaborador(Colaborador* colaborador) {
    this->colaborador = colaborador;
    return *this;
}

Colilla* ColillaBuilder::build() {
    return new Colilla(periodo, fecha, nomina, colaborador);
}