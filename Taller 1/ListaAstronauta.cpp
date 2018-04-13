#include "stdafx.h"
#include "ListaAstronauta.h"




/*Constructor de la clase
*/
ListaAstronauta::ListaAstronauta(int total)
{
	this->total = total;
	this->cantActual = 0;
	this->arrayAstronautas = new Astronauta*[200];
}

/*Metodo que agrega un astronauta desde el leer archivo
*/
void ListaAstronauta::agregarAstronauta(string nombre, int edad, int anios, string nave)
{
	Astronauta* astronauta = new Astronauta(nombre, edad, anios, nave);
	this->arrayAstronautas[this->cantActual] = astronauta;
	this->cantActual = this->cantActual + 1;
}
/*Metodo que imprime los astronautas
*/
void ListaAstronauta::imprimirAstronautas()
{
	ordenarAstronautas();
	for (int i = 0; i < this->cantActual; i++) {
		if (this->arrayAstronautas[i]->nave == "") {
			cout << i + 1 << ".-" << "Nombre:" << this->arrayAstronautas[i]->nombre << " - " << "Edad:" << this->arrayAstronautas[i]->edad << " - " << "Anios:" << this->arrayAstronautas[i]->anios << " - " << "Nave:" << "No tiene Nave" << endl;
		}
		else {
			cout << i + 1 << ".-" << "Nombre:" << this->arrayAstronautas[i]->nombre << " - " << "Edad:" << this->arrayAstronautas[i]->edad << " - " << "Anios:" << this->arrayAstronautas[i]->anios << " - " << "Nave:" << this->arrayAstronautas[i]->nave << endl;
		}
		

	}
	return;
}
/*Metodo que imprime los astronautas sin nave*/
void ListaAstronauta::imprimirAstronautasSinNave()
{	
	for (int i = 0; i < this->cantActual; i++) {
		if (this->arrayAstronautas[i]->nave == "") {
			cout << i + 1 << ".-" << "Nombre:" << this->arrayAstronautas[i]->nombre << endl;
		}
	}
}
/*Metodo que imprime los astronautas con la nave dada por parametro
*/
void ListaAstronauta::imprimirAstronautasOrigen(string nave)
{
	for (int i = 0; i < this->cantActual; i++) {
		if (this->arrayAstronautas[i]->nave == nave) {
			cout << i + 1 << ".-" << "Nombre:" << this->arrayAstronautas[i]->nombre << endl;

		}
	}
}
/*Metodo que busca un astronauta
*/
bool ListaAstronauta::buscarAstronauta(string astronauta)
{
	for (int i = 0; i < this->cantActual; i++) {
		if (this->arrayAstronautas[i]->nombre == astronauta) {
			return true;
		}
	}
	return false;
}
/*Metodo que devuelve la posicion del astronauta en el arreglo*/
int ListaAstronauta::devolverNumero(string astronauta)
{
	for (int i = 0; i < this->cantActual; i++) {
		if (this->arrayAstronautas[i]->nombre == astronauta) {
			return i;
		}
	}
}
/*Metodo que ordena los astronautas de menor a mayor años de experiencia*/
void ListaAstronauta::ordenarAstronautas()
{
	Astronauta* aux;
	for (int i = 0; i < this->cantActual-1; i++) {
		for (int j = i; j < this->cantActual; j++) {
			if (this->arrayAstronautas[i]->anios > this->arrayAstronautas[j]->anios) {
				aux = this->arrayAstronautas[i];
				this->arrayAstronautas[i] = this->arrayAstronautas[j];
				this->arrayAstronautas[j] = aux;
			}
		}
	}
}

/*Destructor de la clase*/
ListaAstronauta::~ListaAstronauta()
{
}
