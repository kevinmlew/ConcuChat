//============================================================================
// Name        : ConcuChat.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <unistd.h>

#include "exceptions/IPCException.h"
#include "log/Logger.h"
#include "model/Historial.h"
#include "model/ManejadorDeConexiones.h"
#include "model/ManejadorDeMensajes.h"

using namespace std;

#define ARCHIVO_COLA_MENSAJES "colaDeMensajes"
#define ARCHIVO_LOCK_COLA_MENSAJES "colaDeMensajesLock"
#define ARCHIVO_COLA_CONEX "colaDeConexiones"
#define ARCHIVO_HISTORIAL "historial"

int main() {
	//El manejador de mensajes se usa en ambos procesos
	Historial historial(ARCHIVO_HISTORIAL);
	try {
		ManejadorDeMensajes manejadorDeMensajes(ARCHIVO_COLA_MENSAJES, &historial, ARCHIVO_LOCK_COLA_MENSAJES);
		Logger::insert(Logger::TYPE_DEBUG, "Manejador De Mensajes iniciado");
		pid_t pid = fork();
		if (pid == 0){
			//Manejar conexiones entrantes
			ManejadorDeConexiones manejadorDeConexiones(ARCHIVO_COLA_CONEX, &manejadorDeMensajes);
			Logger::insert(Logger::TYPE_DEBUG, "Manejador De Conexiones iniciado");
			manejadorDeConexiones.run();
			manejadorDeConexiones.cerrarCola();
		} else {
			//Manejar mensajes de usuarios logueados
			manejadorDeMensajes.run();
			manejadorDeMensajes.cerrarCola();
		}
		Logger::destruir();
	} catch (IPCException& e){
		Logger::insertError(e.what(), e.getCode());
	}

	return 0;
}
