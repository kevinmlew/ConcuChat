/*
 * FileHelper.h
 *
 *  Created on: May 5, 2016
 *      Author: juan
 */

#ifndef IPC_FILEHELPER_H_
#define IPC_FILEHELPER_H_

#include <string>
#include <unistd.h>

using namespace std;

class FileHelper {
public:
	static string crearArchivo(string nombre, string ext);
	static int borrarArchivo(string nombre, string ext);
	virtual ~FileHelper();
};


#endif /* IPC_FILEHELPER_H_ */
