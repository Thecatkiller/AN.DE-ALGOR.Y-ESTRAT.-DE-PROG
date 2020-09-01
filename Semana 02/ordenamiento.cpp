#include <iostream>

using namespace std;

void ordernarBurbuja(int lista[],int n);
void mostrarLista(int lista[],int n);

int main(){
	int n;
	cout << "Ingresar nro de elementos:";
	cin >> n;
	
	int lista[n];
	for (int i=0;i<n;i++){
		cout << "nro " << (i+1) << ":";
		cin >> lista[i];
	}
	ordernarBurbuja(lista,n);
	mostrarLista(lista,n);
	
	return 0;
}

void ordernarBurbuja(int lista[],int n){
	int aux;
	for (int i=0;i<n-1;i++)
		for (int j=0;j<n-1;j++)
			if (lista[j] > lista[j+1]){
				aux        = lista[j];
				lista[j]   = lista[j+1];
				lista[j+1] = aux;
			}	
}

void mostrarLista(int lista[],int n){
	for (int i=0;i<n;i++){
		cout << lista[i] << endl;
	}	
}
