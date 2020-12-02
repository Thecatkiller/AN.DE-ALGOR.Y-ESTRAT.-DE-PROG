#ifndef CUENTA_H
#define CUENTA_H
#include <iostream>
using namespace std;

class Cuenta{
	private:
		int _codigo;
		int _codigoCliente;
		bool _estado;
		double _saldo;
	
	public:		
		Cuenta(int codigoCliente);
		Cuenta();					
		void mostrar();
		void mostrarResumen();
		void grabar();
		void setCodigo(int codigo);
		void setCodigoCliente(int codigoCliente);
		void setEstado(bool estado);
		void setSaldo(double saldo);
		string toRaw();
		int getCodigoCliente();
		bool retirar(double monto);
		double getSaldo();
		int getCodigo();
		string getCodigoConCeros();
};


#endif
