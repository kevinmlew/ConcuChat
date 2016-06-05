/*
 * ManejadorDeConexiones.cpp
 *
 *  Created on: 5 de jun. de 2016
 *      Author: kevin
 */

#include "ManejadorDeConexiones.h"

#include "Conexion.h"

#define ARCHIVO_COLA "colaDeConexiones"

ManejadorDeConexiones::ManejadorDeConexiones(): colaDeConexiones(ARCHIVO_COLA, 'a') {

}

void ManejadorDeConexiones::run() {
	int idClientes = 0;
	Conexion buffer;
	while(gracefulQuit) {
		idClientes++;
		colaDeConexiones.leer(1, &buffer);


	}
}
ManejadorDeConexiones::~ManejadorDeConexiones() {
	// TODO Auto-generated destructor stub
}

