#include "../include/ManejadorUsuario.h"

ManejadorUsuario* ManejadorUsuario::instancia = nullptr;

ManejadorUsuario::ManejadorUsuario() {}

ManejadorUsuario* ManejadorUsuario::getInstancia() {

    if (instancia == nullptr) {
        instancia = new ManejadorUsuario();
    }

    return instancia;
}

Usuario* ManejadorUsuario::find(
    std::string nickname
) {

    auto it = usuarios.find(nickname);

    if (it != usuarios.end()) {
        return it->second;
    }

    return nullptr;
}

void ManejadorUsuario::agregarUsuario(
    Usuario* nuevo_usuario
){
    if(nuevo_usuario != nullptr) {
        this->usuarios[nuevo_usuario->getNickname()] = nuevo_usuario;
    }
}

bool ManejadorUsuario::existe(
    std::string nickname
) {
    return usuarios.find(nickname) != usuarios.end();
}

std::map<std::string, Usuario*>
ManejadorUsuario::obtenerUsuarios() {
    return usuarios;
}

ManejadorUsuario::~ManejadorUsuario() {
  for (auto const &par : usuarios) {
    delete par.second;
  }
  usuarios.clear();
  instancia = nullptr;
}