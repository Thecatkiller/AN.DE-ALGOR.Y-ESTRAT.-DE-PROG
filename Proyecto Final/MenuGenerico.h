#ifndef MENU_GENERICO_H
#define MENU_GENERICO_H

#include <iostream>
 
using namespace std;

class MenuGenerico{
	protected:
		string _color;
		
		void setColor(string color){
			this->_color = "color " + color;
		}
		
		virtual void cargarOpciones(){			
			system(this->_color.c_str());
			system("cls");
			setlocale(LC_ALL,"spanish");
			fflush(stdin);
		}
		
		char leerOpcion(){
			char op=toupper(getche());
			return op;
		}
		
	public:
		virtual void mostrar() = 0;
};




#endif
