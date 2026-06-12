#ifndef MANEJADORVIAJE_H
#define MANEJADORVIAJE_H

#include "DTConsultaViaje.h"
#include "DTFecha.h"
#include "Viaje.h"
#include <map>
#include <vector>

class Vehiculo;

class ManejadorViaje {
private:
  static ManejadorViaje *instancia;

  std::map<int, Viaje *> viajes;
  int ultimoViaje;

  ManejadorViaje();

public:
  static ManejadorViaje *getInstance();

  std::map<int, Viaje *> obtenerViajes();

  void agregarViaje(Viaje *v);

  Viaje *find(int codigo);

  std::vector<DTConsultaViaje> consultarViajes(DTFecha fecha,
                                               std::string origen,
                                               std::string destino,
                                               int asientos);
  Viaje *crearViaje(Vehiculo *v, DTFecha fecha, std::string origen,
                    std::string destino, int asientos, float precio);
  void removerViaje(int codigo);
  int obtenerCodigo();
  ~ManejadorViaje();
};

#endif