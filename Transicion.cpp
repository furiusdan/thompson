#include "Transicion.h"
Transicion::Transicion(char simbolo, Estado *e){
	this->simbolo = simbolo;
	this->destino = e;
}

void Transicion::setSimbolo(char simbolo){
	this->simbolo = simbolo;
}

char Transicion::getSimbolo(){
	return simbolo;
}

void Transicion::setEstado(Estado *e){
	this->destino = e;
}

Estado *Transicion::getDestino(){
	return this->destino;
}




