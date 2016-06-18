/*
 * Historial.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: juan
 */

#include "Historial.h"


Historial::Historial(string archivo) {
	archivoHistorial.open ("archivo", std::ios::app);
}

void Historial::guardarMensaje(string msg){
	archivoHistorial << msg << endl;
}

string Historial::getHistorial(){
	//TODO revisar si al iterator de ifs hay que asignarle la posicion del inicio del file
	string file;
	file.assign((std::istreambuf_iterator<char>(archivoHistorial)),
	            (std::istreambuf_iterator<char>()));
	return file;
}

Historial::~Historial() {
	archivoHistorial.close();
}

