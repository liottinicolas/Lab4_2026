#ifndef VIAJE_H
#define VIAJE_H

#include "DTFecha.h"
#include "DTListarViaje.h"
#include "DTUsuario.h"
#include "Reserva.h"
#include "DTConsultaViaje.h"
#include <string>
#include <vector>

class Vehiculo;

class Viaje {
private:
  int codigo;
  DTFecha fecha;
  std::string origen;
  std::string destino;
  int asientosPublicados;
  float precio;

  // listarViajes
  Vehiculo *vehiculo;
  std::vector<Reserva *> reservas;

public:
  Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino,
        int asientosPublicados, float precio);
  ~Viaje();

  // Getters
  int getCodigo();
  DTFecha getFecha();
  std::string getOrigen();
  std::string getDestino();
  int getAsientosPublicados();
  float getPrecio();
  Vehiculo *getVehiculo();

  void setCodigo(int codigo);
  void setFecha(DTFecha fecha);
  void setOrigen(std::string origen);
  void setDestino(std::string destino);
  void setAsientosPublicados(int asientosPublicados);
  void setPrecio(float precio);
  void setVehiculo(Vehiculo *v);

  std::string getNicknameConductor();
  DTListarViaje getDTListarViaje(std::string nickConductor);
  std::vector<DTUsuario> listaUsuarios(std::string nicknameActor);
  bool calificarUsViaje(Usuario &calificador, Usuario &calificado,
                        int calificacion);
  bool verificarViaje(DTFecha fecha, std::string origen, std::string destino,
                      int asientos);
  bool validarViaje(std::string nickname, int asientos);
  void agregarReserva(Reserva *r);

  DTConsultaViaje datosViaje();
};

#endif
