#pragma once
#include "Nave.h"
#include <iostream>
class ListaNave
{
public:
	ListaNave();
	int cantActual;
	Nave* nave;
	Nave** arregloNave;
	void agregarNave(string nombre, string destino, int cantTripulantes, string* suministros, int* cantSuministros, int cantListaSuministros);
	bool buscarNave(string nave);
	void imprimirNave();
	void imprimirListado();
	~ListaNave();
};

