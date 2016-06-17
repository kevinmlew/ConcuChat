/*
 * ManejadorDeMensajes.cpp
 *
 *  Created on: 5 de jun. de 2016
 *      Author: kevin
 */

#include "ManejadorDeMensajes.h"

#include <cstdlib>
#include <cstring>

#include "Mensaje.h"

ManejadorDeMensajes::ManejadorDeMensajes(const string archivo) : ManejadorDeColaDeMensajes(archivo) {

}

void ManejadorDeMensajes::notificarNuevaConexion(int id) {
	mensaje men;
	men.mtype = MENSAJE_A_SERVIDOR;
	men.tipoMensaje = TIPO_NUEVA_CONEXION;
	strcpy(men.texto, std::to_string(id).c_str());
	colaDeMensajes.escribir(men);
}

void ManejadorDeMensajes::agregarConexionDeUsuario(int id) {
	Usuario user(id);
	usuarios.push_back(user);
}

void ManejadorDeMensajes::procesarMensaje(mensaje m) {
//	int idCliente = PRIMER_USUARIO;
//	if (m.userId == USUARIO_NO_REGISTRADO){
//		// Se conecto un usuario nuevo
//		cout << "Ingreso usuario: " << m.texto << endl;
//		mensaje respuesta;
//		respuesta.mtype = REGISTRAR_USUARIO;
//		respuesta.userId = idCliente;
//		string rs = "OK";
//		strcpy(respuesta.texto, rs.c_str());
//		colaDeMensajes.escribir(respuesta);
//		// Mandar historial
//		idCliente++;
//		//continue;
//	}
//	cout << "UserId: " << m.userId << ". Mensaje: " << m.texto << endl;

	if (m.tipoMensaje == TIPO_NUEVA_CONEXION){
		agregarConexionDeUsuario(atoi(m.texto));
	}

}

ManejadorDeMensajes::~ManejadorDeMensajes() {
}

