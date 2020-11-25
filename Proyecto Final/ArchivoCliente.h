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

#include "ArchivoGenerico.h"
using namespace std;

class ArchivoCliente : public ArchivoGenerico {
	private:
		vector<Cliente*> _listGeneralClientes;	
		bool _listaYaLeida = false;
		
		vector<Cliente*> listar(){
			//esto hace que no se vuelva a leer la lista si ya se ha leido antes
			if(_listaYaLeida)
				return _listGeneralClientes;
			
			vector<Cliente*> lst;								
			this->leerArchivo();
			if(isEnableToRead()){				
				while (!this->_aleer.eof()){
					string codigo,nombre,apellidoPaterno,apellidoMaterno,DNI;
					
					getline(this->_aleer,codigo,';');
					getline(this->_aleer,nombre,';');
					getline(this->_aleer,apellidoPaterno,';');
					getline(this->_aleer,apellidoMaterno,';');
					getline(this->_aleer,DNI,'\n');	
								
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
			_listaYaLeida = true;
			_listGeneralClientes = lst;			
			return lst;
		}
		
		void ordenarSeleccionByCodigo(vector<Cliente*> &lista){
			int vecsize = lista.size();
			for (int j = 0; j < vecsize - 1; ++j) {
			
			    int min = j;
			    for (int i = j+1; i < vecsize; ++i) {
			        if (lista.at(min)->getCodigo() > lista.at(i)->getCodigo()) {
			            min = i;
			        }
			
			    }  
			    if (min != j)
			        swap(lista.at(j), lista.at(min));
			}
		}
		
		void ordenarBurbujaByDNI(vector<Cliente*> &lista){
			int n = lista.size();
			for(int i=0;i<n;i++){
				for(int j=0;j<n-(i+1);j++){
					if(lista.at(j)->getDNI() >lista.at(j+1)->getDNI()){				
						swap(lista.at(j), lista.at(j+1));
					}
				}
			}		
		}	

		
		int busquedaBinariaByCodigo(vector<Cliente*> lista, int inicio, int final, int codigo)
		{
			int medio;
			if(inicio<=final)
			{
				medio = (inicio+final)/2;
				if(lista.at(medio)->getCodigo() == codigo) return medio;
				else if(lista.at(medio)->getCodigo() > codigo) final=medio-1;
				else if (lista.at(medio)->getCodigo()<codigo) inicio = medio+1;
				return busquedaBinariaByCodigo(lista,inicio,final,codigo);
			}
			return -1;
		}
		
	public:		
		ArchivoCliente() : ArchivoGenerico("clientes.txt"){
			
		}
		
		Cliente* buscarPorCodigo(int codigoCliente){
			Cliente* cliente = NULL;
			
			vector<Cliente*> list = this->listar();
			ordenarSeleccionByCodigo(list);
				
			int idx = busquedaBinariaByCodigo(list,0,list.size()-1,codigoCliente);

			if(idx >= 0){
				cliente = new Cliente();
				ArchivoUsuario* archivoUsuario = new ArchivoUsuario();
				ArchivoCuenta* archivoCuenta = new ArchivoCuenta();
				cliente->setUsuario(archivoUsuario->buscarPorCodigoCliente(cliente->getCodigo()));
				cliente->setCuentas(archivoCuenta->buscarCuentasPorCliente(cliente->getCodigo()));
			}
															
			 return cliente;		 
		}
		
		
		Cliente* buscarPorDNI(string DNI){
		  	Cliente* cliente = NULL;
		  	vector<Cliente*> list = this->listar();
		  	
		  	ordenarBurbujaByDNI(list);
		  	
		  	for(int i=0; i < list.size();i++){			
				cout << endl << list.at(i)->toRaw()  << endl;
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
			fescribir.open(this->getArchivo().c_str(),ios::out|ios::app);
			fescribir << c->toRaw();
			fescribir << endl;
			fescribir.close();
		}
		
		void actualizar(Cliente* cliente){
			//se lee todo
			vector<Cliente*> listadoTotal = this->listar();		
			
			ofstream fescribir;
			//se reescribe todo el archivo
			fescribir.open(this->getArchivo().c_str(),ios::out|ios::ate);
			
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
