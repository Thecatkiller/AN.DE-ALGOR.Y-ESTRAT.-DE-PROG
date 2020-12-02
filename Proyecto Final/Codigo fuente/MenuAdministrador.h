#ifndef MENU_ADMINISTRADOR_H
#define MENU_ADMINISTRADOR_H

#include "MenuGenerico.h"
#include "MenuCajero.h"


#include "Cliente.h"
#include "ArchivoCliente.h"
#include "ArchivoCuenta.h"
#include "ArchivoUsuario.h"

#include "Usuario.h"

#include <cstdlib>   
#include <ctime> 
#include "Cuenta.h"
#include "MenuDivisa.h"

class MenuAdministrador : public MenuGenerico{
	
	private:
		void registrarCliente(){
			//cliente
			ArchivoCliente* archivoC = new ArchivoCliente();					
			Cliente *cliente = new Cliente();					
			cliente->pedirDatos();
			if(archivoC->grabar(cliente)){												
				//cuenta								
				ArchivoCuenta* archivoCuenta = new ArchivoCuenta();
				Cuenta *cuenta = new Cuenta(cliente->getCodigo());
				//saldo inicial de la cuenta
				cuenta->setSaldo(1000);
				archivoCuenta->grabar(cuenta);
							
				//usuario
				ArchivoUsuario* archivoUsuario = new ArchivoUsuario();
				Usuario* usuario = new Usuario(cliente->getCodigo(),cliente->getDNI());
				archivoUsuario->grabar(usuario);
			}										
		}
	
	protected:
		virtual void cargarOpciones() {
			MenuGenerico::cargarOpciones();
			cout << "Menu Administrador     " << endl;
			cout << "------------------------------" << endl;
			cout << "[1] Registrar cliente      " << endl;
			cout << "[2] Buscar cliente         " << endl;
			cout << "[3] Crear cuenta           " << endl;
			cout << "[4] Mantenimiento cajero   " << endl;
			cout << "[5] Mantenimiento divisa   " << endl;
			cout << "[9] Salir                  " << endl;
			cout << "Seleccione opción: ";	
		}
	
	public:
		static const char OPC_REGISTRAR_CLIENTE 		= '1';
		static const char OPC_BUSCAR_CLIENTE     		= '2';
		static const char OPC_CREAR_CUENTA      		= '3';
		static const char OPC_MANTENIMIENTO      		= '4';
		static const char OPC_DIVISA      				= '5';
		static const char OPC_SALIR			     		= '9';
		
		MenuAdministrador(){
			this->setColor("03");
		}
		
		virtual void mostrar(){
			char opc;			
			do{
				this->cargarOpciones();				
				opc = this->leerOpcion();
					
				switch(opc)	{
					case MenuAdministrador::OPC_REGISTRAR_CLIENTE:
					{
						registrarCliente();
						break;
					}
					case MenuAdministrador::OPC_BUSCAR_CLIENTE:
					{
						ArchivoCliente* archivo = new ArchivoCliente();		
										
						int cod;						
						cout << endl << "Ingrese Codigo : ";
						cin >> cod;
						Cliente *c = archivo->buscarPorCodigo(cod);
						if(c != NULL)
							c->mostrar();
						else 
							cout << "no se encontró";
						break;
					}
					case MenuAdministrador::OPC_CREAR_CUENTA:
					{
						cout << endl << "Ingrese Codigo Cliente (numero): ";
						
						int codCliente;
						cin >> codCliente;
						
						ArchivoCliente* archivo = new ArchivoCliente();	
						Cliente *c = archivo->buscarPorCodigo(codCliente);
						if(c != NULL)
						{
							Cuenta* cuenta = new Cuenta(c->getCodigo());
							double saldo;
							cout << endl << "Ingresar saldo para la cuenta : ";
							cin >> saldo;
							cuenta->setSaldo(saldo);
							
							ArchivoCuenta* archivoCuenta = new ArchivoCuenta();
							archivoCuenta->grabar(cuenta);
							
							cout << endl << endl << "Se grabó correctamente !!"<<endl;
						}
						else 
							cout << "no se encontró";
						
						break;
					}
					case MenuAdministrador::OPC_MANTENIMIENTO:
					{
						(new MenuCajero())->mostrar();
						break;
					}
					case MenuAdministrador::OPC_DIVISA:
					{
						(new MenuDivisa())->mostrar();
						break;
					}
				}
										
								
				if(opc != this->OPC_SALIR){
					cout << endl << endl;	
					system("pause");
				}					
			}while(opc!=this->OPC_SALIR);	
			
			//cout << endl << "Salio del menu"					;
		}
		
};


#endif
