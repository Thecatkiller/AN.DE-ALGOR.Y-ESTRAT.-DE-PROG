#ifndef MENU_CAJERO_H
#define MENU_CAJERO_H

#include "MenuGenerico.h"
#include "Cajero.h"
#include "ArchivoCajero.h"
#include "ArchivoBillete.h"
#include <vector>

using namespace std;

class MenuCajero : public MenuGenerico{
	private:
		void agregarBilletes(){			
			Cajero* cajero = this->elegirCajero();
			if(cajero == NULL)
				return;
																							
			int cantidad = -1;	
			
			ValorBillete valorBillete = leerDenominacionBillete();	
			if(valorBillete == 0)
				return;					
			do{
				cout << endl << "Ingrese cantidad de billetes : ";
				cin >> cantidad;																														
				if(cantidad <= 0){
					cout << endl << endl << "Cantidad inválida !!!";
				}else if(cantidad > 0){									
					Billete* billete = cajero->getBilletesPorDenominacion(valorBillete);								
					billete->setCantidad(billete->getCantidad() + cantidad);				
					ArchivoBillete* archivoBillete = new ArchivoBillete();																		
					archivoBillete->actualizar(billete);						
					cout << endl << endl << "Se grabó correctamente " << endl;
				}
			}while(cantidad<0);																
			
			
		}
	protected:
		virtual void cargarOpciones() {
			MenuGenerico::cargarOpciones();
			cout << "Menu Cajero     " << endl;
			cout << "------------------------------" << endl;
			cout << "[" << OPC_REGISTRAR_CAJERO <<"] Registrar Cajero       " << endl;
			cout << "[" << OPC_AGREGAR_BILLETES <<"] Agregar billetes       " << endl;
			cout << "[" << OPC_LISTAR_CAJERO <<"] Listar Cajeros       " << endl;
			cout << "[9] Salir                  " << endl;
			cout << "Seleccione opción: ";	
		}
	public:
		static const char OPC_REGISTRAR_CAJERO  		= '1';
		static const char OPC_AGREGAR_BILLETES  		= '2';
		static const char OPC_LISTAR_CAJERO  			= '3';
		static const char OPC_SALIR			     		= '9';
		
		MenuCajero(){
			this->setColor("02");
			
		}
		
		
		
		Cajero* elegirCajero(){
			fflush(stdin);
			system("cls");
			ArchivoCajero* archivo = new ArchivoCajero();			
			vector<Cajero*> cajeros = archivo->listarTodo();
			cout << endl;
			for(int i = 0 ; i < cajeros.size(); i++){
				Cajero* caj = cajeros.at(i);
				cout << "[" << caj->getCodigo() << "] - " << caj->getUbicacion() << endl;
			}
			
			fflush(stdin);
						
			cout << endl << "Ingrese el codigo del cajero (numero): ";
			int codigoCajero;
			cin >> codigoCajero;
			cout << endl;
			Cajero* cajero = archivo->buscarPorCodigo(codigoCajero);
							
			if(cajero != NULL){									
				/*if(cajero->getMontoTotal() == 0){
					cout << "El cajero ingresado no tiene fondos !!!" << endl;
					return NULL;
				}*/
				//_cajeroActual = cajero;				
			}else{
				cout << "El cajero ingresado no existe !!!" << endl;
			}
			return cajero;
		}
		
		ValorBillete leerDenominacionBillete(){
			ValorBillete valorBillete = (ValorBillete)0;
			
			cout << endl << "Denominaciones:" << endl;
			cout << "------------------------------" << endl;
			cout << "[A] -  10 SOLES" << endl;
			cout << "[B] -  20 SOLES" << endl;
			cout << "[C] -  50 SOLES" << endl;
			cout << "[D] -  100 SOLES" << endl;
			cout << "[E] -  200 SOLES" << endl << endl;
			cout << "[0] - SALIR     " << endl << endl;
			
			bool ok = false;
			do{
				cout << endl << "Seleccione opción: ";	
				char denominacion = this->leerOpcion();
					
				if(denominacion== 'A' ||
					denominacion== 'B' ||
					denominacion== 'C' ||
					denominacion== 'D' ||
					denominacion== 'E' || 
					denominacion== '0'){
						ok = true;
				}
														
				if(denominacion == 'A')
					valorBillete = (ValorBillete)10;
				else if(denominacion == 'B')
					valorBillete = (ValorBillete)20;	
				else if(denominacion == 'C')
					valorBillete = (ValorBillete)50;	
				else if(denominacion == 'D')
					valorBillete = (ValorBillete)100;	
				else if(denominacion == 'E')
					valorBillete = (ValorBillete)200;
				
			}while(ok == false);
			
			return valorBillete;
		}
		
		virtual void mostrar(){
			char opc;			
			do{
				this->cargarOpciones();				
				opc = this->leerOpcion();
					
				switch(opc)	{
					case MenuCajero::OPC_REGISTRAR_CAJERO:
					{
						Cajero* cajero = new Cajero();
						cajero->pedirDatos();
						ArchivoCajero* archivo = new ArchivoCajero();
						archivo->grabar(cajero);
						break;
					}	
					case MenuCajero::OPC_AGREGAR_BILLETES:{
						agregarBilletes();
						break;
					}
					case MenuCajero::OPC_LISTAR_CAJERO:
					{
						ArchivoCajero* archivo = new ArchivoCajero();
						vector<Cajero*> lst = archivo->listarTodo();
						for(int i=0; i < lst.size();i++){			
							Cajero* cajero = lst.at(i);
							cajero->mostrar();
						}
						break;
					}				
				}
																		
				if(opc != this->OPC_SALIR){
					cout << endl << endl;	
					system("pause");
				}					
			}while(opc!=this->OPC_SALIR);	
		}
};



#endif
