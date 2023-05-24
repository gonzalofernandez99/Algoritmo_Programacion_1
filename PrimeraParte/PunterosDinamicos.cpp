#include <iostream>
using namespace std;

void Copiar(const char* textoOrigen, char* textoDestino);
int ContarCaracteres(const char* texto);
void Concatenar(char* texto, const char* subTexto);
char* CrearCopia(const char* texto);
void EjemploCadenaCaracteres();

enum TipoPalo{ORO,COPA,ESPADA,BASTO};

struct Carta {
    int valor;
    TipoPalo palo;
};

struct PilonCartas {
    int cantidadCartas;
    Carta** cartas;
};


// Postcondicion: Devuelbe una instancia valida Carta
Carta* CrearCarta(int valor, TipoPalo palo);

PilonCartas* CrearPilonVacio();

// Precondicion: Ninguna
// Postcondicion:Devuelve una instancia valida de PilonCartas
// que contiene las 40 cartas del juego truco
PilonCartas* CrearPilonParaTruco();

void Mostrar(const Carta* carta);
void Mostrar(const PilonCartas* pilon);
void Destruir(PilonCartas* pilon);

int main()
{
    PilonCartas* cartasTruco = CrearPilonParaTruco();
    Mostrar(cartasTruco);
    Destruir(cartasTruco);
}

PilonCartas* CrearPilonVacio() {
    PilonCartas* nuevoPilon = new PilonCartas;
    nuevoPilon->cantidadCartas = 0;


    return nuevoPilon;
}


void EjemploCadenaCaracteres()
{
    char texto[1000];
    Copiar("HOLA", texto);
    char* copiaTexto = CrearCopia(texto);
    if (texto == copiaTexto) {
        cout << "Son IGUALES!" << endl;
    }
    else {
        cout << "NO Son IGUALES!" << endl;
    }
    cout << texto << endl;
    cout << copiaTexto << endl;

    delete[]copiaTexto;
}

Carta* CrearCarta(int valor, TipoPalo palo) {
    Carta* nuevaCarta = new Carta;
    nuevaCarta->valor = valor;
    nuevaCarta->palo = palo;
    
    return nuevaCarta;
}

char* CrearCopia(const char* texto) {
    char* copia = new char[1000];
    Copiar(texto, copia);
    cout << copia << endl;
    return copia;
}

void Copiar(const char* textoOrigen, char* textoDestino) {
    // Precedencia de operadores
    while (*textoDestino++ = * textoOrigen++);
}

int ContarCaracteres(const char* texto) {
    const char* primeraPosicion = texto;
    while (*texto++);
    const char* posicionFin = texto - 1;

    return posicionFin - primeraPosicion;
}

void Concatenar(char* texto, const char* subTexto) {
    Copiar(subTexto, texto + ContarCaracteres(texto));
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

void Mostrar(const PilonCartas* pilon) {
    for (int i = 0; i < pilon->cantidadCartas;++i) {
        Mostrar(pilon->cartas[i]);
    }
}

struct PilonCartas2 {
    int cantidadCartas;
    Carta** cartas;
};

PilonCartas* CrearPilonParaTruco() {
    PilonCartas* nuevoPilon = new PilonCartas;
    nuevoPilon->cantidadCartas = 10;
    nuevoPilon->cartas = new Carta * [10];
    
    // Cargamos primero espadas
    for (int valorCarta = 1,  indiceCarta = 0;
        indiceCarta < 10;++indiceCarta) {
        nuevoPilon->cartas[indiceCarta] = CrearCarta(valorCarta++, ESPADA);
    }

    return nuevoPilon;
}

void Destruir(PilonCartas* pilon) {

}
