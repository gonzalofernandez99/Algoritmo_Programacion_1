#ifndef COLA_H_
#define COLA_H_

namespace UndavCola{
	struct Cola;
	Cola* Crear();
	void Encolar(Cola* cola, void* item);
	void* Desencolar(Cola* cola);
	bool EstaVacia(const Cola* cola);
	void Destruir(Cola* cola);
}

#endif
