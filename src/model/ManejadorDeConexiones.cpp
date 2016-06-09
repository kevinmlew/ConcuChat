/*
 * ManejadorDeConexiones.cpp
 *
 *  Created on: 5 de jun. de 2016
 *      Author: kevin
 */

#include "ManejadorDeConexiones.h"

#include <iostream>

#include "Mensaje.h"
#include "Usuario.h"

#define ARCHIVO_COLA_CONEXIONES "colaDeConexiones"

ManejadorDeConexiones::ManejadorDeConexiones(): colaDeConexiones(ARCHIVO_COLA_CONEXIONES, 'a'), gracefulQuit(true) {

}

void ManejadorDeConexiones::run() {
	int idCliente = 0;
	mensaje m;
	while(gracefulQuit) {
		idCliente++;
		colaDeConexiones.leer(1, &m);
		cout << "Ingreso usuario:" << m.texto << endl;
		// Pasar usuario al otro proceso


	}
}

ManejadorDeConexiones::~ManejadorDeConexiones() {
	// TODO Auto-generated destructor stub
}

