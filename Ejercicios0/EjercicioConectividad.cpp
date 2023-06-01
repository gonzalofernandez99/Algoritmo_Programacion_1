#include <iostream>
using namespace std;
#define Ingresos 30
#define CantidadElementos 10
void Inicializar(int conexiones[]);
void Conectar(int conexiones[], int p, int q);
bool EstanConectados(int p, int q, int conexiones[]);
int ObtenerRaiz(int conexiones[], int p);
void TesObtenerRaiz();
int main()
{
    int p, q;
    int conexiones[CantidadElementos];
    Inicializar(conexiones);
    Conectar(conexiones, 4, 3);
    Conectar(conexiones, 3, 8);
    Conectar(conexiones, 6, 5);
    Conectar(conexiones, 9, 4);
    Conectar(conexiones, 2, 1);
    Conectar(conexiones, 5, 0);
    Conectar(conexiones, 7, 2);
    Conectar(conexiones, 6, 1);
    Conectar(conexiones, 7, 3);
}

void TesObtenerRaiz() {
    int conexiones[10] = { 0, 1, 2, 8,3, 5, 5, 7, 8, 8};

    if (ObtenerRaiz(conexiones, 0) == 0) {
        cout << "OK" << endl;
    }
    else {
        cout << "OH NO" << endl;
    }

    if (ObtenerRaiz(conexiones, 0) == 0) {
        cout << "OK" << endl;
    }
    else {
        cout << "OH NO" << endl;
    }

    if (ObtenerRaiz(conexiones, 6) == 5) {
        cout << "OK" << endl;
    }
    else {
        cout << "OH NO" << endl;
    }

    if (ObtenerRaiz(conexiones, 4) == 8) {
        cout << "OK" << endl;
    }
    else {
        cout << "OH NO" << endl;
    }

    if (ObtenerRaiz(conexiones, 3) == 8) {
        cout << "OK" << endl;
    }
    else {
        cout << "OH NO" << endl;
    }

    if (ObtenerRaiz(conexiones, 9) == 8) {
        cout << "OK" << endl;
    }
    else {
        cout << "OH NO" << endl;
    }
}

bool EsRaiz(int conexiones[], int p) {
    return conexiones[p] == p;
}

int ObtenerRaiz(int conexiones[], int elemento) {
    int raiz = conexiones[elemento];

    while (!EsRaiz(conexiones, raiz))
        raiz = conexiones[raiz];

    return raiz;
}


void Conectar(int conexiones[], int p, int q) {
    int raizQ = ObtenerRaiz(conexiones, q);
    int raizP = ObtenerRaiz(conexiones, p);
    conexiones[raizP] = raizQ;// Quick Union
}

bool EstanConectados(int p, int q, int conexiones[]) {
    int raizP = ObtenerRaiz(conexiones, p);
    int raizQ = ObtenerRaiz(conexiones, q);

    return raizP == raizQ;
}


void Inicializar(int conexiones[]) {
    for (int i = 0; i < CantidadElementos; ++i) {
        conexiones[i] = i;
    }
}




// Ejercicio 2 
// Implementar el siguiente algoritmo utilizando la resolucion de gauss conversada en clase
int ObtenerSumatoriaHasta(int comienzo, int fin) {
    return 0;
}