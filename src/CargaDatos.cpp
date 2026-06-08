#include "../include/CargaDatos.h"
#include "../include/Fabrica.h"
#include "../include/TipoLibreta.h"
#include "../include/TipoVehiculo.h"
#include <iostream>

CargaDatos* CargaDatos::instancia = nullptr;

CargaDatos::CargaDatos() {
    datosCargados = false;
}

CargaDatos* CargaDatos::getInstance() {
    if (instancia == nullptr) {
        instancia = new CargaDatos();
    }
    return instancia;
}

void CargaDatos::cargarDatos() {
    if (datosCargados) {
        std::cout << "Error: Los datos ya han sido cargados anteriormente.\n";
        return;
    }
    
    std::cout << "Cargando datos harcodeados del sistema...\n";
    
    Fabrica* f = Fabrica::getInstance();
    IControladorUsuario* cu = f->getIControladorUsuario();
    IControladorGestionViajes* cg = f->getIControladorGestionViajes();
    IControladorFechaActual* cfa = f->getIControladorFechaActual();

    // 1. Establecer la fecha actual del sistema
    cfa->setFecha(DTFecha(8, 6, 2026));

    // 2. Alta de Pasajeros (nickname, nombre, contrasena, email, CI)
    cu->altaPasajero("pasajero1", "Juan Perez", "123", "juan@mail.com", "1.234.567-8");
    cu->altaPasajero("pasajero2", "Ana Lopez", "456", "ana@mail.com", "8.765.432-1");

    // 3. Alta de Conductores (nickname, nombre, contrasena, email, libretas)
    std::set<TipoLibreta> libretasCarlos = { TipoLibreta::AutoAmateur, TipoLibreta::MotoAmateur };
    cu->altaConductor("chofer1", "Carlos Rodriguez", "pwd", "carlos@mail.com", libretasCarlos);

    std::set<TipoLibreta> libretasMaria = { TipoLibreta::AutoProfesional };
    cu->altaConductor("chofer2", "Maria Gomez", "pwd2", "maria@mail.com", libretasMaria);

    // 4. Registrar Vehículos (nicknameConductor, matricula, capacidad, marca, modelo, tipoVehiculo)
    cu->registrarVehiculo("chofer1", "AAA1234", 4, "Chevrolet", "Onix", TipoVehiculo::Auto);
    cu->registrarVehiculo("chofer1", "BBB5678", 2, "Honda", "CB250", TipoVehiculo::Moto);
    cu->registrarVehiculo("chofer2", "CCC9999", 5, "Toyota", "Corolla", TipoVehiculo::Auto);

    // 5. Alta de Viajes (matricula, fecha, origen, destino, asientos, precio)
    cg->altaViaje("AAA1234", DTFecha(15, 6, 2026), "Montevideo", "Punta del Este", 3, 350.0);
    cg->altaViaje("CCC9999", DTFecha(20, 6, 2026), "Salto", "Montevideo", 4, 800.0);

    // 6. Generar Reservas (nicknamePasajero, codigoViaje, asientosReservados)
    cg->generarReserva("pasajero1", 1, 1);
    cg->generarReserva("pasajero2", 1, 2);
    
    datosCargados = true;
    std::cout << "Datos cargados exitosamente.\n";
}
