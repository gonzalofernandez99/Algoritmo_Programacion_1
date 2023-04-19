#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>

using namespace std;

int ingresoOpcion() {
    int __opcion;
    cout << endl << "1: change number. 2: commit. 3: release number." << endl;
    cout << "Ingrese opcion: ";
    cin >> __opcion;
    return __opcion;
}


int main(int argc, char const *argv[])
{
    ingresoOpcion();
    return 0;
}
