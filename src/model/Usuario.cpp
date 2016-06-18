/*
 * Usuario.cpp
 *
 *  Created on: 5 de jun. de 2016
 *      Author: kevin
 */

#include "Usuario.h"

Usuario::Usuario(int id) : id(id), activo(false) {

}

void Usuario::setActivo(bool activo) {
	this->activo = activo;
}

void Usuario::setNombre(string nombre){
	this->nombre = nombre;
}

string Usuario::getNombre(){
	return nombre;
}

int Usuario::getId(){
	return id;
}

bool Usuario::isActivo() {
	return activo;
}

Usuario::~Usuario() {
	// TODO Auto-generated destructor stub
}

