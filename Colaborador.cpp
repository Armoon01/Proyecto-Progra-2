#include "Colaborador.h"
Colaborador::Colaborador(const string& nombre, const string& cedula, float salarioBase)
    : nombre(nombre), cedula(cedula), salarioBase(salarioBase) {
}

Colaborador::~Colaborador() {
}


string Colaborador::getNombre() const {
    return nombre;
}

string Colaborador::getCedula() const {
    return cedula;
}

float Colaborador::getSalarioBase() const {
    return salarioBase;
}


bool Colaborador::equals(IObjecto* ref) {
    Colaborador* referencia = (Colaborador*)ref;
    return cedula.compare(referencia->cedula) == 0;
}

string Colaborador::toString() const {
	return "Colaborador: " + nombre + ", Cedula: " + cedula + ", Salario Base: " + to_string(salarioBase);
}

void Colaborador::setSalarioBase(float salarioBase) {
	this->salarioBase = salarioBase;
}
void Colaborador::setNombre(const string& nombre) {
	this->nombre = nombre;
}

bool operator==(Colaborador& p1, Colaborador& p2) {
    return p1.getCedula().compare(p2.getCedula()) == 0;
}
