/*
 * MemoriaCompartidaException.cpp
 *
 *  Created on: May 11, 2016
 *      Author: juan
 */

#include "IPCException.h"

using namespace std;

IPCException::IPCException(string msg, int code) : runtime_error(msg), code(code){

}

int IPCException::getCode(){
	return code;
}

IPCException::~IPCException() {
}

