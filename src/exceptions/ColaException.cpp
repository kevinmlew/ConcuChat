/*
 * ColaException.cpp
 *
 *  Created on: Jun 19, 2016
 *      Author: juan
 */

#include "ColaException.h"

string ColaException::TYPE_LEER = "Error al leer de la cola";
string ColaException::TYPE_ESCRIBIR = "Error al escribir en la cola";
string ColaException::TYPE_DESTRUIR= "Error al destruir la cola";

ColaException::ColaException(string msg, int code) : IPCException(msg, code) {

}

ColaException::~ColaException() {
}

