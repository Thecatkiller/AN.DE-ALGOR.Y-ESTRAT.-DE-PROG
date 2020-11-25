#ifndef CAJERO_H
#define CAJERO_H

#include "Billete.h"
#include <vector>
#include <string> 

using namespace std;

class Cajero{
	private:
		int _codigo;
		bool _estado;
		string _ubicacion;
		vector<Billete*> _billetes;
	
	public:
		Cajero();
		Cajero(int codigo,bool estado,string ubicacion);
		int getCodigo();
		string toRaw();
		void mostrar();
		void pedirDatos();
		void setBilletes(vector<Billete*> billetes);
		vector<Billete*> getBilletes();
		double getMontoTotal();
		string getUbicacion();
		string getUbicacionCorta();
		Billete* getBilletesPorDenominacion(ValorBillete valorBillete);
};


#endif
