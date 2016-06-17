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

ManejadorDeConexiones::ManejadorDeConexiones(const string archivoConexiones, ManejadorDeMensajes* manejador) :
		ManejadorDeColaDeMensajes(archivoConexiones){
	manejadorDeMensajes = manejador;
}

void ManejadorDeConexiones::enviarIdAlUsuario(){
	mensaje men;
	men.tipoMensaje = TIPO_ASIGNACION_ID;
	strcpy(men.texto, std::to_string(cantidadDeUsuarios).c_str());
	colaDeMensajes.escribir(men);
}

void ManejadorDeConexiones::enviarNuevaConexionAlManejadorDeMensajes(){
	manejadorDeMensajes->notificarNuevaConexion(cantidadDeUsuarios);
}


void ManejadorDeConexiones::procesarMensaje(mensaje m) {
	cantidadDeUsuarios++;
	enviarNuevaConexionAlManejadorDeMensajes();
	enviarIdAlUsuario();
}

ManejadorDeConexiones::~ManejadorDeConexiones() {
}

