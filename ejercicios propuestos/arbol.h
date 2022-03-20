#ifndef _ARBOL_H_
#define _ARBOL_H_
#include <cassert>

//tad arbol binario, que tiene dos hijos por nodo
template <typename T> class Abin
{
		struct celda;//predeclaracion
	public:
		typedef celda* nodo;
		static const nodo NODO_NULO;
		Abin();//Constructor
		void insertarRaiz(const T& e);
		void insertarHijoIzqdo(nodo n, const T& e);
		void insertarHijoDrcho(nodo n, const T& e);
		void eliminarHijoIzqdo(nodo n);
		void eliminarHijoDrcho(nodo n);
		void eliminarRaiz();
		bool arbolVacio() const;
		const T& elemento(nodo n) const;
		T& elemento(nodo n);
		int altura();
		int profundidad(nodo n);
		nodo raiz() const;
		nodo padre(nodo n) const;
		nodo hijoIzqdo(nodo n) const;
		nodo hijoDrcho(nodo n) const;
		Abin(const Abin<T>& arbol);//ctr copia
		Abin<T>& operator =(const Abin<T>& arbol);
		~Abin();//destructor
	private:
		struct celda
		{
			T elto;
			nodo padre, hizq, hder;
			celda(const T& e, nodo p = NODO_NULO): elto(e), padre(p), hizq(NODO_NULO), hder(NODO_NULO){}
		};
		nodo r; //nodo raiz
		void destructor(nodo& n);
		nodo copiar(nodo n);
		int altura_rec(nodo n);
};


template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO(nullptr);

template <typename T>
inline Abin<T>::Abin(): r(NODO_NULO) {}

template <typename T>
inline void Abin<T>::insertarRaiz(const T& e)
{
	assert(r == NODO_NULO);//comprobamos si se cumple la precondicion
	r = new celda(e);
}

template <typename T>
inline void Abin<T>::insertarHijoIzqdo(nodo n, const T& e)
{
	assert(n != NODO_NULO);
	assert(n->hizq == NODO_NULO);

	n->hizq = new celda(e, n);
}

template <typename T>
inline void Abin<T>::insertarHijoDrcho(nodo n, const T& e)
{
	assert(n != NODO_NULO);
	assert(n->hder == NODO_NULO);

	n->hder = new celda(e, n);
}

template <typename T>
inline void Abin<T>::eliminarHijoIzqdo(nodo n)
{
	assert(n != NODO_NULO);
	assert(n->hizq != NODO_NULO);
	//comprobamos que el nodo que vamos a eliminar sea una hoja
	assert(n->hizq->hizq == NODO_NULO and n->hizq->hder == NODO_NULO);

	delete n->hizq;
	n->hizq = NODO_NULO;
}

template <typename T>
inline void Abin<T>::eliminarHijoDrcho(nodo n)
{
	assert(n != NODO_NULO);
	assert(n->hder != NODO_NULO);
	//comprobamos que el nodo que vamos a eliminar sea una hoja
	assert(n->hder->hizq == NODO_NULO and n->hder->hder == NODO_NULO);

	delete n->hder;
	n->hder = NODO_NULO;
}
template <typename T>
inline void Abin<T>::eliminarRaiz()
{
	assert(r != NODO_NULO);
	assert(r->hizq == NODO_NULO and r->hder == NODO_NULO);

	delete r;
	r = NODO_NULO;
}

template <typename T>
inline bool Abin<T>::arbolVacio() const
{
	return (r == NODO_NULO);
}

template <typename T>
inline const T& Abin<T>::elemento(nodo n) const
{
	assert(n != NODO_NULO);
	return n->elto;
}

template <typename T>
T& Abin<T>::elemento(nodo n)
{
	assert(n != NODO_NULO);
	return n->elto;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::raiz() const
{
	return r;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::padre(nodo n) const
{
	assert(n != NODO_NULO);
	return n->padre;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::hijoIzqdo(nodo n) const
{
	assert(n != NODO_NULO);
	return n->hizq;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::hijoDrcho(nodo n) const
{
	assert(n != NODO_NULO);
	return n->hder;
}

template <typename T>
inline Abin<T>::Abin(const Abin<T>& arbol)//ctr copia
{
	r = copiar(arbol.r);
}

template <typename T>
Abin<T>& Abin<T>::operator =(const Abin<T>& arbol)
{
	if(this != &arbol)//evitamos asignacion
	{
		this->~Abin();
		r = copiar(arbol.r);
	}

	return *this;
}

template <typename T>
typename Abin<T>::nodo Abin<T>::copiar(nodo n)
{
	nodo salida = NODO_NULO;

	if(n != NODO_NULO)
	{
		salida = new celda(n->elto);
		salida->hizq = copiar(n->hizq);
		if(salida->hizq != NODO_NULO) salida->hizq->padre = salida;
		salida->hder = copiar(n->hder);
		if(salida->hder != NODO_NULO) salida->hder->padre = salida;
	}
	
	return salida;
}
//preguntar si hay que pasarle el arbol en este caso (no hace falta no lo necesitamos)
template <typename T>
int Abin<T>::altura_rec(nodo n){
	int ramaA = 0; int ramaB= 0;
	if(n == NODO_NULO)
	{
		return -1;
	}else{
		ramaA = 1 + altura_rec(n->hizq);
		ramaB = 1 + altura_rec(n->hder);

		return (ramaA > ramaB) ? ramaA : ramaB;
	}
}

template <typename T>
int Abin<T>::altura(){
	return altura_rec(r);
}

template <typename T>
int Abin<T>::profundidad(nodo n){
	int profundidad = -1;
	while (n != NODO_NULO){
		n = n->padre;
		profundidad++;
	}
	return profundidad;
}

template <typename T>
void Abin<T>::destructor(nodo& n)
{
	if( n != NODO_NULO)
	{
		destructor(n->hizq);
		destructor(n->hder);
		delete n;
		n = NODO_NULO;
	}
}

template <typename T>
Abin<T>::~Abin()//destructor
{
	destructor(r);
}

#endif
/*

#ifndef _ARBOL_H_
#define _ARBOL_H_
#include <cassert>

//tad arbol binario, que tiene dos hijos por nodo
template <typename T> class Abin
{
		struct celda;//predeclaracion
	public:
		typedef celda* nodo;
		static const nodo NODO_NULO;
		Abin();//Constructor
		
		int profundidad(nodo n);
		int altura(nodo n);
		
		
		void insertarRaiz(const T& e);
		void insertarHijoIzqdo(nodo n, const T& e);
		void insertarHijoDrcho(nodo n, const T& e);
		void eliminarHijoIzqdo(nodo n);
		void eliminarHijoDrcho(nodo n);
		void eliminarRaiz();
		bool arbolVacio() const;
		const T& elemento(nodo n) const;
		T& elemento(nodo n);
		nodo raiz() const;
		nodo padre(nodo n) const;
		nodo hijoIzqdo(nodo n) const;
		nodo hijoDrcho(nodo n) const;
		Abin(const Abin<T>& arbol);//ctr copia
		Abin<T>& operator =(const Abin<T>& arbol);
		~Abin();//destructor
	private:
		struct celda
		{
			T elto;
			nodo padre, hizq, hder;
			celda(const T& e, nodo p = NODO_NULO): elto(e), padre(p), hizq(NODO_NULO), hder(NODO_NULO){}
		};
		nodo r; //nodo raiz
		void destructor(nodo& n);
		nodo copiar(nodo n);
};

template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO(nullptr);

template <typename T>
inline Abin<T>::Abin(): r(NODO_NULO) {}

template <typename T>
inline void Abin<T>::insertarRaiz(const T& e)
{
	assert(r == NODO_NULO);//comprobamos si se cumple la precondicion
	r = new celda(e);
}

template <typename T>
inline void Abin<T>::insertarHijoIzqdo(nodo n, const T& e)
{
	assert(n != NODO_NULO);
	assert(n->hizq == NODO_NULO);

	n->hizq = new celda(e, n);
}

template <typename T>
inline void Abin<T>::insertarHijoDrcho(nodo n, const T& e)
{
	assert(n != NODO_NULO);
	assert(n->hder == NODO_NULO);

	n->hder = new celda(e, n);
}

template <typename T>
inline void Abin<T>::eliminarHijoIzqdo(nodo n)
{
	assert(n != NODO_NULO);
	assert(n->hizq != NODO_NULO);
	//comprobamos que el nodo que vamos a eliminar sea una hoja
	assert(n->hizq->hizq == NODO_NULO and n->hizq->hder == NODO_NULO);

	delete n->hizq;
	n->hizq = NODO_NULO;
}

template <typename T>
inline void Abin<T>::eliminarHijoDrcho(nodo n)
{
	assert(n != NODO_NULO);
	assert(n->der != NODO_NULO);
	//comprobamos que el nodo que vamos a eliminar sea una hoja
	assert(n->hder->hizq == NODO_NULO and n->hder->hder == NODO_NULO);

	delete n->hder;
	n->hder = NODO_NULO;
}
template <typename T>
inline void Abin<T>::eliminarRaiz()
{
	assert(r != NODO_NULO);
	assert(r->hizq == NODO_NULO and r->hder == NODO_NULO);

	delete r;
	r = NODO_NULO;
}

template <typename T>
inline bool Abin<T>::arbolVacio() const
{
	return (r == NODO_NULO);
}

template <typename T>
inline const T& Abin<T>::elemento(nodo n) const
{
	assert(n != NODO_NULO);
	return n->elto;
}

template <typename T>
T& Abin<T>::elemento(nodo n)
{
	assert(n != NODO_NULO);
	return n->elto;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::raiz() const
{
	return r;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::padre(nodo n) const
{
	assert(n != NODO_NULO);
	return n->padre;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::hijoIzqdo(nodo n) const
{
	assert(n != NODO_NULO);
	return n->hizq;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::hijoDrcho(nodo n) const
{
	assert(n != NODO_NULO);
	return n->hder;
}

template <typename T>
inline Abin<T>::Abin(const Abin<T>& arbol)//ctr copia
{
	r = copiar(arbol.r);
}

template <typename T>
Abin<T>& Abin<T>::operator =(const Abin<T>& arbol)
{
	if(this != &arbol)//evitamos asignacion
	{
		this->~Abin();
		r = copiar(arbol.r);
	}

	return *this;
} 

template <typename T>
typename Abin<T>::nodo Abin<T>::copiar(nodo n)
{
	nodo salida = NODO_NULO;

	if(n != NODO_NULO)
	{
		salida = new celda(n->elto);
		salida->hizq = copiar(n->hizq);
		if(salida->hizq != NODO_NULO) salida->hizq->padre = salida;
		salida->hder = copiar(n->hder);
		if(salida->hder != NODO_NULO) salida->hder->padre = salida;
	}
	
	return salida;
}

template <typename T>
void Abin<T>::destructor(nodo& n)
{
	if( n != NODO_NULO)
	{
		destructor(n->hizq);
		destructor(n->hder);
		delete n;
		n = NODO_NULO;
	}
}

template <typename T>
int Abin<T>::profundidad(nodo n)
{
	
	if( n != NODO_NULO && n != r )
	{
		return 1 + profundidad(n->padre);
	}

return 0;
}

template <typename T>
int Abin<T>::altura(nodo n)
{
	int ramaA = 0, ramaB = 0;
	
	if( n != NODO_NULO )
	{
	
		ramaA = 1 + altura(n->hizq);
		ramaB = 1 + altura(n->hder);
		
		return (ramaA > ramaB) ? ramaA : ramaB;
	}
			
return -1;
}

template <typename T>
Abin<T>::~Abin()//destructor
{
	destructor(r);
}

#endif
*/