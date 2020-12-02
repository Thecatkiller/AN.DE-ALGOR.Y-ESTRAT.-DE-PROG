#ifndef MENU_DIVISA_H
#define MENU_DIVISA_H

#include "MenuGenerico.h"
#include "ArchivoDivisa.h"
#include "Divisa.h"

class MenuDivisa : public MenuGenerico{
	private:
		void registrar(){
			system("cls");
			Divisa *divisa = new Divisa();
			divisa->pedirDatos();
			
			ArchivoDivisa* archivoDivisa = new ArchivoDivisa();
			
			if(archivoDivisa->buscarPorCodigo(divisa->getCodigo()) != NULL){
				cout << endl << "Ya existe una divisa con ese código";
			}else{
				if(archivoDivisa->grabar(divisa)){
					cout << endl << "Se grabó correctamente!!";
					system("pause");
				}	
			}
												
		}
		
		void listar(){
			system("cls");
			ArchivoDivisa* archivoDivisa = new ArchivoDivisa();
			
			vector<Divisa*> listadoTotal = archivoDivisa->listarTodo();
			
			for(int i=0; i < listadoTotal.size();i++){
				Divisa* d = listadoTotal.at(i);
				cout << d->getCodigo() << endl;				
			}
			
		
			
			system("pause");
		}
		
	protected:
		virtual void cargarOpciones() {
			MenuGenerico::cargarOpciones();
			cout << "Menu Divisa     " << endl;
			cout << "------------------------------" << endl;
			cout << "[1] Registrar divisa       " << endl;
			cout << "[2] Listar divisas         " << endl;
			cout << "[9] Salir                  " << endl;
			cout << "Seleccione opción: ";	
		}
	public:	
		static const char OPC_REGISTRAR_DIVISA 		= '1';
		static const char OPC_LISTAR_DIVISA     	= '2';
		static const char OPC_SALIR			     	= '9';
		MenuDivisa(){
			this->setColor("02");
		}
		
		virtual void mostrar(){
			char opc;			
			do{
				this->cargarOpciones();				
				opc = this->leerOpcion();
				
				switch(opc)	{
					case MenuDivisa::OPC_REGISTRAR_DIVISA:{
						this->registrar();
						break;
					}					
					case MenuDivisa::OPC_LISTAR_DIVISA:{
						this->listar();
						break;
					}
				}
				
			}while(opc!=this->OPC_SALIR);	
		}
	
};

#endif
