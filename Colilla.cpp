#include "Colilla.h"

Colilla::Colilla(const std::string& periodo, const std::string& fecha, Nomina* nomina)
    : periodo(periodo), fecha(fecha), nomina(nomina) {}

Colilla::~Colilla() {
    delete nomina;
}

void Colilla::mostrarResumen() {
    std::cout << "Periodo: " << periodo << ", Fecha: " << fecha << std::endl;
    // Aquí puedes mostrar más detalles del objeto Nomina
}

std::string Colilla::getPeriodo() const {
    return periodo;
}

std::string Colilla::getFecha() const {
    return fecha;
}

Nomina* Colilla::getNomina() const {
    return nomina;
}