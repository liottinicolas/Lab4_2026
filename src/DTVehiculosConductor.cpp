#include "../include/DTVehiculosConductor.h"

DTVehiculosConductor::DTVehiculosConductor(std::string matricula,
                                           std::string modelo, int capacidad) {
  this->matricula = matricula;
  this->modelo = modelo;
  this->capacidad = capacidad;
}

std::string DTVehiculosConductor::getMatricula() const { return matricula; }

std::string DTVehiculosConductor::getModelo() const { return modelo; }

int DTVehiculosConductor::getCapacidad() const { return capacidad; }

bool DTVehiculosConductor::operator<(const DTVehiculosConductor& other) const {
  return this->matricula < other.matricula;
}
