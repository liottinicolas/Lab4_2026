#include "../include/ManejadorVehiculos.h"

ManejadorVehiculos *ManejadorVehiculos::instancia = nullptr;

ManejadorVehiculos::ManejadorVehiculos() {}

ManejadorVehiculos *ManejadorVehiculos::getInstancia() {
  if (instancia == nullptr) {
    instancia = new ManejadorVehiculos();
  }
  return instancia;
}

Vehiculo *ManejadorVehiculos::find(std::string matricula) {
  auto it = vehiculos.find(matricula);
  if (it != vehiculos.end()) {
    return it->second;
  }
  return nullptr;
}

bool ManejadorVehiculos::existe(std::string matricula) {
  return vehiculos.find(matricula) != vehiculos.end();
}

void ManejadorVehiculos::agregarVehiculo(Vehiculo *v) {
  if (v != nullptr) {
    vehiculos[v->getMatricula()] = v;
  }
}

std::map<std::string, Vehiculo *> ManejadorVehiculos::obtenerVehiculos() {
  return vehiculos;
}

ManejadorVehiculos::~ManejadorVehiculos() {
  for (auto const &par : vehiculos) {
    delete par.second;
  }
  vehiculos.clear();
  instancia = nullptr;
}
