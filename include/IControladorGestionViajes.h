#ifndef ICONTROLADORGESTIONVIAJES_H
#define ICONTROLADORGESTIONVIAJES_H

#include "DTListarViaje.h"
#include <string>
#include <vector>

class IControladorGestionViajes {
public:
    virtual std::vector<DTListarViaje> listarViajes(std::string nickname) = 0;
    virtual std::vector<DTListarViaje> listarViajes() = 0;

    virtual ~IControladorGestionViajes() {}
    
};

#endif