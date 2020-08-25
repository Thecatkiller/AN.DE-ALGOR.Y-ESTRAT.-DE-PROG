#include <iostream>
using namespace std;
int main() {
	
	int n;
	cout << "Ingrese la cantidad de ciudades:";
	cin >> n;
	
	string lista[n];
	
	
	for(int i=0;i<n;i++){
		cout << "Ciudad " << (i+1) << ":" << endl;
		fflush(stdin);
		getline (cin,lista[i]);		
	}
	
	
	
	return 0;
}
