//============================================================================
// Name        : ConcuChat.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstring>
#include <iostream>
#include <string>
#include <signal.h>

#include "ipc/Cola.h"
#include "model/Mensaje.h"
#include "model/ManejadorDelCliente.h"

using namespace std;

#define ARCHIVO_COLA_MENSAJES "colaDeMensajes"
#define ARCHIVO_COLA_CONEX "colaDeConexiones"

int main() {
	ManejadorDelCliente manejador(ARCHIVO_COLA_MENSAJES);
	manejador.conectar(ARCHIVO_COLA_CONEX);
	manejador.login();

	pid_t pid = fork();
	if (pid == 0){
		//Manejar mensajes entrantes
		manejador.run();
	} else {
		//Manejar escritura de mensajes
		manejador.manejarEscritura();
		kill(pid, SIGINT);

	}

	return 0;
}
