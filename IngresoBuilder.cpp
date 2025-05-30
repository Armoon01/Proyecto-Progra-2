#include "IngresoBuilder.h"

IngresoBuilder& IngresoBuilder::setTipo(const std::string& tipo) {
    this->tipo = tipo;
    return *this;
}

IngresoBuilder& IngresoBuilder::setCantidad(int cantidad) {
    this->cantidad = cantidad;
    return *this;
}
