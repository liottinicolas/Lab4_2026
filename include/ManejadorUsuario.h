#ifndef MANEJADORUSUARIO_H
#define MANEJADORUSUARIO_H

#include <map>
#include <set>
#include <string>


#include "Usuario.h"

using namespace std;

class ManejadorUsuario {
private:
  static ManejadorUsuario *instancia;
  std::map<std::string, Usuario *> usuarios;
  // set(DTUsuario) usuarios;
  ManejadorUsuario();

public:
  Usuario *find(string nickname);
  bool existe(string nickname);
  void agregarUsuario(Usuario *nuevo_usuario);
  bool existeVehiculo(string matricula);
  map<string, Usuario *> obtenerUsuarios();
  static ManejadorUsuario *getInstancia();
};

#endif