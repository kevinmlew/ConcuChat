/*
 * ManejadorDeConexiones.h
 *
 *  Created on: 5 de jun. de 2016
 *      Author: kevin
 */

#ifndef MODEL_MANEJADORDECONEXIONES_H_
#define MODEL_MANEJADORDECONEXIONES_H_

#include "../ipc/Cola.h"
#include "Mensaje.h"

using namespace std;

class ManejadorDeConexiones {
	Cola<mensaje> colaDeConexiones;
	bool gracefulQuit;

public:
	ManejadorDeConexiones();
	void run();
	virtual ~ManejadorDeConexiones();
};

#endif /* MODEL_MANEJADORDECONEXIONES_H_ */
