#ifndef ARCHIVO_BILLETE_H
#define ARCHIVO_BILLETE_H

#include "Billete.h"
#include <vector>
#include "ArchivoGenerico.h"

class ArchivoBillete : public ArchivoGenerico {
	private:
		vector<Billete*> listar(){
			vector<Billete*> lst;								
			this->leerArchivo();
			if(isEnableToRead()){				
				while (!this->_aleer.eof()){
					string cantidad,codigoCajero,valorBillete;

					getline(this->_aleer,codigoCajero,';');
					getline(this->_aleer,valorBillete,';');				
					getline(this->_aleer,cantidad,'\n');
													
					int _codigoCajero = std::atoi(codigoCajero.c_str());	
													
					if(_codigoCajero > 0){		
						int _valor = std::atoi(valorBillete.c_str());
						int _cantidad = std::atoi(cantidad.c_str());
						
						ValorBillete valor = (ValorBillete)_valor;
														
						Billete* billete = new Billete(_codigoCajero,valor,_cantidad);						
						lst.push_back(billete);	
					}									
				}
				this->_aleer.close();
			}			
			return lst;
		}
	
	public:
		ArchivoBillete() : ArchivoGenerico("billetes.txt"){
			
		}
		
		vector<Billete*> buscarBilletesPorCajero(int codigoCajero){
			vector<Billete*> listadoTotal = this->listar();	
			vector<Billete*> lst;
			
			for(int i=0; i < listadoTotal.size();i++){			
				if(listadoTotal.at(i)->getCodigoCajero() == codigoCajero){
					lst.push_back(listadoTotal.at(i));
				}
			}
			
			return lst;
		}
		
		void actualizar(Billete* billete){
			//se lee todo
			vector<Billete*> listadoTotal = this->listar();		
			
			ofstream fescribir;
			//se reescribe todo el archivo
			fescribir.open(this->getArchivo().c_str(),ios::out|ios::ate);
			
			for(int i=0; i < listadoTotal.size();i++){			
				if(listadoTotal.at(i)->getCodigoCajero() == billete->getCodigoCajero() &&
					listadoTotal.at(i)->getValorBillete() == billete->getValorBillete())
				{
					fescribir << billete->toRaw();
				}
				else
				{
					fescribir << listadoTotal.at(i)->toRaw();
				}								
				fescribir << endl;
			}
				
			fescribir.close();		
		}
		
		void grabar(Billete* b){							
			ofstream fescribir;
			fescribir.open(this->getArchivo().c_str(),ios::out|ios::app);
			fescribir << b->toRaw();
			fescribir << endl;
			fescribir.close();
		}
};


#endif
