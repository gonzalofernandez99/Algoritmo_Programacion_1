#include "Cola.h"
#include "Carta.h"
#include <iostream>

using UndavCarta::Carta;

struct NodoCola{
	Carta* item;
	NodoCola* siguiente;
};

struct UndavCola::Cola{
	NodoCola* primero;
	NodoCola* ultimo;
};

UndavCola::Cola* UndavCola::CrearCola(){
	Cola* nuevaCola = new Cola;
	nuevaCola->primero= nuevaCola->ultimo = NULL;
	return nuevaCola;

}

// primero -> 1 -> 2 -> 3  <- ultimo
//                      ↓
//                     NULL


// primero -> NULL <-ultimo
//Encolar(99)
// primero -> 99  <- ultimo
//             ↓
//            NULL

NodoCola* CrearUltimoNodo(Carta* item){
	NodoCola* nodo = new NodoCola;
	nodo->item = item;
	nodo->siguiente = NULL;
	return nodo;
}

void UndavCola::Encolar(Cola* cola, Carta* item){
	NodoCola* nuevoUltimo = CrearUltimoNodo(item);
	if(EstaVacia(cola)){
		cola->primero =nuevoUltimo;
	}else{
		cola->ultimo->siguiente = nuevoUltimo;
	}

	cola->ultimo = nuevoUltimo;
}

// primero -> 1 -> 2 -> 3  <- ultimo
//                      ↓
//                     NULL

// Desencolar
// primero -> 2 -> 3  <- ultimo
//                      ↓
//                     NULL
// return 1
Carta* UndavCola::Desencolar(Cola* cola){
	Carta* primerItem = NULL;
	if(!EstaVacia(cola)){
		NodoCola* primerNodo = cola->primero;
		primerItem = primerNodo->item;
		cola->primero = primerNodo->siguiente;
		if(cola->ultimo == primerNodo){
			cola->ultimo = NULL;
		}

		delete primerNodo;
	}

	return primerItem;
}

bool UndavCola::EstaVacia(const Cola* cola){
	return cola->primero == NULL;

}

void UndavCola::Destruir(Cola* cola){
	NodoCola* iterador = cola->primero;
	while(iterador !=NULL){
		NodoCola* auxiliar = iterador;
		iterador = iterador->siguiente;
		delete auxiliar;
	}
}
