#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void factoresPrimos(int n);

int main() {
		
	int n;		
	cout << "Ingrese un numero :";
	cin >> n;
	
	factoresPrimos(n);
			
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

