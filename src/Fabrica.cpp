#include "../include/Fabrica.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ControladorGestionViajes.h"
#include "../include/ControladorUsuario.h"
#include "../include/ManejadorUsuario.h"
#include "../include/ManejadorVehiculos.h"
#include "../include/ManejadorViaje.h"
#include "../include/CargaDatos.h"

Fabrica *Fabrica::instancia = nullptr;

Fabrica::Fabrica() {
  controladorUsuario = nullptr;
  controladorGestionViajes = nullptr;
}

Fabrica *Fabrica::getInstance() {
  if (instancia == nullptr) {
    instancia = new Fabrica();
  }
  return instancia;
}

IControladorFechaActual *Fabrica::getIControladorFechaActual() {
  return ControladorFechaActual::getInstance();
}

IControladorGestionViajes *Fabrica::getIControladorGestionViajes() {
  if (controladorGestionViajes == nullptr) {
    controladorGestionViajes = new ControladorGestionViajes();
  }
  return controladorGestionViajes;
}

IControladorUsuario *Fabrica::getIControladorUsuario() {
  if (controladorUsuario == nullptr) {
    controladorUsuario = new ControladorUsuario();
  }
  return controladorUsuario;
}

Fabrica::~Fabrica() {
  delete controladorGestionViajes;
  delete controladorUsuario;
  delete ControladorFechaActual::getInstance();
  delete ManejadorUsuario::getInstancia();
  delete ManejadorVehiculos::getInstancia();
  delete ManejadorViaje::getInstance();
  delete CargaDatos::getInstance();
  instancia = nullptr;
}