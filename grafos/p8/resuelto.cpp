//Esta pracitca esta pensada para no utilizar dijistra ni floyd aunq se puede se puede utilizar para practicar

//Ejercicio 1
//Si no hay camino es que pertenece a otra isla
//Calculamos con los ejes la distancia a cada uno y luego aplicamos floyd.


//preguntar a kevin en el examen que debemos de implementarle

//Para la distribucion utilizamos la Particion y lo inicializamos con la lista de ciudades

Particion P(N.size());

recorremos toda la matriz, si es distinto de infinito lo metemos en la particiion
 y devolvemos la particion

 //necesitamos definir el struct coordenada, la funcion que calcule la distancia y el de la distribucion N== N cuidades

 Particion Part(N.size());
 int a,b;
for(int i=0; i<N-1;i++){
    a = Part.encontrar(i);
    for(int j=0; j<N.1; j++){
        b = Part.encontrar(j);
        if(M[i][j] != INFINITO AND a!=b){
            Part.unir(a,b);
        }
    }
}

 //-----------------------------
 //ej2

 matriz<tCoste> costeIslas(NCuidades, Infnitio);
 dos bucles anidados que las cuidades que estoy comprobandoo sea de difrentes islas 


//ej6

Grafo <tCoste> G(M.dim())
    for((i=0; i<M.dim(); i++)){
        for(j=0 ; j<M.dim(); j++){
            G[i][j] =  Dist[i][j] * Coste_num - Canal[i][j] * coste_caudal
                    }
    }