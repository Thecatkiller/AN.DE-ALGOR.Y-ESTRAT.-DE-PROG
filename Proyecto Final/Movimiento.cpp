#include "Movimiento.h"

#include <ctime>
#include <iostream>
#include <stdio.h>
#include <sstream>
using namespace std;

Movimiento::Movimiento(int codigoCuenta,double monto){
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
}

