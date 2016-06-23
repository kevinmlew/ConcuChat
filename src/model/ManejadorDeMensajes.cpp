/*
 * ManejadorDeMensajes.cpp
 *
 *  Created on: 5 de jun. de 2016
 *      Author: kevin
 */

#include "ManejadorDeMensajes.h"

#include <cstdlib>
#include <cstring>
#include <iterator>

#include "../log/Logger.h"
#include "Historial.h"
#include "Mensaje.h"

ManejadorDeMensajes::ManejadorDeMensajes(const string archivo, Historial* historial, const string archivoLockMensajes)
: ManejadorDeColaDeMensajes(archivo), lockMensajes(archivoLockMensajes) {
	this->historial = historial;
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
	Logger::insert(Logger::TYPE_INFO, "Se conecto un nuevo usuario con ID: " + to_string(id));
}

bool ManejadorDeMensajes::validarNombreEnUso(string nombre) {
	for (unsigned int i = 0 ; i < this->usuarios.size(); i++)
		if (usuarios.at(i).isActivo() && usuarios.at(i).getNombre() == nombre) return true;
	return false;
}

void ManejadorDeMensajes::enviarNombreEnUso(int id, string nombre){
	Logger::insert(Logger::TYPE_INFO, "Se conecto un nuevo usuario con username: " + nombre +
			" pero ya se encuentra en uso");
	mensaje m;
	m.status = STATUS_ERROR;
	m.mtype = id;
	m.tipoMensaje = TIPO_SELECCION_NOMBRE;
	string txt = "Nombre de usuario " + nombre + " en uso";
	strcpy(m.texto, txt.c_str());
	colaDeMensajes.escribir(m);
}

void ManejadorDeMensajes::enviarNombreDisponible(int id){
	mensaje m;
	m.status = STATUS_OK;
	m.mtype = id;
	m.tipoMensaje = TIPO_SELECCION_NOMBRE;
	string txt = "Bienvenido!";
	strcpy(m.texto, txt.c_str());
	colaDeMensajes.escribir(m);
}

void ManejadorDeMensajes::agregarUsuarioActivo(int id, string nombre) {
	Logger::insert(Logger::TYPE_INFO, "Se conecto un nuevo usuario con nombre: " + nombre);
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

void ManejadorDeMensajes::procesarMensaje(mensaje m, string contenidoCompleto) {
	if (m.tipoMensaje == TIPO_NUEVA_CONEXION){
		agregarConexionDeUsuario(atoi(m.texto));
	} else if (m.tipoMensaje == TIPO_SELECCION_NOMBRE) {
		bool nombreEnUso = validarNombreEnUso(contenidoCompleto);
		if (nombreEnUso) {
			enviarNombreEnUso(m.userId, contenidoCompleto);
		} else {
			agregarUsuarioActivo(m.userId, contenidoCompleto);
			broadcastMensaje("--SERVER--: " + contenidoCompleto + " se acaba de loguear.");
			enviarNombreDisponible(m.userId);
			enviarHistorial(m.userId);
		}
	} else if (m.tipoMensaje == TIPO_CHAT){
		string msgCompleto =  getNombreDeUsuario(m.userId) + ": " + contenidoCompleto;
		guardarMensajeEnHistorial(msgCompleto);
		enviarMensajeAUsuarios(m.userId, msgCompleto);
	} else if (m.tipoMensaje == TIPO_SALIR) {
		eliminarUsuario(m.userId);
		broadcastMensaje("--SERVER--: " + getNombreDeUsuario(m.userId) + " se acaba de desloguear.");
	}

}

void ManejadorDeMensajes::eliminarUsuario(int userId){
	Logger::insert(Logger::TYPE_INFO, "Se desconecto un usuario con ID: " + to_string(userId));
	usuarios[getIndiceDeUsuario(userId)].setActivo(false);
}

int ManejadorDeMensajes::getIndiceDeUsuario(int userId){
	for (unsigned int i = 0; i < usuarios.size(); i++){
		if (userId == usuarios[i].getId()) return i;
	}
	return -1;
}

void ManejadorDeMensajes::guardarMensajeEnHistorial(string mensajeCompleto){
	this->historial->guardarMensaje(mensajeCompleto);
}

void ManejadorDeMensajes::enviarHistorial(int userId){
	string historial = this->historial->getHistorial();
	mensaje m;
	m.status = STATUS_OK;
	m.mtype = userId;
	m.tipoMensaje = TIPO_HISTORIAL;
	enviarParteMensajeConLock(m, historial, &lockMensajes);
}

void ManejadorDeMensajes::enviarMensajeAUsuarios(int autorId, string msgCompleto) {
	for (unsigned int i = 0 ; i < this->usuarios.size(); i++){
		if (usuarios[i].isActivo() && usuarios[i].getId() != autorId){
			enviarMensaje(usuarios[i].getId(), msgCompleto);
		}
	}
}

void ManejadorDeMensajes::broadcastMensaje(string msg){
	for (unsigned int i = 0 ; i < this->usuarios.size(); i++){
		if (usuarios[i].isActivo())
			enviarMensaje(usuarios[i].getId(), msg);
	}
}

void ManejadorDeMensajes::enviarMensaje(int idDestino, string msg){
	mensaje men;
	men.status = STATUS_OK;
	men.mtype = idDestino;
	men.tipoMensaje = TIPO_CHAT;
	enviarParteMensajeConLock(men, msg, &lockMensajes);
}

ManejadorDeMensajes::~ManejadorDeMensajes() {
	lockMensajes.destruirArchivoLock();
}

