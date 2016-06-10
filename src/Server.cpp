//============================================================================
// Name        : ConcuChat.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <unistd.h>
#include <stdlib.h>
#include <iostream>

#include "model/ManejadorDeMensajes.h"

using namespace std;

int main() {

	ManejadorDeMensajes manejadorDeMensajes;
	manejadorDeMensajes.run();

	return 0;
}
