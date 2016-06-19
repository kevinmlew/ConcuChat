/*
 * Historial.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: juan
 */

#include "Historial.h"


Historial::Historial(string archivo) {
	archivoHistorial.open (archivo.c_str(), std::ios::app | std::ios::in | std::ios::out);
}

void Historial::guardarMensaje(string msg){
	archivoHistorial << msg << endl;
}

string Historial::getHistorial(){
	string file;
	archivoHistorial.seekg(0, archivoHistorial.beg);
	file.assign((std::istreambuf_iterator<char>(archivoHistorial)),
	            (std::istreambuf_iterator<char>()));
	return file;
}

Historial::~Historial() {
	archivoHistorial.close();
}

