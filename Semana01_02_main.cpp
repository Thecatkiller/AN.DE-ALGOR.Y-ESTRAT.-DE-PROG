#include <iostream>
using namespace std;

//Seccion de metodos
bool contienePalabra(string frase,string palabra);

int main() {
	string frase,palabra;
	
	cout << "Ingrese frase:";
	getline(cin,frase);
	
	cout << "Ingrese palabra:";
	getline(cin,palabra);
	
	
	cout << endl << (contienePalabra(frase,palabra) ? "Contiene" : "No contiene");
	
	return 0;
}


bool contienePalabra(string frase,string palabra){	
	int vc = 0;
	string resp = "";
	for(int i = 0; i < frase.length();i++){		
		if(frase.substr(i,1) == palabra.substr(vc,1)){			
			resp += palabra.substr(vc,1);
			vc++;			
			if(resp == palabra) return true;	
		}else{
			vc = 0;
			resp = "";
		}					
	}	
	return false;	
}
