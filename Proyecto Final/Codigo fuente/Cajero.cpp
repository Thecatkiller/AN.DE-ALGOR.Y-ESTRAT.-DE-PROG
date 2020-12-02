#include "Cajero.h"
#include <iostream>
#include <string> 
#include <sstream>
#include <vector>

using namespace std;

Cajero::Cajero(){
	this->_estado = true;
}

Cajero::Cajero(int codigo,bool estado,string ubicacion){
	this->_codigo = codigo;
	this->_estado = estado;
	this->_ubicacion = ubicacion;
}

void Cajero::pedirDatos(){
	int codigo;
	string ubicacion;
	cout << endl << "Codigo (numero): ";
	cin >> codigo;
	this->_codigo = codigo;
	
	cout << "Ubicacion: ";
	fflush(stdin);
	getline (cin,ubicacion);
	this->_ubicacion = ubicacion;
}

int Cajero::getCodigo(){
	return this->_codigo;
}

void Cajero::setBilletes(vector<Billete*> billetes){
	this->_billetes = billetes;
}

vector<Billete*> Cajero::getBilletes(){
	return this->_billetes;
}

double Cajero::getMontoTotal(){
	double monto = 0;
	for(int i=0; i < this->_billetes.size();i++){			
		Billete* b = this->_billetes.at(i);
		monto+= b->getMonto();
	}
	return monto;
}

string Cajero::getUbicacion(){
	return this->_ubicacion;
}

string Cajero::getUbicacionCorta(){
	
	int len = this->_ubicacion.length();
	
	if(len > 10){
		return this->_ubicacion.substr(0,10);  
	}
	
	return this->_ubicacion;
}


Billete* Cajero::getBilletesPorDenominacion(ValorBillete valorBillete){
	Billete* billete= NULL;
	for(int i=0; i < this->_billetes.size();i++){			
		Billete* b = this->_billetes.at(i);
		if(b->getValorBillete() == valorBillete){
			billete = b;
			break;
		}
	}
	return billete;
}

void Cajero::mostrar()
{
	cout << endl << "Cajero : " << endl;
	cout << "-----------------------------------" << endl;
	cout << "\tCodigo : " << this->_codigo << endl;
	string estado = (this->_estado == true ? "activo" : "inactivo");
	cout << "\tEstado : " << estado << endl;
	cout << "\tUbicacion : " << this->_ubicacion << endl;
	cout << "\tMonto Total : " << this->getMontoTotal() << endl << endl;
	
	int billete[] = { 200 , 100 , 50 , 20 , 10 };		
	int tam = sizeof(billete) / sizeof(*billete);
	
	for(int i = 0; i < tam; i++){
		Billete* b = this->getBilletesPorDenominacion((ValorBillete) billete[i]);
		cout << "\t" <<billete[i] << " x " << b->getCantidad() << " : " << b->getMonto() << endl;
	}
	
}
string Cajero::toRaw(){	
	ostringstream temp; 
	temp << this->_codigo << ";";
	temp << this->_estado << ";";
	temp << this->_ubicacion;
	return temp.str();
}
