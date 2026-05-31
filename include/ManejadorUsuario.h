#ifndef MANEJADORUSUARIO_H
#define MANEJADORUSUARIO_H

#include <map>
#include <string>
#include <set>

#include "Usuario.h"

using namespace std;

class ManejadorUsuario {
private:
    static ManejadorUsuario* instancia;
    set(DTUsuario) usuarios;
    ManejadorUsuario();

public:
    Usuario* find(string nickname);
    bool existe(string nickname);    
    bool existeVehiculo(string matricula);
    map<string, Usuario*> obtenerUsuarios();
    static ManejadorUsuario* getInstancia();
};

#endif