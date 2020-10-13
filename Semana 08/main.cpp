#include <iostream>
#include <cstdlib>   
#include <ctime> 
#include <conio.h>

using namespace std;

struct Producto{
	int id;
	string nombre;
	int cantidad;
};

char menu();
int generarLista();
void mostrarLista(Producto lista[],int inicial,int final);
long sumarITE(Producto lista[], int inicial,int final);
void ordenarBUR(Producto lista[],int n);
void ordenarBURCOD(Producto lista[],int n);
int busquedaBinITE(Producto lista[],int inicial,int final,int vb);
int valorBusqueda();

Producto* lista;

int main(){
	char op = 'A';
	unsigned int ti,tf;
	int vbuscar;
	int n=0;
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
		    case '7':{											
				vbuscar = valorBusqueda();				
				ordenarBURCOD(lista,n);
				int idx = busquedaBinITE(lista,0,n-1,vbuscar);
				if(idx<0){
					cout << "No encontrado...." << endl;
				}else{
					cout << "Encontrado en el Indice: " << idx << endl;
				}
				break;
			}
		}
		cout << endl;
		system("pause");
	}		
	return 0;
}

int generarLista(){
	int ne;
	cout << "Nro de elementos:";
	cin >> ne;
	lista = new Producto[ne];
	srand(time(0));
	for (int i=0;i<ne;i++){	
		Producto p;
		p.id = (i+1);
		p.nombre = "produ";
		p.cantidad =rand() % 9 + 1; 
		lista[i] = p;        		
	}	
	return ne;
}
void mostrarLista(Producto lista[],int inicial,int final){
	for(int i=inicial;i<final;i++){
		Producto p = lista[i];
		cout<<p.id << " " << p.nombre << " " << p.cantidad <<endl;	
	} 	
}
long sumarITE(Producto lista[], int inicial,int final){
	long sum = 0;
	for (int i=inicial; i <= final; i++){
		sum += lista[i].cantidad;		
	}
	return sum;
}

void ordenarBUR(Producto lista[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-(i+1);j++){
			if(lista[j].cantidad > lista[j+1].cantidad){				
				Producto aux = lista[j];
				lista[j] = lista[j+1];
				lista[j+1] = aux;
			}
		}
	}		
}

void ordenarBURCOD(Producto lista[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-(i+1);j++){
			if(lista[j].id > lista[j+1].id){				
				Producto aux = lista[j];
				lista[j] = lista[j+1];
				lista[j+1] = aux;
			}
		}
	}		
}

int busquedaBinITE(Producto lista[],int inicial,int final,int vb){
	int medio;
	while (inicial <= final){
		medio =(inicial+final)/2;
		if (lista[medio].id == vb) {
			return medio;
		} else if (lista[medio].id > vb){
			final = medio-1;
		} else if (lista[medio].id < vb){
			inicial = medio+1;
		}
	}
	return -1;
}

int valorBusqueda(){
	int v;
	cout << endl <<"Ingrese valor buscado:";
	cin>>v;
	return v;
}



char menu(){
	fflush(stdin);
	setlocale(LC_ALL,"spanish");
	system("cls");
	cout << "Menu principal         " << endl;
	cout << "[1] Generar lista      " << endl;
	cout << "[2] Mostrar lista      " << endl;
	cout << "[3] Sumar DV           " << endl;
	cout << "[4] Sumar ITE          " << endl;
	cout << "[5] Ordenar (Bur)      " << endl;
	cout << "[6] Ordenar (Sel)      " << endl;
	cout << "[7] Busqueda Bin (ITE) " << endl;
	cout << "[8] Busqueda Bin (REC) " << endl;
	cout << "[A] Factorial (ITE)    " << endl;
	cout << "[B] Factorial (REC)    " << endl;
	cout << "[C] Recursivo 1        " << endl;
	cout << "[D] Recursivo 2        " << endl;	
	cout << "[9] Salir              " << endl;
	cout << "Seleccione opción:";					
	return toupper(getche());			
}

