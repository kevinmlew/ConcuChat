/*
 * ManejadorDeConexiones.cpp
 *
 *  Created on: 5 de jun. de 2016
 *      Author: kevin
 */

#include "ManejadorDeConexiones.h"

#include <iostream>

#include "Conexion.h"
#include "Usuario.h"

#define ARCHIVO_COLA_CONEXIONES "colaDeConexiones"

ManejadorDeConexiones::ManejadorDeConexiones(): colaDeConexiones(ARCHIVO_COLA_CONEXIONES, 'a'), gracefulQuit(true) {

}

void ManejadorDeConexiones::run() {
	int idCliente = 0;
	conexion c;
	while(gracefulQuit) {
		idCliente++;
		cout << "Cola de conexiones" << endl;
		colaDeConexiones.leer(1, &c);
		cout << "Ingreso usuario:" << c.nombre << endl;
		// Pasar usuario al otro proceso


	}
}

ManejadorDeConexiones::~ManejadorDeConexiones() {
	// TODO Auto-generated destructor stub
}

