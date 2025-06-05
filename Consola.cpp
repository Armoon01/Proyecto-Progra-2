#include "Consola.h"




Consola::Consola() {
	listaOpciones = new Lista();
	titulo = "";
	instrucciones = "";
}

void Consola::setTitulo(string t) {
	titulo = t;
}


void Consola::setInstrucciones(string i) {
	instrucciones = i;
}


void Consola::agregarOpcion(OpcionMenu* opcion){
	listaOpciones->agregarFinal(opcion);
}

void Consola::agregarOpcion(string texto){
	listaOpciones->agregarFinal(new OpcionMenu(texto));
}

void Consola::show() {
    limpiar();
    cout << "==================================================" << endl;
    cout << "          " << titulo << endl;
    cout << "==================================================" << endl;
    cout << endl;
    if (!instrucciones.empty()) {
        cout << instrucciones << endl;
    }
    cout << endl;
    // Opciones numeradas y con formato
    for (int i = 0; i < listaOpciones->size(); i++) {
        cout << "  [" << (i + 1) << "] " << listaOpciones->get(i)->toString() << endl;
    }
    cout << endl;
    stringstream r;
    r << "Indique un numero entre 1 y " << listaOpciones->size() << "\n";
    lanzar(leerEntero(r.str(), 1, listaOpciones->size()));
}

void Consola::imprimir(string mensaje, bool salto) {
    cout << mensaje;
    if (salto) {
        cout << endl;
    }
}


void Consola::enter(){
	cout << "Presione una tecla para continuar . . .";
	cin.get();
}

void Consola::limpiar(){
#ifdef _WIN32
	system("cls");   // Windows
#else
	system("clear"); // Linux/macOS
#endif
}







int Consola::leerEntero(string mensaje) {
    int numero;
    while (true) {
        cout << mensaje;
        cin >> numero;

        if (cin.fail()) {
            // Entrada no es un int
            cout << "Error: Debe ingresar un número entero válido." << endl;

            // Limpiar estado de error
            cin.clear();

            // Ignorar la entrada inválida
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            // Correcto, salir del ciclo
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar el resto
            return numero;
        }
    }
}

int Consola::leerEntero(string mensaje, int minimo, int maximo) {
    int numero;
    while (true) {
        cout << mensaje;
        cin >> numero;

        if (cin.fail()) {
            cout << "Error: Debe ingresar un número entero válido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (numero < minimo || numero > maximo) {
            cout << "Error: El número debe estar entre " << minimo << " y " << maximo << "." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return numero;
        }
    }
}

double Consola::leerDouble(string mensaje) {
    double numero;
    while (true) {
        cout << mensaje;
        cin >> numero;

        if (cin.fail()) {
            // Entrada no es un int
            cout << "Error: Debe ingresar un número entero válido." << endl;

            // Limpiar estado de error
            cin.clear();

            // Ignorar la entrada inválida
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            // Correcto, salir del ciclo
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar el resto
            return numero;
        }
    }
}

string Consola::leerString(string mensaje) {
    cout << mensaje;
    string entrada;
    getline(cin, entrada); // Leer toda la línea, incluyendo espacios
    return entrada;
}
