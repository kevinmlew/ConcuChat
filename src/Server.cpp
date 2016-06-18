//============================================================================
// Name        : ConcuChat.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <unistd.h>

#include "model/Historial.h"
#include "model/ManejadorDeConexiones.h"
#include "model/ManejadorDeMensajes.h"

using namespace std;

#define ARCHIVO_COLA_MENSAJES "colaDeMensajes"
#define ARCHIVO_COLA_CONEX "colaDeConexiones"
#define ARCHIVO_HISTORIAL "historial"

int main() {
	pid_t pid = fork();

	//El manejador de mensajes se usa en ambos procesos
	Historial historial(ARCHIVO_HISTORIAL);
	ManejadorDeMensajes manejadorDeMensajes(ARCHIVO_COLA_MENSAJES, &historial);

	if (pid == 0){
		//Manejar conexiones entrantes
		ManejadorDeConexiones manejadorDeConexiones(ARCHIVO_COLA_CONEX, &manejadorDeMensajes);
		manejadorDeConexiones.run();
	} else {
		//Manejar mensajes de usuarios logueados
		manejadorDeMensajes.run();
	}

	return 0;
}
