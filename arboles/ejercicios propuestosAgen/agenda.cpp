#include "abb.h"
#include <iostream>
using namespace std;

typedef struct {
    string nombre;
    size_t numero;
    friend bool operator <(const agend& A, const agend& B);
    friend bool operator >(const agend& A, const agend& B);
}agend;

bool operator <(const agend& A, const agend& B){
    if(A.numero < B.numero) return true;
    else return false;
}
bool operator >(const agend& A, const agend& B){
    if(A < B) return false;
    else return true;
}


int main(){
    Abb<agend> Agenda;
    
}//PReguntar q que hay que hacer en este ejercicio