#ifndef MENU_PRINCIPAL_H
#define MENU_PRINCIPAL_H

#include "MenuGenerico.h"
#include "MenuAdministrador.h"
#include "MenuCliente.h"

class MenuPrincipal : public MenuGenerico{		
	protected:
		virtual void cargarOpciones() {
			MenuGenerico::cargarOpciones();
			cout << "Menu Principal     " << endl;
			cout << "------------------------------" << endl;
			cout << "[1] Administrador" << endl;
			cout << "[2] Cliente" << endl;
			cout << "[9] Salir" << endl;
			cout << "Seleccione opción: ";	
		}

	public:
		static const char OPC_ADMINISTRADOR	     		= '1';
		static const char OPC_CLIENTE			   		= '2';
		static const char OPC_SALIR			     		= '9';
		
		
		MenuPrincipal(){
			this->setColor("01");
		}
		
		virtual void mostrar(){
			char opc;			
			do{
				this->cargarOpciones();				
				opc = this->leerOpcion();								
				switch(opc)	{
					case MenuPrincipal::OPC_ADMINISTRADOR:
					{
						(new MenuAdministrador())->mostrar();						
						break;
					}
					case MenuPrincipal::OPC_CLIENTE:
					{
						(new MenuCliente())->mostrar();	

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

