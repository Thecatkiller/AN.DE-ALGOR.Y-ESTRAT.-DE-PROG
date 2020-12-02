#ifndef ARCHIVO_GENERICO_H
#define ARCHIVO_GENERICO_H

#include <iostream>
#include <fstream>
using namespace std;

class ArchivoGenerico {
	
	public:
		ArchivoGenerico(string nombreArchivo){
			this->_archivo = nombreArchivo;
		}
	
	private:
		string _archivo;	
		bool _isEnableToRead = false;
		
	
	protected:
		ifstream _aleer;
		
		string getArchivo(){
			return this->_archivo;
		}
		bool isEnableToRead(){
			return this->_isEnableToRead;
		}
		bool existFile()
		{
		    return ifstream(_archivo.c_str()).good();
		}
		void leerArchivo() {
			
			if(this->existFile() == false){
				ofstream fescribir;
				fescribir.open(_archivo.c_str(),ios::out|ios::app);
				fescribir.close();
			}
			
			_aleer.open(_archivo.c_str(),ios::in);
			if (!_aleer.is_open()){
			 	cout << "No se puede abrir el archivo: " << _archivo << endl;
				_isEnableToRead = false;
			}
			_isEnableToRead = true;
		}
};

#endif
