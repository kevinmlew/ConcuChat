/*
 * ManejadorDelCliente.h
 *
 *  Created on: 17 de jun. de 2016
 *      Author: kevin
 */

#ifndef MODEL_MANEJADORDELCLIENTE_H_
#define MODEL_MANEJADORDELCLIENTE_H_

#include "ManejadorDeColaDeMensajes.h"
#include "../ipc/Cola.h"
#include "../ipc/LockFile.h"
#include "Mensaje.h"
#include "Usuario.h"

#include <string>

using namespace std;

class ManejadorDelCliente : public ManejadorDeColaDeMensajes{
private:
	Usuario* usuario;
	LockFile lock;
	LockFile lockMensajes;
	void procesarMensaje(mensaje m, string contenidoCompleto);
public:
	ManejadorDelCliente(const string archivo, const string archivoLockMensajes);
	void manejarEscritura();
	void conectar(string colaConexion);
	void login();
	virtual ~ManejadorDelCliente();
};

#endif /* MODEL_MANEJADORDELCLIENTE_H_ */
