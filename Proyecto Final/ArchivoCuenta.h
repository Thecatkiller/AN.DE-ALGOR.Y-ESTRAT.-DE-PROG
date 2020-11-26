#ifndef ARCHIVO_CUENTA_H
#define ARCHIVO_CUENTA_H

#include "Cuenta.h";

#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include <stdlib.h> 

using namespace std;

class ArchivoCuenta : public ArchivoGenerico{
	private:			
		vector<Cuenta*> listar(){
			vector<Cuenta*> lst;								
			leerArchivo();
			if(isEnableToRead()){				
				while (!this->_aleer.eof()){
					string _codigo,_codigoCliente,_estado,_saldo;

					getline(this->_aleer,_codigo,';');
					getline(this->_aleer,_codigoCliente,';');
					getline(this->_aleer,_estado,';');
					getline(this->_aleer,_saldo,'\n');
								
					int codigo = std::atoi(_codigo.c_str());
					
					if(codigo > 0){											
						int codigoCliente = std::atoi(_codigoCliente.c_str());						
						Cuenta* cuenta = new Cuenta();
						cuenta->setCodigo(codigo);
						cuenta->setCodigoCliente(codigoCliente);					
						cuenta->setEstado(_estado == "1" ? true:false);
						cuenta->setSaldo(atof(_saldo.c_str()));
														
						lst.push_back(cuenta);	
					}									
				}
				this->_aleer.close();
			}			
			return lst;
		}
		
	public:
		ArchivoCuenta() : ArchivoGenerico("cuentas.txt"){
			
		}
		
		vector<Cuenta*> buscarCuentasPorCliente(int codigoCliente){			
			vector<Cuenta*> lst;
			vector<Cuenta*> listadoTotal = this->listar();
			
			for(int i=0; i < listadoTotal.size();i++){
				if(listadoTotal.at(i)->getCodigoCliente() == codigoCliente){
					lst.push_back(listadoTotal.at(i));
				}
			}		
			
			return lst;
		}
		
		void grabar(Cuenta* cuenta){
			ofstream fescribir;
			fescribir.open(this->getArchivo().c_str(),ios::out|ios::app);
			fescribir << cuenta->toRaw();
			fescribir << endl;
			fescribir.close();
		}
		
		vector<Cuenta*> listarTodo(){
			return this->listar();
		}
		
		void actualizar(Cuenta* cuenta){
			//se lee todo
			vector<Cuenta*> listadoTotal = this->listar();		
			ofstream fescribir;
			//se reescribe todo el archivo
			fescribir.open(this->getArchivo().c_str(),ios::out|ios::ate);
			
			for(int i=0; i < listadoTotal.size();i++){			
				if(listadoTotal.at(i)->getCodigo() == cuenta->getCodigo()){
					fescribir << cuenta->toRaw();
				}else{
					fescribir << listadoTotal.at(i)->toRaw();
				}								
				fescribir << endl;
			}
				
			fescribir.close();		
		}
	
};

#endif
