#include <iostream>
#include <cassert>
using namespace std;

int main() {    
  int rows = 0;
  int cols = 0;

  cout<<"Rows: "<<endl;
  cin>>rows;
  cout<<"Cols: "<<endl;
  cin>>cols;

  // Asignar memoria para los punteros
  int **matriz = new int*[rows];
  for (int i = 0; i < rows; i++) {
    matriz[i] = new int[cols];
  }

  // Asignar valores a la matriz
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matriz[i][j] = i * cols + j;
    }
  }

  // Imprimir la matriz
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << matriz[i][j] << " ";
    }
    cout << endl;
  }

  // Liberar memoria
  for (int i = 0; i < rows; i++) {
    delete[] matriz[i];
  }
  delete[] matriz;


assert( 70 == 80 );

  return 0;
}