#include <iostream>
#include <cstdlib>   
#include <ctime> 
#include <conio.h>


#define OPC_GENERAR       '1'
#define OPC_MOSTRAR       '2'
#define OPC_SUMAR_REC     '3'
#define OPC_SUMAR_ITE     '4'
#define OPC_ORDENAR_BUR   '5'
#define OPC_ORDENAR_SEL   '6'
#define OPC_BUSCAR_ITE    '7'
#define OPC_BUSCAR_REC    '8'
#define OPC_SALIR         '9'
#define OPC_FACTORIAL_ITE 'A'
#define OPC_FACTORIAL_REC 'B'


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
int valorBusqueda(string texto);
int factorialITE(int n);
int factorialREC(int n);

int main() {
	char op = 'A';
	unsigned int ti,tf;
	int n=0;
	int vbuscar;
	while (op != '9'){		
		op = menu();		
		switch (op){			
			case OPC_GENERAR :{
				cout << endl << "generar" << endl;				
				n = generarLista();
				break;
			}
			case OPC_MOSTRAR:{
				cout << endl << "mostrar" << endl;		
				mostrarLista(lista,0,n);			
				break;
			}
			case OPC_SUMAR_REC:{
				ti=clock();
				cout << endl << "Sumar (REC):" << endl;				
				cout << sumarREC(lista,0,n-1) << endl;;	
				tf=clock();
				double tt=(tf-ti)/1000.0;
				cout<<"Tiempo transcurrido (seg):" <<tt<<endl;		
				break;
			}			
			case OPC_SUMAR_ITE:{			
				ti = clock(); 
				cout << endl << "Suma (ite):";
				cout << sumarITE(lista,0,n-1) << endl;				
				tf = clock(); 
				double tt =(tf-ti) / 1000.0; 
				cout << "Tiempo transcurrido (seg):" << tt << endl;
				break;
			}
			case OPC_ORDENAR_BUR:{												
				ti = clock();
				cout << endl << "Ordenar (Bur):" << endl;
				ordenarBUR(lista,n);
				tf = clock();
				double tt = (tf-ti)	/ 1000.0;					
				cout << "Tiempo (seg):" << tt << endl;								
				break;
		    }
		    case OPC_ORDENAR_SEL:{												
				ti = clock();
				cout << endl << "Ordenar (SEL):" << endl;
				ordenarSEL(lista,n);
				tf = clock();
				double tt = (tf-ti)	/ 1000.0;					
				cout << "Tiempo (seg):" << tt << endl;								
				break;
		    }	
			case OPC_BUSCAR_ITE:{
				vbuscar = valorBusqueda("Ingrese valor buscado :");
				
				int idx = busquedaBinITE(lista,0,n-1,vbuscar);
				if(idx < 0){
					cout << "No encontrado...."<<endl;
				}else{
					cout << "Encontrado en el indice: " << idx << endl;
				}
				
				break;
			}
			case OPC_BUSCAR_REC:{
			vbuscar = valorBusqueda("Ingrese valor buscado :");
				
				int idx = busquedaBinREC(lista,0,n-1,vbuscar);
				if(idx < 0){
					cout << "No encontrado...."<<endl;
				}else{
					cout << "Encontrado en el indice: " << idx << endl;
				}
				
				break;
			}    
			case OPC_FACTORIAL_ITE:{
				int num = valorBusqueda("Ingrese valor :");
				cout << endl << factorialITE(num) << endl;
				break;
			}		
			case OPC_FACTORIAL_REC:{
				int num = valorBusqueda("Ingrese valor :");
				cout << endl << factorialREC(num) << endl;
				break;
			}			
			case OPC_SALIR:{
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
	cout << "[7] Busqueda BIN (ITE)  " << endl;
	cout << "[8] Busqueda BIN (REC)  " << endl;
	cout << "[A] Factorial (ITE)    " << endl;
	cout << "[B] Factorial (REC)    " << endl;
	cout << "[9] Salir          " << endl;
	cout << "Seleccione opción:";	
	return toupper(getche());			
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

int valorBusqueda(string texto){
	int v;
	cout<< endl << texto <<endl;
	cin>>v;
	return v;
}

int factorialITE(int n){
	int resp = 1;
	
	for(int i=n;i>1;i--){
		resp *= i;
	}
	
	return resp;
}

int factorialREC(int n){
	if(n <= 1)
		return 1;
	return n * factorialREC(n - 1);
}

