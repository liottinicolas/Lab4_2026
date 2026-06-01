#include "../include/Pasajero.h"

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