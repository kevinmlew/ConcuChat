//============================================================================
// Name        : ConcuChat.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <iostream>

#include "model/ManejadorDeConexiones.h"
#include "model/ManejadorDeMensajes.h"

using namespace std;

int main() {
	cout << "!!!Hello Server!!!" << endl;

	ManejadorDeConexiones manejadorDeConexiones;
	manejadorDeConexiones.run();

	/**pid_t pidMensajes = fork();
	if (pidMensajes == 0){
		//hijo Mensajes
		ManejadorDeMensajes manejadorDeMensajes;
		//manejadorDeMensajes.run();
		return 0;
	} else {
		pid_t pidConexiones = fork();
		if (pidConexiones == 0){
			//hijo conexiones
			ManejadorDeConexiones manejadorDeConexiones;
			manejadorDeConexiones.run();
			return 0;
		} else {
			//padre

		}
	}
	int status;
	wait(&status);
	wait(&status);*/


























	return 0;
}
