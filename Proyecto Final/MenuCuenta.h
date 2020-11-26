#ifndef MENU_CUENTA_H
#define MENU_CUENTA_H

class MenuCuenta: public MenuGenerico{
	private:
		Cuenta* _cuentaActual;	
		Cliente* _clienteActual;	
	public:
		MenuCuenta(Cliente* cliente){
			this->_clienteActual = cliente;
			this->setColor("02");
		}
		
		virtual void mostrar(){
			//		
		}
		
		Cuenta* elegirCuenta(string texto){
			system("cls");
			vector<Cuenta*> cuentas = _clienteActual->getCuentas();
			
			if(_clienteActual->getCantidadCuentas() == 1){
				_cuentaActual = cuentas.at(0);
			}else{
				
				if(texto.length() > 0){
					cout << endl << texto << endl << endl;
				}
				
				cout << "Mis cuentas :" << endl;
				cout << "---------------------------------------------" << endl << endl;
				for(int i=0;i < cuentas.size();i++){
					cout << "[" << (i + 1) << "] -  ";
					cuentas.at(i)->mostrarResumen();
				}
				
				cout << "Seleccione opción: ";	
				int numeroCuenta;
				cin >> numeroCuenta;
				
				if(numeroCuenta<=0 || numeroCuenta - 1 >= cuentas.size()){
					cout << endl << "Cuenta inválida !!!" << endl;
					return NULL;
				}				
				_cuentaActual = cuentas.at(numeroCuenta - 1);
			}	
			
			return _cuentaActual;	
		}
		
		
};


#endif
