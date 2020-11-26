#ifndef MENU_CLIENTE_H
#define MENU_CLIENTE_H

#include "ArchivoCliente.h"
#include "ArchivoCajero.h"
#include "ArchivoCuenta.h"
#include "ArchivoUsuario.h"
#include "ArchivoBillete.h"
#include "ArchivoMovimiento.h"

#include "Cajero.h"
#include "Cliente.h"

#include "Cuenta.h"
#include "Cajero.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "MenuLogin.h"

#include "MenuMovimientos.h"
#include "MenuRetiro.h"
#include "MenuDeposito.h"
#include "MenuTransferir.h"
#include "MenuCuenta.h"

class MenuCliente : public MenuGenerico{	
	public:
		static const char OPC_SALDO			     		= '1';
		static const char OPC_RETIRAR			   		= '2';
		static const char OPC_MOVIMIENTOS		   		= '3';
		static const char OPC_DEPOSITAR			   		= '4';
		static const char OPC_TRANSFERIR		   		= '5';
		static const char OPC_CAMBIO_CLAVE			   	= '6';
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
							this->retirar();
							break;
						}
						case MenuCliente::OPC_DEPOSITAR:{
							this->depositar();							
							break;
						}
						case MenuCliente::OPC_MOVIMIENTOS:{
							this->mostrarMovimientos();											
							break;
						}
						case MenuCliente::OPC_TRANSFERIR:{
							this->transferir();											
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
		
	private:
		Cliente* _clienteActual;
		Cajero* _cajeroActual;
		Cuenta* _cuentaActual;
		
		void transferir(){
			this->_cuentaActual = NULL;
			this->elegirCuenta("Elegir cuenta origen");
			if(this->_cuentaActual != NULL){
				(new MenuTransferir(this->_cuentaActual,this->_clienteActual))->mostrar();
			}
		}
		
		void mostrarMovimientos(){
			this->_cuentaActual = NULL;
			this->elegirCuenta("");
			if(this->_cuentaActual != NULL){
				(new MenuMovimientos(this->_cuentaActual))->mostrarMovs();
			}
		}
		
		void retirar(){
			this->_cajeroActual = NULL;
			this->_cuentaActual = NULL;
			this->elegirCajero();
			if(this->_cajeroActual!=NULL){
				this->elegirCuenta("");
				if(this->_cuentaActual != NULL){
					(new MenuRetiro(_cajeroActual,_cuentaActual))->mostrar();
				}								
			}			
		}
		
		void depositar(){
			this->_cajeroActual = NULL;
			this->_cuentaActual = NULL;
			this->elegirCajero();		
			if(this->_cajeroActual!=NULL){
				this->elegirCuenta("");
				if(this->_cuentaActual != NULL){
					(new MenuDeposito(_cajeroActual,_cuentaActual))->mostrar();						
				}																
			}							
		}
			
		
		
		void elegirCuenta(string texto){
			_cuentaActual = (new MenuCuenta(this->_clienteActual))->elegirCuenta(texto);				
		}
		
		void elegirCajero(){
			Cajero* cajero = (new MenuCajero())->elegirCajero();
			if(cajero == NULL || cajero->getMontoTotal() == 0){
				if(cajero != NULL && cajero->getMontoTotal() == 0)
					cout << "El cajero ingresado no tiene fondos !!!" << endl;
				this->_cajeroActual = NULL;
			}else{
				this->_cajeroActual = cajero;
			}
		}
				
		void login(){			
			this->_clienteActual = (new MenuLogin())->doLogin();
		}
		
		void mostrarSaldoCuentas(){			
			vector<Cuenta*> cuentas = _clienteActual->getCuentas();
			system("cls");
			cout << endl << "Codigo\t\tSaldo\t\t\t Estado" << endl;
			cout << "--------------------------------------------------" << endl;
			for(int i=0;i < cuentas.size();i++){
				cuentas.at(i)->mostrarResumen();
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
			cout << "[3] Ver Movimientos" << endl;
			cout << "[4] Depositar" << endl;
			cout << "[5] Transferir" << endl;
			cout << "[6] Cambiar clave" << endl;
			cout << "[9] Salir" << endl;
			cout << "Seleccione opción: ";	
		}	
};
#endif

