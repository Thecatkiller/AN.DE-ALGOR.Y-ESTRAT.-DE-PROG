#include <iostream>
#include <conio.h>

using namespace std;

long  fibREC(int n);
long  fibITE(int n);
long* fibPD(int n);
int coeBinREC(int n,int k);
unsigned long long* factPD(int n);
unsigned long long binomialFormula(int n, int k);
unsigned long long coeBinPD(int n, int k);
unsigned long long* coeBinPDv2(int n, int k);

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
	cout << "Seleccione opci�n: ";	
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
	int n,k;	
	do{	
		system("cls");
		setlocale(LC_ALL,"spanish");
		fflush(stdin);
		cout << "Menu Coeficiente Binomial" << endl;
		cout << "-------------------------" << endl;
		cout <<"[1] Coef REC                 " << endl;
		cout <<"[2] Coef FORM                " << endl;
		cout <<"[3] Coef PD                  " << endl;		
		cout <<"[5] OM                       " << endl;		
		cout <<"[9] Regresar al menu anterior" << endl;
		cout << "Seleccione opci�n: ";
		op=toupper(getche());
	    switch (op){
	    	case '1':{	    			
				cout << endl << "Digite numeros:" << endl;
				cout << "n: "; cin >> n;
				cout << "k: "; cin >> k;				
				cout << endl << "coebin (rec):" << coeBinREC(n,k) << endl;					    						
				break;
			}		
			case '2':{
				cout << endl << "Digite numeros:" << endl;
				cout << "n: "; cin >> n;
				cout << "k: "; cin >> k;				
				
				unsigned long long*	f = factPD(n);
				cout << endl << "cb_1:" << endl << f[n] / (f[k]*f[n-k]);
				
				cout << endl << "cb_2:" << binomialFormula(n,k) << endl;
				
				break;
			}
			case '3':{	    			
				cout << endl << "Digite numeros:" << endl;
				cout << "n: "; cin >> n;
			//	cout << "k: "; cin >> k;				
			//	cout << endl << "coebin (PD):" << coeBinPD(n,k) << endl;
				for (int i=0;i<=n;i++){
					//cout << endl << "coebin (PD):" << coeBinPD(n,i) << endl;	
					cout << n << ", " << i << " = " << coeBinPD(n,i) << endl;
				}
				
				// tarea resuelta - usando pd
				cout << endl;
				unsigned long long* respuesta = coeBinPDv2(n,n-1);
				for (int f=0;f<=n;f++)
					cout << n << ", " << f << " = " << respuesta[f] << endl;
				
				
				cout << "Serie:" << endl;
				long long acum = 0, aux;				
				for (int i = 0, j = n; j > i; i++,j--){
					 cout << j << "C" << i << " = ";
					 
					 if(i%2==0 && i>0)
				        aux = -coeBinPD(j, i);
				     else 
				     	aux = coeBinPD(j, i);				        
				     
					 acum = acum + aux;
				     
					 cout << aux << endl;
				}
				cout << endl << "Resp:" << acum << endl;




				break;			
			}
		}		
		system("pause");	
	} while(op!='9');
}

int coeBinREC(int n,int k){
    if(k == 0 || n == k) return 1;	
    return coeBinREC(n-1,k-1) + coeBinREC(n-1,k);	   
}

unsigned long long* factPD(int n){
	unsigned long long* lista = new unsigned long long[n+1];		
	lista[1] = lista[0] = 1;
	for(int i=2;i<=n;i++){
		lista[i] = lista[i-1] * i;
	}		
	return lista;
}

unsigned long long binomialFormula(int n, int k){
   unsigned long long * b = factPD(n);	
   return (b[n] / (  b[k] * b[n-k] ) );
}


unsigned long long coeBinPD(int n, int k){
	unsigned long long	m[n][k+1] = {};
	
	if (n==k || k==0) return 1;
		
	for (int f=0;f<n;f++){
		m[f][0]	= 1;
	}
	
	for (int f=1;f<n;f++){
		m[f][1] = f;
	}
	
	for (int fc=2; fc<=k ;fc++){
		m[fc][fc] = 1;
	}
	
	for(int f=3;f<n;f++){
		for(int c=2;c<=k;c++){
			m[f][c] = m[f-1][c-1] + m[f-1][c];
		}
	}			
			
	return  m[n-1][k-1] + m[n-1][k];
	
}



unsigned long long* coeBinPDv2(int n, int k){
	unsigned long long	m[n][k+1] = {};
	
	unsigned long long* resp = new unsigned long long[n+1];
	
    resp[0]=1;
    resp[n]=1;	
		
	for (int f=0;f<n;f++){
		m[f][0]	= 1;
	}
	
	for (int f=1;f<n;f++){
		m[f][1] = f;
	}
	
	for (int fc=2; fc<=k ;fc++){
		m[fc][fc] = 1;
	}
	
	for(int f=3;f<n;f++){
		for(int c=2;c<=k;c++){
			m[f][c] = m[f-1][c-1] + m[f-1][c];
		}
	}				
	
	for (int f=1;f<n;f++){
		resp[f] =  m[n-1][f-1] + m[n-1][f];
	}			
	return  resp;
}

