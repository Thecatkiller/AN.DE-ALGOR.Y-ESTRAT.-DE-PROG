#include <iostream>
using namespace std;

#define OPC_SUMAR       '1'
#define OPC_PROMEDIO    '2'
#define OPC_MAYOR       '3'
#define OPC_SALIR       '9'

char menuPrincipal();
int sumar(int lista[],int n);
double promedio(int lista[],int n);
int main() {	
	char mopc; 
	int lista[] = {15,25,13,18,14};
	int tam = sizeof(lista) / sizeof(*lista);
		
		
	do{
		
		mopc = menuPrincipal();
		
		switch(mopc){
			case OPC_SUMAR:			
				cout << "Sumar" << endl;
				
				cout << sumar(lista,tam) << endl;
				
				break;						
			case OPC_PROMEDIO:
				
				cout << promedio(lista,tam) << endl;
				
				break;					
			case OPC_MAYOR:
				break;
		}
		
		system("pause");
	}while(mopc != OPC_SALIR);
	
	return 0;
}


char menuPrincipal(){
	system("cls");
	cout << "Menu Principal" << endl;
	cout << "[1] Sumar     " << endl; 
	cout << "[2] Promedio  " << endl; 
	cout << "[3] Mayor     " << endl; 
	cout << "[9] Salir     " << endl; 
	cout << "Seleccione: ";
	fflush(stdin);
	char opc = getchar();
	return opc;
}

int sumar(int lista[],int n){
	if (n <= 0) 
        return 0; 
    return (sumar(lista, n - 1) + lista[n - 1]); 
}

double promedio(int lista[],int n){
	int suma = sumar(lista,n);
	return suma / (double) n;
}


