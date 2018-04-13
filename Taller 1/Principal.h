#pragma once

#include "ListaAstronauta.h"
#include "ListaNave.h"
#include "ListaPlaneta.h"
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class Principal
{
public:
	void menuPrincipal();
	void subMenu();
	void subMenu2();

	void leerAstronautas();
	void leerNaves();
	void leerPlanetas();
	void listadoAstronautas();
	void agregarAstronauta();
	void agregarNave();
	void agregarNaveAstronauta();
	bool validarNave(string nombre, int cantTripulantes, string*suministros, int * cantidad, int contador);
	bool validarPlaneta(string nombre, string distancia, string habitado, string *suministros, int* cantidad, int contador);
	void limpiarDato1();
	void limpiarDato2();
	void moverAstronauta();
	
	Principal();
	~Principal();


private:
	ListaAstronauta* astronauta;
	ListaNave* nave;
	ListaPlaneta* planeta;
	



};
