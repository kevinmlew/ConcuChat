/*
 * ManejadorDeConexiones.cpp
 *
 *  Created on: Jun 17, 2016
 *      Author: juan
 */

#include "ManejadorDeConexiones.h"

#include <cstring>
#include <string>

#include "Mensaje.h"

int ManejadorDeConexiones::cantidadDeUsuarios = 0;

ManejadorDeConexiones::ManejadorDeConexiones(const string archivo) : ManejadorDeColaDeMensajes(archivo){

}

void ManejadorDeConexiones::procesarMensaje(mensaje m) {
	cantidadDeUsuarios++;
	mensaje men;
	strcpy(men.texto, std::to_string(cantidadDeUsuarios).c_str());
	colaDeMensajes.escribir(men);
}

ManejadorDeConexiones::~ManejadorDeConexiones() {
}

