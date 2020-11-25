#include <iostream>
#include <fstream>
#include <conio.h>
#include<cstdlib>
#include<cstring>

struct Clientes{
	int codigo;
	char nombre[30];
	double saldo;
};

using namespace std;

char menu();
void agregar();
void listar();
Clientes buscarCliente(int codcli);
Clientes modificarCliente(int codcli);

const string ARCHIVO_CLIENTE = "clientes.txt";
const string ARCHIVO_TEMPORAL = "temporal.txt";

int main() {
	char alt;
	int codigo;
	
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
			case '3':{
				cout<<"Ingrese codigo:";
				cin>>codigo;
				cout<<endl;
				Clientes c=buscarCliente(codigo);
				if(c.codigo==-1){
					cout<<endl<<"No se encontro codigo:"<<codigo<<endl;
				}else{
					cout<<c.codigo<<endl;
					cout<<c.nombre<<endl;
					cout<<c.saldo<<endl;
				}
				break;
			}
			case '4':{
				cout<<"Ingrese codigo:";
				cin>>codigo;
				cout<<endl;
				Clientes c=modificarCliente(codigo);
				if(c.codigo==-1){
					cout<<endl<<"No se encontro codigo:"<<codigo<<endl;
				}else{
					cout<<c.codigo<<endl;
					cout<<c.nombre<<endl;
					cout<<c.saldo<<endl;
				}	
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
	cout << "[3] Buscar"         << endl;
	cout << "[4] Modificar"      << endl;
	cout << "[9] Salir  "        << endl;
	cout << "Seleccione opción:";
	fflush(stdin);
	return getche();
}

void agregar(){
	int codigo;
	Clientes c;
	cout<<endl<<"Agregar"<<endl;
	do{
		cout << endl << "Codigo:";
		cin>>codigo;
		c=buscarCliente(codigo);
		if(c.codigo!=-1){
			cout<<"Codigo registrado:"<<endl;
			cout<<c.codigo<<endl;
			cout<<c.nombre<<endl;
			cout<<c.saldo<<endl;
		}
	}while(c.codigo!=-1);
	
	c.codigo=codigo;
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

Clientes buscarCliente(int codcli){
	Clientes c;
	c.codigo=-1;
	
	ifstream aleer;
	aleer.open(ARCHIVO_CLIENTE.c_str(),ios::in);
	if (!aleer.is_open()){
	 	cout << "No se puede abrir el archivo: " << ARCHIVO_CLIENTE << endl;
		return c;	 	
	}
	string codigo,nombre,saldo;
	while (!aleer.eof()){
	 	getline(aleer,codigo,';');
	 	getline(aleer,nombre,';');
	 	getline(aleer,saldo,';');
	 	
	 	int cod=atoi(codigo.c_str());
	 	if(cod==codcli){
	 		c.codigo=cod;
	 		strcpy(c.nombre,nombre.c_str());
	 		c.saldo=atof(saldo.c_str());
	 		break;
		 }
	}
	aleer.close();
	return c;
}
Clientes modificarCliente(int codcli){
	Clientes c = buscarCliente(codcli); 
	if (c.codigo == -1){		
		return c;
	}
	cout << c.codigo << endl;
	cout << c.nombre << endl;
	cout << c.saldo  << endl;
	fflush(stdin);
	cout << "Nombre:";
	cin.getline(c.nombre,30);
	
	cout << "Saldo:";
	cin >> c.saldo;// en caso de retiro: que esto sea retiro
	
	ofstream fescribir;
	fescribir.open(ARCHIVO_TEMPORAL.c_str(),ios::out);	
	
	ifstream aleer;
	aleer.open(ARCHIVO_CLIENTE.c_str(),ios::in);
	if (!aleer.is_open()){
		cout << "No se puede abrir el archivo:" << ARCHIVO_CLIENTE << endl;
		c.codigo = -1;
		return c;
	}
	
	string codigo, nombre, saldo;
	while (!aleer.eof()){
		getline(aleer,codigo,';');
		getline(aleer,nombre,';');
		getline(aleer,saldo,';');
		
		if (codigo.length()>1){
		int cod = atoi(codigo.c_str());
		if (cod == codcli){
			fescribir << cod << ";";
			fescribir << c.nombre << ";";
			fescribir << c.saldo << ";";		
		} else {
			fescribir << codigo << ";";
			fescribir << nombre << ";";
			fescribir << saldo << ";";	//en caso de retiro: saldo - retiro	
		}		
	}
	}
	fescribir.close();
	aleer.close();	
	remove(ARCHIVO_CLIENTE.c_str());
	rename(ARCHIVO_TEMPORAL.c_str(),ARCHIVO_CLIENTE.c_str());		
	return c;
}
