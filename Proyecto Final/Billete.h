#ifndef BILLETE_H
#define BILLETE_H
#include <iostream>

using namespace std;

	enum ValorBillete {
		DIEZ = 10,
		VEINTE = 20,
		CINCUENTA = 50,
		CIEN = 100,
		DOSCIENTOS = 200
	};
	

class Billete{	
	private:
		int _cantidad;
		int _codigoCajero;
		ValorBillete _valorBillete;
	public:
		Billete();
		Billete(int codigoCajero,ValorBillete valorBillete,int cantidad);
		string toRaw();
		int getCodigoCajero();
		ValorBillete getValorBillete();
		double getMonto();
		void setCantidad(int cantidad);
		int getCantidad();
};


#endif
