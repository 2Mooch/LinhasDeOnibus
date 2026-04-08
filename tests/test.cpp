#include "../include/RotaOnibus.h"
#include <iostream>

int main() {
    RotaOnibus r;

    r.inserirNoFim("Centro");
    r.inserirNoFim("Shopping");
    r.inserirNoInicio("Garagem");

    r.listarRotaIda();

    std::cout << "Total: " << r.contarParadas() << std::endl;

    return 0;
}
