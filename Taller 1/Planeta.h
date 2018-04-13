#pragma once
#include <string>
using namespace std;
class Planeta
{
public:
	Planeta();
	Planeta(string nombre, string distancia, string habitado, string* suminitros, int* cantSuministros,int cantListaSuministros);
	string nombre;
	string distancia;
	string habitado;
	string* suministros;
	int* cantSuministros;
	int cantListaSuministros;
	~Planeta();
};

