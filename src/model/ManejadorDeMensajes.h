/*
 * ManejadorDeMensajes.h
 *
 *  Created on: 5 de jun. de 2016
 *      Author: kevin
 */

#ifndef MODEL_MANEJADORDEMENSAJES_H_
#define MODEL_MANEJADORDEMENSAJES_H_

#include "../ipc/Cola.h"
#include "Mensaje.h"

class ManejadorDeMensajes {
private:
	Cola<mensaje> colaDeMensajes;
	bool gracefulQuit;
public:
	ManejadorDeMensajes();
	void run();
	virtual ~ManejadorDeMensajes();
};

#endif /* MODEL_MANEJADORDEMENSAJES_H_ */
