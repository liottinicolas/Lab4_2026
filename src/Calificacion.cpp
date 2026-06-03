#include "../include/Calificacion.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
}

Calificacion::~Calificacion() {}

DTFecha Calificacion::getFecha() {
    return this->fecha;
}

int Calificacion::getPuntaje() {
    return this->puntaje;
}

void Calificacion::setFecha(DTFecha fecha) {
    this->fecha = fecha;
}

void Calificacion::setPuntaje(int puntaje) {
    this->puntaje = puntaje;
}
