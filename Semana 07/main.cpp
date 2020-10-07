#include <iostream>
#include <cstdlib>   
#include <ctime> 
#include <conio.h>

using namespace std;

char menu();
int generarLista();
int* lista;

void mostrarLista(int lista[],int inicial,int final);
long sumarITE(int lista[],int inicial,int final);
long sumarREC(int lista[],int inicial,int final);
void ordenarBUR(int lista[],int n);
void ordenarSEL(int lista[],int n);                     
int busquedaBinITE(int lista[],int inicial,int final,int vb);
int busquedaBinREC(int lista[],int inicial,int final,int vb);
int valorBusqueda();


int main() {
	char op = 'A';
	unsigned int ti,tf;
	int n=0;
	int vbuscar;
	while (op != '9'){		
		op = menu();		
		switch (op){			
			case '1':{
				cout << endl << "generar" << endl;				
				n = generarLista();
				break;
			}
			case '2':{
				cout << endl << "mostrar" << endl;		
				mostrarLista(lista,0,n);			
				break;
			}
			case '3':{
				ti=clock();
				cout << endl << "Sumar (REC):" << endl;				
				cout << sumarREC(lista,0,n-1) << endl;;	
				tf=clock();
				double tt=(tf-ti)/1000.0;
				cout<<"Tiempo transcurrido (seg):" <<tt<<endl;		
				break;
			}			
			case '4':{			
				ti = clock(); 
				cout << endl << "Suma (ite):";
				cout << sumarITE(lista,0,n-1) << endl;				
				tf = clock(); 
				double tt =(tf-ti) / 1000.0; 
				cout << "Tiempo transcurrido (seg):" << tt << endl;
				break;
			}
			case '5':{												
				ti = clock();
				cout << endl << "Ordenar (Bur):" << endl;
				ordenarBUR(lista,n);
				tf = clock();
				double tt = (tf-ti)	/ 1000.0;					
				cout << "Tiempo (seg):" << tt << endl;								
				break;
		    }
		    case '6':{												
				ti = clock();
				cout << endl << "Ordenar (SEL):" << endl;
				ordenarSEL(lista,n);
				tf = clock();
				double tt = (tf-ti)	/ 1000.0;					
				cout << "Tiempo (seg):" << tt << endl;								
				break;
		    }	
			case '7':{
				vbuscar = valorBusqueda();
				
				int idx = busquedaBinITE(lista,0,n-1,vbuscar);
				if(idx < 0){
					cout << "No encontrado...."<<endl;
				}else{
					cout << "Encontrado en el indice: " << idx << endl;
				}
				
				break;
			}
			case '8':{
			vbuscar = valorBusqueda();
				
				int idx = busquedaBinREC(lista,0,n-1,vbuscar);
				if(idx < 0){
					cout << "No encontrado...."<<endl;
				}else{
					cout << "Encontrado en el indice: " << idx << endl;
				}
				
				break;
			}    					
			case '9':{
				cout << endl << "salir" << endl;	
				break;
			} 					
			default:{
				cout << endl << "No valido" << endl;
				break;
			}							
		}		
		system("pause");		
	}
	return 0;
}

char menu(){
	fflush(stdin);
	setlocale(LC_ALL,"spanish");
	system("cls");
	cout << "Menu principal     " << endl;
	cout << "[1] Generar lista  " << endl;
	cout << "[2] Mostrar lista  " << endl;
	cout << "[3] Sumar DV       " << endl;
	cout << "[4] Sumar ITE      " << endl;
	cout << "[5] Ordenar (Bur)  " << endl;
	cout << "[6] Ordenar (Sel)  " << endl;
	cout << "[7] Busqueda BIN (Sel)  " << endl;
	cout << "[8] Busqueda BIN(REC)  " << endl;
	cout << "[9] Salir          " << endl;
	cout << "Seleccione opción:";	
	return getche();			
}

int generarLista(){
	int ne;
	cout << "Nro de elementos:";
	cin >> ne;
	lista = new int[ne];
	srand(time(0));
	for (int i=0;i<ne;i++){		     	
		lista[i] =  rand() % 9 + 1;      
		// cout << lista[i] << endl;
	}	
	return ne;
}
void mostrarLista(int lista[],int inicial,int final){
	for(int i=inicial;i<final;i++){
		cout<<lista[i]<<endl;	
	} 	
}

long sumarITE(int lista[], int inicial,int final){
	long sum = 0;
	for (int i=inicial; i <= final; i++){
		sum += lista[i];		
	}
	return sum;
}

long sumarREC(int lista[],int inicial,int final){	
	if (inicial == final) return lista[inicial];
	int medio = (inicial+final)/2;
	int izq = sumarREC(lista,inicial,medio);
	int der = sumarREC(lista,medio+1,final);
	return izq+der;	
}

void ordenarBUR(int lista[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-(i+1);j++){
			if(lista[j]>lista[j+1]){				
				int aux = lista[j];
				lista[j] = lista[j+1];
				lista[j+1] = aux;
			}
		}
	}		
}	

void ordenarSEL(int lista[],int n){
	int idx;
	for (int i=0;i<n-1;i++){
		idx = i;		
		for (int j=i+1;j<n;j++){
			if (lista[j]<lista[idx]){		     
				idx = j;				
			}
		}
		int aux = lista[i];
		lista[i]   = lista[idx];
		lista[idx] = aux;
	}
}


int busquedaBinITE(int lista[],int inicial,int final,int vb){
	int medio;
	while (inicial <= final){
		medio =(inicial+final)/2;
		if (lista[medio]==vb) {
			return medio;
		} else if (lista[medio]>vb){
			final = medio-1;
		} else if (lista[medio]<vb){
			inicial = medio+1;
		}
	}
	return -1;
}

int busquedaBinREC(int lista[],int inicial,int final,int vb){
	int medio;
	if(inicial <= final){
		medio = (inicial + final) / 2;
		if(lista[medio] == vb){
			return medio;
		}else if(lista[medio] > vb){
			final = medio - 1;
		}else if(lista[medio] < vb){
			inicial = medio + 1;
		}
		return busquedaBinREC(lista,inicial,final,vb);
	}
	return -1;
}

int valorBusqueda(){
	int v;
	cout<< endl <<"Ingrese valor buscado :"<<endl;
	cin>>v;
	return v;
}
