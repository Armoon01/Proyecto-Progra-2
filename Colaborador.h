#pragma once
#include <iostream>
#include "Lista.h"
#include "ObjectAdaptador.h"
using namespace std;
class Colaborador : public ObjectAdaptador{
private:
    string nombre;
    string cedula;
    float salarioBase;
public:
    Colaborador(const string& nombre, const string& cedula, float salarioBase);
    ~Colaborador();
    // Getters
    string getNombre() const;
    string getCedula() const;
    float getSalarioBase() const;
    string toString() const override;
    virtual bool equals(IObjecto*) override;
    void setSalarioBase(float salarioBase);
    void setNombre(const string& nombre);
};

bool operator==(Colaborador&, Colaborador&);
