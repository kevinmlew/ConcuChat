/*
 * ManejadorDeConexiones.cpp
 *
 *  Created on: Jun 17, 2016
 *      Author: juan
 */

#include "ManejadorDeConexiones.h"

#include <cstring>

#include "../log/Logger.h"
#include "Mensaje.h"

int ManejadorDeConexiones::cantidadDeUsuarios = 1; //Tiene que empezar en 1 porque el server es un usuario

#define ARCHIVO_LOCK "lock"

ManejadorDeConexiones::ManejadorDeConexiones(const string archivoConexiones, ManejadorDeMensajes* manejador) :
		ManejadorDeColaDeMensajes(archivoConexiones){
	manejadorDeMensajes = manejador;
}

void ManejadorDeConexiones::enviarIdAlUsuario(){
	mensaje men;
	men.mtype = REGISTRAR_USUARIO;
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
	Logger::insert(Logger::TYPE_INFO, "Se conecto un nuevo usuario, se le asigna el ID: " + cantidadDeUsuarios);
}

ManejadorDeConexiones::~ManejadorDeConexiones() {
	LockFile lock(ARCHIVO_LOCK);
	lock.destruirArchivoLock();
}

