#include "stdafx.h"
#include "Nave.h"

/*Constructor vacio
*/
Nave::Nave()
{
}
/*Constructor de la clase con parametros*/
Nave::Nave(string nombre, string destino, int cantTripulantes, string * suministros, int * cantSuministros,int cantListaSuministros)
{
	this->nombre = nombre;
	this->destino = destino;
	this->cantTripulantes = cantTripulantes;
	this->suministros = suministros;
	this->cantSuministros = cantSuministros;
	this->CantListaSuministros = cantListaSuministros;
}

/*Destructor de la clase
*/
Nave::~Nave()
{
}
