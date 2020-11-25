#include "Usuario.h"
#include <iostream>
#include <string> 
#include <sstream>

Usuario::Usuario(int codigoCliente,string dniCliente){
	this->_codigoCliente = codigoCliente;
	this->_estado = true;
	this->_clave = dniCliente;
}

Usuario::Usuario(){
	
}

void Usuario::mostrar(){	
	cout << "Usuario : " << endl;
	cout << "-----------------------------------" << endl;
	cout << "\tCodigo Cliente : " << this->_codigoCliente;
	cout << "\tEstado : " << this->_estado;
	cout << "\tClave : " << this->_clave;
}

void Usuario::setEstado(bool estado){
	this->_estado = estado;
}
void Usuario::setClave(string clave){
	this->_clave = clave;
}
void Usuario::setCodigoCliente(int codigoCliente){
	this->_codigoCliente = codigoCliente;
}

bool Usuario::validarClave(string claveIngresada){
	return this->_clave == claveIngresada;
}

int Usuario::getCodigoCliente(){
	return this->_codigoCliente;
}

string Usuario::toRaw(){
	ostringstream data; 
	data << this->_codigoCliente << ";";
	data << this->_clave << ";";
	data << this->_estado;
	return data.str();		
}
