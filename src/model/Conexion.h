/*
 * Conexion.h
 *
 *  Created on: 5 de jun. de 2016
 *      Author: kevin
 */

#ifndef MODEL_CONEXION_H_
#define MODEL_CONEXION_H_

#include <string>

using namespace std;

class Conexion {
private:
	string nombre;
public:
	Conexion();
	string getNombre();
	virtual ~Conexion();
};

#endif /* MODEL_CONEXION_H_ */
