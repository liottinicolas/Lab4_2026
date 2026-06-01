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