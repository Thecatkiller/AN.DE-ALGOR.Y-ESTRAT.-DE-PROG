#ifndef ARCHIVO_CAJERO_H
#define ARCHIVO_CAJERO_H

#include "Cajero.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include <stdlib.h> 
#include "ArchivoBillete.h"
#include "Billete.h"

#include "ArchivoGenerico.h"

class ArchivoCajero : public ArchivoGenerico{
	
	private:
		vector<Cajero*> listar(){
			vector<Cajero*> lst;								
			leerArchivo();
			if(isEnableToRead()){				
				while (!this->_aleer.eof()){				
					string _codigo,_estado,_ubicacion;

					getline(this->_aleer,_codigo,';');
					getline(this->_aleer,_estado,';');
					getline(this->_aleer,_ubicacion,'\n');
											
					int codigo = std::atoi(_codigo.c_str());
		
					if(codigo > 0){						
						bool estado = _estado == "1" ? true : false;																
						Cajero* cajero = new Cajero(codigo,estado,_ubicacion);
						
						ArchivoBillete* archivoBillete = new ArchivoBillete();
					 	cajero->setBilletes(archivoBillete->buscarBilletesPorCajero(codigo));
																		
						lst.push_back(cajero);
					}
														
				}
			}			
			return lst;
		}
			
	public:
		ArchivoCajero() : ArchivoGenerico("cajeros.txt") {
			
		}
		vector<Cajero*> listarTodo(){
			return this->listar();
		}
		
		void grabar(Cajero* c){		
		
			Cajero* cBuscar = this->buscarPorCodigo(c->getCodigo());
				
			if(cBuscar != NULL){
				cout << endl << "El cajero con ese codigo ya existe !!!" << endl;
				return;
			}		
				
			ofstream fescribir;
			fescribir.open(getArchivo().c_str(),ios::out|ios::app);
			fescribir << c->toRaw();
			fescribir << endl;
			fescribir.close();
			
			ArchivoBillete* archivoBillete = new ArchivoBillete();
			
			Billete* b = new Billete(c->getCodigo(), (ValorBillete)10 ,0);
			archivoBillete->grabar(b);
			
			b = new Billete(c->getCodigo(), (ValorBillete)10 ,0);
			archivoBillete->grabar(b);
			
			b = new Billete(c->getCodigo(), (ValorBillete)20 ,0);
			archivoBillete->grabar(b);
			
			b = new Billete(c->getCodigo(), (ValorBillete)50 ,0);
			archivoBillete->grabar(b);
			
			b = new Billete(c->getCodigo(), (ValorBillete)100 ,0);
			archivoBillete->grabar(b);
			
			b = new Billete(c->getCodigo(), (ValorBillete)200 ,0);
			archivoBillete->grabar(b);
		}
		
		Cajero* buscarPorCodigo(int codigoCajero){
			Cajero* cajero = NULL;
			leerArchivo();
			if(isEnableToRead()){				
				while (!this->_aleer.eof()){
					string _codigo;
					string _estado;
					string _ubicacion;
					
					getline(this->_aleer,_codigo,';');
					getline(this->_aleer,_estado,';');
					getline(this->_aleer,_ubicacion,'\n');
											
					int codigo = std::atoi(_codigo.c_str());
		
					if(codigo == codigoCajero){						
						bool estado = _estado == "1" ? true : false;																
						cajero = new Cajero(codigo,estado,_ubicacion);
						
						ArchivoBillete* archivoBillete = new ArchivoBillete();
					 	cajero->setBilletes(archivoBillete->buscarBilletesPorCajero(codigo));
																		
						return cajero;
					}																													
				}
				this->_aleer.close();
			}				
			return cajero;		  
		}
	
};


#endif
