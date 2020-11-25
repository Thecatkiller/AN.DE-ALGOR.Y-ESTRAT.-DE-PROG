#include "Cuenta.h"
#include "MenuAdministrador.h"
#include "MenuCliente.h"

void menuPrincipal();
char menuCliente();
char menuAdministrador();
char mostrarMenuPrincipal();

#define OPC_MENU_ADMINISTRADOR       '1'
#define OPC_MENU_CLIENTE             '2'

void menuPrincipal(){
	char opc;	
	do{		
		opc = mostrarMenuPrincipal();
		switch(opc){
			case OPC_MENU_ADMINISTRADOR:{	
				MenuAdministrador *menuAdmin = new MenuAdministrador();
				menuAdmin->mostrar();								
				break;
			}
			case OPC_MENU_CLIENTE:{
				MenuCliente *menu = new MenuCliente();
				menu->mostrar();		
				break;
			}
		}
		//c->mostrar();
		if(opc != '9'){
			cout << endl << endl;
			system("pause");
		}
	}while(opc!='9');	
}

char mostrarMenuPrincipal(){
	system("color 01");
	system("cls");
	setlocale(LC_ALL,"spanish");
	fflush(stdin);
	cout << "Menu Principal     " << endl;
	cout << "------------------------------" << endl;
	cout << "[1] Administrador" << endl;
	cout << "[2] Cliente" << endl;
	cout << "[9] Salir" << endl;
	cout << "Seleccione opción: ";	
	char op=toupper(getche());
	return op;
}





