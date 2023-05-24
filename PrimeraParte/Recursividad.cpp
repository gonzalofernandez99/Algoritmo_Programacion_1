#include <iostream>
using namespace std;
const int LimiteNumeroNatural = 10;

void MostrarNumerosNaturales(unsigned int numeroNatural) {
	cout << numeroNatural<< " ";
	if (numeroNatural < LimiteNumeroNatural) {
		MostrarNumerosNaturales(numeroNatural + 1);
	}
}

void MostrarNumerosNaturalesReversa(unsigned int numeroNatural);

int ObtenerFactorial(int n);

int ObtenerFibonacci(int n);

void MostrarReversa(const char* texto);

int ObtenerMaximo(int vector[], int indiceInicio, int indiceFin);
int ObtenerMinimo(int vector[], int indiceInicio, int indiceFin);
int ObtenerCantidadDeNumerosPares(int vector[], int indiceInicio, int indiceFin);
int ObtenerFibonacciGeneralizada(int a, int b, int n);
void MostrarReversaSoloVocales(const char* texto);

bool PuedoLlegarAPlantaBaja(int pisoActual, int primerBoton, int segundoBoton);

void MostrarFactoriales(int desdeDonde) {
	for (int n = desdeDonde; n < desdeDonde + 5; ++n)
		cout << n << "! = " << ObtenerFactorial(n)<<endl;
}

int main()
{
	bool resultado = PuedoLlegarAPlantaBaja(7, 3, 4);
	
	cout << resultado << endl;
}

void MostrarNumerosNaturalesReversa(unsigned int numeroNatural) {
	if (numeroNatural < LimiteNumeroNatural) {
		MostrarNumerosNaturalesReversa(numeroNatural + 1);
		cout << numeroNatural <<" "<<endl;
	}
}

int ObtenerFactorial(int n) {
	if (n == 0) return 1;
	int resultadoFactorialN = n * ObtenerFactorial(n - 1);
	return resultadoFactorialN;
}

int ObtenerFibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	return ObtenerFibonacci(n - 2) + ObtenerFibonacci(n - 1);
}

int ObtenerFibonacciGeneralizada(int a, int b, int n){
	if (n == 0) return a;
	if (n == 1) return b;
	return ObtenerFibonacciGeneralizada(a, b, n - 2) * ObtenerFibonacciGeneralizada(a, b, n - 1);
} 

void MostrarReversa(const char* texto) {
	if (*texto != '\0') {
		//No reversa
		MostrarReversa(texto + 1);
		cout << *texto;
		
	}

}

bool esVocal(char valor) {
	return valor == 'A' || valor == 'E' || valor == 'I' || valor == 'O' || valor == 'U';
}

void MostrarReversaSoloVocales(const char* texto) {
	if (*texto != '\0') {
		MostrarReversaSoloVocales(texto + 1);
		if (esVocal(*texto)) {
			cout << *texto;
		}
	}
}

int ObtenerMaximo(int vector[], int indiceInicio, int indiceFin) {
    if (indiceInicio == indiceFin) {
        return vector[indiceInicio];
    }

    int mitad = (indiceInicio + indiceFin) / 2;
    int maxIzquierda = ObtenerMaximo(vector, indiceInicio, mitad);
    int maxDerecha = ObtenerMaximo(vector, mitad + 1, indiceFin);
    
    if (maxIzquierda > maxDerecha) {
        return maxIzquierda;
    } else {
        return maxDerecha;
    }
} 

int ObtenerMinimo(int vector[], int indiceInicio, int indiceFin) {
    if (indiceInicio == indiceFin) {
        return vector[indiceInicio];
    }

    int mitad = (indiceInicio + indiceFin) / 2;
    int minIzquierda = ObtenerMinimo(vector, indiceInicio, mitad);
    int minDerecha = ObtenerMinimo(vector, mitad + 1, indiceFin);
    
    if (minIzquierda < minDerecha) {
        return minIzquierda;
    } else {
        return minDerecha;
    }
} 

int ObtenerCantidadDeNumerosPares(int vector[], int indiceInicio, int indiceFin){
	if (indiceInicio > indiceFin) {
        return 0;
    }

    int mitad = (indiceInicio + indiceFin) / 2;
    int cantidadIzquierda = ObtenerCantidadDeNumerosPares(vector, indiceInicio, mitad - 1);
    int cantidadDerecha = ObtenerCantidadDeNumerosPares(vector, mitad + 1, indiceFin);
    
    int cantidadTotal = cantidadIzquierda + cantidadDerecha;
    if (vector[mitad] % 2 == 0) {
        cantidadTotal++;
    }
    
    return cantidadTotal;
} 

bool PuedoLlegarAPlantaBaja (int pisoActual, int boton1, int boton2){
    if(pisoActual == 0){
        return true;
    }
    if(boton1 > pisoActual && boton2 > pisoActual){
        return false;
    }

    return PuedoLlegarAPlantaBaja(pisoActual - boton1, boton1, boton2) || PuedoLlegarAPlantaBaja(pisoActual - boton2, boton1, boton2);
}