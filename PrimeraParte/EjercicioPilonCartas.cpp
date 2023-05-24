#include <iostream>
#include <cassert>
using namespace std;

const int CARTASTRUCO = 40;
enum TipoPalo{ORO,COPA,ESPADA,BASTO};


struct Carta {
    int valor;
    TipoPalo palo;
};

struct PilonCartas {
    int cantidadCartas;
    Carta** cartas;
};


Carta* CrearCarta(int valor, TipoPalo palo);

PilonCartas* CrearPilonVacio();

PilonCartas* CrearPilonParaTruco();

void Mostrar(const Carta* carta);
void Mostrar(const PilonCartas* pilon);
void Destruir(PilonCartas* pilon);

int main(int argc, char const *argv[])
{
    PilonCartas* cartasTruco = CrearPilonParaTruco();
    Mostrar(cartasTruco);
    //Destruir(cartasTruco);
    

    return 0;
}

PilonCartas* CrearPilonVacio() {
    PilonCartas* nuevoPilon = new PilonCartas;
    nuevoPilon->cantidadCartas = 0;

    
    return nuevoPilon;
}


Carta* CrearCarta(int valor, TipoPalo palo) {
    Carta* nuevaCarta = new Carta;
    nuevaCarta->valor = valor;
    nuevaCarta->palo = palo;
    
    return nuevaCarta;
}

void Mostrar(const Carta* carta) {
    cout << carta->valor << " ";
    switch (carta->palo)
    {
        case ESPADA:
            cout << "ESPADA";break;

        case ORO:
            cout << "ORO";break;

        case BASTO:
            cout << "BASTO";break;

        case COPA:
            cout << "COPA";break;

    default:
        break;
    }

    cout << " " << endl;
}


PilonCartas* CrearPilonParaTruco() {
    PilonCartas* nuevoPilon = new PilonCartas;
    nuevoPilon->cantidadCartas = CARTASTRUCO;
    nuevoPilon->cartas = new Carta * [CARTASTRUCO];
    int indicePalo = 0;
    // Cargamos primero espadas
    for (int valorCarta = 1,indiceCarta = 0;
        indiceCarta < CARTASTRUCO;++indiceCarta) {
        if (valorCarta == 8 or valorCarta == 9)
        {
            indiceCarta--;
            valorCarta++;
        }else
        {
            nuevoPilon->cartas[indiceCarta] = CrearCarta(valorCarta++, TipoPalo(indicePalo));
        }
        if (valorCarta == 13)
        {
            valorCarta = 1;
            indicePalo++;
        }
        
        
        
    }

    return nuevoPilon;
}

 void Mostrar(const PilonCartas* pilon) {
    for (int i = 0; i < pilon->cantidadCartas;++i) {
        Mostrar(pilon->cartas[i]);
    }
}

void Destruir(PilonCartas* pilon) {
    if (pilon == nullptr) {
        return;
    }

    
    for (int i = 0; i < pilon->cantidadCartas; ++i) {
        delete pilon->cartas[i];
    }

    
    delete[] pilon->cartas;

   
    delete pilon;
}