#ifndef MENU_CLIENTE_H
#define MENU_CLIENTE_H

#include "ArchivoCliente.h"
#include "ArchivoCajero.h"
#include "ArchivoCuenta.h"
#include "ArchivoUsuario.h"
#include "ArchivoBillete.h"

#include "Cajero.h"
#include "Cliente.h"

#include "Cuenta.h"
#include "Cajero.h"

#include <vector>

class MenuCliente : public MenuGenerico{
	private:
		Cliente* _clienteActual;
		Cajero* _cajeroActual;
		Cuenta* _cuentaActual;
		
		void retirar(){
			system("cls");
			cout << "Ingrese el monto a retirar : ";
			double monto;
			cin >> monto;
			cout << endl;
								
			int billete[] = { 200 , 100 , 50 , 20 , 10 };	
			int billeteUsado[] = { 0 , 0 , 0 , 0 , 0 };		
			int tam = sizeof(billete) / sizeof(*billete);
			
			double montoTotal = monto;
			
			for(int i = 0; i < tam; i++){
				int cantidadDisponible = _cajeroActual->getBilletesPorDenominacion((ValorBillete) billete[i])->getCantidad();
				//cout << endl << cantidadDisponible << " Billetes de " << billete[i] << endl;
				while(montoTotal >= billete[i]){									
					if(cantidadDisponible > 0){
						montoTotal = montoTotal - billete[i];		
						cantidadDisponible--;
						billeteUsado[i]++;
					}else{
						break;
					}										
				}	
			}
			
			//cout <<endl << endl<< "Monto Total : " << montoTotal << endl << endl;
			
			if(montoTotal > 0){								
				cout << endl << "El cajero no tiene los fondos para el retiro !!" << endl;
				return;
			}
								
			if(_cuentaActual->retirar(monto)){																						
				for(int i = 0; i < tam; i++){
					Billete* b = _cajeroActual->getBilletesPorDenominacion((ValorBillete) billete[i]);
					b->setCantidad(b->getCantidad() - billeteUsado[i]);							
					if(billeteUsado[i] > 0 ){
						ArchivoBillete* archivoBillete = new ArchivoBillete();			
						archivoBillete->actualizar(b);		
					}													
				}						
				ArchivoCuenta* archivo = new ArchivoCuenta();
				archivo->actualizar(_cuentaActual);
				cout << endl << "Operacion exitosa !!" << endl;
			}else{
				cout << endl << endl << "Cuenta :" << endl;
				cout << "---------------------------------------------" << endl ;
				_cuentaActual->mostrarResumen();
			}
		}
		
		void elegirCuenta(){
			vector<Cuenta*> cuentas = _clienteActual->getCuentas();
			
			if(_clienteActual->getCantidadCuentas() == 1){
				_cuentaActual = cuentas.at(0);
			}else{
				
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
					return;
				}				
				_cuentaActual = cuentas.at(numeroCuenta - 1);
			}		
		}
		
		void elegirCajero(){
			system("cls");
			ArchivoCajero* archivo = new ArchivoCajero();
			cout << "Ingrese el codigo del cajero (numero): ";
			int codigoCajero;
			cin >> codigoCajero;
			cout << endl;
			Cajero* cajero = archivo->buscarPorCodigo(codigoCajero);
							
			if(cajero != NULL){									
				if(cajero->getMontoTotal() == 0){
					cout << "El cajero ingresado no tiene fondos !!!" << endl;
					return;
				}
				_cajeroActual = cajero;				
			}else{
				cout << "El cajero ingresado no existe !!!" << endl;
			}
		}
		
		
		void login(){
			Cliente* c = NULL;
			string dni;
			string clave;
			cout << endl << "Ingresar DNI : ";
			cin >> dni;
			
			ArchivoCliente* aCliente = new ArchivoCliente();
			_clienteActual = c = aCliente->buscarPorDNI(dni);
			
			if(c == NULL){
				cout << endl << "El DNI ingresado no existe !!" << endl;
				return;
			}
			
			cout << endl << "Ingresar clave : ";
			cin >> clave;	
			
			if(c->getUsuario()->validarClave(clave) == false){
				cout << endl << "La clave ingresada es incorrecta !!" << endl;
				_clienteActual = NULL;				
				return;
			}
			
			_clienteActual = c;					
		}
		
		void mostrarSaldoCuentas(){
			
			vector<Cuenta*> cuentas = _clienteActual->getCuentas();
			for(int i=0;i < cuentas.size();i++){
				cuentas.at(i)->mostrar();
			}
		}
		
		void cambiarClave(){
			string clave;
			cout << endl << "Ingresar clave nueva: ";
			cin >> clave;		
			
			if(clave.length() < 3){
				cout << endl << "La clave es muy corta" << endl;
				return;
			}
			
			_clienteActual->getUsuario()->setClave(clave);
			
			ArchivoUsuario* archivo = new ArchivoUsuario();
			archivo->actualizar(_clienteActual->getUsuario());		
			
			cout << endl << "La clave se cambio !!!" << endl;
		}
		
	protected:
		virtual void cargarOpciones() {
			MenuGenerico::cargarOpciones();
			cout << "Menu Cliente     " << endl;
			cout << "------------------------------" << endl;
			cout << "[1] Saldo" << endl;
			cout << "[2] Retirar" << endl;
			cout << "[3] Depositar" << endl;
			cout << "[4] Transferir" << endl;
			cout << "[5] Cambiar clave" << endl;
			cout << "[9] Salir" << endl;
			cout << "Seleccione opción: ";	
		}

	public:
		static const char OPC_SALDO			     		= '1';
		static const char OPC_RETIRAR			   		= '2';
		static const char OPC_CAMBIO_CLAVE			   	= '5';
		static const char OPC_SALIR			     		= '9';
		
		
		MenuCliente(){
			this->setColor("02");
			_clienteActual = NULL;
			_cajeroActual = NULL;
			_cuentaActual = NULL;
		}
		
		virtual void mostrar(){
			system("cls");
			this->login();
			if(_clienteActual != NULL){
					char opc;			
				do{
					this->cargarOpciones();				
					opc = this->leerOpcion();
			
					switch(opc){
						case MenuCliente::OPC_SALDO:
						{
							this->mostrarSaldoCuentas();
							break;	
						}
						case MenuCliente::OPC_RETIRAR:
						{
							elegirCajero();
							if(_cajeroActual!=NULL){
								elegirCuenta();
								if(_cuentaActual != NULL){
									retirar();
								}								
							}				
							break;
						}
						case MenuCliente::OPC_CAMBIO_CLAVE:
						{
							cambiarClave();
							break;
						}
					}
				
					if(opc != this->OPC_SALIR){
						cout << endl << endl;	
						system("pause");
					}
				
				}while(opc!=this->OPC_SALIR);
			}
			
			
		}
};
#endif

