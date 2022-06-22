#include "../algoritmos/grafoPMC.h"
#include "../algoritmos/matriz.h"
#include "../algoritmos/alggrafoPMC.h"
enum alergico {T, C, A};


typedef double dinero;
typedef typename GrafoP<dinero>::vertice vertice;

vector<vertice> transporte(const GrafoP<dinero>& avion, const GrafoP<dinero>& carretera, const GrafoP<dinero>& tren, vertice salida, dinero saldo, alergico alerg ){
    GrafoP<dinero> t1 (carretera.numVert());
    GrafoP<dinero> t2 (carretera.numVert()); // tienen todos los grafos los mismos numeros de vertices
    
    if(alerg == T){
        t1 = avion;
        t2 = carretera;
    }else if(alerg == C){
        t1 = avion;
        t2 = tren;
    }else if(alerg == A){
       t1 = carretera;
        t2 = tren;
    }

    GrafoP<dinero> costeMin (2 * carretera.numVert());
    
    for(vertice i = 0; i<t1.numVert(); i++){
        for(vertice j = 0; i<t2.numVert(); j++){
            costeMin[i][j] = std::min(t1[i][j], t2[i][j]);
        }
    }
    vector<typename GrafoP<dinero>::vertice> P;
    vector<dinero> costes = Dijkstra(costeMin, salida, P);
    vector<typename GrafoP<dinero>::vertice> cuidades;
    for(vertice i = 0; i < costes.size();i++){
        if(costes[i] <= saldo) cuidades.push_back(i);
    }

    return cuidades;
}