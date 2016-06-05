/*
 * FileHelper.cpp
 *
 *  Created on: May 5, 2016
 *      Author: juan
 */

#include "FileHelper.h"
#include <fstream>

using namespace std;

string FileHelper::crearArchivo(string name, string ext){
	string nombreCompleto(name + "." + ext);
	ofstream archivo(nombreCompleto.c_str(), ios::app);
	archivo.close();
	return nombreCompleto;
}
int FileHelper::borrarArchivo(string name, string ext){
	return remove( (name + "." + ext).c_str());
}

FileHelper::~FileHelper() {
}

