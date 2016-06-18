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

bool ManejadorDeMensajes::validarNombreEnUso(string nombre) {
	for (unsigned int i = 0 ; i < this->usuarios.size(); i++)
		if (usuarios.at(i).getNombre() == nombre) return true;
	return false;
}

void ManejadorDeMensajes::enviarNombreEnUso(int id, string nombre){
	mensaje m;
	m.status = STATUS_ERROR;
	m.mtype = id;
	m.tipoMensaje = TIPO_SELECCION_NOMBRE;
	string txt = "Nombre de usuario " + nombre + " en uso";
	strcpy(m.texto, txt.c_str());
	colaDeMensajes.escribir(m);
}

void ManejadorDeMensajes::agregarUsuarioActivo(int id, string nombre) {
	for (unsigned int i = 0 ; i < this->usuarios.size(); i++){
		if (usuarios.at(i).getId() == id){
			usuarios.at(i).setActivo(true);
			usuarios.at(i).setNombre(nombre);
			return;
		}
	}
}

string ManejadorDeMensajes::getNombreDeUsuario(int id) {
	for (unsigned int i = 0 ; i < this->usuarios.size(); i++){
		if (usuarios.at(i).getId() == id){
			return usuarios[i].getNombre();
		}
	}
	return "";
}

void ManejadorDeMensajes::procesarMensaje(mensaje m) {
	if (m.tipoMensaje == TIPO_NUEVA_CONEXION){
		agregarConexionDeUsuario(atoi(m.texto));
	} else if (m.tipoMensaje == TIPO_SELECCION_NOMBRE) {
		bool nombreEnUso = validarNombreEnUso(m.texto);
		if (nombreEnUso) {
			enviarNombreEnUso(m.userId, m.texto);
		} else {
			agregarUsuarioActivo(m.userId, m.texto);
		}
	} else if (m.tipoMensaje == TIPO_CHAT){
		enviarMensajeAUsuarios(m.userId, getNombreDeUsuario(m.userId), m.texto);
	}

}

void ManejadorDeMensajes::enviarMensajeAUsuarios(int autorId, string autorNombre, string msg) {
	string msgCompleto = autorNombre + ": " + msg;
	for (unsigned int i = 0 ; i < this->usuarios.size(); i++){
		if (usuarios[i].getId() != autorId){
			enviarMensaje(usuarios[i].getId(), msgCompleto);
		}

	}
}

void ManejadorDeMensajes::enviarMensaje(int idDestino, string msg){
	mensaje men;
	men.status = STATUS_OK;
	men.mtype = idDestino;
	men.tipoMensaje = TIPO_CHAT;
	strcpy(men.texto, msg.c_str());
	colaDeMensajes.escribir(men);
}

ManejadorDeMensajes::~ManejadorDeMensajes() {
}

