#include "SistemaNomina.h"
SistemaNomina* SistemaNomina::instancia = nullptr;

SistemaNomina::SistemaNomina() {
    colaboradores = new Lista();
}

SistemaNomina::~SistemaNomina() {
    delete colaboradores;
}

SistemaNomina* SistemaNomina::getInstance() {
    if (instancia == nullptr) {
        instancia = new SistemaNomina();
    }
    return instancia;
}

void SistemaNomina::registrarColaborador(Colaborador* e) {
    colaboradores->agregar(e);
}

void SistemaNomina::generarPlanilla() {
    ofstream archivo("reporte_nomina.txt");
    if (!archivo.is_open()) {

        // Manejo de error al abrir el archivo
        return;
    }

    archivo << "=== REPORTE DE NÓMINA ===" << endl;
    IIterador* it = colaboradores->getIterador();
    while (it->hasMore()) {
        Colaborador* colab = dynamic_cast<Colaborador*>(it->next());
        if (colab) {
            archivo << colab->toString() << endl;
            Lista* colillas = colab->getColillas();
            IIterador* itColillas = colillas->getIterador();
            while (itColillas->hasMore()) {
                Colilla* colilla = dynamic_cast<Colilla*>(itColillas->next());
                if (colilla) {
                    archivo << "  - Periodo: " << colilla->getPeriodo()
                        << ", Fecha: " << colilla->getFecha() << endl;
                }
            }
            delete itColillas;
        }
    }
    delete it;
    archivo << "=========================" << endl;
    archivo.close();
    // Mensaje de éxito al usuario
}

void SistemaNomina::exportarReporte() {
    ofstream archivo("reporte_nomina.txt");
    if (!archivo.is_open()) {
        // Manejo de error al abrir el archivo
        return;
    }

    archivo << "=== REPORTE DE NÓMINA ===" << endl;
    IIterador* it = colaboradores->getIterador();
    while (it->hasMore()) {
        Colaborador* colab = dynamic_cast<Colaborador*>(it->next());
        if (colab) {
            archivo << colab->toString() << endl;
            Lista* colillas = colab->getColillas();
            IIterador* itColillas = colillas->getIterador();
            while (itColillas->hasMore()) {
                Colilla* colilla = dynamic_cast<Colilla*>(itColillas->next());
                if (colilla) {
                    archivo << "  - Periodo: " << colilla->getPeriodo()
                        << ", Fecha: " << colilla->getFecha() << endl;
                }
            }
            delete itColillas;
        }
    }
    delete it;
    archivo << "=========================" << endl;
    archivo.close();
    // Mensaje de éxito al usuario

}

Lista* SistemaNomina::getColaboradores() const {
    return colaboradores;
}