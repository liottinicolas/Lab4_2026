#ifndef ICONTROLADORGESTIONVIAJES_H
#define ICONTROLADORGESTIONVIAJES_H

#include "DTConsultaViaje.h"
#include "DTFecha.h"
#include "DTListarViaje.h"
#include <string>
#include <vector>


class IControladorGestionViajes {
public:
  virtual std::vector<DTListarViaje> listarViajes(std::string nickname) = 0;
  virtual std::vector<DTListarViaje> listarViajes() = 0;
  virtual std::vector<DTConsultaViaje> consultarViajes(DTFecha fecha,
                                                       std::string origen,
                                                       std::string destino,
                                                       int asientos) = 0;

  virtual ~IControladorGestionViajes() {}
  virtual std::vector<DTUsuario> listarUsuariosViaje(int codigo) = 0;
};

#endif