#include <iostream>
#include <cassert>
using namespace std;
bool TengoCambio(int moneda1, int moneda2, int moneda3, int valor);

void Test(int moneda1, int moneda2, int moneda3, int valor, bool resultadoEsperado);

bool TengoCambioDinamico(int moneda1, int moneda2, int moneda3, int valor);

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
        cout<<punteroEspacioComplejo[i]->parteReal<<endl;
        cout<<punteroEspacioComplejo[i]->parteImaginaria<<endl;
    }
    
    std::cout << TengoCambio(3, 4, 8, 7) << std::endl;
    std::cout << TengoCambio(3, 4, 8, 2) << std::endl;
    std::cout << TengoCambio(3, 4, 8, 19) << std::endl;
    std::cout << TengoCambio(3, 4, 8, 10) << std::endl;
    std::cout << TengoCambio(3, 4, 8, 5) << std::endl;
    return 0;
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

bool TengoCambioDinamico(int moneda1, int moneda2, int moneda3, int valor) {
    // Crea un arreglo dinámico de booleanos
    bool *dp = new bool[valor + 1]();

    dp[0] = true; // siempre puedes obtener un valor de 0, sin usar ninguna moneda

    // Por cada moneda, actualiza el arreglo dp
    for (int i = 1; i <= valor; i++) {
        if (i - moneda1 >= 0) dp[i] = dp[i] || dp[i - moneda1];
        if (i - moneda2 >= 0) dp[i] = dp[i] || dp[i - moneda2];
        if (i - moneda3 >= 0) dp[i] = dp[i] || dp[i - moneda3];
    }

    // Guarda el resultado y luego libera la memoria
    bool resultado = dp[valor];
    delete[] dp;

    // Retorna si puedes obtener el valor objetivo
    return resultado;
}