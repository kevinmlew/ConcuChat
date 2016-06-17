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
#include "Mensaje.h"
#include "Usuario.h"

#include <string>

using namespace std;

class ManejadorDelCliente : public ManejadorDeColaDeMensajes{
private:
	Usuario* usuario;
	void procesarMensaje(mensaje m);
public:
	ManejadorDelCliente(const string archivo);
	void run();
	void conectar(string colaConexion);
	void login();
	virtual ~ManejadorDelCliente();
};

#endif /* MODEL_MANEJADORDELCLIENTE_H_ */
