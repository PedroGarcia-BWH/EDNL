#include <iostream>
#include "../algoritmos/grafoPMC.h"
#include "../algoritmos/alggrafoPMC.h"

using namespace std;
struct casilla {
    size_t i,j;
    casilla(size_t i, size_t j): i(i), j(j) {}
};

//template <typename tCoste>
struct recorrido{
    vector<casilla> camino;
    int longitud;
    recorrido(vector<casilla> camino, int longitud): camino(camino), longitud(longitud) {}
};

struct pared
{
    casilla p1, p2;
};

typename GrafoP<size_t>::vertice casilla_to_vertice(casilla c, size_t N){
    return c.i*N + c.j;
}

casilla vertice_to_casilla(typename GrafoP<size_t>::vertice v, size_t N){
    return casilla(v/N,v%N);
}

bool esAdyacente(casilla c1, casilla c2){
    return (std::abs((double)c1.i-c2.i) + std::abs((double)c1.j - c2.j)) == 1;
}

template <typename tCoste>
recorrido laberinto(size_t N, vector<pared> paredes, casilla entrada, casilla salida){
    GrafoP<tCoste> G(N*N);

    for( typename GrafoP<tCoste>::vertice i=0; i<N*N; i++){
       for(typename GrafoP<tCoste>::vertice j=0; j<N*N; j++){
           if(esAdyacente(vertice_to_casilla(i,N), vertice_to_casilla(j,N))){
               G[i][j] = 1;
           }else{
                G[i][j] = GrafoP<tCoste>::INFINITO; 
           }
       }
       G[i][i] = GrafoP<tCoste>::INFINITO;
    }

    for(auto it = paredes.begin(); it != paredes.end(); it++){
        typename GrafoP<tCoste>::vertice i = casilla_to_vertice(it->p1, N);
         typename GrafoP<tCoste>::vertice j = casilla_to_vertice(it->p2, N);
        G[i][j] = G[j][i] = GrafoP<tCoste>::INFINITO; 
    }

    typename GrafoP<tCoste>::vertice origen = casilla_to_vertice(entrada, N);
    typename GrafoP<tCoste>::vertice destino = casilla_to_vertice(salida, N);
    vector<typename GrafoP<tCoste>::vertice> p;

    vector<tCoste> v = Dijkstra(G,origen,p);
 
    vector<casilla> camino;
    int i = destino;
    while(i != origen){
        camino.insert( camino.begin() ,vertice_to_casilla(p[i], N)); // metemos el camino de ir desde origen hasta p[destino]
        i = p[i];
    }

    recorrido result(camino, v[destino]);
    return result;
}


//comprobacion
int main(){
    size_t N = 3;
    casilla origen(0,0);
    vector<pared> v; 
    casilla salida(2,2);
    recorrido r = laberinto<int>(N,v, origen, salida); 

    cout << "Camino " <<endl;
    for(auto it = r.camino.begin(); it != r.camino.end(); it++){
        cout << it->i << " "<< it->j <<endl;
    }

     cout << "Lon:  " << r.longitud <<endl;
}