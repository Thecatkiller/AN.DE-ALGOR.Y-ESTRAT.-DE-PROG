#include <iostream>
#include <conio.h>

using namespace std;

#include "MenuPrincipal.h"




int main(int argc, char** argv) {
	cout << fixed << setprecision(2);
	MenuPrincipal* menu = new MenuPrincipal();

	menu->mostrar();
	
	return 0;	
}





