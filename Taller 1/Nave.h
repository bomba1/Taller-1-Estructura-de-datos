#pragma once
#include <string>
using namespace std;
class Nave
{
public:
	Nave();
	Nave(string nombre, string destino, int cantTripulantes, string* suministros, int* cantSuministros,int CantListaSuministros);
	string nombre;
	string destino;
	int cantTripulantes;
	string* suministros;
	int* cantSuministros;
	int CantListaSuministros;
	~Nave();
};

