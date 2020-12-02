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
		
		Cuenta* elegirCuentaTercero(string texto){
			system("cls");
			vector<Cuenta*> cuentas;
			ArchivoCuenta* archivoC = new ArchivoCuenta();
			
			vector<Cuenta*> allAccount = archivoC->listarTodo();
			for(int i =0; i < allAccount.size(); i++){
				Cuenta* currentAccount = allAccount.at(i);
				if(currentAccount->getCodigoCliente() != this->_clienteActual->getCodigo()){
					cuentas.push_back(currentAccount);
				}
			}
			
			if(texto.length() > 0){
				cout << endl << texto << endl << endl;
			}
			cout << "---------------------------------------------" << endl << endl;
			for(int i=0;i < cuentas.size();i++){
				cout << "[" << (i + 1) << "] -  ";
				Cuenta* currentAccount = cuentas.at(i);
				cout << currentAccount->getCodigoConCeros() << endl;
			}
			
			cout << "Seleccione opción: ";	
			int numeroCuenta;
			cin >> numeroCuenta;
				
			if(numeroCuenta<=0 || numeroCuenta - 1 >= cuentas.size()){
				cout << endl << "Cuenta inválida !!!" << endl;
				return NULL;
			}	
			
			return cuentas.at(numeroCuenta - 1);;
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
