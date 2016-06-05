/*
 * LockException.h
 *
 *  Created on: 11 de may. de 2016
 *      Author: kevin
 */

#ifndef EXCEPTIONS_LOCKEXCEPTION_H_
#define EXCEPTIONS_LOCKEXCEPTION_H_

#include "IPCException.h"
#include <string>

using namespace std;

class LockException : public IPCException {
public:
	LockException(string msg, int code);
	virtual ~LockException();
	static string TYPE_CREAR;
	static string TYPE_TOMAR;
	static string TYPE_LIBERAR;
	static string TYPE_ESCRIBIR;
};

#endif /* EXCEPTIONS_LOCKEXCEPTION_H_ */
