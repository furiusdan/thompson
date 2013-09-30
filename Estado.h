#ifndef __ESTADO_H__
#define __ESTADO_H__
#include "Transicion.h"
#include <list>
#include <string>

class Transicion;

class Estado{
	private:
		std::string id;
		std::list<Transicion*> transiciones;
	public:
		void agregarTransicion(char simbolo, Estado *e);
		void setId(std::string id);
		std::string getId();
		void setTransiciones(std::list<Transicion*> t);
		std::list<Transicion*> getTransiciones();
};
#endif
