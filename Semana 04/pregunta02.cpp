#include <iostream>
using namespace std;
void OrdenarPorSeleccion(string lista[], int n);
void mostrar(string lista[],int n);
int main2()
{
	int n;
	cout << "Ingrese la cantidad de elementos: ";
	cin >> n;
	string lista[n];
	for(int i=0;i<n;i++)
	{
		cout << "Ingrese la ciudad " << (i+1)<<":";
		fflush(stdin);
		getline(cin,lista[i]);
	}
	
	cout << "ORDENADO DE MANERA DESCENDENTE:" << endl;
	OrdenarPorSeleccion(lista, n);
	mostrar(lista,n);
	return 0;
}
void OrdenarPorSeleccion(string lista[], int n)
{
	int Menor;
	for(int i=0;i<n;i++)
	{
		Menor=i;
		for(int j=i+1;j<n;j++)
		{
			if(lista[j]>lista[Menor])
				{Menor=j;}
		}
		string aux=lista[i];
		lista[i]=lista[Menor];
		lista[Menor]=aux;
	}  }
void mostrar(string lista[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout << lista[i] << endl;
	}  }
