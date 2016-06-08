//============================================================================
// Name        : ConcuChat.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

#include "ipc/Cola.h"
#include "model/Conexion.h"

using namespace std;

int main() {
	// Test cola de conexiones
    Cola<conexion> colaDeConexiones("colaDeConexiones", 'a');

	conexion msj1;
	conexion msj2;

	msj1.mtype = 1;
	msj1.nombre = "test";
	cout << "escribe: " << msj1.nombre << endl;
	colaDeConexiones.escribir(msj1);

	colaDeConexiones.leer(1,&msj2);
	cout << "lee " << msj2.nombre << endl;
	colaDeConexiones.destruir();

	return 0;
}
