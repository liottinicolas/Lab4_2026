#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include "IControladorUsuario.h"
#include "ManejadorUsuario.h"

class ControladorUsuario : public IControladorUsuario {
private:
  ManejadorUsuario *mu;

public:
  ControladorUsuario();

  // ==========================================
  // CASO DE USO: Alta de Usuario
  // ==========================================
  bool altaPasajero(string nickname, string nombre, string contrasena,
                    string email, string ci) override;

  bool altaConductor(string nickname, string nombre, string contrasena,
                     string email, set<TipoLibreta> libretas) override;

  int registrarVehiculo(string nickname, string matricula, int capacidad,
                        string marca, string modelo, TipoVehiculo tipo) override;

  // ==========================================
  // CASO DE USO: Generar Reserva
  // ==========================================
  set<string> listarPasajeros() override;

  // ==========================================
  // CASO DE USO: Calificar Usuario
  // ==========================================
  set<DTUsuario> listarUsuarios() override;
};

#endif