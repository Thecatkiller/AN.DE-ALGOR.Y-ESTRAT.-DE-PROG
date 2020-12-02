#ifndef DIVISA_H
#define DIVISA_H
#include <iostream>
using namespace std;

class Divisa{
	
	private:
		int _codigo;
		string _nombre;
		bool _estado;
		string _simbolo;
	public:			
		Divisa();
		Divisa(int codigo,string nombre,string simbolo,bool estado);
		string toRaw();
		void pedirDatos();
		int getCodigo();
		string getNombre();
		string getSimbolo();
		bool getEstado();
};


#endif
