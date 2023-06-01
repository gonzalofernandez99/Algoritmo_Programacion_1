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

bool cambioMoneda(int moneda1,int moneda2,int moneda3,int valor){
    if (valor == 0){
        return true;
    }
    if(valor<0){
        return false;
    }
    return cambioMoneda(moneda1,moneda2,moneda3,valor-moneda1)|| 
    cambioMoneda(moneda1,moneda2,moneda3,valor-moneda2)|| 
    cambioMoneda(moneda1,moneda2,moneda3,valor-moneda3);
}

int min(int a, int b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}

int minMonedas(int monedas[], int n, int valor) {
    if (valor == 0) {
        return 0;
    }
    if (valor < 0) {
        return INT_MAX;
    }

    int res = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (monedas[i] <= valor) {
            int subRes = minMonedas(monedas, n, valor - monedas[i]);
            if (subRes != INT_MAX) {
                res = min(res, subRes + 1);
            }
        }
    }

    return res;
}

void testminmonedas(){
    int monedas[] = {4, 2, 8};
    int n = sizeof(monedas)/sizeof(monedas[0]);
    cout<<"sizeof(monedas) "<<sizeof(monedas)<<" sizeof(monedas[0]) "<<sizeof(monedas[0])<<" sizeof(monedas)/sizeof(monedas[0])"<<n<<endl;
    int valor = 11;
    int res = minMonedas(monedas, n, valor);
    if (res != INT_MAX) {
        std::cout << "El mínimo número de monedas es " << res << std::endl;
    } else {
        std::cout << "No se puede obtener el valor con las monedas dadas." << std::endl;
    }
}

int corteVarilla(int L, int precios[], int n) {
    if (L <= 0) {
        return 0;
    }

    int max_valor = -1;
    for (int i = 0; i < n; i++) {
        if (L >= i + 1) {
            max_valor = max(max_valor, precios[i] + corteVarilla(L - i - 1, precios, n));
        }
    }

    return max_valor;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void testcorteVarilla(){
    int precios[] = {1, 2, 3, 4, 5, 6, 7, 1};
    int n = sizeof(precios) / sizeof(precios[0]);
    int L = 8;
    std::cout << "Máximo valor obtenible es " << corteVarilla(L, precios, n) << std::endl;
}

bool subconjuntosuma(int conjunto[],int n,int suma){
    if (suma == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }
    if (conjunto[n-1]>suma)
    {
        return subconjuntosuma(conjunto,n-1,suma);
    }
    
    return subconjuntosuma(conjunto,n-1,suma) || subconjuntosuma(conjunto,n-1,suma-conjunto[n-1]);
    
}

void testconjuntosuma(){
    int conjunto[] = {1, 2, 3, 4, 5, 6, 7, 1};
    int n = sizeof(conjunto) / sizeof(conjunto[0]);
    int suma = 8;
    std::cout << "true es 1, false es 0 " << subconjuntosuma(conjunto, n, suma) << std::endl;
}
int main() {
    //testminmonedas();
    //moverTorres(4, 'A', 'C', 'B');
    //testcorteVarilla();
    testconjuntosuma();
    return 0;
}


