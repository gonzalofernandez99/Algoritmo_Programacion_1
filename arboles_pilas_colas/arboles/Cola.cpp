#include "Cola.h"
#include <iostream>

using UndavCola::Cola;

struct NodoCola{
	void* item;
	NodoCola* siguiente;
};

struct UndavCola::Cola{
	NodoCola* primero;
	NodoCola* ultimo;
};

NodoCola* CrearUltimoNodo(void* item){
	NodoCola* nodo = new NodoCola;
	nodo->item = item;
	nodo->siguiente = NULL;

	return nodo;
}

Cola* UndavCola::Crear(){
	Cola* nuevaCola = new Cola;
	nuevaCola->primero = nuevaCola->ultimo = NULL;

	return nuevaCola;
}

void UndavCola::Encolar(Cola* cola, void* item){
	NodoCola* nuevoUltimo = CrearUltimoNodo(item);
	if(EstaVacia(cola)){
		cola->primero = cola->ultimo = nuevoUltimo;
	}else{
		cola->ultimo->siguiente = nuevoUltimo;
		cola->ultimo = nuevoUltimo;
	}
}

void* UndavCola::Desencolar(Cola* cola){
	void* item = NULL;
	if(!EstaVacia(cola)){
		NodoCola* nodoPrimero = cola->primero;
		item = nodoPrimero->item;
		cola->primero = nodoPrimero->siguiente;
		delete nodoPrimero;
		if(cola->primero == NULL){
			cola->ultimo = cola->primero;
		}
	}

	return item;
}

bool UndavCola::EstaVacia(const Cola* cola){
	return cola->primero == NULL;
}

void UndavCola::Destruir(Cola* cola){
	NodoCola *iterador = cola->primero;
	while (iterador != NULL){
		NodoCola *auxiliar = iterador;
		iterador = iterador->siguiente;
		delete auxiliar;
	}

	delete cola;
}
