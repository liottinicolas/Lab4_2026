#include "../include/DTVehiculosConductor.h"

DTVehiculosConductor::DTVehiculosConductor(std::string matricula,
                                           std::string marca,
                                           int capacidad) {
  this->matricula = matricula;
  this->marca = marca;
  this->capacidad = capacidad;
}

std::string DTVehiculosConductor::getMatricula() const { return matricula; }

std::string DTVehiculosConductor::getMarca() const { return marca; }

int DTVehiculosConductor::getCapacidad() const { return capacidad; }

bool DTVehiculosConductor::operator<(const DTVehiculosConductor &other) const {
  return this->matricula < other.matricula;
}

std::ostream& operator<<(std::ostream& os, const DTVehiculosConductor &v) {
  os << "> Matricula: " << v.getMatricula()
     << ", Modelo: " << v.getMarca()
     << ", Capacidad: " << v.getCapacidad();
  return os;
}
