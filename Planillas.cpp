#include "Planillas.h"
#include "Colilla.h"
#include "IIterador.h"

Planillas::Planillas() {
    colillas = new Lista();
}

Planillas::~Planillas() {
    delete colillas;
}

void Planillas::agregarColilla(Colilla* colilla) {
    colillas->agregarFinal(colilla);
}

Lista* Planillas::obtenerColillas() {
    return colillas;
}

Lista* Planillas::obtenerColillasDeColaborador(const ObjectAdaptador* colaborador) const {
    Lista* resultado = new Lista();
    IIterador* it = colillas->getIterador();
    while (it->hasMore()) {
        Colilla* actual = dynamic_cast<Colilla*>(it->next());
        if (actual && actual->getColaborador()->equals(const_cast<IObjecto*>(static_cast<const IObjecto*>(colaborador)))) {
            resultado->agregarFinal(actual);
        }
    }
    delete it;
    return resultado;
}