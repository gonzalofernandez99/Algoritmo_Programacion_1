#include <iostream>
#include "Carta.h"
using namespace UndavCarta;
using namespace std;

typedef Carta* Item;
#define Clave(item) (ObtenerValorTruco(item))
#define EsMenor(itemA, itemB) (Clave(itemA)<Clave(itemB))
#define EsMayor(itemA, itemB) (Clave(itemA)>Clave(itemB))
#define Intercambiar(itemA, itemB) {Item aux = itemA; itemA = itemB; itemB = aux;}
#define SiEsMayorIntercambiar(itemA, itemB) {if(!EsMenor(itemA,itemB)) Intercambiar(itemA,itemB)}
#define SiEsMenorIntercambiar(itemA, itemB) {if(EsMenor(itemA,itemB)) Intercambiar(itemA,itemB)}

void Ordenar(Item items[], int indiceComienzo, int indiceFin);
void Mostrar(Item items[], int cantidad);

void Mostrar(const Carta* carta);
void Mostrar(TipoPalo palo);

// Funciones sobre el tipo Cartas Truco
Carta** CrearCartasTruco();
void DestruirCartasTruco(Carta** cartasTruco);

enum EscalaValoresTruco{CUATROS = 0, CINCOS, SEIS, SIETE_FALSOS, SOTAS, CABALLOS, REYES, UNOS_FALSOS, DOS, TRES, SIETE_ORO, SIETE_ESPADA, ANCHO_BASTO, ANCHO_ESPADA};
// Funciones para establecer la clave de deordenamiento
EscalaValoresTruco  ObtenerValorTruco(Carta* carta);
bool EsSieteFalso(TipoPalo palo);
bool EsAnchoFalso(TipoPalo palo);

int main() {
	Item* itemsPrueba=CrearCartasTruco();
	Mostrar(itemsPrueba, 40);
	Ordenar(itemsPrueba, 0, 39);
	cout<<endl;
	Mostrar(itemsPrueba, 40);
	DestruirCartasTruco(itemsPrueba);
	return 0;
}

// Implementacion del bubble sort que analizaremos mas adelante
void Ordenar(Item items[], int indiceComienzo, int indiceFin)
{
    for(int i=indiceComienzo; i <=indiceFin; ++i)
    {
        for(int j=indiceComienzo; j <indiceFin-i; j++)
        {
            if(EsMayor(items[j], items[j+1]))
            {
                Intercambiar(items[j], items[j+1]);
            }
        }
    }
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

void Mostrar(Item items[], int cantidad){
	for(int i=0; i<cantidad;++i){
		Mostrar(items[i]);
		cout<<" ";
	}
	cout<<endl;
}

void DestruirCartasTruco(Carta** cartasTruco){
	for(int i=0; i<40;++i){
		UndavCarta::Destruir(cartasTruco[i]);
	}
	delete []cartasTruco;
}

EscalaValoresTruco  ObtenerValorTruco(Carta* carta){
	EscalaValoresTruco valor;
	TipoPalo palo = ObtenerPalo(carta);
	switch(ObtenerValor(carta)){
		case 4:
			valor = EscalaValoresTruco::CUATROS;
			break;
		case 5:
			valor = EscalaValoresTruco::CINCOS;
			break;
		case 6:
			valor = EscalaValoresTruco::SEIS;
			break;
		case 7:
		if (EsSieteFalso(palo))
				valor = EscalaValoresTruco::SIETE_FALSOS;
			else
				valor = palo == TipoPalo::Oro ? EscalaValoresTruco::SIETE_ORO : EscalaValoresTruco::SIETE_ESPADA;
			break;
		case 10:
			valor = EscalaValoresTruco::SOTAS;
			break;
		case 11:
			valor = EscalaValoresTruco::CABALLOS;
			break;
		case 12:
			valor = EscalaValoresTruco::REYES;
			break;
		case 1:
		if (EsAnchoFalso(palo))
				valor = EscalaValoresTruco::UNOS_FALSOS;
			else
				valor = palo == TipoPalo::Basto ? EscalaValoresTruco::ANCHO_BASTO : EscalaValoresTruco::ANCHO_ESPADA;
			break;
		case 2:
			valor = EscalaValoresTruco::DOS;
			break;
		case 3:
			valor = EscalaValoresTruco::TRES;
			break;
	}

	return valor;
}

bool EsSieteFalso(TipoPalo palo) {
	return palo == TipoPalo::Basto || palo == TipoPalo::Copa;
}

bool EsAnchoFalso(TipoPalo palo) {
	return palo == TipoPalo::Oro || palo == TipoPalo::Copa;
}

void AgregarRangoCartas(Item* mazo, int comienzo, int fin){
	for(int numeroCarta = comienzo, posicionEnMazo=0; numeroCarta <= fin; ++numeroCarta)
	{
		for(int tipoPalo=0; tipoPalo<4;++tipoPalo, ++posicionEnMazo){
			Item carta = UndavCarta::Crear(numeroCarta, (UndavCarta::TipoPalo)tipoPalo);
			mazo[posicionEnMazo]=carta;
		}
	}
}

Carta** CrearCartasTruco(){
	Item* mazo = new Item[40];
	AgregarRangoCartas(mazo, 1, 7);
	AgregarRangoCartas(&mazo[28], 10, 12);

	return mazo;
}
