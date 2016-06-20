/*
 * ColaException.h
 *
 *  Created on: Jun 19, 2016
 *      Author: juan
 */

#ifndef EXCEPTIONS_COLAEXCEPTION_H_
#define EXCEPTIONS_COLAEXCEPTION_H_

#include <string>

#include "IPCException.h"

using namespace std;

class ColaException : public IPCException {
public:
	ColaException(string msg, int code);
	virtual ~ColaException();

	static string TYPE_LEER;
	static string TYPE_ESCRIBIR;
	static string TYPE_DESTRUIR;
};

#endif /* EXCEPTIONS_COLAEXCEPTION_H_ */
