#include "stdafx.h"
#include "ListaPlaneta.h"

/*Constructor de la clase
*/
ListaPlaneta::ListaPlaneta()
{
	this->cantActual = 0;
	this->arregloPlaneta = new Planeta*[200];
}

/*Metodo que agrega un planeta desde el metodo leerPlaneta*/
void ListaPlaneta::agregarPlaneta(string nombre, string distancia, string habitado, string * suministros, int * cantSuministros, int cantListaSuministros)
{
	Planeta* planeta = new Planeta(nombre, distancia, habitado, suministros, cantSuministros, cantListaSuministros);
	this->arregloPlaneta[this->cantActual] = planeta;
	this->cantActual = this->cantActual + 1;
}
/*Destructor de la clase
*/
ListaPlaneta::~ListaPlaneta()
{
}
/*Metodo que busca el destino en el arreglo
*/
bool ListaPlaneta::buscarDestino(string destino)
{
	for (int i = 0; i < this->cantActual; i++) {
		if (this->arregloPlaneta[i]->nombre == destino) {
			return true;
		}
	}
	return false;
}