#include "MenuColaboradores.h"
#include <exception>
#include <iomanip>
#include <sstream>

// Validar que la cedula sean solo numeros
bool esSoloNumeros(const string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (c < '0' || c > '9') return false;
    }
    return true;
}

// Validar que el nombre sean solo letras y espacios
bool esSoloLetrasYEspacios(const string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == ' ')) return false;
    }
    return true;
}


MenuColaboradores::MenuColaboradores(Control* nuevoGestor, Planillas* planillas) {
    gestor = nuevoGestor;
    this->planillas = planillas;

    Consola::setTitulo("ADMINISTRACION DE Colaboradores");
    Consola::setInstrucciones("Por favor, leer con cuidado las siguientes opciones.");

    agregarOpcion(new OpcionMenu("Crear Colaborador"));
    agregarOpcion(new OpcionMenu("Editar Colaborador"));
    agregarOpcion(new OpcionMenu("Listar Colaboradores"));
    agregarOpcion(new OpcionMenu("Menu Colillas"));
    agregarOpcion(new OpcionMenu("Menu Nominas"));
    agregarOpcion(new OpcionMenu("Regresar al menu"));
}

void MenuColaboradores::lanzar(int posicion) {
    try {
        if (posicion == 1) {
            imprimir("\n-----------------------------------------------");
            imprimir("           CREAR NUEVO COLABORADOR            ");
            imprimir("-----------------------------------------------");
            string cedula = leerString(" > Cedula: ");
            if (!esSoloNumeros(cedula)) throw exception();

            if (gestor->buscarColaborador(cedula) != nullptr) {
                imprimir("\n[!] Ya existe un colaborador con esa cedula.");
                enter();
                show();
                return;
            }

            string nombre = leerString(" > Nombre: ");
            if (!esSoloLetrasYEspacios(nombre)) throw exception();
            float salario = leerDouble(" > Salario: ");
            if (salario < 0) throw exception();
            gestor->agregar(new Colaborador(nombre, cedula, salario));
            imprimir("\n>>> Colaborador creado correctamente. <<<\n");
            enter();
            show();
        }
        else if (posicion == 2) {
            imprimir("\n-----------------------------------------------");
            imprimir("             EDITAR COLABORADOR               ");
            imprimir("-----------------------------------------------");
            string cedula = leerString(" > Cedula del Colaborador a editar: ");
            if (!esSoloNumeros(cedula)) throw exception();
            Colaborador* encontrada = gestor->buscarColaborador(cedula);
            if (encontrada != NULL) {
                string nombre = leerString(" > Nuevo Nombre: ");
                if (!esSoloLetrasYEspacios(nombre)) throw exception();
                float salario = leerDouble(" > Nuevo Salario: ");
                if (salario < 0) throw exception();
                encontrada->setNombre(nombre);
                encontrada->setSalarioBase(salario);
                imprimir("\n>>> Colaborador editado correctamente. <<<\n");
                enter();
            }
            else {
                imprimir("\n[!] Colaborador no encontrado.\n");
                enter();
            }
            show();
        }
        else if (posicion == 3) {
            imprimir("\n---------------------------------------------------------------------");
            imprimir("                      LISTADO DE COLABORADORES                       ");
            imprimir("---------------------------------------------------------------------");
            // Encabezado de la tabla
            cout << "| " << setw(3) << "#"
                << " | " << setw(12) << "Cedula"
                << " | " << setw(22) << "Nombre"
                << " | " << setw(13) << "Salario"
                << " |" << endl;
            imprimir("---------------------------------------------------------------------");

   
            Lista* lista = gestor->getColaboradores(); 
            if (lista->size() == 0) {
                cout << "| " << setw(72) << left << "No hay colaboradores registrados." << "|\n";
            }
            else {
                for (int i = 0; i < lista->size(); ++i) {
                    Colaborador* c = dynamic_cast<Colaborador*>(lista->get(i));
                    cout << "| " << setw(3) << (i + 1)
                        << " | " << setw(12) << c->getCedula()
                        << " | " << setw(22) << c->getNombre()
                        << " | " << setw(13) << fixed << setprecision(2) << c->getSalarioBase()
                        << " |\n";
                }
            }
            imprimir("---------------------------------------------------------------------");
            enter();
            show();
        }
        else if (posicion == 4) {
            imprimir("\n-----------------------------------------------");
            imprimir("                MENU COLILLAS                 ");
            imprimir("-----------------------------------------------");
            string cedula = leerString(" > Cedula del Colaborador: ");
            if (!esSoloNumeros(cedula)) throw exception();
            Colaborador* encontrada = gestor->buscarColaborador(cedula);
            if (encontrada != NULL) {
                gestor->mostrarMenuColillas(encontrada, planillas);
            }
            else {
                imprimir("\n[!] Colaborador no encontrado.\n");
                enter();
                show();
            }
        }
        else if (posicion == 5) {
            imprimir("\n-----------------------------------------------");
            imprimir("                 MENU NOMINAS                 ");
            imprimir("-----------------------------------------------");
            string cedula = leerString(" > Cedula del Colaborador: ");
            if (!esSoloNumeros(cedula)) throw exception();
            Colaborador* encontrada = gestor->buscarColaborador(cedula);
            if (encontrada != NULL) {
                gestor->mostrarMenuNominas(encontrada, planillas);
            }
            else {
                imprimir("\n[!] Colaborador no encontrado.\n");
                enter();
                show();
            }
        }
        else if (posicion == 6) {
            gestor->mostrarMenuPrincipal();
        }
        else {
            throw exception();
        }
    }
    catch (const exception&) {
        imprimir("\n[!] Ha ocurrido un error en la operacion (verifique que la cedula sean solo numeros y el nombre solo letras).\n");
        enter();
        show();
    }
}