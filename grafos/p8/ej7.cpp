#include <vector>
#include "../algoritmos/grafoPMC.h"
#include <cmath>

using namespace std;
struct ciudad{
    double x,y;
};

double distancia (const ciudad& c1, const ciudad& c2){
     return sqrt(pow(c2.x-c1.x,2) + pow(c2.y-c1.y,2));
}


double reconstruccion(const vector<ciudad>& Fobos, const vector<ciudad>& Deimos, const vector<ciudad>& FobosCostera, const vector<ciudad>& DeimosCosteras, const ciudad& origen, const ciudad& destino){
    GrafoP<double> fobos(Fobos.size());
    GrafoP<double> deimos(Deimos.size());
    GrafoP<double> archipielago(Deimos.size() + Fobos.size());


    typedef typename GrafoP<double>::vertice vertice;
    for(vertice i = 0; i< Fobos.size(); i++){
         for(vertice j = 0; j< Fobos.size(); j++){
             fobos[i][j] = fobos[j][i] = distancia(Fobos[i], Fobos[j]);
       }
    }

    fobos = kruskal(fobos); // reconstruimos fobos con los caminos minimos metiendolo en fobos

    for(vertice i = 0; i< Deimos.size(); i++){
        for(vertice j = 0; j< Deimos.size(); j++)
        {
            deimos[i][j] = deimos[j][i] = distancia(Deimos[i], Deimos[j]);
        }
    }

    deimos = kruskal(deimos); // reconstruimos deimos con los caminos minimos metiendolo en deimos

    archipielago = fobos;

    vector<ciudad> allCiudades = Fobos;

    for(auto it = Deimos.begin(); it != Deimos.end(); it++){
        allCiudades.push_back(*it);
    }

    for(vertice i = Fobos.size(); i< allCiudades.size(); i++){
        for(vertice j = Fobos.size(); j< allCiudades.size(); j++)
        {
            archipielago[i][j] = archipielago[j][i] = deimos[i][j]; // MIRAR ESTO PQ NO ESTOY MUY CONVENCIDO
        }
    }

    archipielago = kruskal(archipielago);
    vector<vertice> v;
    vector<double> coste;
    int *p = find(allCiudades.begin(), allCiudades.end(), origen);// aqui hay que hacer un encontrar y asi poder encontrar en que posicion esta el elemento
    vertice origenVert = *p;
    *p = find(allCiudades.begin(), allCiudades.end(), destino);
    vertice destinoVert = *p;


    coste = dijsktra(archipielago, origen, v);
    return coste[destino];
}
