#pragma once
#include "Planeta.h"
class ListaPlaneta
{
public:
	ListaPlaneta();
	int cantActual;
	Planeta* planeta;
	Planeta** arregloPlaneta;
	void agregarPlaneta(string nombre, string distancia, string habitado, string* suministros, int* cantSuministros, int cantListaSuministros);
	bool buscarDestino(string destino);
	~ListaPlaneta();
};

