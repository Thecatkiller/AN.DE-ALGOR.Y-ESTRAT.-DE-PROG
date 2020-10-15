#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;

struct Articulo
{
	int idArticulo;
	string nombre;
	int Cantidad;
	int Categoria; // 1.- Fajas , 2.-Correas , 3.-Rodamiento
	};
void mostrarLista(Articulo lista[],int n);
void Menos_Cantidad(Articulo lista[], int n);
void Ordernar_Nombre(Articulo lista[],int n);
void Menos_Cantidad(Articulo lista[], int cantidad);
int BusquedaBinariaNombre(Articulo lista[], int inicio, int final, string vb);
//int sumarDV_CatFajas(Articulo lista[],int inicio,int final);
int main12()
{
	Articulo* lista;
	int n;
	cout << "Cantidad de articulos a registrar: ";
	cin >> n;
	lista = new Articulo[n];
	for(int i=0;i<n;i++)
	{
		Articulo c;
		cout << "ID: "; cin >> c.idArticulo;
		cout << "Nombre: "; fflush(stdin); getline(cin,c.nombre); 
		cout << "Cantidad de Articulos: "; cin >> c.Cantidad;
		do 
		{
			cout << "Articulos [1]Fajas | [2]Correas | [3]Rodamiento : ";
			cin >> c.Categoria; 
		}while(!(c.Categoria>=1 && c.Categoria<=3));
		lista[i]=c;
	}
	//Pregunta 1
	//MENOR(MUESTRA Y UBICA)
	Menos_Cantidad(lista, n);
	//-----------------------------------
	//Pregunta 3
	//ORDENADDO POR NOMBRES (DESC)
	cout << "Ordenado por Nombres: " << endl;
	Ordernar_Nombre(lista,n);
	mostrarLista(lista, n);
	//BUSCAR POR NOMBRE
	string vBuscar;
	cout << "Ingrese el articulo a buscar: ";
	fflush(stdin); getline(cin,vBuscar);
	int idx = BusquedaBinariaNombre(lista, 0, n-1,vBuscar);
	if(idx<0){
		cout << endl;
		cout << "No encontrado..." << endl;
	}else{
		cout << "Se encuentra en el indice: " << idx << endl;
	}
}
void mostrarLista(Articulo lista[],int n){
	cout << endl;
	for (int i=0;i<n;i++){
		Articulo c= lista[i];
		cout << c.idArticulo << " = " << c.nombre << "|" << c.Cantidad << "|" << c.Categoria<< endl;
	}
}
void Menos_Cantidad(Articulo lista[], int n){
	string Articulo;
	int menCan = lista[0].Cantidad;
	for (int i = 0; i < n; i++){
		if(lista[i].Cantidad < menCan)
		{
			menCan = lista[i].Cantidad;
			Articulo = lista[i].nombre;
			cout << "Encontrado en la pos: " << i ;
		}
	}
	cout << "La Articulo con menor numero de cantidad es: " << Articulo << endl;
	
}
void Ordernar_Nombre(Articulo lista[],int n){ //Ordenar por cantidad
	int idx;
	for (int i=0;i<n-1;i++){
		idx = i;		
		for (int j=i+1;j<n;j++){
			if (lista[j].nombre >lista[idx].nombre){		     
				idx = j;				
			}
		}
		Articulo aux = lista[i];
		lista[i] = lista[idx];
		lista[idx] = aux;
	}	
}
int BusquedaBinariaNombre(Articulo lista[], int inicio, int final, string vb)
{
	int medio;
	if(inicio<=final)
	{
		medio = (inicio+final)/2;
		if(lista[medio].nombre ==vb) return medio;
		else if(lista[medio].nombre>vb) final=medio-1;
		else if (lista[medio].nombre<vb) inicio = medio+1;
		return BusquedaBinariaNombre(lista,inicio,final,vb);
	}
	return -1;
}
