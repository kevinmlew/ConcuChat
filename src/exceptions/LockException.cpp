/*
 * LockException.cpp
 *
 *  Created on: 11 de may. de 2016
 *      Author: kevin
 */

#include "LockException.h"

string LockException::TYPE_CREAR = "Error al crear lock";
string LockException::TYPE_TOMAR = "Error al tomar lock";
string LockException::TYPE_LIBERAR= "Error al liberar lock";

LockException::LockException(string msg, int code) : IPCException(msg, code) {
	// TODO Auto-generated constructor stub

}

LockException::~LockException() {
	// TODO Auto-generated destructor stub
}

