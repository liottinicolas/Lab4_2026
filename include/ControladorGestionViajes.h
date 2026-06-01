#ifndef CONTROLADORGESTIONVIAJES_H
#define CONTROLADORGESTIONVIAJES_H

#include "IControladorGestionViajes.h"
#include "DTListarViaje.h"
#include <string>
#include <vector>
#include "ManejadorViaje.h"

class ControladorGestionViajes : public IControladorGestionViajes {
private:
    static ControladorGestionViajes* instancia;
    
    ControladorGestionViajes();

public:
    static ControladorGestionViajes* getInstancia(); 

    std::vector<DTListarViaje> listarViajes(std::string nickname) override;
    std::vector<DTListarViaje> listarViajes() override;
};

#endif