#ifndef ARCHIVO_MOVIMIENTO_H
#define ARCHIVO_MOVIMIENTO_H

#include "ArchivoGenerico.h"
#include "Movimiento.h"

class ArchivoMovimiento : public ArchivoGenerico{

	private:
		vector<Movimiento*> _listGeneralMovimientos;	
		bool _listaYaLeida = false;
		
		vector<Movimiento*> listar(){
			//esto hace que no se vuelva a leer la lista si ya se ha leido antes
			if(_listaYaLeida)
				return _listGeneralMovimientos;
			
			vector<Movimiento*> lst;								
			this->leerArchivo();
			if(isEnableToRead()){				
				while (!this->_aleer.eof()){
					string _codigo,_codigoCuenta,_monto,_fecha_dia,_fecha_mes,_fecha_anio,
					_fecha_hora,_fecha_minuto,_fecha_segundo,_codigoCajero,_descripcion;
					
					getline(this->_aleer,_codigo,';');
					getline(this->_aleer,_codigoCuenta,';');
					getline(this->_aleer,_monto,';');
					getline(this->_aleer,_fecha_dia,';');
					getline(this->_aleer,_fecha_mes,';');
					getline(this->_aleer,_fecha_anio,';');
					getline(this->_aleer,_fecha_hora,';');
					getline(this->_aleer,_fecha_minuto,';');	
					getline(this->_aleer,_fecha_segundo,';');	
					getline(this->_aleer,_descripcion,';');		
					getline(this->_aleer,_codigoCajero,'\n');	
								
					int codigoCuenta = std::atoi(_codigoCuenta.c_str());
										
					if(codigoCuenta > 0){											
						Movimiento* mov = new Movimiento(
							_codigo,
							codigoCuenta,
							atof(_monto.c_str()),
							atoi(_fecha_dia.c_str()),
							atoi(_fecha_mes.c_str()),
							atoi(_fecha_anio.c_str()),
							atoi(_fecha_hora.c_str()),
							atoi(_fecha_minuto.c_str()),
							atoi(_fecha_segundo.c_str()),						
							atoi(_codigoCajero.c_str()),
							_descripcion
						);																							
						lst.push_back(mov);	
					}									
				}
			}
			_listaYaLeida = true;
			_listGeneralMovimientos = lst;			
			return lst;
		}

		void ordenarSeleccionByCodigoCuenta(vector<Movimiento*> &lista){
			int vecsize = lista.size();
			for (int j = 0; j < vecsize - 1; ++j) {			
			    int min = j;
			    for (int i = j+1; i < vecsize; ++i) {
			        if (lista.at(min)->getCodigoCuenta() > lista.at(i)->getCodigoCuenta()) {
			            min = i;
			        }			
			    }  
			    if (min != j)
			        swap(lista.at(j), lista.at(min));
			}
		}
		
		int busquedaBinariaByCodigoCuenta(vector<Movimiento*> lista, int inicio, int final, int codigo)
		{
			int medio;
			if(inicio<=final)
			{
				medio = (inicio+final)/2;
				int codigoBuscar = lista.at(medio)->getCodigoCuenta();
				if(codigoBuscar == codigo) return medio;
				else if(codigoBuscar > codigo) final=medio-1;
				else if (codigoBuscar < codigo) inicio = medio+1;
				return busquedaBinariaByCodigoCuenta(lista,inicio,final,codigo);
			}
			return -1;
		}
		
		//usando busqueda binaria iterativa
		int obtenerIndiceMenorLista(vector<Movimiento*> lista,int codigoCuenta){
			int low = 0, high = lista.size() - 1;
		    int startIndex = -1;
		    while (low <= high) {
		        int mid = (high - low) / 2 + low;
		        int codigoBuscar = lista.at(mid)->getCodigoCuenta();
		        if (codigoBuscar > codigoCuenta) {
		            high = mid - 1;
		        } else if (codigoBuscar == codigoCuenta) {
		            startIndex = mid;
		            high = mid - 1;
		        } else
		            low = mid + 1;
		    }
		    return startIndex;
		}
		
		//usando busqueda binaria iterativa
		int obtenerIndiceMayorLista(vector<Movimiento*> lista,int codigoCuenta){
			int endIndex = -1;
		    int low = 0;
		    int high = lista.size() - 1;
		    while (low <= high) {
		        int mid = (high - low) / 2 + low;
		        int codigoBuscar = lista.at(mid)->getCodigoCuenta();	        
		        if (codigoBuscar > codigoCuenta) {
		            high = mid - 1;
		        } else if (codigoBuscar == codigoCuenta) {
		            endIndex = mid;
		            low = mid + 1;
		        } else
		            low = mid + 1;
		    }
		    return endIndex;
		}
		
		

	public:
		ArchivoMovimiento() : ArchivoGenerico("movimientos.txt"){
			
		}
		
		vector<Movimiento*> listarByCodigoCuenta(int codigoCuenta){
			vector<Movimiento*> movimientos;
			vector<Movimiento*> list = this->listar();	
			ordenarSeleccionByCodigoCuenta(list);
			
			/*cout << endl;
			for(int i=0; i < list.size();i++){			
				cout << list.at(i)->toRaw() << endl;
			}*/
						
			int idxMenor = obtenerIndiceMenorLista(list, codigoCuenta);
			int idxMayor = obtenerIndiceMayorLista(list, codigoCuenta);
			//cout << endl << "idxMenor : " << idxMenor << endl;
			//cout << endl << "idxMayor : " << idxMayor << endl;
			
			if (idxMenor != -1 && idxMayor != -1){
		        for(int i =idxMayor ; i>=idxMenor; i--){
		        	movimientos.push_back(list.at(i));
				}
    		}
																									
			return movimientos;		
		}
		
		bool grabar(Movimiento* m){	
			ofstream fescribir;
			fescribir.open(this->getArchivo().c_str(),ios::out|ios::app);
			fescribir << m->toRaw();
			fescribir << endl;
			fescribir.close();			
			return true;
		}
		

};

#endif