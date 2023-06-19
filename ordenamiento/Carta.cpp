#include "Carta.h"
#include <iostream>
using UndavCarta::Carta;
using UndavCarta::TipoPalo;
using std::cout;

struct UndavCarta::Carta{
	int valor;
	TipoPalo palo;
};

Carta* UndavCarta::Crear(int valor, TipoPalo palo){
	Carta* cartaNueva = NULL;
	if(valor >=1 && valor <=12){
		cartaNueva = new Carta;
		cartaNueva->palo = palo;
		cartaNueva->valor = valor;
	}

	return cartaNueva;
}


int UndavCarta::ObtenerValor(const Carta* carta){
	return carta->valor;
}

TipoPalo UndavCarta::ObtenerPalo(const Carta* carta){
	return carta->palo;
}

void UndavCarta::Destruir(Carta* carta){
	if(carta!=NULL){
		delete carta;
	}
}
