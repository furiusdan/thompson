#ifndef __TRANSICION_H__
#define __TRANSICION_H__
#include "Estado.h"
class Estado;

class Transicion{
	private: 
		char simbolo;
		Estado* destino;
	public:
		Transicion(char simbolo, Estado *e);
		void setSimbolo(char simbolo);
		char getSimbolo();
		void setEstado(Estado *e);
		Estado *getDestino();
	
};
#endif
