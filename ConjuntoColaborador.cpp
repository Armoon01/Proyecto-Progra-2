#include "ConjuntoColaborador.h"

ConjuntoColaborador::ConjuntoColaborador() {
    listaPersonas = new Lista();
}

ConjuntoColaborador::~ConjuntoColaborador() {
    delete listaPersonas;
}

void ConjuntoColaborador::agregarColaborador(Colaborador* c) {
    listaPersonas->agregar(c);
}

Lista* ConjuntoColaborador::getListaPersonas() const {
    return listaPersonas;
}

IIterador* ConjuntoColaborador::getIterador() const {
    return listaPersonas->getIterador();
}

Colaborador* ConjuntoColaborador::buscar(const std::string& cedula) const {
    IIterador* it = listaPersonas->getIterador();
    while (it->hasMore()) {
        Colaborador* colab = dynamic_cast<Colaborador*>(it->next());
        if (colab && colab->getCedula() == cedula) {
            delete it;
            return colab;
        }
    }
    delete it;
    return nullptr;
}

void ConjuntoColaborador::remover(const std::string& cedula) {
    IIterador* it = listaPersonas->getIterador();
    while (it->hasMore()) {
        Colaborador* colab = dynamic_cast<Colaborador*>(it->next());
        if (colab && colab->getCedula() == cedula) {
            listaPersonas->remover(colab);
            break;
        }
    }
    delete it;
}