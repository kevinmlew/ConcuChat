/*
 * Conexion.h
 *
 *  Created on: 5 de jun. de 2016
 *      Author: kevin
 */

#ifndef MODEL_MENSAJE_H_
#define MODEL_MENSAJE_H_

#define USUARIO_NO_REGISTRADO 0
#define MENSAJE_A_SERVIDOR 1
#define REGISTRAR_USUARIO 2
#define PRIMER_USUARIO 5

#define TEXTO_SIZE 255

typedef struct mensaje {
	long mtype;
	int userId;
	char texto [TEXTO_SIZE];
} mensaje;

#endif /* MODEL_MENSAJE_H_ */
