#include "SistemaNomina.h"

SistemaNomina* SistemaNomina::instancia = nullptr;

SistemaNomina::SistemaNomina(Planillas* planillas)
    : planillas(planillas)
{
    colaboradores = new Lista();
}

SistemaNomina::~SistemaNomina() {
    delete colaboradores;
}

SistemaNomina* SistemaNomina::getInstance(Planillas* planillas) {
    if (instancia == nullptr) {
        instancia = new SistemaNomina(planillas);
    }
    return instancia;
}

void SistemaNomina::registrarColaborador(Colaborador* e) {
    colaboradores->agregar(e);
}

void SistemaNomina::agregarListaColaborador(Lista* e) {
    IIterador* it = e->getIterador();
    while (it->hasMore()) {
        Colaborador* colab = dynamic_cast<Colaborador*>(it->next());
        if (colab) {
            colaboradores->agregar(colab);
        }
    }
    delete it;
}

void SistemaNomina::generarPlanilla() {
    ofstream archivo("reporte_nomina.txt");
    if (!archivo.is_open()) {
        // Manejo de error al abrir el archivo
        return;
    }

    archivo << "=== REPORTE DE NÓMINA ===" << std::endl;
    IIterador* it = colaboradores->getIterador();
    while (it->hasMore()) {
        Colaborador* colab = dynamic_cast<Colaborador*>(it->next());
        if (colab) {
            archivo << colab->toString() << std::endl;
            Lista* colillas = planillas->obtenerColillasDeColaborador(colab);
            IIterador* itColillas = colillas->getIterador();
            while (itColillas->hasMore()) {
                Colilla* colilla = dynamic_cast<Colilla*>(itColillas->next());
                if (colilla) {
                    archivo << "  - Periodo: " << colilla->getPeriodo()
                        << ", Fecha: " << colilla->getFecha() << std::endl;
                    archivo << "    Detalles de la nómina:" << std::endl;

                    archivo << colilla->getNomina()->toString(colab->getSalarioBase()) << std::endl;
                    archivo << fixed << setprecision(2);
                    archivo << "    Salario Bruto: " << colilla->getNomina()->calcularSalarioBruto(colab->getSalarioBase()) << endl;
                    archivo << "    Deducciones: " << colilla->getNomina()->calcularDeducciones(colab->getSalarioBase()) << endl;
                }
            }
            delete itColillas;
            delete colillas;
        }
    }
    delete it;
    archivo << "=========================" << std::endl;
    archivo.close();
}

void SistemaNomina::exportarReporte() {
    ofstream archivo("reporte_nomina.txt");
    if (!archivo.is_open()) {
        // Manejo de error al abrir el archivo
        return;
    }

    archivo << "=== REPORTE DE NÓMINA ===" << std::endl;
    IIterador* it = colaboradores->getIterador();
    while (it->hasMore()) {
        Colaborador* colab = dynamic_cast<Colaborador*>(it->next());
        if (colab) {
            archivo << colab->toString() << std::endl;
            Lista* colillas = planillas->obtenerColillasDeColaborador(colab);
            IIterador* itColillas = colillas->getIterador();
            while (itColillas->hasMore()) {
                Colilla* colilla = dynamic_cast<Colilla*>(itColillas->next());
                if (colilla) {
                    archivo << "  - Periodo: " << colilla->getPeriodo()
                        << ", Fecha: " << colilla->getFecha() << std::endl;
                }
            }
            delete itColillas;
            delete colillas;
        }
    }
    delete it;
    archivo << "=========================" << std::endl;
    archivo.close();
}

Lista* SistemaNomina::getColaboradores() const {
    return colaboradores;
}