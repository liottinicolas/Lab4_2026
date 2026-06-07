#ifndef MANEJADORVEHICULOS_H
#define MANEJADORVEHICULOS_H

#include <map>
#include <string>
#include "Vehiculo.h"

class ManejadorVehiculos {
private:
  static ManejadorVehiculos *instancia;
  std::map<std::string, Vehiculo *> vehiculos;
  ManejadorVehiculos();

public:
  static ManejadorVehiculos *getInstancia();
  Vehiculo *find(std::string matricula);
  bool existe(std::string matricula);
  void agregarVehiculo(Vehiculo *v);
  std::map<std::string, Vehiculo *> obtenerVehiculos();
};

#endif
