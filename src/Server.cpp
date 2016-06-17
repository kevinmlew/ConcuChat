//============================================================================
// Name        : ConcuChat.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <unistd.h>

#include "model/ManejadorDeConexiones.h"
#include "model/ManejadorDeMensajes.h"

using namespace std;

#define ARCHIVO_COLA_MENSAJES "colaDeMensajes"
#define ARCHIVO_COLA_CONEX "colaDeConexiones"

int main() {
	pid_t pid = fork();
	if (pid == 0){
		//Manejar conexiones entrantes
		ManejadorDeConexiones manejadorDeConexiones(ARCHIVO_COLA_CONEX);
		manejadorDeConexiones.run();
	} else {
		//Manejar mensajes de usuarios logueados
		ManejadorDeMensajes manejadorDeMensajes(ARCHIVO_COLA_MENSAJES);
		manejadorDeMensajes.run();
	}

	return 0;
}
