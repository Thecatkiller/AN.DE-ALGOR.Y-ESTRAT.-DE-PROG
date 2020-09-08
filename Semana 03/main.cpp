#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int i = 2;
	int n;
	
	
	cout << "Ingrese un numero :";
	cin >> n;
	
	while(n > 1){
		while(n % i == 0){
			cout << i << endl;
			n = n / i;		
		}		
		if(n % i != 0){
			i++;
		}		
	}
		
	
	return 0;
}
