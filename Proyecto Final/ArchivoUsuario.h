#ifndef ARCHIVO_USUARIO_H
#define ARCHIVO_USUARIO_H

#include "Usuario.h";


#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdlib>

using namespace std;

class ArchivoUsuario{
	private:
		string ARCHIVO = "usuarios.txt";
		bool isEnableToRead = false;
		ifstream aleer;
		
		bool existFile()
		{
		    return ifstream(ARCHIVO.c_str()).good();
		}
		
		void leerArchivo() {
			
			if(this->existFile() == false){
				ofstream fescribir;
				fescribir.open(ARCHIVO.c_str(),ios::out|ios::app);
				fescribir.close();
			}
			
			aleer.open(ARCHIVO.c_str(),ios::in);
			if (!aleer.is_open()){
			 	cout << "No se puede abrir el archivo: " << ARCHIVO << endl;
				isEnableToRead = false;
			}
			isEnableToRead = true;
		}
		
		vector<Usuario*> listar(){
			vector<Usuario*> lst;								
			leerArchivo();
			if(isEnableToRead){				
				while (!aleer.eof()){
					string _codigoCliente;
					string _clave;
					string _estado;
															
					getline(aleer,_codigoCliente,';');
					getline(aleer,_clave,';');
					getline(aleer,_estado,'\n');
								
					int codigoLeido = std::atoi(_codigoCliente.c_str());
					
					if(codigoLeido > 0){											
						Usuario* usuario = new Usuario();
						usuario->setCodigoCliente(codigoLeido);						
						usuario->setEstado(_estado == "1" ? true:false);
						usuario->setClave(_clave);		
						lst.push_back(usuario);	
					}									
				}
			}			
			return lst;
		}
		
	public:								
		void grabar(Usuario* obj){				
			ofstream fescribir;
			fescribir.open(ARCHIVO.c_str(),ios::out|ios::app);
			fescribir << obj->toRaw();
			fescribir << endl;
			fescribir.close();
		}
	
		Usuario* buscarPorCodigoCliente(int codigoCliente){
			Usuario* usuario = NULL;
			leerArchivo();
			if(isEnableToRead){				
				while (!aleer.eof()){
					string _codigoCliente;
					string _clave;
					string _estado;
															
					getline(aleer,_codigoCliente,';');
					getline(aleer,_clave,';');
					getline(aleer,_estado,'\n');
						
					int codigoLeido = std::atoi(_codigoCliente.c_str());
		
					if(codigoLeido == codigoCliente){	
						usuario = new Usuario();
						usuario->setCodigoCliente(codigoLeido);						
						usuario->setEstado(_estado == "1" ? true:false);
						usuario->setClave(_clave);					
						return usuario;
					}																													
				}
				aleer.close();
			}				
			return usuario;		  
		}
		
		
		void actualizar(Usuario* usuario){
			//se lee todo
			vector<Usuario*> listadoTotal = this->listar();		
			
			ofstream fescribir;
			//se reescribe todo el archivo
			fescribir.open(ARCHIVO.c_str(),ios::out|ios::ate);
			
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
