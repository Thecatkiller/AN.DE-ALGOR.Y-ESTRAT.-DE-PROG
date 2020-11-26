#ifndef MENU_LOGIN_H
#define MENU_LOGIN_H

class MenuLogin{
	private:
		Cliente* _clienteActual;
	
	public:
		MenuLogin(){
			_clienteActual = NULL;
		}
	
		Cliente* doLogin(){
			Cliente* c = NULL;
			string dni;
			string clave;
			cout << endl << "Ingresar DNI : ";
			cin >> dni;
			
			ArchivoCliente* aCliente = new ArchivoCliente();
			_clienteActual = c = aCliente->buscarPorDNI(dni);
			
			if(c == NULL){
				cout << endl << "El DNI ingresado no existe !!" << endl;
				return NULL;
			}
			
			cout << endl << "Ingresar clave : ";
			cin >> clave;	
			
			cout << endl << c->getUsuario()->toRaw() << endl;
			
			if(c->getUsuario()->validarClave(clave) == false){
				cout << endl << "La clave ingresada es incorrecta !!" << endl;
				_clienteActual = NULL;				
				return NULL;
			}
			
			_clienteActual = c;	
			return _clienteActual;
		}
};

#endif
