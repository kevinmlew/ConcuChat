/*
 * ManejadorDeConexiones.h
 *
 *  Created on: Jun 17, 2016
 *      Author: juan
 */

#ifndef MODEL_MANEJADORDECONEXIONES_H_
#define MODEL_MANEJADORDECONEXIONES_H_

#include <string>

#include "ManejadorDeColaDeMensajes.h"
#include "ManejadorDeMensajes.h"

using namespace std;

class ManejadorDeConexiones : public ManejadorDeColaDeMensajes {
	static int cantidadDeUsuarios;

	ManejadorDeMensajes* manejadorDeMensajes;

	void procesarMensaje(mensaje m);
	void enviarIdAlUsuario();
	void enviarNuevaConexionAlManejadorDeMensajes();
public:
	ManejadorDeConexiones(const string archivoConex, ManejadorDeMensajes* manejador);
	virtual ~ManejadorDeConexiones();
};

#endif /* MODEL_MANEJADORDECONEXIONES_H_ */
