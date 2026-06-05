#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "DTFecha.h"

class Usuario;
class Reserva;

class Calificacion {
private:
    DTFecha fecha;
    int puntaje;
    Usuario* calificado;
    Usuario* calificador;
    Reserva* reserva;

public:
    Calificacion(DTFecha fecha, int puntaje, Usuario& calificado, Usuario& calificador, Reserva& r);
    ~Calificacion();

    DTFecha getFecha();
    int getPuntaje();
    Usuario* getCalificador();
    Usuario* getCalificado();
    Reserva* getReserva();
    void setFecha(DTFecha fecha);
    void setPuntaje(int puntaje);
};

#endif
