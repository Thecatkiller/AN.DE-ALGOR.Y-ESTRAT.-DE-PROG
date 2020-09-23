#include <iostream>
using namespace std;

char menuPrincipal();

int main() {
	
	char opc = menuPrincipal();
	
	return 0;
}


char menuPrincipal(){
	cout << "Menu Principal" << endl;
	cout << "[1] Sumar     " << endl; 
	cout << "[2] Promedio  " << endl; 
	cout << "[3] Mayor     " << endl; 
	cout << "[9] Salir     " << endl; 
	cout << "Seleccione: ";
	
	char opc = getchar();
	return opc;
}
