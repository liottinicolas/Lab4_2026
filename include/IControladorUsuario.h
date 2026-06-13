#ifndef ICONTROLADORUSUARIO_H
#define ICONTROLADORUSUARIO_H

#include <set>
#include <string>

#include "DTUsuario.h"
#include "TipoLibreta.h"
#include "TipoVehiculo.h"

using namespace std;

class IControladorUsuario {
public:
  // ==========================================
  // CASO DE USO: Alta de Usuario
  // ==========================================
  virtual bool altaPasajero(string nickname, string nombre, string contrasena,
                            string email, string ci) = 0;

  virtual bool altaConductor(string nickname, string nombre, string contrasena,
                             string email, set<TipoLibreta> libretas) = 0;

  virtual int registrarVehiculo(string nickname, string matricula,
                                int capacidad, string marca, string modelo,
                                TipoVehiculo tipo) = 0;

  // ==========================================
  // CASO DE USO: Generar Reserva
  // ==========================================
  virtual set<string> listarPasajeros() = 0;

  // ==========================================
  // CASO DE USO: Calificar Usuario
  // ==========================================
  virtual set<DTUsuario> listarUsuarios() = 0;

  virtual ~IControladorUsuario() {}
};

#endif