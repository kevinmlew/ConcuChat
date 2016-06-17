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
using namespace std;

class ManejadorDeMensajes : public ManejadorDeColaDeMensajes {
	void procesarMensaje(mensaje m);
public:
	ManejadorDeMensajes(const string archivo);
	void notificarNuevaConexion(int id);
	virtual ~ManejadorDeMensajes();
};

#endif /* MODEL_MANEJADORDEMENSAJES_H_ */
