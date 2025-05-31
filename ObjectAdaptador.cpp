#include "ObjectAdaptador.h"
#include <typeinfo>

//Un toString generico
string ObjectAdaptador::toString() const {
    return typeid(this).name();
}
//Compara el objecto actual con otro
bool ObjectAdaptador::equals(IObjecto* ref)
{
    return this == ref;
}
//Retorna el tipo del objecto actual
string ObjectAdaptador::getType() const {
    return typeid(*this).name();
}