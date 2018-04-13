#include "stdafx.h"
#include "Astronauta.h"

/*Constructor vacio
*/
Astronauta::Astronauta()
{
	nombre = "";
	edad = 0;
	anios = 0;
	nave = "";

}
/*Constructor de la clase
*/
Astronauta::Astronauta(string nombre, int edad, int anios, string nave)
{
	this->nombre = nombre;
	this->edad = edad;
	this->anios = anios;
	this->nave = nave;


}







/*Destructor de la clase
*/
Astronauta::~Astronauta()
{
}
