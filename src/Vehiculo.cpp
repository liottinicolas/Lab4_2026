#include "../include/Vehiculo.h"
#include "../include/Conductor.h"
#include "../include/Viaje.h"

Vehiculo::Vehiculo(std::string matricula, int capacidad, std::string marca,
                   std::string modelo, TipoVehiculo tipo) {
  this->matricula = matricula;
  this->capacidad = capacidad;
  this->marca = marca;
  this->modelo = modelo;
  this->tipo = tipo;
}

Vehiculo::~Vehiculo() {}

void Vehiculo::setConductor(Conductor *c) { this->conductor = c; }

std::string Vehiculo::getMatricula() { return this->matricula; }

int Vehiculo::getCapacidad() { return this->capacidad; }

std::string Vehiculo::getMarca() { return this->marca; }

std::string Vehiculo::getModelo() { return this->modelo; }

TipoVehiculo Vehiculo::getTipo() { return this->tipo; }

bool Vehiculo::hayViajesConductor(DTFecha fecha) {
  return this->conductor->hayViajesFechaConductor(fecha);
}

std::vector<Viaje *> Vehiculo::getViajes() { return this->viajes; }

void Vehiculo::agregarViaje(Viaje *vi) { this->viajes.push_back(vi); }

std::string Vehiculo::getNicknameConductor() {
  // 2.2.1.1.1: nick := getNickname()
  return this->conductor->getNickname();
}

std::vector<DTListarViaje>
Vehiculo::obtenerDTListarViajes(std::string nickname) {
  std::vector<DTListarViaje> lista;

  // 2.4.1*: [foreach]: vi2 := next()
  for (Viaje *vi2 : this->viajes) {
    // 2.4.2*: dtv := getDTListarViaje(nickname)
    lista.push_back(vi2->getDTListarViaje(nickname));
  }

  return lista;
}

bool Vehiculo::hayViajesFecha(DTFecha fecha) {
  for (Viaje *vcv : this->viajes) {
    if (vcv->getFecha() == fecha) {
      return true;
    }
  }
  return false;
}

bool Vehiculo::EsDueño(std::string nickname) {
  return nickname == getNicknameConductor();
}

DTUsuario Vehiculo::ObtenerDTUsCond() { return this->conductor->getDTUsuario(); }

DTConsultaViaje Vehiculo::datosVehiculoYChofer(int codigo, float precio) {
  return DTConsultaViaje(codigo, this->marca, this->modelo,
                         this->conductor->getNickname(),
                         this->conductor->promedioCalificaciones(), precio);
}
