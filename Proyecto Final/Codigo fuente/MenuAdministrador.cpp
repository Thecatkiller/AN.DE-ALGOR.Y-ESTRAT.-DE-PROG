#include "MenuAdministrador.h"

MenuAdministrador::MenuAdministrador(string color){
	this->setColor(color);
}

void MenuAdministrador::mostrar(){
	system(this->_color.c_str());
	system("cls");
	setlocale(LC_ALL,"spanish");
	fflush(stdin);
	cout << "Menu Administrador     " << endl;
	cout << "------------------------------" << endl;
	cout << "[1] Administrador" << endl;
	cout << "[2] Cliente" << endl;
	cout << "[9] Salir" << endl;
	cout << "Seleccione opción: ";	
}
