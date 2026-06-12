#include "../include/DTConsultaViaje.h"

DTConsultaViaje::DTConsultaViaje(int codigo, std::string marca,
                                 std::string modelo, std::string conductor,
                                 float calificacionProm, float precioTotal) {
  this->codigo = codigo;
  this->marca = marca;
  this->modelo = modelo;
  this->conductor = conductor;
  this->calificacionProm = calificacionProm;
  this->precioTotal = precioTotal;
}

int DTConsultaViaje::getCodigo() { return codigo; }
std::string DTConsultaViaje::getMarca() { return marca; }
std::string DTConsultaViaje::getModelo() { return modelo; }
std::string DTConsultaViaje::getConductor() { return conductor; }
float DTConsultaViaje::getCalificacionProm() { return calificacionProm; }
float DTConsultaViaje::getPrecioTotal() { return precioTotal; }

std::ostream& operator<<(std::ostream& os, DTConsultaViaje cv) {
  os << "> Codigo: " << cv.getCodigo()
     << ", Marca: " << cv.getMarca()
     << ", Modelo: " << cv.getModelo()
     << ", Conductor: " << cv.getConductor()
     << ", CalificacionPromedio: " << cv.getCalificacionProm()
     << ", PrecioTotal: " << cv.getPrecioTotal();
  return os;
}

