/*
 * ManejadorDelCliente.cpp
 *
 *  Created on: 17 de jun. de 2016
 *      Author: kevin
 */

#include "ManejadorDelCliente.h"

#include <iostream>
#include <cstring>

#define ARCHIVO_LOCK "lock"

ManejadorDelCliente::ManejadorDelCliente(const string archivo) : ManejadorDeColaDeMensajes(archivo), usuario(NULL), lock(ARCHIVO_LOCK) {

}

void ManejadorDelCliente::procesarMensaje(mensaje m) {
	cout << m.texto << endl;
}

void ManejadorDelCliente::conectar(string colaConexion) {
	Cola<mensaje> colaDeConexiones(colaConexion, 'a');

	mensaje mensajeConexion;
	mensajeConexion.mtype = MENSAJE_A_SERVIDOR;
	mensajeConexion.userId = USUARIO_NO_REGISTRADO;
	string texto = "conexion";
	strcpy(mensajeConexion.texto, texto.c_str());
	mensaje respuesta;

	lock.tomarLock(0);
	colaDeConexiones.escribir(mensajeConexion);
	colaDeConexiones.leer(REGISTRAR_USUARIO, &respuesta);
	lock.liberarLock(0);
	this->tipoALeer = atoi(respuesta.texto);
	this->usuario = new Usuario(atoi(respuesta.texto));
}

void ManejadorDelCliente::login() {

	mensaje mensajeLogin;
	mensajeLogin.mtype = MENSAJE_A_SERVIDOR;
	mensajeLogin.tipoMensaje = TIPO_SELECCION_NOMBRE;
	mensajeLogin.userId = usuario->getId();
	mensaje respuesta;

	bool nombreExistente = true;
	while(nombreExistente) {
		cout << "Ingrese nombre de usuario: ";
		cin.getline(mensajeLogin.texto, sizeof(mensajeLogin.texto));
		lock.tomarLock(1);
		colaDeMensajes.escribir(mensajeLogin);
		colaDeMensajes.leer(tipoALeer, &respuesta);
		lock.liberarLock(1);
		if(respuesta.status == STATUS_ERROR) {
			cout << respuesta.texto << endl; // Mensaje de error
		} else {
			cout << respuesta.texto << endl; // Mensaje de bienvenida
			this->usuario->setNombre(mensajeLogin.texto);
			nombreExistente = false;
		}
	}
}

void ManejadorDelCliente::manejarEscritura() {
	mensaje m;
	bool enChat = true;
	m.mtype = MENSAJE_A_SERVIDOR;
	m.tipoMensaje = TIPO_CHAT;
	m.userId = usuario->getId();
	while (enChat) {
		cin.getline(m.texto, sizeof(m.texto));
		if ( strcmp(m.texto,"exit") == 0) {
			enChat = false;
			m.tipoMensaje = TIPO_SALIR;
		}
		colaDeMensajes.escribir(m);

	}

}

ManejadorDelCliente::~ManejadorDelCliente() {
	delete usuario;
}

