#include "../include/Calificacion.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje, Usuario &calificado,
                           Usuario &calificador, Reserva &r) {
  this->fecha = fecha;
  this->puntaje = puntaje;
  this->calificado = &calificado;
  this->calificador = &calificador;
  this->reserva = &r;
}

Calificacion::~Calificacion() {}

DTFecha Calificacion::getFecha() { return this->fecha; }

int Calificacion::getPuntaje() { return this->puntaje; }

Usuario *Calificacion::getCalificado() { return this->calificado; }

Usuario *Calificacion::getCalificador() { return this->calificador; }

Reserva *Calificacion::getReserva() { return this->reserva; }

void Calificacion::setFecha(DTFecha fecha) { this->fecha = fecha; }

void Calificacion::setPuntaje(int puntaje) { this->puntaje = puntaje; }
