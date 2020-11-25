#ifndef ARCHIVO_CLIENTE_H
#define ARCHIVO_CLIENTE_H

#include "Cliente.h";


#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <vector>

#include "ArchivoUsuario.h"
#include "Usuario.h"

#include "ArchivoCuenta.h"
#include "Cuenta.h"

using namespace std;

class ArchivoCliente{
	private:
		string ARCHIVO_CLIENTE = "clientes.txt";
		bool isEnableToRead = false;
		ifstream aleer;
		
		bool existFile()
		{
		    return ifstream(ARCHIVO_CLIENTE.c_str()).good();
		}
		
		void leerArchivo() {
			
			if(this->existFile() == false){
				ofstream fescribir;
				fescribir.open(ARCHIVO_CLIENTE.c_str(),ios::out|ios::app);
				fescribir.close();
			}
			
			aleer.open(ARCHIVO_CLIENTE.c_str(),ios::in);
			if (!aleer.is_open()){
			 	cout << "No se puede abrir el archivo: " << ARCHIVO_CLIENTE << endl;
				isEnableToRead = false;
			}
			isEnableToRead = true;
		}
		
		vector<Cliente*> listar(){
			vector<Cliente*> lst;								
			leerArchivo();
			if(isEnableToRead){				
				while (!aleer.eof()){
					string codigo;
					string nombre;
					string apellidoPaterno;
					string apellidoMaterno;
					string DNI;
					
					getline(aleer,codigo,';');
					getline(aleer,nombre,';');
					getline(aleer,apellidoPaterno,';');
					getline(aleer,apellidoMaterno,';');
					getline(aleer,DNI,'\n');	
								
					int codigoCliente = std::atoi(codigo.c_str());
					
					if(codigoCliente > 0){											
						Cliente* cliente = new Cliente();
						cliente->setCodigo(codigoCliente);
						cliente->setNombre(nombre);
						cliente->setApellidoPaterno(apellidoPaterno);
						cliente->setApellidoMaterno(apellidoMaterno);
						cliente->setDNI(DNI);
						lst.push_back(cliente);	
					}									
				}
			}			
			return lst;
		}
		
	public:		
					
		Cliente* buscarPorCodigo(int codigoCliente){
			Cliente* cliente = NULL;
			leerArchivo();
			if(isEnableToRead){				
				while (!aleer.eof()){
					string codigo;
					string nombre;
					string apellidoPaterno;
					string apellidoMaterno;
					string DNI;
					
					getline(aleer,codigo,';');
					getline(aleer,nombre,';');
					getline(aleer,apellidoPaterno,';');
					getline(aleer,apellidoMaterno,';');
					getline(aleer,DNI,'\n');	

					int codigoLeido = std::atoi(codigo.c_str());
		
					if(codigoCliente == codigoLeido){
						ArchivoUsuario* archivoUsuario = new ArchivoUsuario();
						ArchivoCuenta* archivoCuenta = new ArchivoCuenta();
						
						cliente = new Cliente();
						cliente->setCodigo(codigoCliente);
						cliente->setNombre(nombre);
						cliente->setApellidoPaterno(apellidoPaterno);
						cliente->setApellidoMaterno(apellidoMaterno);
						cliente->setDNI(DNI);
						cliente->setUsuario(archivoUsuario->buscarPorCodigoCliente(cliente->getCodigo()));
						cliente->setCuentas(archivoCuenta->buscarCuentasPorCliente(cliente->getCodigo()));
						
						return cliente;
					}																													
				}
				aleer.close();
			}				
			return cliente;		  
		}
		
		
		Cliente* buscarPorDNI(string DNI){
		  	Cliente* cliente = NULL;
		  	leerArchivo();
			if(isEnableToRead){
				while (!aleer.eof()){
					string codigo;
					string nombre;
					string apellidoPaterno;
					string apellidoMaterno;
					string _DNI;
					
					getline(aleer,codigo,';');
					getline(aleer,nombre,';');
					getline(aleer,apellidoPaterno,';');
					getline(aleer,apellidoMaterno,';');
					getline(aleer,_DNI,'\n');	

					if(DNI == _DNI){
						ArchivoCuenta* archivoCuenta = new ArchivoCuenta();
						ArchivoUsuario* archivoUsuario = new ArchivoUsuario();
																		
						cliente = new Cliente();
						cliente->setCodigo(std::atoi(codigo.c_str()));
						cliente->setNombre(nombre);
						cliente->setApellidoPaterno(apellidoPaterno);
						cliente->setApellidoMaterno(apellidoMaterno);
						cliente->setDNI(DNI);
						cliente->setUsuario(archivoUsuario->buscarPorCodigoCliente(cliente->getCodigo()));
						cliente->setCuentas(archivoCuenta->buscarCuentasPorCliente(cliente->getCodigo()));
												
						return cliente;
					}		
					
																															
				}
				aleer.close();
			}				
			return cliente;
		}
		
		void grabar(Cliente* c){	
		
			Cliente* cCodigo = this->buscarPorCodigo(c->getCodigo());
			Cliente* cDNI = this->buscarPorDNI(c->getDNI());
		
			if(cCodigo != NULL){
				cout << "Ya existe un cliente registrado con ese codigo."<<endl;
				return;
			}
			if(cDNI != NULL){
				cout << "Ya existe un cliente registrado con ese DNI."<<endl;
				return;
			}
		
			
			ofstream fescribir;
			fescribir.open(ARCHIVO_CLIENTE.c_str(),ios::out|ios::app);
			fescribir << c->toRaw();
			fescribir << endl;
			fescribir.close();
		}
		
		void actualizar(Cliente* cliente){
			//se lee todo
			vector<Cliente*> listadoTotal = this->listar();		
			
			ofstream fescribir;
			//se reescribe todo el archivo
			fescribir.open(ARCHIVO_CLIENTE.c_str(),ios::out|ios::ate);
			
			for(int i=0; i < listadoTotal.size();i++){			
				if(listadoTotal.at(i)->getCodigo() == cliente->getCodigo()){
					fescribir << cliente->toRaw();
				}else{
					fescribir << listadoTotal.at(i)->toRaw();
				}								
				fescribir << endl;
			}
				
			fescribir.close();		
		}
	
	
};


#endif
