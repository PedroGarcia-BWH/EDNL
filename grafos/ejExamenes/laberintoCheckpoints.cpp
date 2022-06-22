#include "../algoritmos/alggrafoPMC.h"
#include "../algoritmos/grafoPMC.h"
#include "../algoritmos/grafoMA.h"
#include <cmath>
#include <iostream>

using namespace std;

struct Camino{
    vector<Casilla> camino;
    size_t coste;
    Camino(size_t coste, vector<Casilla> camino): coste(coste), camino(camino) {}
};


struct Casilla{
    size_t i,j;
    Casilla(size_t i, size_t j): i(i), j(j) {}
};

struct Pared{
    Casilla c1, c2;
};

Casilla verticeToCasilla(typename GrafoP<size_t>::vertice v, size_t N){
    return Casilla(v/N, v%N);
}

typename GrafoP<size_t>::vertice CasillaToVertice(Casilla c, size_t N){
    return c.i*N + c.j;
}

bool esAdyacente(Casilla c1, Casilla c2){
    return (abs((double)c1.i-c2.i) + abs((double)c1.j - c2.j)) == 1;
}

template <typename tCoste>
Camino laberintoCheckpoint(size_t N, const vector<Pared>& paredes, const vector<Casilla>& checkPoints, Casilla entrada, Casilla salida){
    typename GrafoP<size_t>::vertice vertice;
    GrafoP<int> Glaberinto(N*N); // como vamos a poner a 1 los que tiene camino vamos a suponer nuestro grafo como size_t

    for(vertice i = 0; i < Glaberinto.numVert(); i++){
        for(vertice j = 0; j < Glaberinto.numVert(); j++){
            if(esAdyacente(verticeToCasilla(i,N), verticeToCasilla(j,N))){
                Glaberinto[i][j] = 1;
            }
        }
    }

     for(int i = 0; i < paredes.size(); i++){
        Glaberinto[CasillaToVertice(paredes[i].c1)][CasillaToVertice(paredes[i].c2)] = Glaberinto[CasillaToVertice(paredes[i].c2)][CasillaToVertice(paredes[i].c1)] = GrafoP<size_t>::INFINITO;
    }//Ponemos a infinito para ir de paredes

    matriz<vertice> P;
    matriz<int> costes = Floyd(G, P);

    for(int i = 0; i < checkPoints.size()){

    }

    
}