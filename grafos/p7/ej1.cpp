#include "../algoritmos/grafoPMC.h"
#include "../algoritmos/matriz.h"

template <typename tCoste>
struct presupuesto{
    typedef typename GrafoP<tCoste>::vertice;
    tCoste coste;
    vertice origen, destino;
    presupuesto(tCoste coste, vertice origen, vertice destino): coste(coste), origen(origen), vertice(vertice); 
};

template <typename tCoste>
presupuesto<tCoste> clienteRico(const matriz<tCoste>& costes){
    
}

