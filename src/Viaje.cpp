#include "../include/Viaje.h"

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
}

Viaje::~Viaje() {}

std::string Viaje::getNicknameConductor() {
    // 2.2.1.1: nickConductor := getNickname()
    return this->vehiculo->getNicknameConductor(); 
}

DTListarViaje Viaje::getDTListarViaje(std::string nickConductor) {
    return DTListarViaje(this->codigo, this->fecha, this->origen, this->destino, nickConductor);
}