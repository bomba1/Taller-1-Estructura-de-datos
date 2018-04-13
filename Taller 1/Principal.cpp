#include "stdafx.h"
#include "Principal.h"






/*
Metodo que crea un nuevo csv con datos limpios
*/
void Principal::limpiarDato2()
{
	ofstream datosLimpios("N_planetas.csv", ios::out); //Variable de archivo de salida
	for (int i = 0; i < this->planeta->cantActual; i++) {
		datosLimpios << this->planeta->arregloPlaneta[i]->nombre << ",";
		datosLimpios << this->planeta->arregloPlaneta[i]->distancia << ",";
		datosLimpios << this->planeta->arregloPlaneta[i]->habitado << ",";
		for (int j = 0; j < this->planeta->arregloPlaneta[i]->cantListaSuministros; j++) {
			datosLimpios << this->planeta->arregloPlaneta[i]->suministros[j] << "," << this->planeta->arregloPlaneta[i]->cantSuministros[j] << endl;
		}
	}

}



Principal::Principal()
{
	leerAstronautas();
	leerNaves();
	leerPlanetas();
	menuPrincipal();



}



Principal::~Principal()
{
}


/*Este metodo es el que ejecuta el menu principal del programa
*/
void Principal::menuPrincipal() {

	bool menu = true;

	cout << "Bienvenido al sistema de ayuda de la Nasa" << endl;
	string opcion;
	while (menu) {  //While infinito que es usado para el menu principal

		cout << "Menu principal:" << endl;
		cout << "1.-Agregar nuevo dato\n2.-Listado de naves\n3.-Listado de astronautas ordenado\n4.-Manejar astronautas\n5.-Estado de mision\n6.-Limpiar datos corruptos\n7.-Crear archivos\n8.-Salir" << endl;
		getline(cin, opcion);
		try
		{
			std::stoi(opcion);
		}
		catch (const std::exception&)
		{
			cout << "Error,no escribio un numero" << endl;
			continue;
		}
		int opcionDef = std::stoi(opcion);

		switch (opcionDef) //Menu
		{
		case 1:
			subMenu();
			break;
		case 2:
			this->nave->imprimirListado();
			break;
		case 3:
			listadoAstronautas();
			break;
		case 4:
			subMenu2();
			break;
		case 5:
			cout << "Opcion aun no implementada" << endl;
			break;
		case 6:
			limpiarDato1();
			limpiarDato2();
			cout << "Se han limpiado los datos" << endl;
			break;
		case 7:
			cout << "No se ha implementado este metodo" << endl;
			break;
		case 8:
			cout << "!Adios, Buena suerte!" << endl;
			return;
		default:
			cout << "Error, ingrese un numero valido porfavor" << endl;
			break;
		}

	}
}
/*Este metodo ejecuta un el subMenu de la opcion 1
*/
void Principal::subMenu() {
	bool menu = true;
	cout << "Usted escogio Agregar nuevo dato" << endl;
	string opcion;
	while (menu) { //While infinito que sera usado para el submenu

		cout << "Escoja la opcion que desea agregar" << endl;
		cout << "1.-Astronauta\n2.-Nave\n3.-Planeta\n4.-Volver" << endl;
		getline(cin, opcion);
		try
		{
			std::stoi(opcion);
		}
		catch (const std::exception&)
		{
			cout << "Error,no escribio un numero" << endl;
			continue;
		}
		int opcionDef = std::stoi(opcion);

		switch (opcionDef) //Menu
		{
		case 1:
			agregarAstronauta();
			return;
		case 2:
			agregarNave();
			return;
		case 3:
			cout << "No hubo tiempo :c" << endl;
			break;
		case 4:
			cout << "Volviendo..." << endl;
			return;
		default:
			cout << "Error, ingrese un numero valido porfavor" << endl;
			break;
		}

	}
}
/*Este metodo ejecuta el subMenu  de la opcion 4
*/
void Principal::subMenu2() {
	bool menu = true;
	cout << "Usted escogio Manejar Astronautas" << endl;
	string opcion;
	while (menu) { //While infinito que sera usado para el submenu

		cout << "Escoja la opcion que desea" << endl;
		cout << "1.-Agregar astronauta a una nave\n2.-Mover astronauta\n3.-Volver" << endl;

		getline(cin, opcion);
		try
		{
			std::stoi(opcion);
		}
		catch (const std::exception&)
		{
			cout << "Error,no escribio un numero" << endl;
			continue;
		}
		int opcionDef = std::stoi(opcion);

		switch (opcionDef) //Menu
		{
		case 1:
			agregarNaveAstronauta();
			return;
		case 2:
			moverAstronauta();
			return;
		case 3:
			cout << "Volviendo..." << endl;
			return;
		default:
			cout << "Error, ingrese un numero valido porfavor" << endl;
			break;
		}

	}
}



/*Metodo que lee el archivo Astronautas.txt e introduce los datos a los arreglos
*/
void Principal::leerAstronautas() {
	ifstream archivo("Astronautas.txt"); //abre  el archivo Astronautas.txt
	
	string linea = "";
	int totalAstronautas = 0;
	getline(archivo, linea);//obtiene la primera linea del archivo(cantidad de astronautas)
	totalAstronautas = atoi(linea.c_str());//convierte el string a entero
	
	this->astronauta = new ListaAstronauta(totalAstronautas);
	
	for (int i = 0; i < totalAstronautas;i++) {
		
		
		getline(archivo, linea);//obtiene la linea del archivo
		string nombre = "";
		string auxEdad = "";
		int edad = 0;
		string auxAnio = "";
		int anio = 0;
		string nave = "";
		istringstream is(linea);
		getline(is, nombre, ',');
		getline(is, auxEdad, ',');
		edad = atoi(auxEdad.c_str());
		getline(is, auxAnio, ',');
		anio = atoi(auxAnio.c_str());
		getline(is, nave);
		this->astronauta->agregarAstronauta(nombre, edad, anio, nave);//se agrega un astronauta a la lista
		
		
	}
	archivo.close();
}
/*Metodo que valida la linea Nave.csv
*/
bool Principal::validarNave(string nombre, int cantTripulantes, string*suministros, int * cantidad, int contador) {
	int bueno = 0;

	if (nombre == "" || cantTripulantes == 0) {
		bueno = 1;
	}

	for (int i = 0; i < contador; i++) {
		if (suministros[i] == "" || cantidad[i] == 0) {
			bueno = 1;
		}
	}

	if (bueno == 1) {
		return false;
	}
	else {
		return true;
	}
}
/*Metodo que lee el archivo Naves.csv e introduce los datos a los arreglos
*/
void Principal::leerNaves() {
	ifstream archivo("Naves.csv");//Abre el archivo Naves.csv
	string linea = "";
	this->nave = new ListaNave();

	while (!archivo.eof()) {
		getline(archivo, linea);
		string nombre = "";
		string destino = "";
		string Tripulantes = "";
		int cantTripulantes = 0;
		//Parametros de la nave
		
		string auxSuminitros = "";
		string auxCantSuminitros = "";
		int auxCant = 0;
		int contador = 0;
		string * suministros = new string[100];
		int * cantidad = new int[100];
		//lista de suministros
		
		istringstream is(linea);
		getline(is, nombre, ',');
		getline(is, destino, ',');
		getline(is, Tripulantes, ',');
		cantTripulantes = atoi(Tripulantes.c_str());

		bool terminado = true;

		while (terminado != false) {
			getline(is, auxSuminitros, ',');
			getline(is, auxCantSuminitros, ',');
			auxCant = atoi(auxCantSuminitros.c_str());

			if (auxSuminitros == suministros[contador - 1] || auxCant == cantidad[contador - 1]) {
				terminado = false;
			}
			else {
				suministros[contador] = auxSuminitros;
				cantidad[contador] = auxCant;
				contador++;
			}

			if (auxSuminitros == "" || auxCant == 0) {
				terminado = false;
			}
		}//fin del while

		bool validar = validarNave(nombre, cantTripulantes, suministros, cantidad, contador);
		if (validar == true) {
			this->nave->agregarNave(nombre, destino, cantTripulantes, suministros, cantidad, contador);
		}
		
	}


}
/*Metodo que valida las lineas del archivo Planetas.csv
*/
bool Principal::validarPlaneta(string nombre, string distancia,string habitado, string*suministros, int * cantidad, int contador) {
	int bueno = 0;

	if (nombre == "" || distancia == "" || habitado == "") {
		bueno = 1;
	}

	for (int i = 0; i < contador; i++) {
		if (suministros[i] == "" || cantidad[i] == 0) {
			bueno = 1;
		}
	}

	if (bueno == 1) {
		return false;
	}
	else {
		return true;
	}
}
/*Metodo que crea un nuevo csv con datos limpios
*/
void Principal::limpiarDato1()
{
	ofstream datosLimpios("N_naves.csv", ios::out); //Variable de salida
	for (int i = 0; i < this->nave->cantActual; i++) {
		datosLimpios << this->nave->arregloNave[i]->nombre << ",";
		datosLimpios << this->nave->arregloNave[i]->destino << ",";
		datosLimpios << this->nave->arregloNave[i]->cantTripulantes << ",";
		for (int j = 0; j < this->nave->arregloNave[i]->CantListaSuministros; j++) {
			datosLimpios << this->nave->arregloNave[i]->suministros[j] << "," << this->nave->arregloNave[i]->cantSuministros[j] << endl;
		}
	}

}
/*Metodo que lee el archivo planetas.csv e introduce los datos al arreglo
*/
void Principal::leerPlanetas() {
	ifstream archivo("Planetas.csv");//Abre el archivo Planetas
	string linea = "";
	this->planeta = new ListaPlaneta();

	while (!archivo.eof()) {
		getline(archivo, linea);
		//Datos del Planeta
		string nombre = "";
		string distancia = "";
		string habitado = "";
		

		//lista de suministros
		string auxNom = "";
		string auxAuxCant = "";
		int auxCant = 0;
		int contador = 0;
		string * suministros = new string[100];
		int * cantidad = new int[100];

		istringstream is(linea);
		getline(is, nombre, ',');
		getline(is, distancia, ',');
		getline(is, habitado, ',');
		

		bool terminado = true;

		while (terminado != false) {
			getline(is, auxNom, ',');
			getline(is, auxAuxCant, ',');
			auxCant = atoi(auxAuxCant.c_str());

			if (auxNom == suministros[contador - 1] || auxCant == cantidad[contador - 1]) {
				terminado = false;
			}
			else {
				suministros[contador] = auxNom;
				cantidad[contador] = auxCant;
				contador++;
			}

			if (auxNom == "" || auxCant == 0) {
				terminado = false;
			}
		}//fin del while

		bool validar = validarPlaneta(nombre, distancia ,habitado, suministros, cantidad, contador);
		if (validar == true) {
			this->planeta->agregarPlaneta(nombre, distancia, habitado, suministros, cantidad, contador);
		}
	}


}
/*Metodo que imrpime a los astronautas segun sus años de experiencia
*/
void Principal::listadoAstronautas()
{
	cout << "Astronautas segun sus años de experiencia de menor a mayor: " << endl;
	astronauta->imprimirAstronautas();
}
/*Metodo para agregar un astronauta desde la consola
*/
void Principal::agregarAstronauta() {
	bool bucle = true;
	string nombre = "";
	int edad = 0;
	int anios = 0;
	string nave = "";
	string pregunta = "";

	cout << "Ingrese el nombre del astronauta:" << endl;
	getline(cin, nombre);

	cout << "Ingrese la edad del astronauta " << endl;
	cin >> edad;

	cout << "Ingrese los anios de experiencia" << endl;
	cin >> anios;
	
	cout << "¿Quiere designarle una nave?" << endl;
	while (bucle) { 
		
		getline(cin, pregunta);
		if (pregunta == "si") {
			while (bucle) {
				cout << "Escriba la nave a la cual lo quiere designar" << endl;
				getline(cin, nave);
				if (this->nave->buscarNave(nave)) {
					cout << "Nave encontrada" << endl;
					cout << "Agregando astonauta..." << endl;
					this->astronauta->agregarAstronauta(nombre, edad, anios, nave);
					return;
				}
				else {
					cout << "Nave no encontrada" << endl;
					continue;
				}
			}
		}
		else if (pregunta == "no") {
			cout << "Agregando astronauta..." << endl;
			this->astronauta->agregarAstronauta(nombre, edad, anios, nave);
			return;
		}
		else {
			cout << "Escriba si o no porfavor" << endl;
			continue;
		}
	}


}
/*Metodo que agrega una nave desde la consola
*/
void Principal::agregarNave()
{
	bool bucle = true;
	string nombre = "";
	string destino = "";
	int cantTripulantes = 0;
	string* suministros = new string[100];
	int* cantSuministros = new int[100];
	string pregunta = "";
	string auxSuministro = "";
	int auxCantidad = 0;
	string pregunta2 = "si";
	int i = 0;

	cout << "Ingrese el nombre de la nave" << endl;
	getline(cin, nombre);

	cout << "Quiere ingresar el destino de la nave?" << endl;
	while (bucle) {
		getline(cin, pregunta);
		if (pregunta == "si") {
			while (bucle) { //While infinito para validar
				cout << "Ingrese el nombre del destino" << endl;
				getline(cin, destino);
				if (this->planeta->buscarDestino(destino)) {
					cout << "Destino encontrado" << endl;
					break;
				}
				else {
					cout << "Destino no encontrado" << endl;
					continue;
				}
			}
			break;
		}
		else if (pregunta == "no") {
			cout << "Sigamos" << endl;
			break;
		}
		else {
			cout << "Escriba si o no porfavor" << endl;
			continue;
		}

	}
	cout << "Ingrese la cantidad maxima de tripulantes" << endl;
	cin >> cantTripulantes;

	while (pregunta2 == "si") { //Sigue preguntando hasta que el usuario no quiera agregar mas suministros
		cout << "Ingrese el nombre del suministro " << i + 1 << endl;
		cin>>auxSuministro;
		suministros[i] = auxSuministro;
		
		cout << "Ingrese la cantidad de " << auxSuministro << endl;
		cin >> auxCantidad;
		cantSuministros[i] = auxCantidad;
		
		i++;
		

		cout << "Desea agregar otro suministro?(si para seguir, cualquier cosa para no seguir)" << endl;
		cin >> pregunta2;
	}
	cout << "Agregando nave..." << endl;
	this->nave->agregarNave(nombre, destino, cantTripulantes, suministros, cantSuministros, i);
	return;
	

}
/*Metodo  que le designa una nave a algun astronauta que no tenga
*/
void Principal::agregarNaveAstronauta()
{
	bool bucle = true;
	string opcion = "";
	string nave = "";
	this->astronauta->imprimirAstronautasSinNave();

	while (bucle) { //While infinito para validar
		cout << "A quien desea agregarle una nave?(Escriba su nombre porfavor respetando las mayusculas)" << endl;
		cin >> opcion;
		if (this->astronauta->buscarAstronauta(opcion)) {
			while (bucle) { //While infinito para validar
				cout << "Cual nave desea designarle al astronauta elegido?" << endl;
				cin >> nave;

				if (this->nave->buscarNave(nave)) {
					this->astronauta->arrayAstronautas[this->astronauta->devolverNumero(opcion)]->nave = nave;
					cout << "Nave asignada" << endl;
					return;
				}
				else {
					cout << "Nave no encontrada" << endl;
					continue;
				}
			}
		}
		else {
			cout << "Astronauta no encontrado" << endl;
			continue;
		}
	}
}
/*Metodo que le reasigna una nave a un astronauta
*/
void Principal::moverAstronauta() {
	string nave = "";
	bool bucle = true;
	string nave2 = "";
	string opcion = "";

	while (bucle) { //While infinito para validar
		cout << "Desde cual nave quiere mover al astronauta?" << endl;
		cin >> nave;

		if (this->nave->buscarNave(nave)) {
			cout << "Nave de origen encontrada" << endl;
			break;
		}
		else {
			cout << "Nave no encontrada" << endl;
			continue;
		}
	}

	while (bucle) { //While infinito para validar
		cout << "A cual nave quiere mover al astronauta?" << endl;
		cin >> nave2;

		if (this->nave->buscarNave(nave2)) {
			cout << "Nave de destino encontrada" << endl;
			break;
		}
		else {
			cout << "Nave no encontrada" << endl;
			continue;
		}
	}
	this->astronauta->imprimirAstronautasOrigen(nave);
	

	while (bucle) { //While infinito para validar
		cout << "Cual astronauta desea que pase de " << nave << " a " << nave2 << "?" << endl;
		cin >> opcion;
		if (this->astronauta->buscarAstronauta(opcion)) {
			this->astronauta->arrayAstronautas[this->astronauta->devolverNumero(opcion)]->nave = nave2;
			cout << "Nave cambiada" << endl;
			return;
		}
		else {
			cout << "Astronauta no encontrado" << endl;
			continue;
		}
	}
}




