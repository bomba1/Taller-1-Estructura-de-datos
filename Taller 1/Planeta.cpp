#include "stdafx.h"
#include "Planeta.h"

/*Constructor vacio
*/
Planeta::Planeta()
{
}
/*Constructor con parametros
*/
Planeta::Planeta(string nombre, string distancia, string habitado, string * suminitros, int * cantSuministros, int cantListaSuministros)
{
	this->nombre = nombre;
	this->distancia = distancia;
	this->habitado = habitado;
	this->suministros = suminitros;
	this->cantSuministros = cantSuministros;
	this->cantListaSuministros = cantListaSuministros;
}

/*Destructor
*/
Planeta::~Planeta()
{
}
