#include <iostream>
using namespace std;

// Define Valor maximo Columnas y filas
#define TOPE 9

// Funcion que imprime el sudoku
void MuestraSodoku(int grid[][TOPE]) {
    for(int row = 0; row < TOPE; row++) {
        for(int col = 0; col < TOPE; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Funcion que verifica si el numero dado se puede colar en la celda
bool TodOk(int grid[][TOPE], int row, int col, int num) {

    // Check si existe en la fila
    for(int i = 0; i < TOPE; i++) {
        if(grid[row][i] == num) {
            return false;
        }
    }

    // Check si existe en la columna 
    for(int i = 0; i < TOPE; i++) {
        if(grid[i][col] == num) {
            return false;
        }
    }

    // Check si existe en el 3x3
    //ejemplos -> Row 1 - (row % 3)=1 ->boxRow es 0 (comienza a iterar en la posicion 0)
    //ejemplos -> Row 3 - (row % 3)=0 ->boxRow es 3 (comienza a iterar en la posicion 3)
    //ejemplos -> Row 8 - (row % 3)=2 ->boxRow es 6 (comienza a iterar en la posicion 3)
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    
    for(int i = boxRow; i < boxRow + 3; i++) {
        for(int j = boxCol; j < boxCol + 3; j++) {
            if(grid[i][j] == num) {
                return false;
            }
        }
    }

    // Si el numero se puede colocar, devuelve verdadero 
    return true;
}

// Funcion que resuelve el sodoku, resive sodoku con la carga en el main, lo devuelve resuelto (si se puede)

bool ResuelveSudoku(int grid[][TOPE], int row, int col) {
    // Check si finalizo la grilla, Si llega hasta el final de la grilla devuelve TRUE (se pudo resolver), sino devuelve false al final de la funcion
    if(row == TOPE - 1 && col == TOPE) {
        return true;
    }

    // Check si hemos llegado al final de la fila
    if(col == TOPE) {
        row++;
        col = 0;
    }

    // Check si la celda ya está llena
    if(grid[row][col] != 0) {
        //incrementa en 1 columna para pasar al siguiente, si llega a pasar que esta en la final de la columna ocurre que pasa al if de arriba 
        return ResuelveSudoku(grid, row, col + 1);
    }

    // Intenta llenar la celda con números del 1 al 9
    for(int num = 1; num <= TOPE; num++) {
        if(TodOk(grid, row, col, num)) {
            grid[row][col] = num;
            if(ResuelveSudoku(grid, row, col + 1)) {
                return true;
            }
        }
        grid[row][col] = 0;

        // Si no encuentra ningun numero utiliza backtrack(Vuelve hacia atras y vuelve a intentar)
    }

    return false;
}

int main() {
    // Define sodoku a resolver
    int grid[TOPE][TOPE] = {
        {0, 2, 0, 0, 5, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 0, 0, 0, 0},
        {0, 4, 8, 0, 0, 0, 0, 6, 0},
        {9, 0, 0, 0, 6, 0, 0, 0, 3},
        {2, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 2, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 4, 0, 2},
        {0, 9, 0, 0, 0, 0, 0, 8, 0}}; 
        
    cout << "Sodoku sin resolver:" << endl;
    MuestraSodoku(grid);

    if(ResuelveSudoku(grid, 0, 0)) {
        cout << endl << "Sodoku Resuleto:" << endl;
        MuestraSodoku(grid);
    }
    else {
        cout << "No Existe solucion" << endl;
    }

    return 0;
}