#include "../include/Usuario.h"

Usuario::Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;
}

std::string Usuario::getNickname(){
    return this->nickname;
}
std::string Usuario::getNombre(){
    return this->nombre;
}
std::string Usuario::getContrasena(){
    return this->contrasena;
}
std::string Usuario::getEmail(){
    return this->email;
}

void Usuario::setNickname(std::string nickname){
    this->nickname = nickname;
}
void Usuario::setNombre(std::string nombre){
    this->nombre = nombre;
}
void Usuario::setContrasena(std::string contrasena){
    this->contrasena = contrasena;
}
void Usuario::setEmail(std::string email){
    this->email = email;
}

Usuario::~Usuario() {}

DTUsuario Usuario::getDTUsuario() {
    return DTUsuario(this->nickname, this->nombre); 
}