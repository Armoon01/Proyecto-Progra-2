#include "ConjuntoColaborador.h"
#include <iomanip>
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

Colaborador* ConjuntoColaborador::buscar(const string& cedula) const {
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

void ConjuntoColaborador::remover(const string& cedula) {
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

string ConjuntoColaborador::listarColaboradores() const {
    ostringstream oss;
    oss << "----------------------------------------------------------------------------\n";
    for (int i = 0; i < listaPersonas->size(); ++i) {
        Colaborador* col = dynamic_cast<Colaborador*>(listaPersonas->get(i));
        if (col) {
            oss << i + 1 << ". Nombre: " << col->getNombre()
                << " | Cedula: " << col->getCedula()
                << " | Salario Base: " << fixed << setprecision(2) << col->getSalarioBase()
                << "\n";
        }
    }
    if (listaPersonas->size() == 0) {
        oss << "No hay colaboradores registrados.\n";
    }
    oss << "----------------------------------------------------------------------------";
    return oss.str();
}