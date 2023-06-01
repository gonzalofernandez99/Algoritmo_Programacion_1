#include <iostream>
#include <cassert>

using namespace std;
const int TOPE = 6;

struct NumeroComplejo {
    double parteReal;
    double parteImaginaria;
};


int ContarMultiplos(int numeros[], int numero, int indiceComienzo, int indiceFin);

void testContarMultiplos();

int main(){

    //Consigna 1
    NumeroComplejo v[TOPE] = {{0,0},{0,1},{0,2},{0,3},{0,4},{0,5}};

    //Consigna 2
    NumeroComplejo* x[3];
    NumeroComplejo* y[3];

    //Consigna 3
    for (int i = 0; i < 3; ++i) {
    x[i] = &v[i];
    y[i] = &v[i+3];
    }

    //Consigna 4
    for (int i = 0; i < 3; ++i) {
        NumeroComplejo temp = *x[i];
        x[i]->parteReal = y[i]->parteReal;
        x[i]->parteImaginaria = y[i]->parteImaginaria;
        y[i]->parteReal = temp.parteReal;
        y[i]->parteImaginaria = temp.parteImaginaria;
    }


    testContarMultiplos();
    return 0;

}

int ContarMultiplos(int numeros[], int numero, int indiceComienzo, int indiceFin){
    if (indiceFin < indiceComienzo){
        return 0;
    }

    if(numeros[indiceFin]%numero==0){
        return 1+ContarMultiplos(numeros,numero,indiceComienzo,indiceFin-1);
    }else
    {
        return ContarMultiplos(numeros,numero,indiceComienzo,indiceFin-1);
    }
    
}

void testContarMultiplos(){
    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    assert(ContarMultiplos(numeros, 10, 0, 9) == 1); 
    assert(ContarMultiplos(numeros, 11, 0, 9) == 0);
    assert(ContarMultiplos(numeros, 2, 0, 9) == 5); 
    assert(ContarMultiplos(numeros, 3, 0, 9) == 3); 
    assert(ContarMultiplos(numeros, 1, 0, 9) == 10); 

    int numeros2[] = {73, 146, 219, 292, 365,438,511};

    assert(ContarMultiplos(numeros2, 73, 0, 6) == 7); 
    assert(ContarMultiplos(numeros2, 2, 0, 6) == 3); 
    assert(ContarMultiplos(numeros2, 1, 0, 6) == 7); 

}
