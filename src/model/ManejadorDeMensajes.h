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

#include "ManejadorDeColaDeMensajes.h"
#include "Usuario.h"

class Historial;

using namespace std;

class ManejadorDeMensajes : public ManejadorDeColaDeMensajes {
	vector<Usuario> usuarios;
	Historial* historial;
	void procesarMensaje(mensaje m);
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

public:
	ManejadorDeMensajes(const string archivo, Historial* historial);
	void notificarNuevaConexion(int id);
	virtual ~ManejadorDeMensajes();
};

#endif /* MODEL_MANEJADORDEMENSAJES_H_ */
