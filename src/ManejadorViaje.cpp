#include "../include/ManejadorViaje.h"

ManejadorViaje* ManejadorViaje::instancia = nullptr;

ManejadorViaje::ManejadorViaje() {}

ManejadorViaje* ManejadorViaje::getInstance() {
    if (instancia == nullptr) {
        instancia = new ManejadorViaje();
    }
    return instancia;
}

std::map<int, Viaje*> ManejadorViaje::obtenerViajes() {
    return this->viajes;
}

void ManejadorViaje::agregarViaje(Viaje* v) {
    if (v != nullptr) {
        this->viajes[v->getCodigo()] = v;
    }
}