#include "Divisa.h"
#include <iostream>
#include <string> 
#include <sstream>

using namespace std;

Divisa::Divisa(){
	this->_estado = true;
}

Divisa::Divisa(int codigo,string nombre,string simbolo,bool estado){
	this->_codigo = codigo;
	this->_nombre = nombre;
	this->_simbolo = simbolo;
	this->_estado = estado;
}


int Divisa::getCodigo(){
	return this->_codigo;
}

bool Divisa::getEstado(){
	return this->_estado;
}

string Divisa::getSimbolo(){
	return this->_nombre;
}

string Divisa::getNombre(){
	return this->_nombre;
}

string Divisa::toRaw(){
	ostringstream temp; 
	
	temp << this->_codigo << ";";
	temp << this->_nombre << ";";
	temp << this->_simbolo << ";";
	temp << this->_estado;
	
	return temp.str();
}

void Divisa::pedirDatos(){	
	cout << endl << "Codigo (numero): ";
	cin >> this->_codigo;
	
	cout << "Nombre: ";
	fflush(stdin);
	getline (cin,this->_nombre);
	
	cout << "Simbolo: ";
	fflush(stdin);
	getline (cin,this->_simbolo);
}
