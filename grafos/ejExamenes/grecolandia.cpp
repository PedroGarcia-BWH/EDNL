#include "../algoritmos/alggrafoPMC.h"
#include "../algoritmos/grafoPMC.h"
#include "../algoritmos/grafoMA.h"
#include <cmath>
#include <iostream>

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


puente construirPuenteGrecolandia(const matriz<bool>& Fobos, const matriz<bool>& Deimos,
const vector<cuidad>& ciudadesFobos, const vector<cuidad>& ciudadesDeimos, const vector<cuidad>& fobosCostero,
const vector<cuidad>& deimosCostero){

    typedef typename GrafoP<tCoste>::vertice vertice;
    GrafoP<tCoste> G(Fobos.dimension() + Deimos.dimension());

     for(vertice i=0; i < Fobos.dimension();i++){
        for(vertice j=0; j < Fobos.dimension(); j++){
            if(Fobos[i][j] == true ) G[i][j] = distanciaEuclidea(ciudadesFobos[i], ciudadesFobos[j]); // si no ponemos nada es porque ya el constructor ha puesto todos en INFINITO
        }
    }


    for(vertice i= Fobos.dimension() ; i < Deimos.dimension()+Fobos.dimension();i++){
        for(vertice j= Fobos.dimension() ; j < Deimos.dimension() + Fobos.dimension(); j++){
            if(Deimos[i][j] == true ) G[i][j] = distanciaEuclidea(ciudadesDeimos[i], ciudadesDeimos[j]); // si no ponemos nada es porque ya el constructor ha puesto todos en INFINITO
        }
    }

    cuidad cFobos, cDeimos;

    tCoste costeMin, costeAux;;
    matriz<tCoste> costes;

    matriz<vertice> P;

    for(int i = 0; i < fobosCostero.size(); i++){
        for(int j = 0; j < deimosCostero.size(); j++){
            if(i == 0 && j == 0){
                cFobos = fobosCostero[i];
                cFobos = deimosCostero[j];
                G[i][j] =  G[j][i] = distanciaEuclidea(fobosCostero[i], deimosCostero[j]);
                costes = Floyd(G, P);
                costeMin = calculoCosteTotal(costes);
            }else{
                if(j != 0){
                    G[i-1][j-1] =  G[j-1][i-1] = GrafoP<tCoste>::INFINITO; // ponemos infinito el puente anterior para ver cual es mejor
                    G[i][j] =  G[j][i] = distanciaEuclidea(fobosCostero[i], deimosCostero[j]);

                    costes = Floyd(G, P);
                    costeAux = calculoCosteTotal(costes);

                    if(costeAux < costeMin){
                        cFobos = fobosCostero[i];
                        cFobos = deimosCostero[j];
                        costeMin = costeAux;
                    }
                }else{
                    G[i-1][deimosCostero.size()-1] =  G[deimosCostero.size()-1][i-1] = GrafoP<tCoste>::INFINITO; // cuando j es 0 el anterior es el i-1 y el ultimo de deimosCostero
                    G[i][j] =  G[j][i] = distanciaEuclidea(fobosCostero[i], deimosCostero[j]);

                    costes = Floyd(G, P);
                    costeAux = calculoCosteTotal(costes);

                    if(costeAux < costeMin){
                        cFobos = fobosCostero[i];
                        cFobos = deimosCostero[j];
                        costeMin = costeAux;
                    }
                }
            }
        }
    }
    puente puent(cFobos, cDeimos);
    return puent;
}

tCoste distanciaEuclidea(cuidad c1, cuidad c2){
    return sqrt(pow(c2.x - c1.x, 2) + pow(c2.y - c1.y, 2));
}

tCoste calculoCosteTotal(const matriz<tCoste>& costes){
    tCoste result = 0;
     for(int i = 0; i < costes.dimension(); i++){
        for(int j = 0; j < costes.dimension(); j++){
            result += costes[i][j];
        }

        return result;
}