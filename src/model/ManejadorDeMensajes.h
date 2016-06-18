/*
 * ManejadorDeMensajes.h
 *
 *  Created on: 5 de jun. de 2016
 *      Author: kevin
 */

#ifndef MODEL_MANEJADORDEMENSAJES_H_
#define MODEL_MANEJADORDEMENSAJES_H_

#include <string>

#include "ManejadorDeColaDeMensajes.h"
#include "Usuario.h"

#include <vector>

using namespace std;

class ManejadorDeMensajes : public ManejadorDeColaDeMensajes {
	vector<Usuario> usuarios;
	void procesarMensaje(mensaje m);
	void agregarConexionDeUsuario(int id);
	bool validarNombreEnUso(string nombre);
	void enviarNombreEnUso(int id, string nombre);
	void agregarUsuarioActivo(int id, string nombre);
	string getNombreDeUsuario(int id);
	void enviarMensajeAUsuarios(int autorId, string msg);
	void enviarMensaje(int idAutor, string msg);
	void guardarMensajeEnHistorial(string msg);

public:
	ManejadorDeMensajes(const string archivo);
	void notificarNuevaConexion(int id);
	virtual ~ManejadorDeMensajes();
};

#endif /* MODEL_MANEJADORDEMENSAJES_H_ */
