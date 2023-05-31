#ifndef PILA_H_
#define PILA_H_

#include "Carta.h"

using UndavCarta::Carta;
// LIFO Last In First Out
namespace UndavPila{
	struct Pila;
	Pila* Crear();
	// O(1)
	void Apilar(Pila* pila, Carta* item);//Agregar / push
	// O(1)
	Carta* Desapilar(Pila* pila); // Quitar / pop eye
	bool EstaVacia(const Pila* pila);
	void Destruir(Pila* pila);
}

#endif
