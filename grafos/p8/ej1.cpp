#include <iostream>
#include "particion.h"
#include "grafoMA.h"
#include "grafoPMC"
#include "matriz.h"
#include "cmath"
using namespace std;

typedef struct{
    double x;
    double y;
}coordenadas;


typedef double tCoste;

double distancia(const coordenadas& c1, const coordenadas& c2){
    return sqrt(pow(c2.x-c1.x,2) + pow(c2.y-c1.y,2));
}
//preguntar a kevin que si pone que nos dan una matriz de adyacencia si es el grafo o una matriz
Particion Tombuctu(const vector<coordenadas>& Ciudades, const Grafo& G, matriz<tCoste>& coste){
    GrafoP<tCoste> costes(Cuidades.size());
    matriz<bool> conexiones = Warshall(G);
    for(int i =0; i< Cuidades.size(); i++){
        for(int j=0; j< Cuidades.size();j++){
            if(conexiones[i][j]) costes[i][j] = distancia(Cuidades[i], Ciudades[j]);
        }
    }
    matriz<typename GrafoP<tcoste>::vertice> P;

    coste = Floyd(costes, P);
    
    Particion islas(Cuidades.size());

    for(int i =0; i< Cuidades.size(); i++){
        for(int j=0; j< Cuidades.size();j++){
            if(conexiones[i][j] && islas.encontrar(i) != islas.encontrar(j) ) islas.unir(islas.encontrar(i), islas.encontrar(j));
        }
    }

    return islas;
}


Particion Tombuctu2(const vector<coordenadas>& Ciudades, const Grafo& G){
    GrafoP<tCoste> costes(Cuidades.size());
    matriz<bool> conexiones = Warshall(G);
    
    Particion islas(Cuidades.size());

    for(int i =0; i< Cuidades.size(); i++){
        for(int j=0; j< Cuidades.size();j++){
            if(conexiones[i][j] && islas.encontrar(i) != islas.encontrar(j) ) islas.unir(islas.encontrar(i), islas.encontrar(j));
        }
    }
    //utilizar kruskal pero añadiendo la restriccion de que no puede ser de la misma particion
    
    return islas;
}




