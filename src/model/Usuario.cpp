/*
 * Usuario.cpp
 *
 *  Created on: 5 de jun. de 2016
 *      Author: kevin
 */

#include "Usuario.h"

Usuario::Usuario(int id, string nombre) : id(id), nombre(nombre), activo(true) {

}

void Usuario::setActivo(bool activo) {
	this->activo = activo;
}

bool Usuario::isActivo() {
	return activo;
}

Usuario::~Usuario() {
	// TODO Auto-generated destructor stub
}

