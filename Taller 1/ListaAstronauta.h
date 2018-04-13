#pragma once
#include "Astronauta.h"
class ListaAstronauta
{
public:
	ListaAstronauta(int total);
	int total;
	int cantActual;
	Astronauta* astronauta;
	Astronauta** arrayAstronautas;
	void agregarAstronauta(string nombre, int edad, int anios, string nave);
	void imprimirAstronautas();
	void imprimirAstronautasSinNave();
	void imprimirAstronautasOrigen(string nave);
	bool buscarAstronauta(string astronauta);
	int devolverNumero(string astronauta);
	void ordenarAstronautas();



	~ListaAstronauta();
};

