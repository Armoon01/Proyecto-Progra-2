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
