/*
 * MemoriaCompartidaException.h
 *
 *  Created on: May 11, 2016
 *      Author: juan
 */

#ifndef MEMORIACOMPARTIDAEXCEPTION_H_
#define MEMORIACOMPARTIDAEXCEPTION_H_

#include <string>

#include "IPCException.h"

using namespace std;

class MemoriaCompartidaException : public IPCException {
public:
	MemoriaCompartidaException(string msg, int code);
	virtual ~MemoriaCompartidaException();
	static string TYPE_FTOK;
	static string TYPE_SHMGET;
	static string TYPE_SHMAT;
	static string TYPE_SHMDT;
	static string TYPE_SHMCTL;

};

#endif
