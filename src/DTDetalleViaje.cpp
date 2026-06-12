#include "../include/DTDetalleViaje.h"

DTDetalleViaje::DTDetalleViaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio, DTDetalleVehiculo vehi, std::vector<DTDetalleReserva> res)
    : codigo(codigo), fecha(fecha), origen(origen), destino(destino), asientosPublicados(asientosPublicados), precio(precio), vehiculo(vehi), reservas(res) {
}

int DTDetalleViaje::getCodigo() { return codigo; }
DTFecha DTDetalleViaje::getFecha() { return fecha; }
std::string DTDetalleViaje::getOrigen() { return origen; }
std::string DTDetalleViaje::getDestino() { return destino; }
int DTDetalleViaje::getAsientosPublicados() { return asientosPublicados; }
float DTDetalleViaje::getPrecio() { return precio; }
DTDetalleVehiculo DTDetalleViaje::getVehiculo() { return vehiculo; }
std::vector<DTDetalleReserva> DTDetalleViaje::getReservas() { return reservas; }

std::ostream &operator<<(std::ostream &os, DTDetalleViaje dt) {
  os << ">> Viaje <<\n"
     << "--- Codigo: " << dt.getCodigo()
     << ", Fecha: " << dt.getFecha()
     << ", Origen: " << dt.getOrigen()
     << ", Destino: " << dt.getDestino()
     << ", AsientosPublicados: " << dt.getAsientosPublicados()
     << ", Precio por asiento: " << dt.getPrecio() << "\n"
     << ">> Vehiculo <<\n"
     << "--- Matricula: " << dt.getVehiculo().getMatricula()
     << ", Capacidad: " << dt.getVehiculo().getCapacidad()
     << ", Marca: " << dt.getVehiculo().getMarca()
     << ", Modelo: " << dt.getVehiculo().getModelo()
     << ", Tipo: " << (dt.getVehiculo().getTipo() == TipoVehiculo::Auto ? "Auto" : "Moto") << "\n"
     << ">> Reservas <<";
  for (DTDetalleReserva r : dt.getReservas()) {
    os << "\n--- AsientosReservados: " << r.getAsientosReservados()
       << ", Fecha: " << r.getFecha()
       << ", Pasajero: " << r.getPasajero();
  }
  return os;
}
