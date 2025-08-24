#include "IteradorLista.h"

IteradorLista::IteradorLista(Nodo* tmp) {
    actual = tmp;
}

bool IteradorLista::hasMore() const {
    return actual != NULL;
}

ObjectAdaptador* IteradorLista::next() {
    ObjectAdaptador* tmp = actual->getDato();
    actual = actual->getSiguiente();
    return tmp;
}