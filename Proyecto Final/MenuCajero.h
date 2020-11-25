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
			fflush(stdin);
			system("cls");
			int codigoCajero;
			cout << endl << "Ingresar codigo cajero (numero): ";
			cin >> codigoCajero;
			
			ArchivoCajero* archivo = new ArchivoCajero();
			Cajero* cajero = archivo->buscarPorCodigo(codigoCajero);
			
			if(cajero == NULL){
				cout << endl << endl << "El codigo de cajero ingresado no existe !!" << endl; 
				return;
			}
			
			cout << endl << endl << "Denominaciones:" << endl;
			cout << "------------------------------" << endl;
			cout << "[A] -  10 SOLES" << endl;
			cout << "[B] -  20 SOLES" << endl;
			cout << "[C] -  50 SOLES" << endl;
			cout << "[D] -  100 SOLES" << endl;
			cout << "[E] -  200 SOLES" << endl << endl;
			
			char denominacion;
			bool ok = false;
			do{
				cout << endl << "Seleccione opción: ";	
				denominacion = this->leerOpcion();
								
				int cantidad = -1;	
					if(denominacion== 'A' ||
					denominacion== 'B' ||
					denominacion== 'C' ||
					denominacion== 'D' ||
					denominacion== 'E'){
						ok = true;
					}			
				do{
					cout << endl << "Ingrese cantidad de billetes : ";
					cin >> cantidad;
					
					
																				
					if(cantidad <= 0){
						cout << endl << endl << "Cantidad inválida !!!";
					}else if(cantidad > 0 && ok){
						ValorBillete valorBillete;
						
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
												
						Billete* billete = cajero->getBilletesPorDenominacion(valorBillete);								
						billete->setCantidad(billete->getCantidad() + cantidad);				
						ArchivoBillete* archivoBillete = new ArchivoBillete();																		
						archivoBillete->actualizar(billete);						
						cout << endl << endl << "Se grabó correctamente " << endl;
					}
				}while(cantidad<0);																
			}while(ok == false);
			
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
