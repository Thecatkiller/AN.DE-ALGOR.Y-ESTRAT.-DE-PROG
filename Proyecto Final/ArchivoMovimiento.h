#ifndef ARCHIVO_MOVIMIENTO_H
#define ARCHIVO_MOVIMIENTO_H

#include "ArchivoGenerico.h"

class ArchivoMovimiento : public ArchivoGenerico{

	public:
		ArchivoMovimiento() : ArchivoGenerico("movimientos.txt"){
			
		}

};

#endif
