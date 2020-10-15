#include <iostream>
#include <cstdlib>   
#include <ctime> 
#include <conio.h>
#include <sstream>
#include <string>

using namespace std;

#define OPC_GENERAR       '1'
#define OPC_MOSTRAR       '2'
#define OPC_PREGUNTA1     '3'
#define OPC_ORDERNAR_DESC '4'
#define OPC_BUSCAR_NOMBRE '5'
#define OPC_MAYOR_ROD     '6'
#define OPC_CANT_ROD      '7'
#define OPC_SALIR         '9'

enum Categoria { Fajas = 1, Mangueras = 2, Rodamientos = 3 };

struct Articulo{
	int idArticulo;
	string nombre;
	int cantidad;
	Categoria idCategoria;
};

char menu();
int generarLista();
void mostrarLista(Articulo lista[],int inicial,int final);
int mayorCantidadFB(Articulo arr[], int n);
int menorCantidad(Articulo arr[], int inicio, int fin);
int sumar(Articulo lista[],int n);

Articulo* crearArregloCantidad(Articulo arr[], int n,int numero,int &cantidadElementos);
Articulo* crearArregloCategoria(Articulo lista[], int n,Categoria cat,int &cantidadElementos);

void ordenarSELDESC(Articulo lista[],int n);
int busquedaBinREC(Articulo lista[],int inicial,int final,string vb);
string valorBusqueda(string texto);


Articulo* lista;

int main(int argc, char** argv) {
	int n;
	char op = 'A';
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
				mostrarLista(lista,0, n);			
				break;
			}
			case OPC_PREGUNTA1:{
				int mayor = mayorCantidadFB(lista,n);
				int cElementos = 0;
				
				Articulo* listaMayores = crearArregloCantidad(lista,n,mayor,cElementos);
				
				cout << endl << endl << "Numero cantidad mayor : " << mayor << endl;
				cout << "Articulos mayores :" << endl;
				mostrarLista(listaMayores,0, cElementos);
				break;
			}
			case OPC_ORDERNAR_DESC:{
				ordenarSELDESC(lista,n);				
				break;
			}
			case OPC_BUSCAR_NOMBRE:{
				
				string vbuscar = valorBusqueda("Ingrese nombre a buscar :");
				int idx = busquedaBinREC(lista,0,n-1,vbuscar);
				
				if(idx >= 0){
					cout << "Articulo "<< vbuscar << " encontrado" << endl;
				}else{
					cout << "Articulo "<< vbuscar << " no encontrado" << endl;
				}
				
				break;
			}
			case OPC_MAYOR_ROD:{
				int cantidad = 0;
											
				Articulo* arr =crearArregloCategoria(lista,n,(Categoria)1,cantidad);
				int menor = menorCantidad(arr,0,cantidad - 1);
				
				cout << endl <<"Elementos de la categoria Fajas :" << endl;
				
				mostrarLista(arr,0,cantidad);
				
				cout << endl << "La menor cantidad es :" << menor << endl;
				
				break;
			}
			case OPC_CANT_ROD:{
				int cantidad = 0;
											
				Articulo* arr =crearArregloCategoria(lista,n,(Categoria)2,cantidad);
				int suma = sumar(arr,cantidad);
				
				cout << endl <<"Elementos de la categoria Mangueras :" << endl;
				
				mostrarLista(arr,0,cantidad);
				
				cout << endl << "El total de mangueras es :" << suma << endl;
				
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

int generarLista(){
	int ne;
	cout << "Nro de elementos:";
	cin >> ne;
	lista = new Articulo[ne];
	srand(time(0));
	for (int i=0;i<ne;i++){	
		Articulo p;
		p.idArticulo = (i+1);
		
		std::ostringstream ss;
    	ss << (i+1);

		p.nombre = "articulo " + ss.str();
		p.cantidad = rand() % (ne * 2) + 1; 
		p.idCategoria = (Categoria) (rand() % 3 + 1); 
		lista[i] = p;        		
	}	
	return ne;
}

void mostrarLista(Articulo lista[],int inicial,int final){
	for(int i=inicial;i<final;i++){
		Articulo p = lista[i];
		cout<<p.idArticulo << " " << p.nombre << " " << p.cantidad << " " << p.idCategoria <<endl;	
	} 	
}

int mayorCantidadFB(Articulo arr[], int n) 
{ 
    int max = arr[0].cantidad;
        
    for(int i = 1; i < n; i++) 
    { 
         if (arr[i].cantidad > max)      
            max = arr[i].cantidad; 
    } 
    
    return max; 
} 

Articulo* crearArregloCantidad(Articulo lista[], int n,int numero,int &cantidadElementos){
	
	int ne = 0;
	
	for(int i = 0; i < n; i++) 
    { 
         if (lista[i].cantidad == numero)      
            ne++; 
    } 
	cantidadElementos = ne;
	Articulo* arr = new Articulo[ne];
	int cont = 0;
		
	for(int i = 0; i < n; i++) 
    { 
         if (lista[i].cantidad == numero)      
            {
            	arr[cont] = lista[i];
            	cont++;
			}
    } 
	
	return arr;
}

Articulo* crearArregloCategoria(Articulo lista[], int n,Categoria cat,int &cantidadElementos){
	
	int ne = 0;
	
	for(int i = 0; i < n; i++) 
    { 
         if (lista[i].idCategoria == cat)      
            ne++; 
    } 
	cantidadElementos = ne;
	Articulo* arr = new Articulo[ne];
	int cont = 0;
		
	for(int i = 0; i < n; i++) 
    { 
         if (lista[i].idCategoria == cat)      
            {
            	arr[cont] = lista[i];
            	cont++;
			}
    } 
	
	return arr;
}

void ordenarSELDESC(Articulo lista[],int n){
	int idx;
	for (int i=0;i<n-1;i++){
		idx = i;		
		for (int j=i+1;j<n;j++){
			if (lista[j].idArticulo > lista[idx].idArticulo){		     
				idx = j;				
			}
		}
		Articulo aux = lista[i];
		lista[i]   = lista[idx];
		lista[idx] = aux;
	}
}

int busquedaBinREC(Articulo lista[],int inicial,int final,string vb){
	int medio;
	if(inicial <= final){
		medio = (inicial + final) / 2;
		if(lista[medio].nombre.compare(vb) == 0){
			return medio;
		}else if(lista[medio].nombre.compare(vb) > 0){
			final = medio - 1;
		}else if(lista[medio].nombre.compare(vb) < 0){
			inicial = medio + 1;
		}
		return busquedaBinREC(lista,inicial,final,vb);
	}
	return -1;
}

string valorBusqueda(string texto){	
	string vb;
	cout<< endl << texto <<endl;
	
	fflush(stdin);
    getline (cin,vb);	
	
	return vb;
}

int menorCantidad(Articulo arr[], int inicio, int fin){
	if(inicio == fin) return lista[inicio].cantidad;
	int medio = (inicio + fin) / 2;
	int izq = menorCantidad(lista,inicio, medio);
	int der = menorCantidad(lista,medio + 1, fin);
	
	cout <<endl << "izq :" << izq << " der: " << der<< endl; 
	
	return min(izq,der);
}

int sumar(Articulo lista[],int n){
	if (n <= 0) 
        return 0; 
    return (sumar(lista, n - 1) + lista[n - 1].cantidad); 
}

char menu(){
	fflush(stdin);
	setlocale(LC_ALL,"spanish");
	system("cls");
	cout << "Menu principal     " << endl;
	cout << "[1] Generar lista  " << endl;
	cout << "[2] Mostrar lista  " << endl;
	cout << "[3] PREGUNTA 1     " << endl;
	cout << "[4] Ordenar SEL DESC" << endl;
	cout << "[5] Buscar nombre   " << endl;
	cout << "[6] Menor fajas" << endl;
	cout << "[7] Cantidad mangueras" << endl;
	cout << "[9] Salir          " << endl;
	cout << "Seleccione opcion:";	
	
	return toupper(getche());			
}





