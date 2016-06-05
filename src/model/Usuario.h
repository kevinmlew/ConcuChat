/*
 * Usuario.h
 *
 *  Created on: 5 de jun. de 2016
 *      Author: kevin
 */

#ifndef MODEL_USUARIO_H_
#define MODEL_USUARIO_H_

#include <string>

using namespace std;

class Usuario {
private:
	int id;
	string nombre;
	bool activo;
public:
	Usuario(int id, string nombre);
	void setActivo(bool activo);
	bool isActivo();
	virtual ~Usuario();

};

#endif /* MODEL_USUARIO_H_ */
