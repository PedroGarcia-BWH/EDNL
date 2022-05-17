#include <cassert>
#include "grafoPMC.h"       // grafo ponderado
#include <vector>           // para Dijkstra
#include "matriz.h"         // para Floyd
#include "apo.h"            // para Prim y Kruskall
#include "particion.h"      // para Kruskall
template <typename T>
bool subvencion(GrafoP<T> G){
    if(G.esDirigido()){
        typedef typename GrafoP<T>::vertice vertice;
        size_t nVertices = G.numVert();

         for (size_t i = 0; i < nVertices; i++){
            
         }

    }else{
        return false; // si no es dirigido no puede ser aciclico asi que no puede devolver true
    }
}

