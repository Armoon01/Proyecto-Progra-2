#include "OpcionMenu.h"

OpcionMenu::OpcionMenu(string tittle){
    titulo = tittle;
}

string OpcionMenu::toString() const{
    return titulo;
}
