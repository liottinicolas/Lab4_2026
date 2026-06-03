#include "../include/Reserva.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
}

Reserva::~Reserva() {}

DTListarViaje Reserva::getDTListarViaje() {
    // 2.2.1: nickConductor := getNicknameConductor()
    std::string nickConductor = this->viaje->getNicknameConductor();
    
    return this->viaje->getDTListarViaje(nickConductor); 
}

int Reserva::getAsientosReservados() {
    return this->asientosReservados;
}

void Reserva::setAsientosReservados(int asientosReservados) {
    this->asientosReservados = asientosReservados;
}

DTFecha Reserva::getFecha() {
    return this->fecha;
}

void Reserva::setFecha(DTFecha fecha) {
    this->fecha = fecha;
}

void Reserva::setViaje(Viaje* v) {
    this->viaje = v;
}

Viaje* Reserva::getViaje() {
    return this->viaje;
}