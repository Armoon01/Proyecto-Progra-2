#include "MenuColaboradores.h"
#include <exception>

// Validar que la cédula sean solo números
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
    agregarOpcion(new OpcionMenu("Colillas del Colaborador"));
    agregarOpcion(new OpcionMenu("Menu Colillas"));
    agregarOpcion(new OpcionMenu("Menu Nominas"));
    agregarOpcion(new OpcionMenu("Regresar al menu"));
}

void MenuColaboradores::lanzar(int posicion) {
    try {
        if (posicion == 1) {
            imprimir("Creando Colaborador");
            string cedula = leerString("Por favor, digitar cedula:");
            if (!esSoloNumeros(cedula)) throw exception();
            string nombre = leerString("Por favor, digitar Nombre:");
            if (!esSoloLetrasYEspacios(nombre)) throw exception();
            float salario = leerDouble("Por favor, digitar Salario:");
            if (salario < 0) throw exception();
            gestor->agregar(new Colaborador(nombre, cedula, salario));
            imprimir("Colaborador creado correctamente.");
            enter();
            show();
        }
        else if (posicion == 2) {
            imprimir("Editando Colaborador");
            string cedula = leerString("Cedula del Colaborador a editar: ");
            if (!esSoloNumeros(cedula)) throw exception();
            Colaborador* encontrada = gestor->buscarColaborador(cedula);
            if (encontrada != NULL) {
                string nombre = leerString("Nuevo Nombre: ");
                if (!esSoloLetrasYEspacios(nombre)) throw exception();
                float salario = leerDouble("Nuevo Salario: ");
                if (salario < 0) throw exception();
                encontrada->setNombre(nombre);
                encontrada->setSalarioBase(salario);
                imprimir("Colaborador editado correctamente.");
                enter();
            }
            else {
                imprimir("Colaborador no encontrado.");
                enter();
            }
            show();
        }
        else if (posicion == 3) {
            imprimir("Listando");
            imprimir("Colaboradores registrados:");
            imprimir(gestor->listarColaboradores());
            enter();
            show();
        }
        else if (posicion == 4) {
            string cedula = leerString("Cedula del Colaborador: ");
            if (!esSoloNumeros(cedula)) throw exception();
            Colaborador* encontrada = gestor->buscarColaborador(cedula);
            if (encontrada != NULL) {
                imprimir("Colaborador encontrado: " + encontrada->toString());
                Lista* colillas = planillas->obtenerColillasDeColaborador(encontrada);
                if (!colillas) throw exception();
                if (colillas->size() > 0) {
                    imprimir("Colillas asociadas:");
                    imprimir(colillas->toString());
                    enter();
                }
                else {
                    imprimir("No hay colillas asociadas a este colaborador.");
                    enter();
                }
                delete colillas;
            }
            else {
                imprimir("Colaborador no encontrado.");
                enter();
            }
            show();
        }
        else if (posicion == 5) {
            string cedula = leerString("Cedula del Colaborador: ");
            if (!esSoloNumeros(cedula)) throw exception();
            Colaborador* encontrada = gestor->buscarColaborador(cedula);
            if (encontrada != NULL) {
                gestor->mostrarMenuColillas(encontrada, planillas);
            }
            else {
                imprimir("Colaborador no encontrado.");
                enter();
                show();
            }
        }
        else if (posicion == 6) {
            string cedula = leerString("Cedula del Colaborador: ");
            if (!esSoloNumeros(cedula)) throw exception();
            Colaborador* encontrada = gestor->buscarColaborador(cedula);
            if (encontrada != NULL) {
                gestor->mostrarMenuNominas(encontrada, planillas);
            }
            else {
                imprimir("Colaborador no encontrado.");
                enter();
                show();
            }
        }
        else if (posicion == 7) {
            gestor->mostrarMenuPrincipal();
        }
        else {
            throw exception();
        }
    }
    catch (const exception&) {
        imprimir("Ha ocurrido un error en la operación (verifique que la cédula sean solo números y el nombre solo letras).");
        enter();
        show();
    }
}