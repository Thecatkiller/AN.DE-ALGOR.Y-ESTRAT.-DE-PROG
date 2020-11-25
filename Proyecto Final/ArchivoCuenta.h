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

class ArchivoCuenta{
	private:
		string ARCHIVO = "cuentas.txt";
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
		
		vector<Cuenta*> listar(){
			vector<Cuenta*> lst;								
			leerArchivo();
			if(isEnableToRead){				
				while (!aleer.eof()){
					string _codigo;
					string _codigoCliente;
					string _estado;
					string _saldo;
					
					getline(aleer,_codigo,';');
					getline(aleer,_codigoCliente,';');
					getline(aleer,_estado,';');
					getline(aleer,_saldo,'\n');
								
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
			}			
			return lst;
		}
		
	public:
		
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
			fescribir.open(ARCHIVO.c_str(),ios::out|ios::app);
			fescribir << cuenta->toRaw();
			fescribir << endl;
			fescribir.close();
		}
		
		void actualizar(Cuenta* cuenta){
			//se lee todo
			vector<Cuenta*> listadoTotal = this->listar();		
			ofstream fescribir;
			//se reescribe todo el archivo
			fescribir.open(ARCHIVO.c_str(),ios::out|ios::ate);
			
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
