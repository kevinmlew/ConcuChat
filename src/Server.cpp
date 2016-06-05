//============================================================================
// Name        : ConcuChat.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <unistd.h>
#include <stdlib.h>
#include <iostream>

#include "model/ManejadorDeConexiones.h"
#include "model/ManejadorDeMensajes.h"

using namespace std;

int main() {
	cout << "!!!Hello Server!!!" << endl;

	pid_t pidMensajes = fork();
	if (pidMensajes == 0){
		//hijo Mensajes
		ManejadorDeMensajes manejadorDeMensajes;
		return 0;
	} else {
		pid_t pidConexiones = fork();
		if (pidConexiones == 0){
			//hijo conexiones
			ManejadorDeConexiones manejadorDeConexiones;
			return 0;
		} else {
			//padre

		}
	}


























	return 0;
}
