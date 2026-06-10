#ifndef DT_VEHICULOS_CONDUCTOR_H
#define DT_VEHICULOS_CONDUCTOR_H

#include <string>
#include <iostream>

class DTVehiculosConductor {
private:
  std::string matricula;
  std::string marca;
  int capacidad;

public:
  DTVehiculosConductor(std::string matricula, std::string marca,
                       int capacidad);

  std::string getMatricula() const;
  std::string getMarca() const;
  int getCapacidad() const;
  // operador para ordenar en los sets.
  bool operator<(const DTVehiculosConductor &other) const;
};

std::ostream& operator<<(std::ostream& os, const DTVehiculosConductor &v);

#endif
