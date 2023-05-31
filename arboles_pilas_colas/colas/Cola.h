#ifndef COLA_H_
#define COLA_H_

#include "Carta.h"

using UndavCarta::Carta;
//FIFO
namespace UndavCola{
	struct Cola;
	Cola* CrearCola();
	//O(1)
	void Encolar(Cola* cola, Carta* item);
	//O(1)
	Carta* Desencolar(Cola* cola);
	Carta* ObtenerItem(Cola* cola);
	bool EstaVacia(const Cola* cola);
	void Destruir(Cola* cola);
}

#endif
