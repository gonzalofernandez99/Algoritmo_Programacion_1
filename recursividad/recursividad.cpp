#include <iostream>
using namespace std;

int sumaDeArray(int arr[], int n) {

    if (n <= 0) {
        return 0;
    }

    return arr[0] + sumaDeArray(arr + 1, n - 1);
}

int potencia(int base, int exponente) {
    
    if (exponente == 0) {
        return 1;
    }

   
    if (exponente == 1) {
        return base;
    }

    return base * potencia(base, exponente - 1);
}


void moverTorres(int n, char origen, char destino, char auxiliar) {
    // Caso base: si solo queda un disco, mueve ese disco al destino y termina la función.
    if (n == 1) {
        std::cout << "Mover el disco 1 de la torre " << origen << " a la torre " << destino << "\n";
        return;
    }
    
    // Mover n-1 discos de la torre origen a la torre auxiliar, usando la torre destino.
    moverTorres(n - 1, origen, auxiliar, destino);
    
    // Mover el disco restante de la torre origen a la torre destino.
    std::cout << "Mover el disco " << n << " de la torre " << origen << " a la torre " << destino << "\n";
    
    // Mover los n-1 discos de la torre auxiliar a la torre destino, usando la torre origen.
    moverTorres(n - 1, auxiliar, destino, origen);
}


int main() {
    // Ejemplo con 4 discos.
    moverTorres(4, 'A', 'C', 'B');
    
    return 0;
}