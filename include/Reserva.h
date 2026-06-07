#ifndef RESERVA_H
#define RESERVA_H

#include "DTFecha.h"
#include "DTListarViaje.h"

class Viaje;
class Usuario;
class Pasajero;

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;

    // listarViaje
    Viaje* viaje;
    Pasajero* pasajero;

public:
    Reserva(int asientosReservados, DTFecha fecha);
    ~Reserva();

    int getAsientosReservados();
    void setAsientosReservados(int asientosReservados);

    DTFecha getFecha();
    void setFecha(DTFecha fecha);

    //listarViaje
    void setViaje(Viaje* v);
    Viaje* getViaje();
    DTListarViaje getDTListarViaje();

    //calificarUsuario
    Pasajero* getPasajero();
    void setPasajero(Pasajero* p);
    bool calificarUsRes(Usuario& calificador, Usuario& calificado, int calificacion);
};

#endif
