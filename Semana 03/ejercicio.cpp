#include <iostream>
#include <vector>
 
using namespace std;


int main() {
	
	int monto;
	
	cout << "Ingresar un monto:";
	cin >> monto;
	
	int billete[] = { 200 , 100 , 50 , 20 , 10 };
	int tam = sizeof(billete) / sizeof(*billete);
	int i = 0;
	
	for(int i = 0; i < tam; i++){
		while(monto >= billete[i]){
			cout << billete[i] << endl;
			monto = monto - billete[i];		
		}	
	}
		
	
	return 0;
}
