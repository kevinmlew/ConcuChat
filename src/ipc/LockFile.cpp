#include "LockFile.h"

#include <asm-generic/errno-base.h>
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include <cstdio>

#include "../exceptions/LockException.h"
#include "FileHelper.h"

#define ARCHIVO_LOCK_EXT "tmp"

LockFile :: LockFile ( const std::string nombre ) {
	std::string nombreCompleto = FileHelper::crearArchivo(nombre, ARCHIVO_LOCK_EXT);
	this->nombre = nombre;
	this->fl.l_type = F_WRLCK;
	this->fl.l_whence = SEEK_SET;
	this->fl.l_start = 0;
	this->fl.l_len = sizeof(char);
	this->fd = open ( nombreCompleto.c_str(),O_CREAT|O_WRONLY,0777 );
	if (fd == -1) throw LockException(LockException::TYPE_CREAR, errno);
}

int LockFile :: tomarLock (int pos) {
	this->fl.l_type = F_WRLCK;
	this->fl.l_start = sizeof(char) * pos;
	int resultado = fcntl ( this->fd,F_SETLKW,&(this->fl) );
	if (resultado == -1 && errno != EAGAIN)
		throw LockException(LockException::TYPE_TOMAR, errno);
	return resultado;
}

int LockFile :: liberarLock (int pos) {
	this->fl.l_type = F_UNLCK;
	this->fl.l_start = sizeof(char) * pos;
	int resultado = fcntl ( this->fd,F_SETLK,&(this->fl) );
	if (resultado == -1)
		throw LockException(LockException::TYPE_LIBERAR, errno);
	return resultado;
}

void LockFile :: destruirArchivoLock(){
	FileHelper::borrarArchivo(this->nombre, ARCHIVO_LOCK_EXT);
}

LockFile :: ~LockFile () {
	close ( this->fd );
}

