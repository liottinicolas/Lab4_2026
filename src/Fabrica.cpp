#include "../include/Fabrica.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ControladorGestionViajes.h"
#include "../include/ControladorUsuario.h"

Fabrica *Fabrica::instancia = nullptr;

Fabrica::Fabrica() {}

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
  return ControladorGestionViajes::getInstancia();
}

IControladorUsuario *Fabrica::getIControladorUsuario() {
  return ControladorUsuario::getInstancia();
}

Fabrica::~Fabrica() {
  delete ControladorGestionViajes::getInstancia();
  delete ControladorUsuario::getInstancia();
  delete ControladorFechaActual::getInstance();
  instancia = nullptr;
}