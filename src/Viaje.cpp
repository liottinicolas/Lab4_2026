#include "../include/Viaje.h"
#include "../include/Vehiculo.h"

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino,
             int asientosPublicados, float precio) {
  this->codigo = codigo;
  this->fecha = fecha;
  this->origen = origen;
  this->destino = destino;
  this->asientosPublicados = asientosPublicados;
  this->precio = precio;
}

Viaje::~Viaje() {}

// Getters
int Viaje::getCodigo() { return this->codigo; }

DTFecha Viaje::getFecha() { return this->fecha; }

std::string Viaje::getOrigen() { return this->origen; }

std::string Viaje::getDestino() { return this->destino; }

int Viaje::getAsientosPublicados() { return this->asientosPublicados; }

float Viaje::getPrecio() { return this->precio; }

Vehiculo *Viaje::getVehiculo() { return this->vehiculo; }

// Setters
void Viaje::setCodigo(int codigo) { this->codigo = codigo; }

void Viaje::setFecha(DTFecha fecha) { this->fecha = fecha; }

void Viaje::setOrigen(std::string origen) { this->origen = origen; }

void Viaje::setDestino(std::string destino) { this->destino = destino; }

void Viaje::setAsientosPublicados(int asientosPublicados) {
  this->asientosPublicados = asientosPublicados;
}

void Viaje::setPrecio(float precio) { this->precio = precio; }

void Viaje::setVehiculo(Vehiculo *v) { this->vehiculo = v; }

std::string Viaje::getNicknameConductor() {
  // 2.2.1.1: nickConductor := getNickname()
  return this->vehiculo->getNicknameConductor();
}

DTListarViaje Viaje::getDTListarViaje(std::string nickConductor) {
  return DTListarViaje(this->codigo, this->fecha, this->origen, this->destino,
                       nickConductor);
}

bool Viaje::verificarViaje(DTFecha fecha, std::string origen,
                           std::string destino, int asientos) {
  return (this->fecha == fecha && this->origen == origen &&
          this->destino == destino && this->asientosPublicados >= asientos);
}
