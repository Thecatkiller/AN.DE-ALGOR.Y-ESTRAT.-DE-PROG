#ifndef MENU_TRANSFERIR_H
#define MENU_TRANSFERIR_H

#include "MenuCuenta.h"

class MenuTransferir : public MenuGenerico {
	
	private:
		Cuenta* _cuentaOrigen;
		Cliente* _clienteActual;
		
		void aCuentaPropia(){
			fflush(stdin);
			system("cls");		
			
			MenuCuenta* menuCuenta = new MenuCuenta(this->_clienteActual);
			Cuenta *cuentaDestino = menuCuenta->elegirCuenta("Elegir cuenta destino");	
			
			if(cuentaDestino != NULL){
				//verifica que las cuentas sean distintas
				if(_cuentaOrigen->getCodigo() == cuentaDestino->getCodigo()){
					cout << endl << "La cuenta origen no puede ser igual a la destino !!" << endl;
					return;
				}
				double monto = this->ingresoMonto();			
				if(monto > 0)
				{
					if(validarSaldoCuentaOrigen(monto)){
						this->grabarTrxCuentaOrigen(monto,cuentaDestino);
						this->grabarTrxCuentaDestino(monto,cuentaDestino);
					}
				}
			}						
		}
		
		void grabarTrxCuentaDestino(double monto,Cuenta* cuentaDestino){
			ArchivoCuenta* archivoCuenta = new ArchivoCuenta();
			ArchivoMovimiento* archivoMovimiento = new ArchivoMovimiento();
				
			string descripcion = "ABONO CTA. " + this->_cuentaOrigen->getCodigoConCeros();
			Movimiento* mov = new Movimiento(
										cuentaDestino->getCodigo(),
										monto,
										-1,//se pone como codigo de cajero uno que no existe
										//TODO ver como manejarlo luego
										descripcion
										);
			archivoMovimiento->grabar(mov);	
			cuentaDestino->setSaldo(cuentaDestino->getSaldo() + monto);	
			archivoCuenta->actualizar(cuentaDestino);
		}
		
		void grabarTrxCuentaOrigen(double monto,Cuenta* cuentaDestino){
			ArchivoCuenta* archivoCuenta = new ArchivoCuenta();
			ArchivoMovimiento* archivoMovimiento = new ArchivoMovimiento();
				
			string descripcion = "TRANSF.CTA. " + cuentaDestino->getCodigoConCeros();
				
			Movimiento* mov = new Movimiento(
										this->_cuentaOrigen->getCodigo(),
										-1 * monto,
										-1,//se pone como codigo de cajero uno que no existe
										//TODO ver como manejarlo luego
										descripcion
										);
										
			archivoMovimiento->grabar(mov);				
			this->_cuentaOrigen->setSaldo(this->_cuentaOrigen->getSaldo() - monto);
									
			//actualiza el saldo de la cuenta origen
			archivoCuenta->actualizar(this->_cuentaOrigen);
		}
		
		bool validarSaldoCuentaOrigen(double monto){
			double montoRestante = _cuentaOrigen->getSaldo() - monto;
			if(montoRestante < 0){
				cout << endl << "La cuenta origen no tiene los fondos para la transferencia !!!" << endl;
				return false;
			}			
			return true;
		}
		
		double ingresoMonto(){
			//TODO esto se puede llevar a un menu aparte
			system("cls");
			cout << "Ingrese el monto a transferir : ";
			double monto;
			cin >> monto;
			cout << endl;
				
			//valida que el monto a retirar sea positivo
			if(monto <= 0){
				cout << endl << "El monto no puede ser menor o igual a 0 !!!";
				return -1;
			}	
									
			return monto;			
		}
		
		
	public:
		MenuTransferir(Cuenta* cuentaOrigen,Cliente* cliente){
			this->_cuentaOrigen = cuentaOrigen;
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
