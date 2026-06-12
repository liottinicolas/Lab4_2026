#include "../include/CargaDatos.h"
#include "../include/Fabrica.h"
#include "../include/TipoLibreta.h"
#include "../include/TipoVehiculo.h"
#include "../include/ManejadorUsuario.h"
#include "../include/Conductor.h"
#include "../include/Pasajero.h"
#include "../include/ManejadorVehiculos.h"
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
    cu->altaPasajero("santi_90", "Santiago Acosta", "sacosta90", "santiago.acosta@gmail.com", "1.492.304-2");
    cu->altaPasajero("mari_b", "Maria Noel Barreto", "maribarreto", "mari.barreto@outlook.com", "4.103.859-1");
    cu->altaPasajero("nacho_f", "Ignacio Figueroa", "ifigueroa26", "ignacio.figueroa@fing.edu.uy", "3.847.112-5");
    cu->altaPasajero("valen_uy", "Valentina Mendez", "vmendezQ2", "valen.mendez@fing.edu.uy", "2.956.403-6");
    cu->altaPasajero("joaco_r", "Joaquin Rivero", "jrivero99x", "joaquin_rivero@hotmail.com", "5.021.784-3");

    // 3. Alta de Conductores (nickname, nombre, contrasena, email, libretas)
    std::set<TipoLibreta> libretasMatias = { TipoLibreta::AutoAmateur };
    cu->altaConductor("matil92", "Matias Lopez", "m4t14s92", "matias.lopez.92@gmail.com", libretasMatias);

    std::set<TipoLibreta> libretasAna = { TipoLibreta::AutoProfesional };
    cu->altaConductor("ana_silva", "Ana Silva", "asilva2026", "anasilva.m@outlook.com", libretasAna);

    std::set<TipoLibreta> libretasDiego = { TipoLibreta::MotoAmateur };
    cu->altaConductor("greg_m", "Diego Rodriguez", "drodriguez88", "diegorodiguez@fing.edu.uy", libretasDiego);

    std::set<TipoLibreta> libretasLaura = { TipoLibreta::MotoProfesional };
    cu->altaConductor("lau_vaz", "Laura Vazquez", "lvazquezQ7", "laura.vazquez@fing.edu.uy", libretasLaura);

    std::set<TipoLibreta> libretasCarlos = { TipoLibreta::AutoProfesional, TipoLibreta::MotoAmateur };
    cu->altaConductor("carlos_r", "Carlos Rossi", "crossi99x", "carlos.rossi.uy@gmail.com", libretasCarlos);

    // 4. Registrar Vehículos (nicknameConductor, matricula, capacidad, marca, modelo, tipoVehiculo)
    cu->registrarVehiculo("matil92", "ABJ4586", 4, "Chevrolet", "Onix", TipoVehiculo::Auto);
    cu->registrarVehiculo("matil92", "ACM4455", 6, "Toyota", "Rush", TipoVehiculo::Auto);
    cu->registrarVehiculo("ana_silva", "BAS7895", 4, "Fiat", "Argo", TipoVehiculo::Auto);
    cu->registrarVehiculo("ana_silva", "BCS4105", 9, "Hyundai", "H1", TipoVehiculo::Auto);
    cu->registrarVehiculo("greg_m", "LDA4875", 1, "Honda", "CB Twis", TipoVehiculo::Moto);
    cu->registrarVehiculo("lau_vaz", "PDB1205", 1, "Yumbo", "Max 110", TipoVehiculo::Moto);
    cu->registrarVehiculo("carlos_r", "SBJ4874", 4, "Volkswagen", "Gol", TipoVehiculo::Auto);
    cu->registrarVehiculo("carlos_r", "SCF2469", 1, "Yamaha", "FZ S", TipoVehiculo::Moto);
    
    // 5. Alta de Viajes (matricula, fecha, origen, destino, asientos, precio)
    cg->altaViaje("ABJ4586", DTFecha(21, 10, 2026), "montevideo", "mercedes", 4, 200.0);
    cg->altaViaje("ACM4455", DTFecha(20, 10, 2026), "young", "montevideo", 5, 250.0);
    cg->altaViaje("BAS7895", DTFecha(20, 10, 2026), "young", "montevideo", 4, 200.0);
    cg->altaViaje("BCS4105", DTFecha(21, 10, 2026), "montevideo", "mercedes", 9, 200.0);
    cg->altaViaje("LDA4875", DTFecha(21, 10, 2026), "montevideo", "mercedes", 1, 300.0);
    cg->altaViaje("PDB1205", DTFecha(21, 10, 2026), "montevideo", "mercedes", 1, 350.0);
    cg->altaViaje("SBJ4874", DTFecha(21, 10, 2026), "montevideo", "mercedes", 4, 260.0);
    cg->altaViaje("SCF2469", DTFecha(20, 10, 2026), "montevideo", "cerro chato", 1, 150.0);
    cg->altaViaje("ABJ4586", DTFecha(15, 3, 2026), "montevideo", "colonia", 4, 140.0);
    cg->altaViaje("BCS4105", DTFecha(15, 3, 2026), "montevideo", "colonia", 9, 180.0);
    cg->altaViaje("SBJ4874", DTFecha(15, 3, 2026), "montevideo", "colonia", 1, 100.0);
    cg->altaViaje("SBJ4874", DTFecha(14, 3, 2026), "montevideo", "colonia", 4, 600.0);
    cg->altaViaje("LDA4875", DTFecha(20, 10, 2026), "young", "montevideo", 1, 250.0);
    
    // 6. Generar Reservas (nicknamePasajero, codigoViaje, asientosReservados)
    // Reservas de fecha 13/3/2026
    cfa->setFecha(DTFecha(13, 3, 2026));
    cg->generarReserva("mari_b", 12, 1);
    cg->generarReserva("nacho_f", 12, 1);
    cg->generarReserva("nacho_f", 9, 1);

    // Reservas de fecha 14/3/2026
    cfa->setFecha(DTFecha(14, 3, 2026));
    cg->generarReserva("santi_90", 9, 2);
    cg->generarReserva("mari_b", 9, 1);
    cg->generarReserva("nacho_f", 10, 5);
    cg->generarReserva("valen_uy", 10, 3);
    cg->generarReserva("joaco_r", 10, 1);

    // Reservas de fecha 1/6/2026
    cfa->setFecha(DTFecha(1, 6, 2026));
    cg->generarReserva("mari_b", 1, 2);

    // Restablecer la fecha actual a la original (8/6/2026)
    cfa->setFecha(DTFecha(8, 6, 2026));

    // 7. Calificaciones (nicknameCalificador, codigoViaje, nicknameCalificado, calificacion)
    cg->listarViajes("santi_90");
    cg->listarUsuariosViaje(9);
    cg->calificarUsuario("matil92", 4);

    cg->listarViajes("mari_b");
    cg->listarUsuariosViaje(9);
    cg->calificarUsuario("matil92", 4);

    cg->listarViajes("matil92");
    cg->listarUsuariosViaje(9);
    cg->calificarUsuario("mari_b", 3);

    cg->listarViajes("ana_silva");
    cg->listarUsuariosViaje(10);
    cg->calificarUsuario("valen_uy", 5);

    cg->listarViajes("ana_silva");
    cg->listarUsuariosViaje(10);
    cg->calificarUsuario("joaco_r", 5);

    cg->listarViajes("mari_b");
    cg->listarUsuariosViaje(12);
    cg->calificarUsuario("carlos_r", 5);

    cg->listarViajes("carlos_r");
    cg->listarUsuariosViaje(12);
    cg->calificarUsuario("nacho_f", 5);
    
    datosCargados = true;
    std::cout << "Datos cargados exitosamente.\n";
}

CargaDatos::~CargaDatos() {
    instancia = nullptr;
}
