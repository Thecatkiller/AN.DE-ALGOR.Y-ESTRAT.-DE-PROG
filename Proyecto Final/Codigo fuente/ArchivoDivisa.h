#ifndef ARCHIVO_DIVISA_H
#define ARCHIVO_DIVISA_H

#include "ArchivoGenerico.h"

#include "Divisa.h"
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include "iomanip"
#include "sstream"

class ArchivoDivisa : public ArchivoGenerico{
	
	private:
		vector<Divisa*> _listGeneral;	
		bool _listaYaLeida = false;
	
		vector<Divisa*> listar(){
			//esto hace que no se vuelva a leer la lista si ya se ha leido antes
			if(_listaYaLeida)
				return _listGeneral;
				
			vector<Divisa*> lst;								
			this->leerArchivo();
			if(isEnableToRead()){			
				while (!this->_aleer.eof()){
					string _codigo,_nombre,_estado,_simbolo;
					
					getline(this->_aleer,_codigo,';');
					getline(this->_aleer,_nombre,';');
					getline(this->_aleer,_estado,';');	
					getline(this->_aleer,_simbolo,'\n');
					
					int codigo = std::atoi(_codigo.c_str());	

					if(codigo > 0){
						//int codigo,string nombre,string simbolo
						Divisa* divisa = new Divisa(
							codigo,
							_nombre,
							_simbolo,
							_estado == "1" ? true : false
						);																							
						lst.push_back(divisa);	
					}
				}
				this->_aleer.close();			
			}
			_listaYaLeida = true;
			_listGeneral = lst;			
			return lst;
		}
	
	public:
		ArchivoDivisa() : ArchivoGenerico("divisas.txt"){
			
		}
	
		vector<Divisa*> listarTodo(){
			return this->listar();
		}
	
		Divisa* buscarPorCodigo(int codigo){
			Divisa* divisa = NULL;
			vector<Divisa*> listadoTotal = this->listar();
			for(int i=0; i < listadoTotal.size();i++){
				Divisa* d = listadoTotal.at(i);
				if(d->getCodigo() == codigo){
					return d;
				}
			}
			return divisa;
		}
	
		bool grabar(Divisa* d){							
			ofstream fescribir;
			fescribir.open(this->getArchivo().c_str(),ios::out|ios::app);
			fescribir << d->toRaw();
			fescribir << endl;
			fescribir.close();
			
			
			return true;
		}
	
};

#endif
