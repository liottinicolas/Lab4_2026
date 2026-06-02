#ifndef CONTROLADORGESTIONVIAJES_H
#define CONTROLADORGESTIONVIAJES_H

#include "DTListarViaje.h"
#include "IControladorGestionViajes.h"
#include "ManejadorViaje.h"
#include "ManejadorUsuario.h"
#include <string>
#include <vector>


class ControladorGestionViajes : public IControladorGestionViajes {
private:
  static ControladorGestionViajes *instancia;
  ControladorGestionViajes();

  ManejadorUsuario *mu;
  ManejadorViaje *mv;

public:
  static ControladorGestionViajes *getInstancia();

  std::vector<DTListarViaje> listarViajes(std::string nickname) override;
  std::vector<DTListarViaje> listarViajes() override;
};

#endif