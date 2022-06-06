#include <iostream>
#include "../algoritmos/grafoPMC.h"
#include <map>
using namespace std;

typedef typename GrafoP<km>::vertice vertice;
typedef double km;
map<vertice,vector<vertice>> sinCapital(vertice capital, GrafoP<km> G){
    vector<vertice> camino(G.numVert());
    map<vertice,vector<vertice>> caminos;
    vector<km> coste(G.numVert());
    for(vertice i = 0; i < G.numVert(); i++){
        coste = DijkstraSinCapital(G, i, camino, capital);
        caminos[i] = camino;
    }

    return caminos;
}


template <typename tCoste>
vector<tCoste> DijkstraSinCapital(const GrafoP<tCoste>& G,
                        typename GrafoP<tCoste>::vertice origen,
                        vector<typename GrafoP<tCoste>::vertice>& P,typename GrafoP<tCoste>::vertice capital )
{
   typedef typename GrafoP<tCoste>::vertice vertice;
   vertice v, w;
   const size_t n = G.numVert();
   vector<bool> S(n, false);                  // Conjunto de vértices vacío.
   vector<tCoste> D;                          // Costes mínimos desde origen.

   // Iniciar D y P con caminos directos desde el vértice origen.
   D = G[origen];
   D[origen] = 0;                             // Coste origen-origen es 0.
   P = vector<vertice>(n, origen);

   // Calcular caminos de coste mínimo hasta cada vértice.
   S[origen] = true;                          // Incluir vértice origen en S.
   for (size_t i = 1; i <= n-2; i++) {
      // Seleccionar vértice w no incluido en S
      // con menor coste desde origen.
      tCoste costeMin = GrafoP<tCoste>::INFINITO;

      if(i != capital){
        for (v = 0; v < n; v++)
         if (!S[v] && D[v] <= costeMin && v != capital) {
            costeMin = D[v];
            w = v;
         }
      }else{
          for (v = 0; v < n; v++)
         if (!S[v] && D[v] <= costeMin && v) { // como sabemos que podemos viajar a la capital directamente cuando le toque ir a la captial si podemos ir
            costeMin = D[v];
            w = v;
         }
      }
      
      S[w] = true;                          // Incluir vértice w en S.
      // Recalcular coste hasta cada v no incluido en S a través de w.
      for (v = 0; v < n; v++)
         if (!S[v]) {
            tCoste Owv = suma(D[w], G[w][v]);
            if (Owv < D[v]) {
               D[v] = Owv;
               P[v] = w;
            }
         }
   }
   return D;
}