#include <iostream>
#include "Cola.h"

using namespace std;
using namespace UndavCola;

typedef char Item;

struct Nodo{
	Item item;
	Nodo* subArbolIzquierdo;
	Nodo* subArbolDerecho;
};

// Funciones creacionales del arbol del ejemplo
Nodo* CrearArbolPrueba();
Nodo* CrearNodo(char item, Nodo* izq, Nodo* der);
Nodo* CrearHoja(char item);

typedef void (*FuncionVisitar)(Nodo* nodo);

void MostrarItem(Nodo* nodo);

// Ejercicios a realizar en clase
void RecorrerEnOrden(Nodo* subArbol, FuncionVisitar visitar);
void RecorrerPostOrden(Nodo* subArbol, FuncionVisitar visitar);
void RecorrerPreOrden(Nodo* subArbol, FuncionVisitar visitar);
void RecorrerAncho(Nodo* subArbol, FuncionVisitar visitar);
void DestruirArbol(Nodo* subArbol);
int ObtenerAltura(Nodo* subArbol);
int ObtenerTamanio(Nodo* subArbol);
int ObtenerCantidadNodosExternos(Nodo* subArbol);

int main() {
	Nodo* arbol = CrearArbolPrueba();
	cout<<"La altura del arbol es:\n\t";
	cout<<ObtenerAltura(arbol);
	cout<<endl;
	cout<<"El tamanio del arbol es:\n\t";
	cout<<ObtenerTamanio(arbol);
	cout<<endl;
	cout<<"Recorridos en profundidad (DFS)\n\t";
	cout<<"Recorrido en orden:\n\t";
	RecorrerEnOrden(arbol, MostrarItem);
	cout<<endl;
	cout<<"\tRecorrido en pre-orden:\n\t";
	RecorrerPreOrden(arbol, MostrarItem);
	cout<<endl;
	cout<<"\tRecorrido en post-orden:\n\t";
	RecorrerPostOrden(arbol, MostrarItem);
	cout<<endl;
	cout<<"\tRecorrido a lo ancho (BFS)\n\t";
	RecorrerAncho(arbol, MostrarItem);
	cout<<"\nDestruyendo Arbol..."<<endl;
	DestruirArbol(arbol);
	cout<<"\nArbol destruido"<<endl;
	return 0;
}

void RecorrerEnOrden(Nodo* subArbol, FuncionVisitar visitar){
  if(subArbol == NULL) return;
  RecorrerEnOrden(subArbol->subArbolIzquierdo, visitar);
  visitar(subArbol);
  RecorrerEnOrden(subArbol->subArbolDerecho, visitar);
  // UOXAZBYC
}

void RecorrerPostOrden(Nodo* subArbol, FuncionVisitar visitar)
{
	if(subArbol == NULL) return;
	RecorrerPostOrden(subArbol->subArbolIzquierdo, visitar);
	RecorrerPostOrden(subArbol->subArbolDerecho, visitar);
	visitar(subArbol);
}

void DestruirNodo(Nodo* nodo){
	delete nodo;
}

void DestruirArbol(Nodo* subArbol)
{
	RecorrerPostOrden(subArbol, DestruirNodo);
}

void MostrarItem(Nodo* nodo){
	cout<<nodo->item<<" ";
}

void RecorrerPreOrden(Nodo* subArbol, FuncionVisitar visitar){
	if(subArbol == NULL) return;
	visitar(subArbol);
	RecorrerPreOrden(subArbol->subArbolIzquierdo, visitar);
	RecorrerPreOrden(subArbol->subArbolDerecho, visitar);
}

//Recorrido BFS
void RecorrerAncho(Nodo* subArbol, FuncionVisitar visitar){
	Cola* cola = Crear();
	if(subArbol!=NULL){
		Encolar(cola, subArbol);
		while(!EstaVacia(cola)){
			Nodo* nodo = (Nodo*)Desencolar(cola);
			visitar(nodo);
			if(nodo->subArbolIzquierdo != NULL) Encolar(cola,nodo->subArbolIzquierdo);
			if(nodo->subArbolDerecho != NULL) Encolar(cola,nodo->subArbolDerecho);
		}
	}

	Destruir(cola);
}

int ObtenerCantidadNodosExternos(Nodo* subArbol){
	return ObtenerTamanio(subArbol) + 1;
}

int ObtenerAltura(Nodo* subArbol){
	int altura =-1;
	if(subArbol != NULL){
		int alturaArbolIzquierdo = ObtenerAltura(subArbol->subArbolIzquierdo);
		int alturaSubArbolDerecho = ObtenerAltura(subArbol->subArbolDerecho);
		altura = 1 + ( alturaArbolIzquierdo > alturaSubArbolDerecho ? alturaArbolIzquierdo : alturaSubArbolDerecho);
	}

	return altura;
}
int ObtenerTamanio(Nodo* subArbol){
	if(subArbol == NULL) return 0;
	else{
		return 1 + ObtenerTamanio(subArbol->subArbolIzquierdo) + ObtenerTamanio(subArbol->subArbolDerecho);
	}
}

Nodo* CrearNodo(char item, Nodo* izq, Nodo* der)
{
	Nodo* nodo = new Nodo;
	nodo->subArbolIzquierdo = izq;
	nodo->subArbolDerecho = der;
	nodo->item = item;
	return nodo;
}

Nodo* CrearHoja(char item)
{
	Nodo* nodo = new Nodo;
	nodo->subArbolIzquierdo = NULL;
	nodo->subArbolDerecho = NULL;
	nodo->item = item;
	return nodo;
}

Nodo* CrearArbolPrueba()
{
	Nodo* subArbolO = CrearNodo('O', CrearHoja('U'), CrearHoja('X'));
	Nodo* subArbolB = CrearNodo('B', CrearHoja('Z'), CrearNodo('C', CrearHoja('Y'), NULL));
	Nodo* raiz = CrearNodo('A', subArbolO, subArbolB);
	return raiz;
}
