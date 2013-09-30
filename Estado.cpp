#include "Estado.h"
void Estado::agregarTransicion(char simbolo, Estado *e){
	Transicion *t = new Transicion(simbolo, e);
	transiciones.push_front(t);
}

void Estado::setId(std::string id){
	this->id = id;
}

std::string Estado::getId(){
	return id;
}

void Estado::setTransiciones(std::list<Transicion*> t){
	this->transiciones = t;
}


std::list<Transicion*> Estado::getTransiciones(){
	return this->transiciones;
}
