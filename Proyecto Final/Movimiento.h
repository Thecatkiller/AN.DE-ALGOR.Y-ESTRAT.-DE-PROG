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
		int _codigoCajero;
		string _descripcion;
	public: 
		//Movimiento();
		Movimiento(int codigoCuenta,double monto,int codigoCajero,string _descripcion);
		Movimiento(string codigo,int codigoCuenta,double monto,int dia,int mes,int anio,int hora,int minuto,int segundo,int codigoCajero,string descripcion);
		string toRaw();
		int getCodigoCuenta();
		string getCodigoCuentaConCeros();
		void mostrarDetalle(string saldo);
		string getCodigo();
		double getMonto();
		int getCodigoCajero();
};


#endif
