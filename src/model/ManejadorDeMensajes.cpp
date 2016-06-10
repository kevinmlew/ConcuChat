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

#define ARCHIVO_COLA_MENSAJES "colaDeMensajes"

ManejadorDeMensajes::ManejadorDeMensajes(): colaDeMensajes(ARCHIVO_COLA_MENSAJES, 'a'), gracefulQuit(true) {
	// TODO Auto-generated constructor stub

}

void ManejadorDeMensajes::run() {
	int idCliente = PRIMER_USUARIO;
	mensaje m;
	while(gracefulQuit) {
		colaDeMensajes.leer(MENSAJE_A_SERVIDOR, &m);
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
			continue;
		}
		cout << "UserId: " << m.userId << ". Mensaje: " << m.texto << endl;



	}
}

ManejadorDeMensajes::~ManejadorDeMensajes() {
	// TODO Auto-generated destructor stub
}

