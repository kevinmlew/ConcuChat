/*
 * ManejadorDeColaDeMensajes.cpp
 *
 *  Created on: Jun 17, 2016
 *      Author: juan
 */

#include "ManejadorDeColaDeMensajes.h"


ManejadorDeColaDeMensajes::ManejadorDeColaDeMensajes(const string archivo): colaDeMensajes(archivo, 'a'), tipoALeer(MENSAJE_A_SERVIDOR) {
	SignalHandler :: getInstance()->registrarHandler ( SIGINT,&sigint_handler );

}

void ManejadorDeColaDeMensajes::run() {
	mensaje m;
	while(sigint_handler.getGracefulQuit() == 0) {
		colaDeMensajes.leer(tipoALeer, &m);
		procesarMensaje(m);
	}
}

void ManejadorDeColaDeMensajes::cerrarCola() {
	colaDeMensajes.destruir();
}

ManejadorDeColaDeMensajes::~ManejadorDeColaDeMensajes() {
	SignalHandler :: getInstance()->destruir();
}

