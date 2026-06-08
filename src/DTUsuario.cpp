#include "../include/DTUsuario.h"

DTUsuario::DTUsuario(std::string nickname, std::string nombre) {
  this->nickname = nickname;
  this->nombre = nombre;
}

std::string DTUsuario::getNickname() const { return nickname; }
std::string DTUsuario::getNombre() const { return nombre; }
