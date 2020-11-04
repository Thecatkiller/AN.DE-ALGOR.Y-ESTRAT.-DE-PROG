#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	double mi, i;
	int t;
	
	setlocale(LC_ALL,"spanish");
	cout <<"Monto Inicial:";
	cin >> mi;
	cout << "Tasa Anual (TEA):";
	cin >> i;
	cout << "Años:";
	cin >> t;
	
	
	cout << endl;
	cout.width(5);
	cout << "Años";
	cout.width(20);
	cout << "Monto Inicial";
	cout.width(15);
	cout << "Interes";
	cout.width(20);
	cout << "Monto Acumulado";
	cout <<endl;
	
	double mig, mf, tasa = i / 100, acuInt=0;
	
	cout << fixed << setprecision(2);
	
	for(int i=1; i<=t; i++){
		mig = round(mi * tasa * 100) / 100.0;
		mf = mi + mig;
		acuInt = acuInt + mig;
		cout.width(5);
		cout << i;
		cout.width(20);
		cout << mi;
		cout.width(15);
		cout << mig;
		cout.width(20);
		cout << mf;
		cout << endl;
		mi = mf;
	}
	cout << endl;
	cout.width(40);
	cout << acuInt;
	cout << endl;
	return 0;
}
