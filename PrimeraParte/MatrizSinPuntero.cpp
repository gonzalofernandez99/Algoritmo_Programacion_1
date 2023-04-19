#include <iostream>
using namespace std;

int main() {
  int rows = 0;
  int cols = 0100;

  cout<<"Rows: "<<endl;
  cin>>rows;
  cout<<"Cols: "<<endl;
  cin>>cols;

  // Declarar un array multidimensional
  int matriz[rows][cols];

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

  return 0;
}