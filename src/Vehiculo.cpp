#include "../include/Vehiculo.h"
#include "../include/Conductor.h"

Vehiculo::Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
}

Vehiculo::~Vehiculo() {}

void Vehiculo::setConductor(Conductor* c) {
    this->conductor = c;
}

std::string Vehiculo::getMatricula() {
    return this->matricula;
}

int Vehiculo::getCapacidad() {
    return this->capacidad;
}

std::string Vehiculo::getMarca() {
    return this->marca;
}

std::string Vehiculo::getModelo() {
    return this->modelo;
}

TipoVehiculo Vehiculo::getTipo() {
    return this->tipo;
}

std::string Vehiculo::getNicknameConductor() {
    // 2.2.1.1.1: nick := getNickname()
    return this->conductor->getNickname(); 
}

std::vector<DTListarViaje> Vehiculo::obtenerDTListarViajes(std::string nickname) {
    std::vector<DTListarViaje> lista;
    
    // 2.4.1*: [foreach]: vi2 := next()
    for (Viaje* vi2 : this->viajes) {
        // 2.4.2*: dtv := getDTListarViaje(nickname)
        lista.push_back(vi2->getDTListarViaje(nickname));
    }
    
    return lista;
}

bool Vehiculo::EsDueño(std::string nickname){
    return nickname == getNicknameConductor();
}

DTUsuario Vehiculo::ObtenerDTUsCond(){
    return this->conductor.getDTUsuario();
}