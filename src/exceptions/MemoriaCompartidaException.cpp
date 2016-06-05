/*
 * MemoriaCompartidaException.cpp
 *
 *  Created on: May 11, 2016
 *      Author: juan
 */

#include "MemoriaCompartidaException.h"
using namespace std;

string MemoriaCompartidaException::TYPE_FTOK = "Error al crear memoria compartida - FTOK";
string MemoriaCompartidaException::TYPE_SHMGET = "Error al crear memoria compartida - SHMGET";
string MemoriaCompartidaException::TYPE_SHMAT = "Error al crear memoria compartida - SHMAT";
string MemoriaCompartidaException::TYPE_SHMDT = "Error al eliminar memoria compartida - SHMDT";
string MemoriaCompartidaException::TYPE_SHMCTL= "Error al liberar la memoria compartida - SHMCTL";

MemoriaCompartidaException::MemoriaCompartidaException(string msg, int code) : IPCException(msg, code){

}

MemoriaCompartidaException::~MemoriaCompartidaException() {
}

