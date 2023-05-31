#include <iostream>
#include "Carta.h"
#include "Pila.h"
#include "Cola.h"

using namespace UndavCarta;
using namespace std;
using namespace UndavPila;
using namespace UndavCola;

void Mostrar(const Carta* carta);
void Mostrar(TipoPalo palo);

void LogApilar(Pila* pila, Carta* item);
void LogDesapilar(Pila* pila);

void LogEncolar(Cola* cola, Carta* item);
void LogDesencolar(Cola* cola);

void DestruirCartas(Carta** cartas, int cantidadCartas);
void ProbarPila(Carta** cartas, int cantidadCartas);
void ProbarCola(Carta** cartas, int cantidadCartas);

int main() {
	Carta* cartas[4] = {Crear(2, Oro), Crear(3, Oro), Crear(4, Oro), Crear(5, Oro)};
	ProbarPila(cartas, 4);
	ProbarCola(cartas, 4);

	DestruirCartas(cartas, 4);
	return 0;
}

void LogDesapilar(Pila* pila){
	cout<<"Despilando: ";
	void* item = Desapilar(pila);
	Mostrar((Carta*)item);
	cout<<endl;
}

void LogApilar(Pila* pila, Carta* item){
	cout<<"Apilando: ";
	Mostrar(item);
	cout<<endl;
	Apilar(pila, item);
}

void LogDesencolar(Cola* cola){
	cout<<"Desencolando: ";
	void* item = Desencolar(cola);
	Mostrar((Carta*)item);
	cout<<endl;
}

void LogEncolar(Cola* cola, Carta* item){
	cout<<"Encolando: ";
	Mostrar(item);
	cout<<endl;
	Encolar(cola, item);
}

void Mostrar(const Carta* carta){
	cout<<ObtenerValor(carta)<<" ";
	Mostrar(ObtenerPalo(carta));
}

void Mostrar(TipoPalo palo){
	switch(palo){
		case TipoPalo::Espada:
			cout<<"Espada";
			break;
		case TipoPalo::Oro:
			cout<<"Oro";
			break;
		case TipoPalo::Copa:
			cout<<"Copa";
			break;
		case TipoPalo::Basto:
			cout<<"Basto";
			break;
		default:
			break;
	}
}

void DestruirCartas(Carta** cartas, int cantidadCartas){
	for(int i=0; i < cantidadCartas; ++i){
		UndavCarta::Destruir(cartas[i]);
	}
}

void ProbarPila(Carta** cartas, int cantidadCartas){
	Pila* pilaCartas = Crear();
	// Apilamos las cartas
	for(int i=0; i< cantidadCartas; ++i){
		LogApilar(pilaCartas, cartas[i]);
	}
	// Luego desapilamos todo
	while(!EstaVacia(pilaCartas)){
		LogDesapilar(pilaCartas);
	}

	Destruir(pilaCartas);
}

void ProbarCola(Carta** cartas, int cantidadCartas){
	Cola* colaCartas = CrearCola();
	// Apilamos las cartas
	for(int i=0; i< cantidadCartas; ++i){
		LogEncolar(colaCartas, cartas[i]);
	}
	// Luego desapilamos todo
	while(!EstaVacia(colaCartas)){
		LogDesencolar(colaCartas);
	}

	Destruir(colaCartas);
}
