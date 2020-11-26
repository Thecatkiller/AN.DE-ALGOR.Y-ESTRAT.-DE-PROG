#ifndef MENU_MOVIMIENTOS_H
#define MENU_MOVIMIENTOS_H

class MenuMovimientos{
	private:
		Cuenta* _cuentaActual;
	public:
		MenuMovimientos(Cuenta* cuenta){
			this->_cuentaActual = cuenta;
		}
	
		void mostrarMovs(){
			system("cls");
				cout << "Mi cuenta:" << endl;
				cout << "----------------------------------------------------" << endl << endl;
				_cuentaActual->mostrarResumen();
				cout << endl << "Mis Movimientos:"<<endl<<endl;
				cout << "Fecha"; cout.width(15);
				cout << "Hora"; cout.width(23);
				cout << "Descripción"; cout.width(31);
				cout << "Importe"; cout.width(18);
				cout << "Saldo" << endl;
				cout << "-------------------------------------------------------------------------------------------------------" << endl;
				ArchivoMovimiento* archivo = new ArchivoMovimiento();
				vector<Movimiento*> movs = archivo->listarByCodigoCuenta(this->_cuentaActual->getCodigo());
				
				double saldoCalculado = this->_cuentaActual->getSaldo();
				
				for(int i=0; i < movs.size();i++){			
					Movimiento* mov = movs.at(i);
					
					std::ostringstream saldo;
					saldo << "S/. " << saldoCalculado;
					mov->mostrarDetalle(saldo.str());
					
					saldoCalculado+= -1 * mov->getMonto();
				}
		}
	
	
};




#endif
