#ifndef FABRICA_H
#define FABRICA_H

#include "IControladorFechaActual.h"
#include "IControladorGestionViajes.h"
#include "IControladorUsuario.h"

class Fabrica {
private:
  static Fabrica *instancia;

  Fabrica();

public:
  static Fabrica *getInstance();

  IControladorFechaActual *getIControladorFechaActual();
  IControladorUsuario *getIControladorUsuario();
  IControladorGestionViajes *getIControladorGestionViajes();
  ~Fabrica();
};

#endif
