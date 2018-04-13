#pragma once
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
class Astronauta
{
public:
	Astronauta();
	Astronauta(string nombre, int edad, int anios, string nave);
	
	string nombre;
	int edad;
	int anios;
	string nave;


    ~Astronauta();
private:

};

