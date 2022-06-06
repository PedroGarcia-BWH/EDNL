#include "../algoritmos/alggrafoPMC.h"
#include "../algoritmos/grafoPMC.h"
#include <iostream>

typedef int vertice;

int pedido(vertice i) {}
//asumiremos q la capacidad es entera y no negativa
//como no tenemos donde esta el almacen y suponemos que empezamos en el  suponemos que es el primer vertice
template <typename tCoste>
tCoste reparto(const GrafoP<tCoste>& G, size_t capacidadCamion){
    vertice situacionActual = 0;
    vertice almacen = 0;
    vertice repartoProx;
    size_t capacidadAct = capacidadCamion;
    tCoste distanciaTotal = 0;
    matriz<tCoste> costes = Floyd(G);

    vector<bool> verticesRepartidos(G.numVert(), false);
    
    verticesRepartidos[0] = true; // el almacen no lo contamos como repartido

    while(!finReparto(verticesRepartidos)){
        repartoProx = proxReparto(situacionActual);
        if( capacidadAct < pedido(repartoProx)){
            distanciaTotal += costes[situacionActual][repartoProx];
            situacionActual = repartoProx; // ahora estamos en la ubicacion de reparto
            distanciaTotal += costes[situacionActual][almacen];
            situacionActual = almacen; // hemos descargado y hemos vuelto al almacen 
            capacidadAct = capacidadCamion; // rellenamos la capacidad del camion
        }else{
            distanciaTotal += costes[situacionActual][repartoProx];
            situacionActual = repartoProx;  // estamos en el reparto el cual tenemos cajas suficientes
            capacidadAct -= pedido(repartoProx);

            verticesRepartidos[situacionActual] = true;
            if(capacidadAct == 0){
                distanciaTotal += costes[situacionActual][almacen];
                situacionActual = almacen; // nos hemos quedado sin cajas y volvemos al almacen
                capacidadAct = capacidadCamion; // rellenamos la capacidad del camion
            }
        }
    }
}

template <typename tCoste>
vertice proxReparto(vertice actual, const vector<bool>& verticesRepartidos, const matriz<tCoste>& costes){
        vertice min = GrafoP<tCoste>::INFINITO;// podriamos iniciarlo entre infinito y cero ya que no tendria sentido que la distancia fuera negativa
        for(vertice i = 0; i < verticesRepartidos.size(); i++){
            if(verticesRepartidos[i] == false) min = std::min(min, costes[actual][i]); // mientras que ese vertice no este ya repartido guardamos el minimo desde donde estamos a cualquiera de las posiciones
        }

        return min;
}

//vericamos si esta repartido todo
bool finReparto(const vector<bool>& verticesRepartidos){
    for(auto it = verticesRepartidos.begin(); it != verticesRepartidos.end(); it++){
        if( *it == false) return false;
    }

    return true;
}

