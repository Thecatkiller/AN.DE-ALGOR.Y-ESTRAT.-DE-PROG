#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
using namespace std;
struct Producto{
	int id;
	string nombre;
	int cantidad;
};
char menu();
int generarLista();
int* lista;
int main(){
	
	return 0;
}
int generarLista(){
	int ne;
	cout<<"Numero de elementos: ";
	cin>>ne;
	lista=new Producto[ne];
	srand(time(0));
	for(int i=0;i<ne;i++){
		Producto p;
		p.id=(i+1);
		p.nombre="producto";
		p.cantidad=rand()%9+1;
		lista[i]=p;
	}
	return ne;
}
