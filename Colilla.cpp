#include "Colilla.h"
#include <sstream>
Colilla::Colilla(const std::string& periodo, const std::string& fecha, Nomina* nomina, Colaborador* colaborador)
    : periodo(periodo), fecha(fecha), nomina(nomina), colaborador(colaborador) {}

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

Colaborador* Colilla::getColaborador() const {
    return colaborador; 
}

std::string Colilla::toString() const {
	std::ostringstream oss;
	oss << "Colilla [Periodo: " << periodo << ", Fecha: " << fecha
		<< ", Nomina: " << (nomina ? nomina->toString(colaborador->getSalarioBase()) : "null")
		<< ", Colaborador: " << (colaborador ? colaborador->toString() : "null") << "]";
	return oss.str();
}