#include "../algoritmos/alggrafoPMC.h"
#include "../algoritmos/grafoPMC.h"
#include "../algoritmos/grafoMA.h"
#include <cmath>
#include <iostream>

using namespace std;

struct Casilla{
    size_t i,j;
    Casilla(size_t i, size_t j): i(i), j(j) {}
};

struct Camino{
    vector<Casilla> camino;
    size_t coste;
    Camino(size_t coste, vector<Casilla> camino): coste(coste), camino(camino) {}
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
Camino laberintoCheckpoint(size_t N, const vector<Pared>& paredes, Casilla checkPoint, Casilla entrada, Casilla salida){
    typename GrafoP<tCoste>::vertice vertice;
    GrafoP<tCoste> Glaberinto(N*N); // como vamos a poner a 1 los que tiene camino vamos a suponer nuestro grafo como size_t

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

    vector<vertice> P, Pinv;
    vector<tCoste> costes = Dijkstra(Glaberinto,CasillaToVertice[entrada], P);
    vector<tCoste> costesInv = DijkstraInv(Glaberinto, CasillaToVertice[destino], Pinv);

    vector<vertice> Camino;

    vertice aux = CasillaToVertice[checkPoint];

    while(aux != entrada){
        camino.insert(verticeToCasilla(aux), camino.begin());
        aux = P[aux];
    }

      vertice aux = checkPoint;
    while(aux != destino){
        camino.insert(verticeToCasilla(aux), camino.begin());
        aux = P[aux];
    }

    Camino result(costes[checkPoint] + costesInv[checkPoint], camino);
    return result;

}


int main(){
    size_t N = 3;
    Casilla origen(0,0);
    vector<Pared> v; 
    Casilla salida(2,2);
    Camino r = laberintoCheckpoint<int>(N,v, Casilla(1,1), origen, salida); 

    cout << "Camino " <<endl;
    for(auto it = r.camino.begin(); it != r.camino.end(); it++){
        cout << it->i << " "<< it->j <<endl;
    }

     cout << "Lon:  " << r.coste <<endl;
}