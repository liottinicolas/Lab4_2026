#include "../include/Menu.h"
#include "../include/Fabrica.h"

int main() {
    Menu menu;
    menu.mostrarMenu();
    delete Fabrica::getInstance();
    return 0;
}
