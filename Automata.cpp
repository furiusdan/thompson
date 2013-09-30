#include "Automata.h"


void Automata::setInicial(Estado *e){
	this->inicial = e;
}

Estado *Automata::getInicial(){
	return this->inicial;
}

void Automata::setFinal(Estado *e){
	this->final = e;
}

Estado *Automata::getFinal(){
	return this->final;
}

Automata::Automata(Estado *inicial, Estado *final){
	this->inicial = inicial;
	this->final = final;
}


