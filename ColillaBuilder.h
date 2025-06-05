#pragma once
#include <string>
#include "Nomina.h"
#include "Colaborador.h"
#include "Colilla.h"

class ColillaBuilder {
private:
    string periodo;
    string fecha;
    Nomina* nomina = nullptr;
    Colaborador* colaborador = nullptr;
public:
    ColillaBuilder& setPeriodo(const string& periodo);
    ColillaBuilder& setFecha(const string& fecha);
    ColillaBuilder& setNomina(Nomina* nomina);
    ColillaBuilder& setColaborador(Colaborador* colaborador);

    Colilla* build();
};