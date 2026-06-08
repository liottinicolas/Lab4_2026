#ifndef DT_VEHICULOS_CONDUCTOR_H
#define DT_VEHICULOS_CONDUCTOR_H

#include <string>

class DTVehiculosConductor {
private:
  std::string matricula;
  std::string modelo;
  int capacidad;

public:
  DTVehiculosConductor(std::string matricula, std::string modelo,
                       int capacidad);

  std::string getMatricula() const;
  std::string getModelo() const;
  int getCapacidad() const;
  // operador para ordenar en los sets.
  bool operator<(const DTVehiculosConductor &other) const;
};

#endif
