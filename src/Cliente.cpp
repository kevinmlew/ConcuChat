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

using namespace std;

int main() {
	// Test cola de conexiones
    Cola<mensaje> colaDeConexiones("colaDeConexiones", 'a');

	mensaje msj1;
	msj1.mtype = 1;
	string nombre = "test";
	strcpy(msj1.texto, nombre.c_str());
	cout << "escribe: " << msj1.texto << endl;
	colaDeConexiones.escribir(msj1);

	return 0;
}
