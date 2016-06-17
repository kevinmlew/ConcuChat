/*
 * ManejadorDeConexiones.h
 *
 *  Created on: Jun 17, 2016
 *      Author: juan
 */

#ifndef MODEL_MANEJADORDECONEXIONES_H_
#define MODEL_MANEJADORDECONEXIONES_H_

#include "ManejadorDeColaDeMensajes.h"
using namespace std;

class ManejadorDeConexiones : public ManejadorDeColaDeMensajes {
	static int cantidadDeUsuarios;
	void procesarMensaje(mensaje m);
public:
	ManejadorDeConexiones(const string archivo);
	virtual ~ManejadorDeConexiones();
};

#endif /* MODEL_MANEJADORDECONEXIONES_H_ */
