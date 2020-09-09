#include <iostream>
#include <vector>
using namespace std;


void factoresPrimos(int n);
void factoresPrimosV2(int n);
vector<int> factoresPrimosV3(int n);

int main() {
		
	int n;		
	cout << "Ingrese un numero :";
	cin >> n;
	
	factoresPrimos(n);
	cout << endl;
	factoresPrimosV2(n);	
	cout << endl;
	factoresPrimosV3(n);
	
	
	
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
	int contador = 0;
	int i = 2;
	while(n > 1){
		while(n % i == 0){
			contador++;
			n = n / i;		
		}		
				
		if(contador>0){
			cout << i << "^" << contador << endl;
			contador = 0;	
		}
		
		i++;
				
	}
		
}

vector<int> factoresPrimosV3(int n){
	vector<int> lista;
		
	int i = 2;
	while(n > 1){
		while(n % i == 0){
			lista.push_back(i);
			n = n / i;		
		}		
		i++;			
	}
	return lista;
}

