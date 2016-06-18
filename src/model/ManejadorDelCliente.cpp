/*
 * ManejadorDelCliente.cpp
 *
 *  Created on: 17 de jun. de 2016
 *      Author: kevin
 */

#include "ManejadorDelCliente.h"

#include <iostream>
#include <cstring>


ManejadorDelCliente::ManejadorDelCliente(const string archivo) : ManejadorDeColaDeMensajes(archivo), usuario(NULL){
	// TODO Auto-generated constructor stub

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

	//TODO Tomar lock1
	colaDeConexiones.escribir(mensajeConexion);
	colaDeConexiones.leer(REGISTRAR_USUARIO, &respuesta);
	//TODO Liberar lock1
	this->tipoALeer = atoi(respuesta.texto);
	this->usuario = new Usuario(atoi(respuesta.texto));
}

void ManejadorDelCliente::login() {

	mensaje mensajeLogin;
	mensajeLogin.mtype = MENSAJE_A_SERVIDOR;
	mensajeLogin.tipoMensaje = TIPO_SELECCION_NOMBRE;
	mensajeLogin.userId = usuario->getId();
	mensaje respuesta;
	string nombre;

	bool nombreExistente = true;
	while(nombreExistente) {
		cout << "Ingrese nombre de usuario: ";
		cin >> nombre;
		strcpy(mensajeLogin.texto, nombre.c_str());
		//TODO Tomar lock2
		colaDeMensajes.escribir(mensajeLogin);
		colaDeMensajes.leer(tipoALeer, &respuesta);
		//TODO Liberar lock2
		if(respuesta.status == STATUS_ERROR) {
			cout << respuesta.texto << endl; // Mensaje de error
		} else {
			cout << respuesta.texto << endl; // Historial
			this->usuario->setNombre(nombre);
			nombreExistente = false;
		}
	}
}

void ManejadorDelCliente::manejarEscritura() {
	mensaje m;
	string entrada;
	bool enChat = true;
	m.mtype = MENSAJE_A_SERVIDOR;
	m.tipoMensaje = TIPO_CHAT;
	m.userId = usuario->getId();
	while (enChat) {
		cin >> entrada;
		if ( entrada == "exit") {
			enChat = false;
			m.tipoMensaje = TIPO_SALIR;
		}
		strcpy(m.texto, entrada.c_str());
		colaDeMensajes.escribir(m);

	}

}

ManejadorDelCliente::~ManejadorDelCliente() {
	// TODO Auto-generated destructor stub
}

