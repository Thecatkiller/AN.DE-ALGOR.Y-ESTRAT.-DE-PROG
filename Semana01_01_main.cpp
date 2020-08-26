#include <iostream>
using namespace std;

//Seccion de metodos
bool buscarCiudad(string lista[],int n,string vbsucar);


int main() {
	
	int n;
	cout << "Ingrese la cantidad de ciudades:";
	cin >> n;
	
	string lista[n];
	
	
	for(int i=0;i<n;i++){
		cout << "Ciudad " << (i+1) << ": ";
		fflush(stdin);
		getline (cin,lista[i]);		
	}
	
	string vb;
	cout << "Ingrese la ciudad a buscar: ";
	
	fflush(stdin);
    getline (cin,vb);	
	
	bool resp = buscarCiudad(lista,n,vb);
	
	//Usando operador ternario
	//cout << "Ciudad " <<vb << (resp ? " " : " no ") << "encontrada";
	
	//Usando estructura condicional con if
	if(resp){
		cout << "Ciudad "<< vb << " encontrada";
	}else{
		cout << "Ciudad "<< vb << " no encontrada";
	}
	
	return 0;
}


bool buscarCiudad(string lista[],int n,string vbsucar){
	for(int i=0;i<n;i++){
		if(lista[i] == vbsucar)	
			return true;
	}
	return true;
}

