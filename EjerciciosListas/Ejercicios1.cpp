#include <iostream>
using namespace std;

struct Nodo{
    int item;
    Nodo* siguiente;
};

struct Lista {
    Nodo* primero;
};


void Mostrar(const Lista* lista);
Lista* CrearLista(int enteros[], int cantidad);
Nodo* CrearNodo(int item);
void DeleteLista(Lista* lista);

// Precondicion: @lista es una instancia valida
// Postcondicion: Invierte los nodos de la lista
// Ejemplo:
// Si mi lista era: 3 -> 1 -> 9 -> -1 -> NULL
// Luego de llamar a la funcion:
// -1 -> 9 -> 1 -> 3 -> NULL
void Invertir(Lista* lista);
// El algoritmo debe ser O(N)
// Debe ser inplace: No utiliza mucha memoria significativa para resolver el problema


// Precondicion: @lista es una instancia valida 
// Postcondicion: Devuelve true si la lista al recorrerla secuencialmente no tiene marca de fin. 
// caso contrario devuelve False
bool HayCiclo(Lista* lista);
// El algoritmo debe ser O(N)

int main()
{
    int items[] = { 9,8,7,6,5,4,3,2,1 };
    Lista* lista = CrearLista(items, 9);
    Mostrar(lista);
    Invertir(lista);
    Mostrar(lista); // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9

    DeleteLista(lista);

    return 0;
}

void Mostrar(const Lista* lista) {
    Nodo* iterador = lista->primero;
    while (iterador != NULL) {
        cout << iterador->item << " -> ";
        iterador = iterador->siguiente;
    }
    cout << "NULL" << endl;
}

Nodo* CrearNodo(int item) {
    Nodo* nodo = new Nodo;
    nodo->item = item;
    nodo->siguiente = NULL;

    return nodo;
}

Lista* CrearLista(int enteros[], int cantidad) {
    Lista* lista = new Lista;
    lista->primero = NULL;
    if (cantidad > 0) {
        lista->primero = CrearNodo(enteros[0]);
        Nodo* nodo = lista->primero;
        for (int i = 1; i < cantidad;++i) {
            nodo->siguiente = CrearNodo(enteros[i]);
            nodo = nodo->siguiente;
        }
    }

    return lista;
}

void DeleteLista(Lista* lista) {
    Nodo* nodoActual = lista->primero;
    while (nodoActual != nullptr) {
        Nodo* nodoAEliminar = nodoActual;
        nodoActual = nodoActual->siguiente;
        delete nodoAEliminar;
    }
    delete lista;
}

void Invertir(Lista* lista) {
    Nodo* nodoActual = lista->primero;
    Nodo* nodoPrevio = nullptr;
    Nodo* nodoSiguiente = nullptr;
    
    while (nodoActual != nullptr) {
        cout << "nodoActual: " << nodoActual->item << "\n";
        if(nodoPrevio != nullptr) {
            cout << "nodoPrevio: " << nodoPrevio->item << "\n";
        }
        if(nodoSiguiente != nullptr) {
            cout << "nodoSiguiente: " << nodoSiguiente->item << "\n";
        }
        // Almacena el nodo siguiente
        nodoSiguiente = nodoActual->siguiente;
        
        // Cambia el puntero siguiente del nodo actual para que apunte al nodo previo
        nodoActual->siguiente = nodoPrevio;
        
        // Mueve los punteros uno hacia adelante
        nodoPrevio = nodoActual;
        nodoActual = nodoSiguiente;
        cout << "--- Fin de la iteración ---" << "\n";
    }
    
    // Cambia la cabeza de la lista
    lista->primero = nodoPrevio;
}