#include "../include/Conductor.h"

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {
    this->libretas = libs;
}

Conductor::~Conductor() {}

std::vector<DTListarViaje> Conductor::obtenerDTListarViajes() {
    std::vector<DTListarViaje> dtViajes;
    
    // 2.3*: [u es Conductor] [foreach]: v := next()
    for (Vehiculo* v : this->vehiculos) {
        // 2.4*: dtvs := obtenerDTListarViajes(nickname)
        std::vector<DTListarViaje> viajesVehiculo = v->obtenerDTListarViajes(this->nickname);
        
        dtViajes.insert(dtViajes.end(), viajesVehiculo.begin(), viajesVehiculo.end());
    }
    
    return dtViajes;
}

void Conductor::agregarVehiculo(Vehiculo* v) {
    this->vehiculos.push_back(v);
}

std::set<TipoLibreta> Conductor::getLibretas() {
    return this->libretas;
}

void Conductor::setLibretas(std::set<TipoLibreta> libretas) {
    this->libretas = libretas;
}

std::vector<Vehiculo*> Conductor::getVehiculos() {
    return this->vehiculos;
}

void Conductor::setVehiculos(std::vector<Vehiculo*> vehiculos) {
    this->vehiculos = vehiculos;
}