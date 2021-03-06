/*
 * ManejadorDeMensajes.h
 *
 *  Created on: 5 de jun. de 2016
 *      Author: kevin
 */

#ifndef MODEL_MANEJADORDEMENSAJES_H_
#define MODEL_MANEJADORDEMENSAJES_H_

#include <string>
#include <vector>

#include "../ipc/LockFile.h"
#include "ManejadorDeColaDeMensajes.h"
#include "Usuario.h"

class Historial;

using namespace std;

class ManejadorDeMensajes : public ManejadorDeColaDeMensajes {
	vector<Usuario> usuarios;
	Historial* historial;
	LockFile lockMensajes;
	void procesarMensaje(mensaje m, string contenidoCompleto);
	void agregarConexionDeUsuario(int id);
	bool validarNombreEnUso(string nombre);
	void enviarNombreEnUso(int id, string nombre);
	void enviarNombreDisponible(int id);
	void agregarUsuarioActivo(int id, string nombre);
	string getNombreDeUsuario(int id);
	void enviarMensajeAUsuarios(int autorId, string msg);
	void enviarMensaje(int idAutor, string msg);
	void guardarMensajeEnHistorial(string msg);
	void enviarHistorial(int id);
	void eliminarUsuario(int userId);
	int getIndiceDeUsuario(int userId);
	void enviarParteMensaje(mensaje msg, string parte);
	void broadcastMensaje(string msg);

public:
	ManejadorDeMensajes(const string archivo, Historial* historial, const string archivoLockMensajes);
	void notificarNuevaConexion(int id);
	virtual ~ManejadorDeMensajes();
};

#endif /* MODEL_MANEJADORDEMENSAJES_H_ */
