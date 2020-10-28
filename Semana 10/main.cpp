#include <iostream>
#include <conio.h>

using namespace std;

long  fibREC(int n);
long  fibITE(int n);
long* fibPD(int n);

char menuPD();
void menuCB();

int main() {
	char opc;
	int n;
	do{
		opc = menuPD();
		switch (opc){
			case '1':{
				cout << endl << "Ingrese nro:";
				cin >> n;
				cout << endl;
				for(int i=0;i<=n;i++){
					cout.width(15);
					cout << fibREC(i);
					if ((i+1) % 5 ==0) cout << endl; 			
				}
				break;
			}	
			case '2':{
				cout << endl << "Ingrese nro:";
				cin >> n;
				cout << endl;
				for(int i=0;i<=n;i++){
					cout.width(15);
					cout << fibITE(i);
					if ((i+1) % 5 ==0) cout << endl; 			
				}
				break;
			}
			case '3':{
				cout << endl << "Nro: ";
				cin >> n;
				cout << endl << "FIB (PD):" << endl;
				long* lista = fibPD(n);				
				for (int i=0;i<=n;i++){
					cout.width(15);
					cout << lista[i];					
					if ((i+1)%5==0)	cout << endl;
				}
				cout <<endl;
				break;
			}
			case '4':{
				menuCB();
				break;
			}
				
		}
		cout << endl << endl;
		system("pause");		
	} while(opc!='9');	
		
	return 0;
}

long fibREC(int n){	
	if (n<=1) return n;
	return fibREC(n-1) + fibREC(n-2);
}

char menuPD(){
	system("color 02");
	system("cls");
	setlocale(LC_ALL,"spanish");
	fflush(stdin);
	cout << "Menu Principal     " << endl;
	cout << "-------------------" << endl;
	cout <<"[1] Fibonacci REC   " << endl;
	cout <<"[2] Fibonacci ITE            " << endl;
	cout <<"[3] Fibonacci PD             " << endl;
	cout <<"[4] Menu Coeficiente Binomial" << endl;
	cout <<"[9] Salir                    " << endl;
	cout << "Seleccione opción: ";	
	char op=toupper(getche());
	return op;		
}

long fibITE(int n){
	long a=0,b=1,c=0;
	for (int i=0;i<n;i++){
		c = a+b;	
		a = b;
		b = c;
	}
	return a;
}

long* fibPD(int n){
	long* lista = new long[n+1];		
	lista[0] = 0;
	lista[1] = 1;
	for(int i=2;i<=n;i++){
		lista[i] = lista[i-2] + lista[i-1];
	}		
	return lista;
}

void menuCB(){
	char op;
	
	do{	
		system("cls");
		setlocale(LC_ALL,"spanish");
		fflush(stdin);
		cout << "Menu Coeficiente Binomial " << endl;
		cout << "--------------------------" << endl;
		cout <<"[1] Recursivo              " << endl;
		cout <<"[2] Formula                " << endl;
		cout <<"[3] CB - PD                " << endl;
		cout <<"[9] Regresar menu principal" << endl;
		cout << "Seleccione opción: ";	
	    op=toupper(getche());
			
	} while(op!='9');
}
