#ifndef COLA_H_
#define COLA_H_

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cerrno>
#include <string>

#include "../exceptions/ColaException.h"
#include "FileHelper.h"

#define ARCHIVO_COLA_EXT "tmp"

template <class T> class Cola {
	private:
		key_t	clave;
		int		id;
		std::string nombreArchivo;

	public:
		Cola ( const std::string& archivo,const char letra );
		~Cola();
		int escribir ( const T& dato ) const;
		int leer ( const int tipo,T* buffer ) const;
		int destruir () const;
};

template <class T> Cola<T> :: Cola ( const std::string& archivo,const char letra ) {
	std::string nombreCompleto = FileHelper::crearArchivo(archivo, ARCHIVO_COLA_EXT);
	nombreArchivo = archivo;
	this->clave = ftok ( nombreCompleto.c_str(),letra );
	if ( this->clave == -1 )
		perror ( "Error en ftok" );

	this->id = msgget ( this->clave,0777|IPC_CREAT );
	if ( this->id == -1 )
		perror ( "Error en msgget" );
}

template <class T> Cola<T> :: ~Cola () {
}

template <class T> int Cola<T> :: destruir () const {
	int resultado = msgctl ( this->id,IPC_RMID,NULL );
	if (resultado == -1)
		throw ColaException(ColaException::TYPE_DESTRUIR, errno);
	FileHelper::borrarArchivo(nombreArchivo, ARCHIVO_COLA_EXT);
	return resultado;
}

template <class T> int Cola<T> :: escribir ( const T& dato ) const {
	int resultado = msgsnd ( this->id,static_cast<const void*>(&dato),sizeof(T)-sizeof(long),0 );
	if (resultado == -1)
			throw ColaException(ColaException::TYPE_ESCRIBIR, errno);
	return resultado;
}

template <class T> int Cola<T> :: leer ( const int tipo,T* buffer ) const {
	int resultado = msgrcv ( this->id,static_cast<void *>(buffer),sizeof(T)-sizeof(long),tipo,0 );
	if (resultado == -1 && errno != EINTR)
		throw ColaException(ColaException::TYPE_LEER, errno);
	return resultado;
}

#endif /* COLA_H_ */
