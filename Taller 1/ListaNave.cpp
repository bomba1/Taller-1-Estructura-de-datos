#include "stdafx.h"
#include "ListaNave.h"

/*Constructor de la clase
*/
ListaNave::ListaNave()
{
	this->cantActual = 0;
	this->arregloNave = new Nave*[200];
}
/*Metodo que agrega una nave desde el metodo leerNave*/
void ListaNave::agregarNave(string nombre, string destino, int cantMax, string* suministros, int* cantidad, int cantListaSuministros) {
	Nave* nuevaNave = new Nave(nombre, destino, cantMax, suministros, cantidad, cantListaSuministros);
	this->arregloNave[this->cantActual] = nuevaNave;
	this->cantActual = this->cantActual + 1;
}
/*Metodo que busca una nave en el arreglo*/
bool ListaNave::buscarNave(string nave)
{
	for (int i = 0; i < this->cantActual; i++) {
		if (this->arregloNave[i]->nombre == nave) {
			return true;
		}
	}
	return false;
}

/*Destructor de la clase*/
ListaNave::~ListaNave()
{
}
/*Metodo que imprime todas las naves*/
void ListaNave::imprimirNave()
{
	
	for (int i = 0; i < this->cantActual; i++) {
		cout << i + 1 << ".-" << "Nombre:" << this->arregloNave[i]->nombre << endl;


	}
	return;
}
/*Metodo que imprime el requerimiento 3
*/
void ListaNave::imprimirListado()
{
	for (int i = 0; i < this->cantActual; i++) {
		if (this->arregloNave[i]->destino == "") {
			cout << i + 1 << ".-" << "Nombre:" << this->arregloNave[i]->nombre << " - " << "Destino:" << "No tiene" << " - " << "MaxTripulantes:" << this->arregloNave[i]->cantTripulantes << " - " << "Listado de tripulantes:" << "Casi :("<<"" << endl;;
			for (int j = 0; j < this->arregloNave[i]->CantListaSuministros; j++) {
				cout <<"ListaSuministros: "<<" - "<< this->arregloNave[i]->suministros[j] << " - " << this->arregloNave[i]->cantSuministros[j] << endl;
			}
		}
		else {
			cout << i + 1 << ".-" << "Nombre:" << this->arregloNave[i]->nombre << " - " << "Destino:" << this->arregloNave[i]->destino << " - " << "MaxTripulantes:" << this->arregloNave[i]->cantTripulantes << " - " << "Listado de tripulantes:" << "Casi :(";
			for (int j = 0; j < this->arregloNave[i]->CantListaSuministros; j++) {
				cout << "ListaSuministros: " << " - " << this->arregloNave[i]->suministros[j] << " - " << this->arregloNave[i]->cantSuministros[j] << endl;
			}
		}


	}
}
