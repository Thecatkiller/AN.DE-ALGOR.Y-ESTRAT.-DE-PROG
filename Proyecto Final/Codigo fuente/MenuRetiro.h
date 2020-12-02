#ifndef MENU_RETIRO_H
#define MENU_RETIRO_H

#include <stdio.h>
#include <string.h>
using namespace std;

class MenuRetiro{
	private:
		Cajero* _cajeroActual;
		Cuenta* _cuentaActual;
	public:
		MenuRetiro(Cajero* caj,Cuenta* cuenta){
			this->_cajeroActual = caj;
			this->_cuentaActual = cuenta;
		}
		
	
		void mostrar(){
			system("cls");
			cout << "Ingrese el monto a retirar : ";
			double monto;
			cin >> monto;
			cout << endl;
				
			//valida que el monto a retirar sea positivo
			if(monto <= 0){
				cout << endl << "El monto no puede ser menor o igual a 0 !!!";
				return;
			}
								
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
				ArchivoMovimiento* archivoMov = new ArchivoMovimiento();
				
				string descripcion = "RETIRO EFECTIVO-" + this->_cajeroActual->getUbicacionCorta();
				
				Movimiento* mov = new Movimiento(
					_cuentaActual->getCodigo(),
					-1 * monto,this->_cajeroActual->getCodigo(),
					descripcion
				);
				 
				archivoMov->grabar(mov);		
				cout << endl << "Operacion exitosa !!" << endl;
			}else{
				cout << endl << endl << "Cuenta :" << endl;
				cout << "---------------------------------------------" << endl ;
				_cuentaActual->mostrarResumen();
			}
		}
	
};

#endif
