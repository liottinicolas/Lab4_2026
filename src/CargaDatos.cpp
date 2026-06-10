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
    cu->altaPasajero("pasajero1", "Juan Perez", "pass1234", "juan@mail.com", "1.234.567-8");
    cu->altaPasajero("pasajero2", "Ana Lopez", "pass5678", "ana@mail.com", "8.765.432-1");

    // 3. Alta de Conductores (nickname, nombre, contrasena, email, libretas)
    std::set<TipoLibreta> libretasCarlos = { TipoLibreta::AutoAmateur, TipoLibreta::MotoAmateur };
    cu->altaConductor("chofer1", "Carlos Rodriguez", "passwordCarlos", "carlos@mail.com", libretasCarlos);

    std::set<TipoLibreta> libretasMaria = { TipoLibreta::AutoProfesional };
    cu->altaConductor("chofer2", "Maria Gomez", "passwordMaria", "maria@mail.com", libretasMaria);

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
    
    // --- CASOS DE PRUEBA DE ROBUSTEZ E INTEGRIDAD ---
    std::cout << "\n=== PRUEBAS DE ROBUSTEZ E INTEGRIDAD ===\n";

    // Prueba 1: Nickname repetido (Pasajero)
    bool p1 = cu->altaPasajero("pasajero1", "Otro Juan", "pass12345", "juan2@mail.com", "2.345.678-9");
    std::cout << "Prueba 1: Intentar registrar pasajero con nickname existente ('pasajero1')\n";
    std::cout << "  - Esperado: 0 (false)\n";
    std::cout << "  - Obtenido: " << p1 << " (" << (p1 ? "true" : "false") << ")\n";
    std::cout << "  - Resultado: " << (!p1 ? "[OK]" : "[FALLA]") << "\n\n";

    // Prueba 2: Nickname repetido (Conductor)
    std::set<TipoLibreta> libsDummy = { TipoLibreta::AutoAmateur };
    bool p2 = cu->altaConductor("chofer2", "Otro Chofer", "pass12345", "chofer_otro@mail.com", libsDummy);
    std::cout << "Prueba 2: Intentar registrar conductor con nickname existente ('chofer2')\n";
    std::cout << "  - Esperado: 0 (false)\n";
    std::cout << "  - Obtenido: " << p2 << " (" << (p2 ? "true" : "false") << ")\n";
    std::cout << "  - Resultado: " << (!p2 ? "[OK]" : "[FALLA]") << "\n\n";

    // Prueba 3: Contraseña corta (Pasajero, 7 caracteres)
    bool p3 = cu->altaPasajero("pasajeroNuevo1", "Roberto", "1234567", "roberto@mail.com", "3.456.789-0");
    std::cout << "Prueba 3: Intentar registrar pasajero con contrasena corta (7 caracteres)\n";
    std::cout << "  - Esperado: 0 (false)\n";
    std::cout << "  - Obtenido: " << p3 << " (" << (p3 ? "true" : "false") << ")\n";
    std::cout << "  - Resultado: " << (!p3 ? "[OK]" : "[FALLA]") << "\n\n";

    // Prueba 4: Contraseña corta (Conductor, 5 caracteres)
    bool p4 = cu->altaConductor("choferNuevo1", "Pedro", "12345", "pedro@mail.com", libsDummy);
    std::cout << "Prueba 4: Intentar registrar conductor con contrasena corta (5 caracteres)\n";
    std::cout << "  - Esperado: 0 (false)\n";
    std::cout << "  - Obtenido: " << p4 << " (" << (p4 ? "true" : "false") << ")\n";
    std::cout << "  - Resultado: " << (!p4 ? "[OK]" : "[FALLA]") << "\n\n";

    // Prueba 5: Contraseña válida (8 caracteres)
    bool p5 = cu->altaPasajero("pasajeroNuevo2", "Marta", "12345678", "marta@mail.com", "4.567.890-1");
    std::cout << "Prueba 5: Registrar pasajero con contrasena valida (8 caracteres)\n";
    std::cout << "  - Esperado: 1 (true)\n";
    std::cout << "  - Obtenido: " << p5 << " (" << (p5 ? "true" : "false") << ")\n";
    std::cout << "  - Resultado: " << (p5 ? "[OK]" : "[FALLA]") << "\n\n";

    std::cout << "========================================\n\n";

    // --- PRUEBAS DE ROBUSTEZ PARA registrarVehiculo ---
    std::cout << "=== PRUEBAS DE ROBUSTEZ: registrarVehiculo ===\n";

    // Prueba 6: Matrícula repetida (debe dar -1)
    int rv1 = cu->registrarVehiculo("chofer2", "AAA1234", 4, "Ford", "Fiesta", TipoVehiculo::Auto);
    std::cout << "Prueba 6: Intentar registrar vehiculo con matricula existente ('AAA1234')\n";
    std::cout << "  - Esperado: -1\n";
    std::cout << "  - Obtenido: " << rv1 << "\n";
    std::cout << "  - Resultado: " << (rv1 == -1 ? "[OK]" : "[FALLA]") << "\n\n";

    // Prueba 7: Conductor sin libreta apropiada (debe dar -2)
    int rv2 = cu->registrarVehiculo("chofer2", "DDD1111", 2, "Yamaha", "R3", TipoVehiculo::Moto);
    std::cout << "Prueba 7: Intentar registrar Moto para conductor con libreta solo de Auto ('chofer2')\n";
    std::cout << "  - Esperado: -2\n";
    std::cout << "  - Obtenido: " << rv2 << "\n";
    std::cout << "  - Resultado: " << (rv2 == -2 ? "[OK]" : "[FALLA]") << "\n\n";

    // Prueba 8: Registro exitoso (debe dar 0)
    int rv3 = cu->registrarVehiculo("chofer1", "EEE2222", 2, "Kawasaki", "Ninja", TipoVehiculo::Moto);
    std::cout << "Prueba 8: Registrar Moto para conductor con libreta de Moto ('chofer1')\n";
    std::cout << "  - Esperado: 0\n";
    std::cout << "  - Obtenido: " << rv3 << "\n";
    std::cout << "  - Resultado: " << (rv3 == 0 ? "[OK]" : "[FALLA]") << "\n\n";

    std::cout << "==============================================\n\n";

    // --- PRUEBAS DE ROBUSTEZ PARA altaViaje ---
    std::cout << "=== PRUEBAS DE ROBUSTEZ: altaViaje ===\n";

    // Prueba 9: Asientos > Capacidad (debe dar false)
    bool v1 = cg->altaViaje("AAA1234", DTFecha(25, 6, 2026), "Montevideo", "Punta del Este", 5, 300.0);
    std::cout << "Prueba 9: Intentar registrar viaje con mas asientos (5) que la capacidad del vehiculo ('AAA1234', cap: 4)\n";
    std::cout << "  - Esperado: 0 (false)\n";
    std::cout << "  - Obtenido: " << v1 << " (" << (v1 ? "true" : "false") << ")\n";
    std::cout << "  - Resultado: " << (!v1 ? "[OK]" : "[FALLA]") << "\n\n";

    // Prueba 10: Conductor con viaje en la misma fecha (debe dar false)
    // El conductor de BBB5678 es chofer1, que ya tiene un viaje el 15/6/2026 con el vehiculo AAA1234
    bool v2 = cg->altaViaje("BBB5678", DTFecha(15, 6, 2026), "Montevideo", "Punta del Este", 1, 150.0);
    std::cout << "Prueba 10: Intentar registrar viaje en fecha ocupada (15/6/2026) para el mismo conductor ('chofer1') con otro vehiculo\n";
    std::cout << "  - Esperado: 0 (false)\n";
    std::cout << "  - Obtenido: " << v2 << " (" << (v2 ? "true" : "false") << ")\n";
    std::cout << "  - Resultado: " << (!v2 ? "[OK]" : "[FALLA]") << "\n\n";

    // Prueba 11: Registro exitoso (debe dar true)
    bool v3 = cg->altaViaje("BBB5678", DTFecha(18, 6, 2026), "Montevideo", "Maldonado", 1, 200.0);
    std::cout << "Prueba 11: Registrar viaje exitoso para 'chofer1' usando 'BBB5678' el 18/6/2026\n";
    std::cout << "  - Esperado: 1 (true)\n";
    std::cout << "  - Obtenido: " << v3 << " (" << (v3 ? "true" : "false") << ")\n";
    std::cout << "  - Resultado: " << (v3 ? "[OK]" : "[FALLA]") << "\n\n";

    std::cout << "==============================================\n\n";

    // Mostrar todos los usuarios registrados al final
    std::cout << "=== USUARIOS REGISTRADOS EN EL MANEJADOR ===\n";
    std::set<DTUsuario> todosUsuarios = cu->listarUsuarios();
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    for (const DTUsuario &u : todosUsuarios) {
        std::string tipo = "Desconocido";
        Usuario* user = mu->find(u.getNickname());
        if (dynamic_cast<Conductor*>(user) != nullptr) {
            tipo = "Conductor";
        } else if (dynamic_cast<Pasajero*>(user) != nullptr) {
            tipo = "Pasajero";
        }
        std::cout << "  - Nickname: " << u.getNickname() 
                  << " | Nombre: " << u.getNombre() 
                  << " | Tipo: " << tipo << "\n";
    }
    std::cout << "============================================\n\n";

    // Mostrar todos los vehículos registrados al final
    std::cout << "=== VEHICULOS REGISTRADOS EN EL MANEJADOR ===\n";
    ManejadorVehiculos *mve = ManejadorVehiculos::getInstancia();
    std::map<std::string, Vehiculo *> todosVehiculos = mve->obtenerVehiculos();
    for (auto const &par : todosVehiculos) {
        Vehiculo *v = par.second;
        std::string tipoStr = (v->getTipo() == TipoVehiculo::Auto) ? "Auto" : "Moto";
        std::cout << "  - Matricula: " << v->getMatricula()
                  << " | Marca: " << v->getMarca()
                  << " | Modelo: " << v->getModelo()
                  << " | Capacidad: " << v->getCapacidad()
                  << " | Tipo: " << tipoStr
                  << " | Conductor (Nickname): " << v->getNicknameConductor() << "\n";
    }
    std::cout << "=============================================\n\n";
    
    datosCargados = true;
    std::cout << "Datos cargados exitosamente.\n";
}
