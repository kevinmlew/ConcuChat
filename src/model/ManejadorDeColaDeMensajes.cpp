/*
 * ManejadorDeColaDeMensajes.cpp
 *
 *  Created on: Jun 17, 2016
 *      Author: juan
 */

#include "ManejadorDeColaDeMensajes.h"

#include <csignal>
#include <cstring>
#include <sstream>

#include "../ipc/LockFile.h"
#include "../ipc/SignalHandler.h"

ManejadorDeColaDeMensajes::ManejadorDeColaDeMensajes(const string archivo): colaDeMensajes(archivo, 'a'), tipoALeer(MENSAJE_A_SERVIDOR) {
	SignalHandler :: getInstance()->registrarHandler ( SIGINT,&sigint_handler );

}

void ManejadorDeColaDeMensajes::run() {
	mensaje m;
	int resultado;
	while(sigint_handler.getGracefulQuit() == 0) {
		stringstream ss;
		resultado = colaDeMensajes.leer(tipoALeer, &m);
			if (resultado == -1)
				continue;
		while (m.status == STATUS_INCOMPLETO) {
			ss << m.texto;
			resultado = colaDeMensajes.leer(tipoALeer, &m);
			if (resultado == -1)
			    continue;
		}
		ss << m.texto;
		procesarMensaje(m, ss.str());
	}
}

void ManejadorDeColaDeMensajes::enviarParteMensajeConLock(mensaje msg, string parte, LockFile* lock){
	lock->tomarLock(0);
	enviarParteMensaje(msg, parte);
	lock->liberarLock(0);
}

void ManejadorDeColaDeMensajes::enviarParteMensaje(mensaje msg, string parte){
	if (parte.size() <= TEXTO_SIZE) {
		strcpy(msg.texto, parte.c_str());
		colaDeMensajes.escribir(msg);
	} else {
		int statusAux = msg.status;
		string primeraParte = parte.substr(0, TEXTO_SIZE - 1);
		msg.status = STATUS_INCOMPLETO;
		enviarParteMensaje(msg, primeraParte);
		msg.status = statusAux;
		string resto = parte.substr(TEXTO_SIZE - 1, parte.size() - 1);
		enviarParteMensaje(msg, resto);
	}
}

void ManejadorDeColaDeMensajes::cerrarCola() {
	colaDeMensajes.destruir();
}

ManejadorDeColaDeMensajes::~ManejadorDeColaDeMensajes() {
	SignalHandler :: getInstance()->destruir();
}

