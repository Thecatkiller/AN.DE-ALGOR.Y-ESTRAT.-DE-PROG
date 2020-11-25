#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H
#include <iostream>

using namespace std;

class Movimiento{
	private:
		string _codigo;
		int _codigoCuenta;
		double _monto;
		int _fecha_dia;
		int _fecha_mes;
		int _fecha_anio;
		int _fecha_hora;
		int _fecha_minuto;
		int _fecha_segundo;
	public: 
		//Movimiento();
		Movimiento(int codigoCuenta,double monto);
		string toRaw();
};


#endif
