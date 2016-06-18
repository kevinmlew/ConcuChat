/*
 * Historial.h
 *
 *  Created on: Jun 18, 2016
 *      Author: juan
 */

#ifndef MODEL_HISTORIAL_H_
#define MODEL_HISTORIAL_H_

#include <fstream>
#include <string>

using namespace std;

class Historial {
private:
	fstream archivoHistorial;
public:
	Historial(string nombreArchivo);
	void guardarMensaje(string msg);
	string getHistorial();
	virtual ~Historial();
};

#endif /* MODEL_HISTORIAL_H_ */
