#include "Control.h"
#include "Planillas.h"
int main() {
    Planillas* planillas = new Planillas();
    Control appControl(planillas);
    appControl.mostrarMenuPrincipal();
    return 0;
}