/*
 * ManejadorDeColaDeMensajes.h
 *
 *  Created on: Jun 17, 2016
 *      Author: juan
 */

#ifndef MODEL_MANEJADORDECOLADEMENSAJES_H_
#define MODEL_MANEJADORDECOLADEMENSAJES_H_

#include <string>

#include "../ipc/Cola.h"
#include "../ipc/SignalHandler.h"
#include "../ipc/SIGINT_Handler.h"
#include "Mensaje.h"

using namespace std;

class ManejadorDeColaDeMensajes {
protected:
	Cola<mensaje> colaDeMensajes;
	SIGINT_Handler sigint_handler;
	int tipoALeer;
	virtual void procesarMensaje(mensaje m) = 0;

public:
	ManejadorDeColaDeMensajes(const string archivo);
	void run();
	void cerrarCola();
	virtual ~ManejadorDeColaDeMensajes();
};

#endif /* MODEL_MANEJADORDECOLADEMENSAJES_H_ */
