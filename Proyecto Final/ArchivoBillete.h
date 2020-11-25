#ifndef ARCHIVO_BILLETE_H
#define ARCHIVO_BILLETE_H

#include "Billete.h"
#include <vector>

class ArchivoBillete{
	
	private:
		string ARCHIVO = "billetes.txt";
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
		
		vector<Billete*> listar(){
			vector<Billete*> lst;								
			leerArchivo();
			if(isEnableToRead){				
				while (!aleer.eof()){
					string cantidad;
					string codigoCajero;
					string valorBillete;
					
					getline(aleer,codigoCajero,';');
					getline(aleer,valorBillete,';');				
					getline(aleer,cantidad,'\n');
													
					int _codigoCajero = std::atoi(codigoCajero.c_str());	
													
					if(_codigoCajero > 0){		
						int _valor = std::atoi(valorBillete.c_str());
						int _cantidad = std::atoi(cantidad.c_str());
						
						ValorBillete valor = (ValorBillete)_valor;
														
						Billete* billete = new Billete(_codigoCajero,valor,_cantidad);						
						lst.push_back(billete);	
					}									
				}
			}			
			return lst;
		}
	
	public:
		
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
			fescribir.open(ARCHIVO.c_str(),ios::out|ios::ate);
			
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
			fescribir.open(ARCHIVO.c_str(),ios::out|ios::app);
			fescribir << b->toRaw();
			fescribir << endl;
			fescribir.close();
		}
};


#endif
