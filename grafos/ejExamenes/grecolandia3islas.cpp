#include "../algoritmos/alggrafoPMC.h"
#include "../algoritmos/grafoPMC.h"
#include "../algoritmos/grafoMA.h"
#include <cmath>
#include <iostream>


/* Prototipos utilizados
    de la clase GrafoP:
    explicit GrafoP(int n);
    size_t numVert() const;
    const tCoste& operator[] const;
    tCoste& operator[];


    de la clase matriz:
    size_t dimension() const;

    algoritmos
    template <typename tCoste>
    vector<tCoste> Dijkstra(const GrafoP<tCoste>& G, typename GrafoP<tCoste>::vertice origen, vector<GrafoP<tCoste>::vertice>& P);
    
*/


using namespace std;

typedef double tCoste;

//como los costes estan dados por distancia euclidea podemos suponer que las cuidades estan en tipo double
struct puente{
    cuidad cFobos, cDeimos;
    puente(cuidad cFobos, cuidad cDeimos): cFobos(cFobos), cDeimos(cDeimos){}
};

struct cuidad{
    double x,y;
};


vector<puente> construirPuenteGrecolandia(const matriz<bool>& Fobos, const matriz<bool>& Deimos,const matriz<bool>& Teruel,
const vector<cuidad>& ciudadesFobos, const vector<cuidad>& ciudadesDeimos, const vector<cuidad>& ciudadesTeruel, const vector<cuidad>& fobosCostero,
const vector<cuidad>& deimosCostero, const vector<cuidad>& teruelCostero){
    typedef typename GrafoP<tCoste>::vertice vertice;
    GrafoP<tCoste> GFobos(Fobos.dimension());
    GrafoP<tCoste> GDeimos(Deimos.dimension());
    GrafoP<tCoste> GTeruel(Teruel.dimension());
  

    cuidad cuidadFobos, cuidadDeimos, cuidadTeruel;
    
     rellenarGrafo(GFobos,ciudadesFobos, Fobos);// rellenamos los grafos
    rellenarGrafo(GDeimos,ciudadesDeimos, Deimos);
    rellenarGrafo(GTeruel,ciudadesTeruel, Teruel);

    cuidadFobos =  ciudadMinima(GFobos, fobosCostero); // buscamos el camino minimo
    cuidadDeimos =  ciudadMinima(GDeimos, deimosCostero);
    cuidadTeruel =  ciudadMinima(GTeruel, teruelCostero);


    vector<puente> puentes = {puente(cuidadFobos, cuidadDeimos), puente(cuidadFobos, cuidadTeruel)};

     return puentes;

}

void rellenarGrafo(GrafoP<tCoste>& G,const vector<cuidad>& ciudades, const matriz<bool>& camino ){
     typedef typename GrafoP<tCoste>::vertice vertice;
    for(vertice i=0; i<G.numVert();i++){
        for(vertice j = 0; j < G.numVert(); j++){
            if(camino[i][j] == true) G[i][j] = distanciaEuclidea(ciudades[i],ciudades[j]); //rellenamos fobos
        }
    }
}


tCoste distanciaEuclidea(const cuidad& c1, const cuidad& c2){
    return sqrt(pow(c2.x-c1.x, 2) + pow(c2.y-c1.y, 2));
}

tCoste sumaCostesDijkstra(const vector<tCoste>& costes){
    tCoste suma = 0;
      for(int i=1; i<costes.size();i++){
           if(costes[i] != GrafoP<tCoste>::INFINITO) suma += costes[i];
    }

    return suma;
}


cuidad ciudadMinima(const GrafoP<tCoste>& G, const vector<cuidad>& costeros){
      typedef typename GrafoP<tCoste>::vertice vertice;
      vector<vertice> P;

    vector<tCoste> costes = Dijkstra(G, 0, P);
    cuidad ciudadMinima;
    tCoste costeMinimos, costeAux;

    costeMinimos = sumaCostesDijkstra(costes);// sumamos los costes de 0
    ciudadMinima = costeros[0];

    for(int i=1; i<costeros.size();i++){
            costes =  Dijkstra(G, i, P);
            costeAux = sumaCostesDijkstra(costes);
            if(costeAux < costeMinimos){
                costeMinimos = costeAux;
                ciudadMinima = costeros[i];
            }
    }
}