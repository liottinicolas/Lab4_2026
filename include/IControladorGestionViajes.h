#ifndef ICONTROLADORGESTIONVIAJES_H
#define ICONTROLADORGESTIONVIAJES_H

#include "DTConsultaViaje.h"
#include "DTFecha.h"
#include "DTListarViaje.h"
#include "DTUsuario.h"
#include "DTVehiculosConductor.h"
#include "DTDetalleViaje.h"
#include <set>
#include <string>
#include <vector>

class IControladorGestionViajes {
public:
  // ==========================================
  // CASO DE USO: Alta de Viaje
  // ==========================================
  virtual std::set<DTVehiculosConductor>
  listarVehiculosConductor(std::string nickname) = 0;

  virtual bool altaViaje(std::string matricula, DTFecha fecha,
                         std::string origen, std::string destino, int asientos,
                         float precio) = 0;

  // ==========================================
  // CASO DE USO: Generar Reserva
  // ==========================================
  virtual std::vector<DTConsultaViaje> consultarViajes(DTFecha fecha,
                                                       std::string origen,
                                                       std::string destino,
                                                       int asientos) = 0;

  virtual bool generarReserva(std::string nickname, int codigo,
                              int asientos) = 0;

  // ==========================================
  // CASO DE USO: Calificar Usuario
  // ==========================================
  virtual std::set<DTListarViaje> listarViajes(std::string nickname) = 0;
  virtual std::vector<DTUsuario> listarUsuariosViaje(int codigo) = 0;
  virtual bool calificarUsuario(std::string nicknameCalificado,
                                int calificacion) = 0;

  // ==========================================
  // CASO DE USO: Eliminar Viaje
  // ==========================================
  virtual std::set<DTListarViaje> listarViajes() = 0;
  virtual DTDetalleViaje detalleViaje(int codigo) = 0;
  virtual void eliminarViaje() = 0;
  virtual void cancelarEliminarViaje() = 0;

  virtual ~IControladorGestionViajes() {}
};

#endif