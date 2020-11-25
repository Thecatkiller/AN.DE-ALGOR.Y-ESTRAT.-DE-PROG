#include "Movimiento.h"

#include <ctime>
#include <iostream>
#include <stdio.h>
#include <sstream>
using namespace std;

Movimiento::Movimiento(int codigoCuenta,double monto, int codigoCajero){
	//obtiene la hora del sistema
	time_t t = time(0); 
	tm* now = localtime(&t);
			
	this->_codigoCuenta = codigoCuenta;
	this->_monto = monto;	

	this->_fecha_dia = now->tm_mday;
	this->_fecha_mes = now->tm_mon + 1;
	this->_fecha_anio = (now->tm_year + 1900);
	this->_fecha_hora = now->tm_hour;
	this->_fecha_minuto = now->tm_min;
	this->_fecha_segundo = now->tm_sec;
	
	ostringstream data; 
		
	char cuenta[13];
	char fecha[15];
	//ddMMyyyyHHmmss
	sprintf(cuenta, "%012d", _codigoCuenta);
	sprintf(fecha, "%02d%02d%04d%02d%02d%02d", _fecha_dia, _fecha_mes, _fecha_anio,_fecha_hora,_fecha_minuto,_fecha_segundo);
	
	data << cuenta << "-";
	data << fecha;
	
	this->_codigo = data.str();
	this->_codigoCajero = codigoCajero;
	
}

Movimiento::Movimiento(string codigo,int codigoCuenta,double monto,int dia,int mes,int anio,int hora,int minuto,int segundo,int codigoCajero){
	this->_codigo = codigo;
	this->_codigoCuenta = codigoCuenta;
	this->_monto = monto;
	this->_fecha_dia = dia;
	this->_fecha_mes = mes;
	this->_fecha_anio = anio;
	this->_fecha_hora = hora;
	this->_fecha_minuto = minuto;
	this->_fecha_segundo = segundo;
	this->_codigoCajero = codigoCajero;
}

int Movimiento::getCodigoCuenta(){
	return this->_codigoCuenta;
}

void Movimiento::mostrarDetalle(){	
	char fecha[30];
	sprintf(fecha, "%02d:%02d:%02d %02d/%02d/%04d",_fecha_hora,_fecha_minuto,_fecha_segundo, _fecha_dia, _fecha_mes, _fecha_anio);
	cout << "\t S/. " <<  this->_monto << "\t\t";
	//cout << fecha << "\t" << this->_codigoCuenta <<  endl;
	cout << fecha << endl;
}
string Movimiento::getCodigo(){
	return this->_codigo;
}
string Movimiento::toRaw(){
	ostringstream data; 
	data << this->_codigo << ";";
	data << this->_codigoCuenta << ";";
	data << this->_monto << ";";
	data << this->_fecha_dia << ";";
	data << this->_fecha_mes << ";";
	data << this->_fecha_anio << ";";
	data << this->_fecha_hora << ";";
	data << this->_fecha_minuto << ";";
	data << this->_fecha_segundo << ";";
	data << this->_codigoCajero;
	return data.str();		
}


