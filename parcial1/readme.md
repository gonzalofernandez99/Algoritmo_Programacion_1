__La evaluacion se aprueba sumando 4 puntos__
-Ejercicio 1 (6 Puntos) –  Punteros
    Consigna 1: Dada la definicion de la estructura numero complejo se pide lo siguiente:
    Declarar un vector de tamaño 6 de tipo NumeroComplejo. Inicializarlo con los numeros [ (0,0),(0,1),(0,2),(0,3),(0,4),(0,5)]. Nombrar la variable cómo v
    Declarar dos vectores. Cada uno de tamano 3 donde cada item del vector es de tipo puntero a NumeroComplejo, nombrarlos: x y
    Inicializar el vector x con los primeros 3 elementos de v. Luego inicializar el vector y con los ultimos 3 elementos v  
    Finalmente hacer un intercambio de cada item de x con cada item de y

struct NumeroComplejo {
    double parteReal;
    double parteImaginaria;
};



-Ejercicio 2 (4 Puntos) – Recursividad
    Consigna: Implementar la función recursiva “ContarMultiplos” que cumpla con la post-condición dada.
    Criterio de evaluación: Se evaluará el cumplimiento de los requerimientos descritos en la post-condición de la función. La implementación tiene que ser recursiva. 
    Recordar que un número es múltiplo de otro si el resto de la división del número es igual a 0.
    /*
    * Precondición: @indiceComienzo e @indiceFin son posiciones validas
    * dentro de @numeros. @numero es un numero positivo 
    * Postcondicion: Devuelve la cantidad de numeros en @numeros que son
    * multiplos de @numero que se encuentrn desde @indiceComienzo hasta 
    * @indiceFin en @numeros
    */
    int ContarMultiplos(int numeros[], int numero, int indiceComienzo, int indiceFin);
