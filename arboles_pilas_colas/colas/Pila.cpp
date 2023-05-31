#include "Pila.h"
#include "Carta.h"

#include <iostream>

using UndavCarta::Carta;

struct UndavPila::Pila{
	Carta* *items;
	int cima;
	int capacidad;
	int cantidadItems;
};

UndavPila::Pila* UndavPila::Crear(){
	Pila* nuevaPila=new Pila;
	nuevaPila->cima=-1;
	nuevaPila->cantidadItems = 0;
	nuevaPila->capacidad = 0;
	nuevaPila->items = NULL;

	return nuevaPila;
}

void Redimensionar(UndavPila::Pila* pila, int nuevoTamanio){
	Carta** itemsRedimensionados = new Carta*[nuevoTamanio];
	for(int i=0; i<pila->cantidadItems && i<nuevoTamanio; ++i){
		itemsRedimensionados[i] = pila->items[i];
	}
	if(!EstaVacia(pila)){
		delete []pila->items;
	}

	pila->items = itemsRedimensionados;
	pila->capacidad = nuevoTamanio;
}



//Apilar(40) Apilar(90)
//
//
// 40 <-cima (0)


// AMORTIZED -> AMORTIGUAR
//
//apilar(3)



//




// 10000 -> CAPACIDAD 20000
// DESAPILAR() -> 9999
// CANTIDAD 1 -> 1


//O(N)
// El orden de crecimiento del perod caso -> O(N)
// El orden de crecimiento en promedio -> O(1)
void UndavPila::Apilar(Pila* pila, Carta* item){
	if(pila->cantidadItems + 1 > pila->capacidad){
		Redimensionar(pila, (pila->cantidadItems + 1) * 2);
	}

	pila->items[++(pila->cima)] = item;
	++(pila->cantidadItems);
}

// El orden de crecimiento del perod caso -> O(N)
// El orden de crecimiento en promedio -> O(1)
Carta* UndavPila::Desapilar(Pila* pila){
	Carta* item = NULL;
	if(!EstaVacia(pila)){
		item = pila->items[pila->cima];
		pila->items[pila->cima] = NULL;
		--pila->cima;
		--(pila->cantidadItems);
		if(pila->cantidadItems == pila->capacidad /2){
			Redimensionar(pila, pila->cantidadItems + (pila->cantidadItems/2));
		}
	}

	return item;
}

bool UndavPila::EstaVacia(const Pila* pila){
	return pila->cima == -1;
}

void UndavPila::Destruir(Pila* pila){
 if(pila->capacidad>0){
	 delete []pila->items;
 }
}
