#ifndef DT_USUARIO_H
#define DT_USUARIO_H

#include <iostream>
#include <set>
#include <string>
#include "TipoUsuario.h"

class DTUsuario {
private:
  std::string nickname;
  std::string nombre;
  TipoUsuario tipo;

public:
  DTUsuario(std::string nickname, std::string nombre, TipoUsuario tipo = TipoUsuario::Pasajero);

  std::string getNickname() const;
  std::string getNombre() const;
  TipoUsuario getTipo() const;
  // operador para ordenar en los sets.
  bool operator<(const DTUsuario &other) const;
};

std::ostream &operator<<(std::ostream &os, DTUsuario u);

#endif
