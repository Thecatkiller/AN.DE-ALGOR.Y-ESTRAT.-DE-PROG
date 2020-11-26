#include "Cuenta.h"
#include <iostream>
#include <cstdlib>   
#include <ctime> 
#include <string> 
#include <sstream>

using namespace std;
Cuenta::Cuenta(int codigoCliente){
	srand(time(0));	
	_saldo = 0;
	_codigoCliente=codigoCliente;
	_codigo=(rand() % 9999999 + 100000); ;
	_estado= true;
}
Cuenta::Cuenta(){
	
}

void Cuenta::mostrar(){
	
	cout << endl << "Cuenta : " << endl;
	cout << "-----------------------------------" << endl;
	cout << "\tCodigo : " << this->_codigo << endl;
	cout << "\tEstado : " << this->_estado << endl;
	cout << "\tSaldo : " << this->_saldo << endl << endl;
}


void Cuenta::mostrarResumen(){
	string estado = this->_estado ? "activo" : "inactivo";
	cout << this->_codigo;
	cout << "\t\t S/. " << this->_saldo;
	cout << "\t\t " << estado << endl;
}

void Cuenta::setCodigo(int codigo){
	this->_codigo = codigo;
}
void Cuenta::setCodigoCliente(int codigoCliente){
	this->_codigoCliente = codigoCliente;
}
void Cuenta::setEstado(bool estado){
	this->_estado = estado;
}
void Cuenta::setSaldo(double saldo){
	this->_saldo = saldo;
}

int Cuenta::getCodigoCliente(){
	return this->_codigoCliente;
}

int Cuenta::getCodigo(){
	return this->_codigo;
}

bool Cuenta::retirar(double monto){
	double balance = this->_saldo - monto;
	
	if(balance < 0){
		cout << endl << "El monto a retirar supera el saldo de la cuenta";
		return false;
	}
	
	this->_saldo = balance;
	
	return true;
}

double Cuenta::getSaldo(){
	return this->_saldo;
}

string Cuenta::getCodigoConCeros(){
	ostringstream data; 
	char cuenta[13];
	sprintf(cuenta, "%012d", this->getCodigo());
	data << cuenta;
	return data.str();
}

string Cuenta::toRaw(){
	ostringstream data; 
	data << this->_codigo << ";";
	data << this->_codigoCliente << ";";
	data << this->_estado << ";";
	data << this->_saldo;
	return data.str();
}	


