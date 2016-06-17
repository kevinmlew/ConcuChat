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

void ManejadorDelCliente::procesarMensaje(mensaje m) {}

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
	this->usuario = new Usuario(respuesta.userId);
}

void ManejadorDelCliente::login() {

	mensaje mensajeLogin;
	mensajeLogin.mtype = MENSAJE_A_SERVIDOR;
	mensajeLogin.userId = USUARIO_NO_REGISTRADO;
	mensaje respuesta;
	string nombre;

	bool nombreExistente = true;
	while(nombreExistente) {
		cout << "Ingrese nombre de usuario: ";
		cin >> nombre;
		strcpy(mensajeLogin.texto, nombre.c_str());
		//TODO Tomar lock2
		colaDeMensajes.escribir(mensajeLogin);
		colaDeMensajes.leer(REGISTRAR_USUARIO, &respuesta);
		//TODO Liberar lock2
		if(respuesta.status == STATUS_OK) {
			cout << respuesta.texto << endl; // Mensaje de bienvenida
			this->usuario->setNombre(nombre);
			nombreExistente = false;
		} else {
			cout << "Ya existe usuario con ese nombre" << endl;
		}
	}
}

ManejadorDelCliente::~ManejadorDelCliente() {
	// TODO Auto-generated destructor stub
}

