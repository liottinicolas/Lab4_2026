#include "../include/Reserva.h"
#include "../include/Viaje.h"
#include "../include/Usuario.h"
#include "../include/Pasajero.h"
#include "../include/ControladorFechaActual.h"

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

Pasajero* Reserva::getPasajero(){
    return this->pasajero;
}

void Reserva::setPasajero(Pasajero* p) {
    this->pasajero = p;
}

bool Reserva::calificarUsRes(Usuario& calificador, Usuario& calificado, int calificacion){
    bool a = calificador.ExisteCal(calificado, *this);
    if(!a) {
        DTFecha fechaSistema = ControladorFechaActual::getInstance()->getFecha();
        calificador.calificarUs(calificado, *this, calificacion, fechaSistema);
    }
    return !a;
}

DTDetalleReserva Reserva::getDTDetalleReserva() {
    return DTDetalleReserva(this->asientosReservados, this->fecha, this->pasajero->getNickname());
}