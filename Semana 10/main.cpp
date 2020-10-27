#include <iostream>
#include <conio.h>

using namespace std;

long  fibREC(int n);
long  fibITE(int n);
long* fibPD(int n);

char menuPD();


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
	system("cls");
	setlocale(LC_ALL,"spanish");
	fflush(stdin);
	cout << "Menu Principal     " << endl;
	cout << "-------------------" << endl;
	cout <<"[1] Fibonacci REC   " << endl;
	cout <<"[2] Fibonacci ITE   " << endl;
	cout <<"[9] Salir           " << endl;
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

