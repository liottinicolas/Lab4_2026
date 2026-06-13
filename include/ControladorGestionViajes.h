#ifndef CONTROLADORGESTIONVIAJES_H
#define CONTROLADORGESTIONVIAJES_H

#include "DTListarViaje.h"
#include "DTVehiculosConductor.h"
#include "IControladorGestionViajes.h"
#include "ManejadorUsuario.h"
#include "ManejadorViaje.h"
#include <string>
#include <vector>

class ControladorGestionViajes : public IControladorGestionViajes {
private:
  ManejadorUsuario *mu;
  ManejadorViaje *mv;
  std::string nicknameActor;
  int codigoActor;

public:
  ControladorGestionViajes();

  // ==========================================
  // CASO DE USO: Alta de Viaje
  // ==========================================
  std::set<DTVehiculosConductor>
  listarVehiculosConductor(std::string nickname) override;

  bool altaViaje(std::string matricula, DTFecha fecha, std::string origen,
                 std::string destino, int asientos, float precio) override;

  // ==========================================
  // CASO DE USO: Generar Reserva
  // ==========================================
  std::vector<DTConsultaViaje> consultarViajes(DTFecha fecha,
                                               std::string origen,
                                               std::string destino,
                                               int asientos) override;

  bool generarReserva(std::string nickname, int codigo, int asientos) override;

  // ==========================================
  // CASO DE USO: Calificar Usuario
  // ==========================================
  std::set<DTListarViaje> listarViajes(std::string nickname) override;
  std::vector<DTUsuario> listarUsuariosViaje(int codigo) override;
  bool calificarUsuario(std::string nicknameCalificado,
                        int calificacion) override;

  // ==========================================
  // CASO DE USO: Eliminar Viaje
  // ==========================================
  std::set<DTListarViaje> listarViajes() override;
  DTDetalleViaje detalleViaje(int codigo) override;
  void eliminarViaje() override;
  void cancelarEliminarViaje() override;
};

#endif