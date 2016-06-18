/*
 * ManejadorDeColaDeMensajes.cpp
 *
 *  Created on: Jun 17, 2016
 *      Author: juan
 */

#include "ManejadorDeColaDeMensajes.h"


ManejadorDeColaDeMensajes::ManejadorDeColaDeMensajes(const string archivo): colaDeMensajes(archivo, 'a'), gracefulQuit(true), tipoALeer(MENSAJE_A_SERVIDOR) {

}

void ManejadorDeColaDeMensajes::run() {
	mensaje m;
	while(gracefulQuit) {
		colaDeMensajes.leer(tipoALeer, &m);
		procesarMensaje(m);
	}
}

ManejadorDeColaDeMensajes::~ManejadorDeColaDeMensajes() {
}

