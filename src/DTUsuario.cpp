#include "../include/DTUsuario.h"

DTUsuario::DTUsuario(std::string nickname, std::string nombre) {
  this->nickname = nickname;
  this->nombre = nombre;
}

std::string DTUsuario::getNickname() const { return nickname; }
std::string DTUsuario::getNombre() const { return nombre; }
bool DTUsuario::operator<(const DTUsuario &other) const {
  return this->nickname < other.nickname;
}

std::ostream &operator<<(std::ostream &os, DTUsuario u) {
  os << "> Nickname: " << u.getNickname() << ", Nombre: " << u.getNombre();
  return os;
}
