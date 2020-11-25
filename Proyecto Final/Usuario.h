#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
using namespace std;

class Usuario{
	private:
		bool _estado;
		string _clave;
		int _codigoCliente;
	
	public:		
		Usuario(int codigoCliente,string dniCliente);
		Usuario();					
		void mostrar();
		void setEstado(bool estado);
		void setClave(string clave);	
		void setCodigoCliente(int codigoCliente);
		string toRaw();
		bool validarClave(string claveIngresada);
		int getCodigoCliente();
};


#endif
