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
					archivo << "    Detalles de la nómina:" << endl;
					archivo << colilla->getNomina()->toString(colab->getSalarioBase()) << endl;
					archivo << "    Salario Bruto: " << colilla->getNomina()->calcularSalarioBruto(colab->getSalarioBase()) << endl;
					archivo << "    Deducciones: " << colilla->getNomina()->calcularDeducciones(colab->getSalarioBase()) << endl;
					

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