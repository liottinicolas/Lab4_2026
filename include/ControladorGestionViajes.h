#ifndef CONTROLADORGESTIONVIAJES_H
#define CONTROLADORGESTIONVIAJES_H

#include "DTListarViaje.h"
#include "IControladorGestionViajes.h"
#include "ManejadorViaje.h"
#include "ManejadorUsuario.h"
#include <string>
#include <vector>
#include <map>
#include "ManejadorViaje.h"

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
  std::vector<DTConsultaViaje> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos) override;
  std::vector<DTUsuario> listarUsuariosViaje(int codigo) override;
};

#endif