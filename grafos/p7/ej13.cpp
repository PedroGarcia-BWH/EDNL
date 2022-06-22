#include "../algoritmos/grafoPMC.h"
#include "../algoritmos/matriz.h"
#include "../algoritmos/alggrafoPMC.h"
#include <vector>

using namespace std;

template <typename tCoste>
struct puente{
    typedef typename GrafoP<tCoste>::vertice vertice;
    vertice i,j;
    puente(vertice i, vertice j): i(i), j(j) {}
};

template<typename tCoste>
vector<puente<tCoste>> reconstruccionPuentes(const matriz<tCoste>& isla1 , const matriz<tCoste>& isla2, const matriz<tCoste>& isla3 ,const vector<typename GrafoP<tCoste>::vertice>& Isla1Costero,
const vector<typename GrafoP<tCoste>::vertice>& Isla2Costero, const vector<typename GrafoP<tCoste>::vertice>& Isla3Costero){
    typedef typename GrafoP<tCoste>::vertice vertice;

    

}