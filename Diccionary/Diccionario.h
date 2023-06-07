struct PartidoFutbol {
	int idPartido;
};

struct Resultado {
	int golesEquipo1;
	int golesEquipo2;
};

typedef int Clave;
typedef Resultado* Valor;

#define SonIguales(a, b) a == b

namespace UndavDiccionario {
	struct Diccionario;
	Diccionario* Crear();

	// Precondicion:
	// Postcondicion: Si @clave no existe la agrega en @diccionario. Si @clave existe reemplaza el valor
	// asociado por @valor
	
	// 
	void Agregar(Diccionario* diccionario, Clave clave, Valor valor);

	// Precondicion: @clave debe existir si o si en @diccionario


	// Buscar tiene dos resultados posibles:
	// - HIT -> Esta y lo devuelve
	// - Miss -> No esta
	Valor Obtener(Diccionario* diccionario, Clave clave);
	bool Contiene(const Diccionario* diccionario, Clave clave);
	void Destruir();
}



// Algo importante que cumple una clave: KA KB
// Debe pasar alguna de estas 3 cosas de manera excluyentes
// KA == KB 
// KA < KB
// KA > KB