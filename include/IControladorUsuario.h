#ifndef ICONTROLADORUSUARIO_H
#define ICONTROLADORUSUARIO_H

#include <string>
#include <set>

#include "TipoLibreta.h"
#include "TipoVehiculo.h"
#include "DTUsuario.h"

using namespace std;

class IControladorUsuario {
public:

    virtual bool altaPasajero(
        string nickname,
        string nombre,
        string contrasena,
        string email,
        string ci
    ) = 0;

    virtual bool altaConductor(
        string nickname,
        string nombre,
        string contrasena,
        string email,
        set<TipoLibreta> libretas
    ) = 0;

    virtual int registrarVehiculo(
        string nickname,
        string matricula,
        int capacidad,
        string marca,
        string modelo,
        TipoVehiculo tipo
    ) = 0;

    virtual set<DTUsuario> listarUsuarios() = 0;

    virtual void listarVehiculosConductor() = 0;

    virtual set<string> listarPasajeros() = 0;

    virtual ~IControladorUsuario() {}
};

#endif