#ifndef RESERVA_H
#define RESERVA_H

#include "DTFecha.h"
#include "DTListarViaje.h"

class Viaje;

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;

    // listarViaje
    Viaje* viaje;

public:
    Reserva(int asientosReservados, DTFecha fecha);
    ~Reserva();

    //listarViaje
    void setViaje(Viaje* v);
    DTListarViaje getDTListarViaje();
};

#endif
