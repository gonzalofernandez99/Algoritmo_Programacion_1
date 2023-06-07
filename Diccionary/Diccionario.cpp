#include "Diccionario.h"
#include <iostream>

struct NodoLista {
	NodoLista* siguiente;
	// Item
	Clave clave;
	Valor valor;
};

struct Lista {
	NodoLista* primero;
};

struct UndavDiccionario::Diccionario {
	Lista* lista;
};

NodoLista* CrearNodo(Clave clave, Valor valor, NodoLista* siguiente) {
	NodoLista* nuevoNodo = new NodoLista;
	nuevoNodo->clave = clave;
	nuevoNodo->valor = valor;
	nuevoNodo->siguiente = siguiente;

	return nuevoNodo;
}

// O(N)
void UndavDiccionario::Agregar(Diccionario* diccionario, Clave clave, Valor valor) {
	NodoLista* iterador = diccionario->lista->primero;
	bool encontrado = false;
	while (iterador != NULL && !encontrado) {
		if (SonIguales(clave, iterador->clave))
		{
			iterador->valor = valor;
			encontrado = true;
		}
			
		iterador = iterador->siguiente;
	}

	if (!encontrado) {
		diccionario->lista->primero = CrearNodo(clave, valor, diccionario->lista->primero);
	}
}