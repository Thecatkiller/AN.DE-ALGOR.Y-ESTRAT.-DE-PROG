#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void factoresPrimos(int n);
void factoresPrimosV2(int n);

int main() {
		
	int n;		
	cout << "Ingrese un numero :";
	cin >> n;
	
	factoresPrimos(n);
	cout << endl;
	factoresPrimosV2(n);	
	
	return 0;
}



void factoresPrimos(int n){
	int i = 2;
	while(n > 1){
		while(n % i == 0){
			cout << i << endl;
			n = n / i;		
		}		
		i++;			
	}
}

void factoresPrimosV2(int n){
	int contador;
	int i = 2;
	while(n > 1){
		while(n % i == 0){
			contador++;
			n = n / i;		
		}		
				
		if(contador>0){
			cout << i << "^" << contador << endl;
		}
		
		i++;
		contador = 0;			
	}
		
}

