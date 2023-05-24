#include <iostream>
#include <cassert>
using namespace std;
bool TengoCambio(int moneda1, int moneda2, int moneda3, int valor);

void Test(int moneda1, int moneda2, int moneda3, int valor, bool resultadoEsperado);

void PruebaParcial() {
    Test(3, 4, 8, 7, true);
    Test(3, 4, 8, 10, true);
    Test(3, 4, 8, 19, true);
    Test(3, 4, 8, 5, false);
    Test(3, 4, 8, 2, false);
}


struct NumeroComplejo {
    double parteReal;
    double parteImaginaria;
};


int main()
{
    //Consigna 1
    NumeroComplejo espacioComplejo[10];
    //Consigna 2
    for (int i = 0; i < 10; ++i)
    {
        espacioComplejo[i].parteImaginaria = 99;
        espacioComplejo[i].parteReal = 99;
    }
    //Consigna 3
    NumeroComplejo* punteroEspacioComplejo[10];
    //Consigna 4
    for (int i = 0; i < 10; ++i)
    {
        punteroEspacioComplejo[i]=&espacioComplejo[i];
    }
}

bool TengoCambio(int moneda1, int moneda2, int moneda3, int valor) {
    if (valor == 0) return true;
    if (valor < 0) return false;
    return TengoCambio(moneda1, moneda2, moneda3, valor - moneda1) || 
        TengoCambio(moneda1, moneda2, moneda3, valor - moneda2) || 
        TengoCambio(moneda1, moneda2, moneda3, valor - moneda3);
}

void Test(int moneda1, int moneda2, int moneda3, int valor, bool resultadoEsperado) {
    if (TengoCambio(moneda1, moneda2, moneda3, valor) == resultadoEsperado) {
        cout << "Test OK" << endl;
    }
    else {
        cout << "Test Mal" << endl;
    }
}