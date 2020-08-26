#include <iostream>
using namespace std;

//Seccion de metodos
bool buscarCiudad(string lista[],int n,string vbsucar);
int buscarCiudadIdx(string lista[],int n,string vbsucar);


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
		cout << "Ciudad "<< vb << " encontrada" << endl;
	}else{
		cout << "Ciudad "<< vb << " no encontrada" << endl;
	}
	
	//Usando el otro metodo de buscar por indice
	int idx = buscarCiudadIdx(lista,n,vb);
	
	if(idx >= 0){
		cout << "Ciudad "<< vb << " encontrada" << endl;
	}else{
		cout << "Ciudad "<< vb << " no encontrada" << endl;
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

int buscarCiudadIdx(string lista[],int n,string vbsucar){
	for(int i=0;i<n;i++){
		if(lista[i] == vbsucar)	
			return i;
	}
	return -1;
}

