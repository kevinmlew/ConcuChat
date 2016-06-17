/*
 * ManejadorDeMensajes.cpp
 *
 *  Created on: 5 de jun. de 2016
 *      Author: kevin
 */

#include "ManejadorDeMensajes.h"

#include <cstring>
#include <iostream>
#include <string>

ManejadorDeMensajes::ManejadorDeMensajes(const string archivo) : ManejadorDeColaDeMensajes(archivo) {

}

void ManejadorDeMensajes::procesarMensaje(mensaje m) {
	int idCliente = PRIMER_USUARIO;
	if (m.userId == USUARIO_NO_REGISTRADO){
		// Se conecto un usuario nuevo
		cout << "Ingreso usuario: " << m.texto << endl;
		mensaje respuesta;
		respuesta.mtype = REGISTRAR_USUARIO;
		respuesta.userId = idCliente;
		string rs = "OK";
		strcpy(respuesta.texto, rs.c_str());
		colaDeMensajes.escribir(respuesta);
		// Mandar historial
		idCliente++;
		//continue;
	}
	cout << "UserId: " << m.userId << ". Mensaje: " << m.texto << endl;
}

ManejadorDeMensajes::~ManejadorDeMensajes() {
}

