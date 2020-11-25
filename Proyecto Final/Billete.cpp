#include "Billete.h"

#include <iostream>
#include <cstdlib>   
#include <ctime> 
#include <string> 
#include <sstream>

using namespace std;

Billete::Billete(){
	
}
Billete::Billete(int codigoCajero,ValorBillete valorBillete,int cantidad){
	this->_codigoCajero = codigoCajero;
	this->_valorBillete = valorBillete;
	this->_cantidad = cantidad;
}

int Billete::getCodigoCajero(){
	return this->_codigoCajero;
}

double Billete::getMonto(){
	return this->_cantidad * (int)this->_valorBillete * 1.0;
}

ValorBillete Billete::getValorBillete(){
	return this->_valorBillete;
}

int Billete::getCantidad(){
	return this->_cantidad;
}

void Billete::setCantidad(int cantidad){
	this->_cantidad = cantidad;
}


string Billete::toRaw(){
	ostringstream data; 
	data << this->_codigoCajero << ";";
	data << this->_valorBillete << ";";
	data << this->_cantidad;
	return data.str();	
}
