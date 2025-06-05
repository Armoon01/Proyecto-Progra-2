#include "Colilla.h"
#include <sstream>
Colilla::Colilla(const string& periodo, const string& fecha, Nomina* nomina, Colaborador* colaborador)
    : periodo(periodo), fecha(fecha), nomina(nomina), colaborador(colaborador) {}

Colilla::~Colilla() {
    delete nomina;
}

void Colilla::mostrarResumen() {
    cout << "Periodo: " << periodo << ", Fecha: " << fecha << endl;
    // Aquí puedes mostrar más detalles del objeto Nomina
}

string Colilla::getPeriodo() const {
    return periodo;
}

string Colilla::getFecha() const {
    return fecha;
}

Nomina* Colilla::getNomina() const {
    return nomina;
}

Colaborador* Colilla::getColaborador() const {
    return colaborador; 
}

string Colilla::toString() const {
	ostringstream oss;
	oss << "Colilla [Periodo: " << periodo << ", Fecha: " << fecha
		<< ", Nomina: " << (nomina ? nomina->toString(colaborador->getSalarioBase()) : "null")
		<< ", Colaborador: " << (colaborador ? colaborador->toString() : "null") << "]";
	return oss.str();
}