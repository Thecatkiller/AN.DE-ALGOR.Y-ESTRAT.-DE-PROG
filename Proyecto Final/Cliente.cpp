#include "Cliente.h"
#include <iostream>
#include <string> 
#include <sstream>
using namespace std;

Cliente::Cliente(){
	
}

void Cliente::mostrar(){
	cout << endl << endl;
	cout << "Codigo: "  << this->_codigo << endl;
	cout << "Nombre: "  << this->_nombre << endl;
	cout << "Apellido Paterno: "  << this->_apellidoPaterno << endl;
	cout << "Apellido Materno: "  << this->_apellidoMaterno << endl;
	cout << "DNI: "  << this->_DNI << endl;
	cout << endl;	
}

void Cliente::pedirDatos(){
	int codigo;
	string nombre;
	string apellidoPaterno;
	string apellidoMaterno;
	string DNI;
	
	cout << endl << "Codigo (numero): ";
	cin >> codigo;
	this->setCodigo(codigo);
	
	cout << "Nombre: ";
	fflush(stdin);
	getline (cin,nombre);
	this->setNombre(nombre);
	
	cout << "Apellido Paterno: ";
	fflush(stdin);
	getline (cin,apellidoPaterno);
	this->setApellidoPaterno(apellidoPaterno);
		
	cout << "Apellido Materno: ";
	fflush(stdin);
	getline (cin,apellidoMaterno);
	this->setApellidoMaterno(apellidoMaterno);
	
	cout << "DNI: ";
	fflush(stdin);
	getline (cin,DNI);
	this->setDNI(DNI);
	

}

void Cliente::setCodigo(int codigo){
	this->_codigo = codigo;
}
void Cliente::setNombre(string nombre){
	this->_nombre = nombre;
}
void Cliente::setApellidoPaterno(string apellidoP){
	this->_apellidoPaterno = apellidoP;
}
void Cliente::setApellidoMaterno(string apellidoM){
	this->_apellidoMaterno = apellidoM;
}
void Cliente::setDNI(string DNI){
	this->_DNI = DNI;
}

void Cliente::setUsuario(Usuario* usuario){
	this->_usuario = usuario;
}

void Cliente::setCuentas(vector<Cuenta*> cuentas){
	this->_cuentas = cuentas;
}

int Cliente::getCodigo(){
	return this->_codigo;
}
string Cliente::getDNI(){
	return this->_DNI;
}
Usuario* Cliente::getUsuario(){
	return this->_usuario;
}
vector<Cuenta*> Cliente::getCuentas(){
	return this->_cuentas;
}

int Cliente::getCantidadCuentas(){
	return this->_cuentas.size();
}

string Cliente::toRaw(){
	string c = "";
	
	ostringstream temp; 
	temp << this->_codigo;

	c += temp.str() + ";";
	c += this->_nombre + ";";
	c += this->_apellidoPaterno + ";";
	c += this->_apellidoMaterno + ";";
	c += this->_DNI;
	
	return c;
}		
