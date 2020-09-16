#include <iostream>
using namespace std;

bool listaUnica(int lista[],int n);
void ordernarBurbuja(int lista[],int n);
int masRepetido(int lista[],int n);
int main1() {
	int n;
	cout << "Ingrese cantidad registros:";
	cin >> n;
	
	int lista[n];
	
	for(int i=0;i<n;i++){
		cout << "Numero " << (i+1) << ": ";
		cin >> lista[i];	
	}
	
	if(!listaUnica(lista,n)){
		cout << "La lista no unica" << endl;
		ordernarBurbuja(lista,n);
		int repetido = masRepetido(lista,n);
		cout << "Numero mas repetido" << ": " << repetido;	
	}
	
	
	
	
	return 0;
}

bool listaUnica(int lista[],int n){	
	for (int i = 0; i < n -1; i++) 
        for (int j = i + 1; j < n; j++) 
            if (lista[i] == lista[j]) 
                return false;                    
    return true;
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

int masRepetido(int arr[],int n){
	int max_count = 1, res = arr[0], curr_count = 1; 
    for (int i = 1; i < n; i++) { 
        if (arr[i] == arr[i - 1]) 
            curr_count++; 
        else { 
            if (curr_count > max_count) { 
                max_count = curr_count; 
                res = arr[i - 1]; 
            } 
            curr_count = 1; 
        } 
    } 
  
    if (curr_count > max_count) 
    { 
        max_count = curr_count; 
        res = arr[n - 1]; 
    } 
  
    return res; 
}

