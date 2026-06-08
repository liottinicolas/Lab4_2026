#include "../include/Pasajero.h"
#include "../include/Reserva.h"

Pasajero::Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento)
    : Usuario(nickname, nombre, contrasena, email) {
    this->ci = documento;
}

Pasajero::~Pasajero() {}

std::vector<DTListarViaje> Pasajero::obtenerDTListarViajes() {
    std::vector<DTListarViaje> dtViajes;
    
    // 2.1*: [u es Pasajero] [foreach]: r := next()
    for (Reserva* r : this->reservas) {
        // 2.2*: dtv := getDTListarViaje()
        dtViajes.push_back(r->getDTListarViaje());
    }
    
    return dtViajes;
}

void Pasajero::agregarReserva(Reserva* r) {
    this->reservas.push_back(r);
}

std::string Pasajero::getCi() {
    return this->ci;
}

void Pasajero::setCi(std::string ci) {
    this->ci = ci;
}

std::vector<Reserva*> Pasajero::getReservas() {
    return this->reservas;
}

void Pasajero::setReservas(std::vector<Reserva*> reservas) {
    this->reservas = reservas;
}