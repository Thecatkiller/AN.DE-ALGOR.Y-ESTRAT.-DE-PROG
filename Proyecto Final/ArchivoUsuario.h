#ifndef ARCHIVO_USUARIO_H
#define ARCHIVO_USUARIO_H

#include "Usuario.h";


#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdlib>

#include "ArchivoGenerico.h"

using namespace std;

class ArchivoUsuario : ArchivoGenerico{
	private:		
		vector<Usuario*> listar(){
			vector<Usuario*> lst;								
			this->leerArchivo();
			if(this->isEnableToRead()){				
				while (!this->_aleer.eof()){
					string _codigoCliente,_clave,_estado;
												
					getline(this->_aleer,_codigoCliente,';');
					getline(this->_aleer,_clave,';');
					getline(this->_aleer,_estado,'\n');
								
					int codigoLeido = std::atoi(_codigoCliente.c_str());
					
					if(codigoLeido > 0){											
						Usuario* usuario = new Usuario();
						usuario->setCodigoCliente(codigoLeido);						
						usuario->setEstado(_estado == "1" ? true:false);
						usuario->setClave(_clave);		
						lst.push_back(usuario);	
					}									
				}
				this->_aleer.close();
			}			
			return lst;
		}
		
	public:	
		ArchivoUsuario() : ArchivoGenerico("usuarios.txt"){
			
		}
								
		void grabar(Usuario* obj){				
			ofstream fescribir;
			fescribir.open(this->getArchivo().c_str(),ios::out|ios::app);
			fescribir << obj->toRaw();
			fescribir << endl;
			fescribir.close();
		}
	
		Usuario* buscarPorCodigoCliente(int codigoCliente){
			Usuario* usuario = NULL;
			leerArchivo();
			
			//cout << endl << "Buscando usuario (codigoCliente) : " << codigoCliente << endl;
			
			if(this->isEnableToRead()){				
				while (!this->_aleer.eof()){
					string _codigoCliente,_clave,_estado;
															
					getline(this->_aleer,_codigoCliente,';');
					getline(this->_aleer,_clave,';');
					getline(this->_aleer,_estado,'\n');
						
					int codigoLeido = std::atoi(_codigoCliente.c_str());
		
					//cout << endl << "Leyendo usuario : " << codigoLeido << endl;
		
					if(codigoLeido == codigoCliente){
						//cout << endl << "encontro usuario : " << codigoLeido << endl;	
						usuario = new Usuario();
						usuario->setCodigoCliente(codigoLeido);						
						usuario->setEstado(_estado == "1" ? true:false);
						usuario->setClave(_clave);					
						return usuario;
					}																													
				}
				this->_aleer.close();
			}				
			return usuario;		  
		}
		
		
		void actualizar(Usuario* usuario){
			//se lee todo
			vector<Usuario*> listadoTotal = this->listar();		
			
			ofstream fescribir;
			//se reescribe todo el archivo
			fescribir.open(this->getArchivo().c_str(),ios::out|ios::ate);
			
			for(int i=0; i < listadoTotal.size();i++){			
				if(listadoTotal.at(i)->getCodigoCliente() == usuario->getCodigoCliente()){
					fescribir << usuario->toRaw();
				}else{
					fescribir << listadoTotal.at(i)->toRaw();
				}								
				fescribir << endl;
			}
				
			fescribir.close();		
		}
	
	
};


#endif
