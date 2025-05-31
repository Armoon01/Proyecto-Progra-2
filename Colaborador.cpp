#include "Colaborador.h"
Colaborador::Colaborador(const std::string& nombre, const std::string& cedula, float salarioBase)
    : nombre(nombre), cedula(cedula), salarioBase(salarioBase) {
    colillas = new Lista();
}

Colaborador::~Colaborador() {
    delete colillas;
}

void Colaborador::agregarColilla(Colilla* c) {
    colillas->agregar(c);
}

std::string Colaborador::getNombre() const {
    return nombre;
}

std::string Colaborador::getCedula() const {
    return cedula;
}

float Colaborador::getSalarioBase() const {
    return salarioBase;
}

Lista* Colaborador::getColillas() const {
    return colillas;
}

bool Colaborador::equals(IObjecto* ref) {
    Colaborador* referencia = (Colaborador*)ref;
    return cedula.compare(referencia->cedula) == 0;
}

std::string Colaborador::toString() const {
	return "Colaborador: " + nombre + ", Cedula: " + cedula + ", Salario Base: " + to_string(salarioBase);
}
