#ifndef MENU_DEPOSITO_H
#define MENU_DEPOSITO_H

#include "MenuCajero.h"
#include "ArchivoCajero.h"
#include "ArchivoBillete.h"
#include "ArchivoCuenta.h"
#include "ArchivoMovimiento.h"
#include "Movimiento.h"

class MenuDeposito{
	private:
		Cajero* _cajeroActual;
		Cuenta* _cuentaActual;
	public:
		MenuDeposito(Cajero* caj,Cuenta* cuenta){
			this->_cajeroActual = caj;
			this->_cuentaActual = cuenta;
		}
	
		void mostrar(){
			system("cls");					
			cout << endl << endl << "Se debe elegir la denominacion y cantidad de billetes a depositar !!" << endl << endl;		
			MenuCajero* caj = new MenuCajero();			
			ValorBillete valorBillete = caj->leerDenominacionBillete();	
			if(valorBillete == 0)
				return;	
			
			int billeteUsado[] = { 0 , 0 , 0 , 0 , 0 };
			int billete[] = { 200 , 100 , 50 , 20 , 10 };
			
			int cantidad = -1;
			do{
				system("cls");	
				fflush(stdin);
				
				cout << endl << "Ingrese cantidad de billetes : ";
				cin >> cantidad;																														
				if(cantidad <= 0){
					cout << endl << endl << "Cantidad inválida !!!";
				}else if(cantidad > 0){									
					ArchivoBillete* archivoB = new ArchivoBillete();
					ArchivoCuenta* archivoC = new ArchivoCuenta();
					ArchivoMovimiento* archivoM = new ArchivoMovimiento();
					
					Billete* billete = _cajeroActual->getBilletesPorDenominacion(valorBillete);			
					billete->setCantidad(billete->getCantidad() + cantidad);
					archivoB->actualizar(billete);														
					double monto = valorBillete * cantidad * 1.0;				
					
					this->_cuentaActual->setSaldo(this->_cuentaActual->getSaldo() + monto);
					archivoC->actualizar(this->_cuentaActual);
					
					string descripcion = "DEPOSITO EFECTIVO-" + this->_cajeroActual->getUbicacionCorta();
					
					Movimiento* mov = new Movimiento(
										this->_cuentaActual->getCodigo(),
										monto,
										this->_cajeroActual->getCodigo(),
										descripcion
										);
					
					archivoM->grabar(mov);
					
					cout << endl << endl << "Se depositó : S/. " << monto << " en la cuenta." << endl;
				}
			}while(cantidad<0);	
			
		}
	
};


#endif
