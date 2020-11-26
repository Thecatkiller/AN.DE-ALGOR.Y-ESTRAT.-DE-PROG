#ifndef MENU_TRANSFERIR_H
#define MENU_TRANSFERIR_H

class MenuTransferir : public MenuGenerico {
	
	private:
		Cuenta* _cuentaOrigen;
		Cliente* _clienteActual;
		
		void aCuentaPropia(){
			fflush(stdin);
			system("cls");		
			
		}
		
		
	public:
		MenuTransferir(Cuenta* cuenta,Cliente* cliente){
			this->_cuentaOrigen = cuenta;
			this->_clienteActual = cliente;
			
			this->setColor("03");
		}
		
		virtual void mostrar(){
			fflush(stdin);
			system("cls");
			
			cout << endl << "[1] - Transferencia entre mis cuentas" << endl;
			cout << "[2] - Transferencia a un tercero" << endl;
			cout << "Seleccione opción: ";	
			char opc;
						
			opc = this->leerOpcion();
			
			if(opc == '1'){
				this->aCuentaPropia();
			}
						
		}
};


#endif
