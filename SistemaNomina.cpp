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
    colaboradores = e;
}

void SistemaNomina::generarPlanilla() {
    ofstream archivo("reporte_nomina.txt");
    if (!archivo.is_open()) {
        // Manejo de error al abrir el archivo
        return;
    }

    archivo << "=================== REPORTE DE NÓMINA ===================\n\n";
    IIterador* it = colaboradores->getIterador();
    while (it->hasMore()) {
        Colaborador* colab = dynamic_cast<Colaborador*>(it->next());
        if (colab) {
            archivo << "Colaborador: " << colab->getNombre()
                << " | Cédula: " << colab->getCedula()
                << " | Salario Base: " << fixed << setprecision(2) << colab->getSalarioBase() << "\n";
            archivo << "----------------------------------------------------------\n";

            Lista* colillas = planillas->obtenerColillasDeColaborador(colab);
            IIterador* itColillas = colillas->getIterador();
            int numColilla = 1;
            while (itColillas->hasMore()) {
                Colilla* colilla = dynamic_cast<Colilla*>(itColillas->next());
                if (colilla) {
                    archivo << "Colilla #" << numColilla++ << " | Periodo: " << colilla->getPeriodo()
                        << " | Fecha: " << colilla->getFecha() << "\n";
                    archivo << "----------------------------------------------------------\n";

                    archivo << "  Ingresos:\n";
                    archivo << colilla->getNomina()->listarIngresos(); // Ya incluye sangría y saltos de línea

                    archivo << "  Deducciones:\n";
                    archivo << colilla->getNomina()->listarDeducciones(colab->getSalarioBase());

                    archivo << "  Salario Bruto : " << fixed << setprecision(2) << colilla->getNomina()->calcularSalarioBruto(colab->getSalarioBase()) << "\n";
                    archivo << "  Deducciones   : " << fixed << setprecision(2) << colilla->getNomina()->calcularDeducciones(colab->getSalarioBase()) << "\n";
                    archivo << "  Salario Neto  : " << fixed << setprecision(2) << colilla->getNomina()->calcularSalarioNeto(colab->getSalarioBase()) << "\n";
                    archivo << "----------------------------------------------------------\n";
                }
            }
            delete itColillas;
            delete colillas;

            archivo << "\n";
        }
    }
    delete it;
    archivo << "=============== FIN DEL REPORTE DE NÓMINA ===============\n";
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