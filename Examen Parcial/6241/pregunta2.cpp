#include <iostream>
#include <cstdlib>   
#include <ctime> 
#include <conio.h>

using namespace std;

void pregunta2();
void imprimePregunta2(int n, int contar,int num,int ite);



int main(int argc, char** argv) {
	pregunta2();
	return 0;
}


void pregunta2(){
	
	int n = 20;
	int contar = 0;
	int num = 2;
	int ite = 0;
	while(n > 1){
		
		contar = 0;
		while(n % num == 0){
			n = n / num;
			contar++;
			ite+= 1;
			
			imprimePregunta2(n,contar,num,ite);
		}
		
		if(contar > 0) cout << num << " ^ " << contar << endl;
		num++;
		ite = ite + 1;
		
		
		imprimePregunta2(n,contar,num,ite);
	}
	
}

void imprimePregunta2(int n, int contar,int num,int ite){
	cout << "n:" << n << "\t";
	cout << "num:" << num << "\t";
	cout << "contar:" << contar << "\t";
	cout << "ite:" << ite << endl << endl << endl;
}


