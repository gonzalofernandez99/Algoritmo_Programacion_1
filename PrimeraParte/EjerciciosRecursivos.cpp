#include <iostream>
using namespace std;

int ObtenerMaximo(int elementos[], int indiceComienzo, int indiceFin);

struct Item {
    int peso;
    int valor;
    char codigo;
};

void CargarItems(Item items[]);
int ObtenerMaximoBotin(Item items[], int pesoMaximo);
const int PesoMaximoMochila = 6;

int MaximoBotinEncontrado[PesoMaximoMochila+1];
const int PesoDesconocido = -1;

void InicializarBuffer() {
    for (int i = 0; i <= PesoMaximoMochila; ++i) {
        MaximoBotinEncontrado[i] = PesoDesconocido;
    }
}

int main()
{
    InicializarBuffer();
    Item items[4];
    CargarItems(items);
    int maximoValor = ObtenerMaximoBotin(items, PesoMaximoMochila);//$ 26
    cout << maximoValor;
}

int ObtenerMaximoBotin(Item items[], int pesoMochila) {
    if (MaximoBotinEncontrado[pesoMochila] != PesoDesconocido) return MaximoBotinEncontrado[pesoMochila];
    int maximoBotin = 0;
    for (int i = 0; i < 4; ++i) {
        Item item = items[i];
        int nuevoPesoMochila = pesoMochila - item.peso;
        if (nuevoPesoMochila >= 0) {
            int posibleMaximo = item.valor + ObtenerMaximoBotin(items, nuevoPesoMochila);
            if (posibleMaximo > maximoBotin) {
                maximoBotin = posibleMaximo;
            }
        }
    }

    MaximoBotinEncontrado[pesoMochila] = maximoBotin;
    return maximoBotin;
}

void CargarItems(Item items[]) {
    items[0].peso = 7;
    items[0].valor = 5;
    items[0].codigo = 'A';

    items[1].peso = 2;
    items[1].valor = 4;
    items[1].codigo = 'B';


    items[2].peso = 9;
    items[2].valor = 7;
    items[2].codigo = 'C';


    items[3].peso = 3;
    items[3].valor = 6;
    items[3].codigo = 'D';
}

// Invariantes
int ObtenerMaximo(int elementos[], int indiceComienzo, int indiceFin) {
    if (indiceComienzo == indiceFin)
        return elementos[indiceComienzo];

    int indiceMitad = indiceComienzo + (indiceFin - indiceComienzo) / 2;
    int maximoPrimerMitad = ObtenerMaximo(elementos, indiceComienzo, indiceMitad);
    int maximoSegundaMitad = ObtenerMaximo(elementos, indiceMitad + 1, indiceFin);
    if (maximoPrimerMitad > maximoSegundaMitad)
        return maximoPrimerMitad;
    else
        return maximoSegundaMitad;
}