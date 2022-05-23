#include <cassert>
#include "grafoPMC.h"       // grafo ponderado
#include <vector>           // para Dijkstra
#include "matriz.h"         // para Floyd
#include "apo.h"            // para Prim y Kruskall
#include "particion.h"      // para Kruskall
#include "alggrafoPMC.h" 

template <typename tCoste>
matriz<tCoste> viajesZuelandia(const GrafoP<tCoste>& G, const std::vector<typename GrafoP<tCoste>::vertice>& ciudadesR, const matriz<bool>& carreterasR, const typename GrafoP<tCoste>::vertice& capital)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    GrafoP<tCoste> costeViajes(G);
    
    //Ciudades cortadas (no hay arcos en esos vÃ©rtices)
    for( vertice i = 0; i < ciudadesR.size(); ++i )
        for( vertice j = 0; j < costeViajes.numVert(); ++j )
        {
            costeViajes[ciudadesR[i]][j] = GrafoP<tCoste>::INFINITO;
            costeViajes[j][ciudadesR[i]] = GrafoP<tCoste>::INFINITO;
        }

    //Carreteras cortadas (se eliminan esos arcos)
    for( vertice i = 0; i < costeViajes.numVert(); ++i )
        for( vertice j = 0; j < costeViajes.numVert(); ++j )
            if( carreterasR[i][j] )
                costeViajes[i][j] = GrafoP<tCoste>::INFINITO;

    //Pasar por la capital es obligatorio (solo se consideran los arcos de ese vÃ©rtice)
    for( vertice i = 0; i < costeViajes.numVert(); ++i )
        if( i != capital )
            for( vertice j = 0; j < costeViajes.numVert(); ++j )
                if( j != capital )
                    costeViajes[i][j] = GrafoP<tCoste>::INFINITO;

    std::vector<vertice> P(costeViajes.numVert());
    std::vector<tCoste> capital_Origen = Dijkstra(costeViajes, capital, P);
    std::vector<tCoste> capital_Destino = DijkstraInv(costeViajes, capital, P);

    for( vertice i = 0; i < costeViajes.numVert(); ++i )
    {
		for( vertice j = 0; j < costeViajes.numVert(); ++j )
			costeViajes[i][j] = suma(capital_Destino[i], capital_Origen[j]);
        costeViajes[i][i] = 0;
    }

    return grafoP_a_matrizCostes(costeViajes);
}