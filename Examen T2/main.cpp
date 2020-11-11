#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cmath>
#include <cstdlib>   
#include <ctime> 
#include <sstream>
#include <string>

using namespace std;

enum TipoEquipo { Tipo01 = 1, Tipo02 = 2, Tipo03 = 3, Tipo04 = 4 };


struct Equipo{
	int idEquipo;
	string nombre; 
	int anofabrica;
	TipoEquipo idTipoEquipo;
};


long* fibPD(int n);
void pregunta01();
void pregunta02();
void pregunta03();
void ordernarBurbuja(Equipo lista[],int n);
char menuPD();
void imprimir02(Equipo* lista, int ne);
int contarPorTipo(Equipo lista[],int n, int tipo);

int main(int argc, char** argv) {	
	char opc;
	
	do{
		opc = menuPD();
		switch (opc){
			case '1':{
				pregunta01();
				break;
			}	
			case '2':{
				pregunta02();	
				break;
			}
			case '3':{
				pregunta03();
				break;
			}							
		}
		cout << endl << endl;
		system("pause");		
	} while(opc!='9');	
		
	return 0;
	
	
	return 0;
}

void pregunta01(){
	int n;
	cout << endl << "Ingrese nro:";
	cin >> n;
	cout << endl;

	long* fibo = fibPD(n);

	int contadorPar = 0;

	for(int i=0;i<=n;i++){
		cout.width(12);
		cout << fibo[i];
		
		if(fibo[i] % 2 == 0 && i > 0){
			contadorPar++;
			cout << "  " << "P";
		}else if(i > 0){
			cout << "  " << "I";
		}else{
			cout << "   ";
		}
			

		if ((i+1) % 5 ==0) cout << endl; 			
	}
	int contadorImpar = n - contadorPar;
	double porcentajePar = round(((double)contadorPar / n) * 100);
	cout << endl;
	cout << fixed << setprecision(2);
	cout << "(P) Par:" << contadorPar << "\t" << porcentajePar << "%" << endl;
	cout << "(P) Impar:" << contadorImpar << "\t" << 100 - porcentajePar << "%";
	
}
void pregunta02(){
	int ne;
	cout << endl << "Nro de elementos:";
	cin >> ne;
	cout << endl;

	Equipo* lista = new Equipo[ne];

	for (int i=0;i<ne;i++){	
		Equipo p;
		p.idEquipo = (i+1);
		
		std::ostringstream ss;
    	ss << (i+1);

		p.nombre = "articulo " + ss.str();
		p.anofabrica = rand() % (rand() % 2000 + 1); 
		p.idTipoEquipo = (TipoEquipo) (rand() % 4 + 1); 
		lista[i] = p;        		
	}

	imprimir02(lista,ne);
	ordernarBurbuja(lista,ne);
	cout << endl << endl << "Elementos ordenados" << endl;
	imprimir02(lista,ne);
	cout << endl;
	for(int i = 1 ; i<= 4 ; i++){
		cout << "Tipo " << i << ": " << contarPorTipo(lista,ne,i) << endl;
	}

}


void pregunta03(){
	int n;
	cout << endl << "Digite numero:" << endl;
	cout << "n: "; cin >> n;



}

void imprimir02(Equipo* lista, int ne){
	cout<< "\t" << "id" << "\t\t" << "Nombre" << "\t\t" << "anio fabricacion" << "\t\t"  << "tipo" <<endl;	
	for(int i=0;i<ne;i++){
		Equipo p = lista[i];
		cout<< "\t" << p.idEquipo << "\t\t" << p.nombre << "\t\t" << p.anofabrica << "\t\t\t"  << p.idTipoEquipo <<endl;	
	} 
}

int contarPorTipo(Equipo lista[],int n,int tipo){
	int contador = 0;
	for(int i = 0 ; i < n ; i++){
		if(lista[i].idTipoEquipo == tipo){
			contador++;	
		}
	}
	return contador;
}


long* fibPD(int n){
	long* lista = new long[n+1];		
	lista[0] = 0;
	lista[1] = 1;
	for(int i=2;i<=n;i++){
		lista[i] = lista[i-2] + lista[i-1];
	}		
	return lista;
}

void ordernarBurbuja(Equipo lista[],int n){
	Equipo aux;
	for (int i=0;i<n-1;i++)
		for (int j=0;j<n-1;j++)
			if (lista[j].nombre.compare(lista[j+1].nombre) < 0){
				aux        = lista[j];
				lista[j]   = lista[j+1];
				lista[j+1] = aux;
			}	
}


char menuPD(){
	system("color 02");
	system("cls");
	setlocale(LC_ALL,"spanish");
	fflush(stdin);
	cout << "Menu Principal     " << endl;
	cout << "-------------------" << endl;
	cout <<"[1] Pregunta 01   " << endl;
	cout <<"[2] Pregunta 02            " << endl;
	cout <<"[3] Pregunta 03             " << endl;
	cout <<"[9] Salir                    " << endl;
	cout << "Seleccione opción: ";	
	char op=toupper(getche());
	return op;		
}
