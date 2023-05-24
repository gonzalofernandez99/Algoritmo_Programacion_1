- declarar un vecto de tamaño 10 ddonde cada item del vector es de tipo numero complejo nombrado como espacio complejo 
- inicializar el vector con el numero complejo (99,99)
- declarar un vector de tamano 1 dondde cada item del vector es de tipo puntero a numero complejo, nombrarlo como punteroespaciocomplejo
- inicializar el vector punteroespaciocomplejo con las referencias de cada item del vector espaciocomplejo
- conjugar todas las instancias de numerocomplejo que tiene utiliando su instancia punteroespacio complejo 

**_Ejercicio recursividad_**

* precondicion: @moneda1@moneda2@moneda3 son mayores que cero 
* postcondicion: devuelve true si utilizando una combinacion de @moneda1 @moneda2 @moneda3 igualo exactamente a @valor, caso contrario devuelve falso,repetir una misma moneda esta permitido 
* ejemplo: 
tengocambio(3,4,8,7) = true 3+4 = 7
tengocambio(3,4,8,2) = false
tengocambio(3,4,8,19) = true 8+8+3
tengocambio(3,4,8,10) = true 3+3+4
tengocambio(3,4,8,5) = false

bool TengoCambio(int moneda1,int moneda2,int moneda3,int valor);