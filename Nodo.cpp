#include "Nodo.h"

Nodo::Nodo(ObjectAdaptador* dato, Nodo* sig) {
    _dato = dato;
    _siguiente = sig;
}

void Nodo::setSiguiente(Nodo* sig) {
    _siguiente = sig;
}

void Nodo::setDato(ObjectAdaptador* dato) {
    _dato = dato;
}

Nodo* Nodo::getSiguiente() const {
    return _siguiente;
}

ObjectAdaptador* Nodo::getDato() const {
    return _dato;
}
