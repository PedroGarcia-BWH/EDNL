#include "../algoritmos/alggrafoPMC.h"
#include "../algoritmos/grafoPMC.h"
#include "../algoritmos/grafoMA.h"
#include <cmath>
#include <iostream>

typedef double caudal;

template <typename tCoste>
struct canal{
    tCoste longitud;
    caudal caudal_;
};

template <typename tCoste>
vector<canal<tCoste>> EMASAJER(const matriz<tCoste>& distancias, const matriz<caudal>& caudales, tCoste costeCanal, )