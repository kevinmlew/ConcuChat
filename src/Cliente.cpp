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
	}

	// Test cola de conexiones
    /**Cola<mensaje> colaDeMensajes("colaDeMensajes", 'a');

	mensaje msj1;
	msj1.mtype = MENSAJE_A_SERVIDOR;
	msj1.userId = USUARIO_NO_REGISTRADO;
	string nombre = "test";
	strcpy(msj1.texto, nombre.c_str());
	cout << "Ingresa usuario: " << msj1.texto << endl;
	colaDeMensajes.escribir(msj1);

	mensaje respuesta;
	colaDeMensajes.leer(REGISTRAR_USUARIO,&respuesta);
	cout << "UserId: " << respuesta.userId << ". Resp: " << respuesta.texto << endl;

	string texto;
	cout << ">";
	cin >> texto;

	mensaje msj2;
	msj2.mtype = MENSAJE_A_SERVIDOR;
	msj2.userId = respuesta.userId;
	strcpy(msj2.texto, texto.c_str());
	colaDeMensajes.escribir(msj2);*/

	return 0;
}
