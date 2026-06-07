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
