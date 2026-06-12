#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include "IControladorUsuario.h"
#include "ManejadorUsuario.h"

class ControladorUsuario : public IControladorUsuario {
private:
  ManejadorUsuario *mu;

public:
  ControladorUsuario();

  bool altaPasajero(string nickname, string nombre, string contrasena,
                    string email, string ci);

  bool altaConductor(string nickname, string nombre, string contrasena,
                     string email, set<TipoLibreta> libretas);

  int registrarVehiculo(string nickname, string matricula, int capacidad,
                        string marca, string modelo, TipoVehiculo tipo);

  set<DTUsuario> listarUsuarios();
  set<string> listarPasajeros();
};

#endif