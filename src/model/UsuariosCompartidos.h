/*
 * UsuariosCompartidos.h
 *
 *  Created on: 5 de jun. de 2016
 *      Author: kevin
 */

#ifndef MODEL_USUARIOSCOMPARTIDOS_H_
#define MODEL_USUARIOSCOMPARTIDOS_H_

#include "../ipc/LockFile.h"
#include "../ipc/MemoriaCompartida.h"
#include "Usuario.h"

class UsuariosCompartidos {
private:
	MemoriaCompartida<Usuario> mem;
	MemoriaCompartida<int> cantidadUsuarios;
	//LockFile lockUsuarios;
	//LockFile lockCantidadUsuarios;
public:
	UsuariosCompartidos();
	void agregarUsuario(Usuario usuario);
	void agregarUsuarioAlFinal(Usuario usuario);
	void editarUsuario(Usuario usuario, int pos);
	void escribir(Usuario usuario);
	virtual ~UsuariosCompartidos();
};

#endif /* MODEL_USUARIOSCOMPARTIDOS_H_ */
