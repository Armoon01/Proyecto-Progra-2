#pragma once
#include <iostream>
#include "Lista.h"
#include "Colilla.h"
#include "ObjectAdaptador.h"
using namespace std;
class Colaborador : public ObjectAdaptador{
private:
    string nombre;
    string cedula;
    float salarioBase;
    Lista* colillas; // Lista de Colilla*
public:
    Colaborador(const string& nombre, const string& cedula, float salarioBase);
    ~Colaborador();
    void agregarColilla(Colilla* c);
    // Getters
    string getNombre() const;
    string getCedula() const;
    float getSalarioBase() const;
    Lista* getColillas() const;
    string toString() const override;
    virtual bool equals(IObjecto*) override;
    void setSalarioBase(float salarioBase);
    void setNombre(const string& nombre);
};

bool operator==(Colaborador&, Colaborador&);
