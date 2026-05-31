#include "../include/ControladorUsuario.h"
#include "../include/Conductor.h"
#include "../include/Pasajero.h"

ControladorUsuario::ControladorUsuario() {
    mu = ManejadorUsuario::getInstance();
}