#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include "Usuario.h"
#include "Cuenta.h"
#include <vector>
using namespace std;

class Cliente{
	private:
		int _codigo;
		string _nombre;
		string _apellidoPaterno;
		string _apellidoMaterno;
		string _DNI;
		Usuario* _usuario;
		vector<Cuenta*> _cuentas;
		
	public:
		Cliente();
		void mostrar();
		string toRaw();
		void pedirDatos();
		void setCodigo(int codigo);
		void setNombre(string nombre);
		void setApellidoPaterno(string apellidoP);
		void setApellidoMaterno(string apellidoM);
		void setDNI(string DNI);
		void setUsuario(Usuario* usuario);
		void setCuentas(vector<Cuenta*> cuentas);
		int getCodigo();
		string getDNI();
		Usuario* getUsuario();
		vector<Cuenta*> getCuentas();
		int getCantidadCuentas();
};


#endif
