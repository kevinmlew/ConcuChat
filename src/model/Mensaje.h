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
#define TIPO_SELECCION_NOMBRE 2
#define TIPO_CHAT 3
#define TIPO_SALIR 4
#define TIPO_HISTORIAL 5

#define STATUS_OK 0
#define STATUS_ERROR -1
#define STATUS_INCOMPLETO 1

#define TEXTO_SIZE 255

typedef struct mensaje {
	long mtype; //Tipo de mensaje a enviar segun cola (id del receptor)
	int tipoMensaje; //Tipo del mensaje a enviar
	int userId; //Autor del mensaje
	int status;
	char texto [TEXTO_SIZE]; //Contenido del mensaje
} mensaje;

#endif /* MODEL_MENSAJE_H_ */
