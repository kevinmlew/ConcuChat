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

#define TIPO_ASIGNACION_ID 0
#define TIPO_NUEVA_CONEXION 1

#define TEXTO_SIZE 255

typedef struct mensaje {
	long mtype;
	int tipoMensaje;
	int userId;
	char texto [TEXTO_SIZE];
} mensaje;

#endif /* MODEL_MENSAJE_H_ */
