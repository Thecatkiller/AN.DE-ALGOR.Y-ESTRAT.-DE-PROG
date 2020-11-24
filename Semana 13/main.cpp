#include <iostream>
#include <fstream>
#include <conio.h>

struct Clientes{
	int codigo;
	char nombre[30];
	double saldo;
};

using namespace std;

char menu();
void agregar();
void listar();

const string ARCHIVO_CLIENTE = "clientes.txt";


int main() {
	char alt;
	
	do{
		alt = menu();
		switch (alt){
			case '1':{
				agregar();			
				break;
			}
			case '2':{
				listar();			
				break;
			}
		}
	}while (alt!='9');
	
	
	
	return 0;
}

char menu(){
	setlocale(LC_ALL,"spanish");
	cout << "Menu Clientes"      << endl;
	cout << "[1] Agregar"        << endl;
	cout << "[2] Listar"         << endl;
	cout << "[9] Salir  "        << endl;
	cout << "Seleccione opción:";
	fflush(stdin);
	return getche();
}

void agregar(){
	Clientes c;
	cout << endl << "Codigo:";
	cin >> c.codigo;
	cout << "Nombre:";
	fflush(stdin);
	cin.getline(c.nombre,30);
	cout << "Saldo:";
	cin >> c.saldo;
	
	ofstream fescribir;
	fescribir.open(ARCHIVO_CLIENTE.c_str(),ios::out|ios::app);
	
	fescribir << c.codigo << ";" ;
	fescribir << c.nombre << ";" ;
	fescribir << c.saldo  << ";" ;
	
	fescribir.close();
}

void listar(){
	 ifstream aleer;
	 aleer.open(ARCHIVO_CLIENTE.c_str(),ios::in);  
	 if (!aleer.is_open()){
	 	cout << "No se puede abrir el archivo: " << ARCHIVO_CLIENTE << endl;
		return ;	 	
	 }
	 cout << endl << "Listado" << endl;
	 cout.width(10);
	 cout << left << "codigo";
	 cout.width(30);
	 cout << left << "nombre";
	 cout.width(12);
	 cout << right << "saldo" << endl;	 		
	 
	 
	 string codigo,nombre,saldo;
	 while (!aleer.eof()){
	 	getline(aleer,codigo,';');
	 	getline(aleer,nombre,';');
	 	getline(aleer,saldo,';');
	 	if (codigo.length()>1){
	 		cout.width(10);
	 		cout << left << codigo;
	 		cout.width(30);
	 		cout << left << nombre;
	 		cout.width(12);
	 		cout << right << saldo << endl;	 		
		}
	 }	 
	 aleer.close();
}
