#ifndef CARTA_H
#define CARTA_H

namespace UndavCarta{
	struct Carta;
	enum TipoPalo{ Espada = 0, Oro = 1, Copa =2, Basto =3};

	// Postcondicion: Devuelve una instancia valida. Si valor es invalido devuelve NULL
	Carta* Crear(int valor, TipoPalo palo);

	// Precondicion: @carta es una instancia valida
	// Postcondicion: Devuelve el valor de la carta
	int ObtenerValor(const Carta* carta);

	// Precondicion: @carta es una instancia valida
	// Postcondicion: Devuelve el palo de la carta
	TipoPalo ObtenerPalo(const Carta* carta);

	// Postcondicion: Liberar los recursos asociados
	void Destruir(Carta* carta);
}

#endif
