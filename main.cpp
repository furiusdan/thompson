#include "Transicion.h"
#include "Estado.h"
#include "Automata.h"

int main(void){

	return 0;
}

//Construcciones de THOMPSOM

Automata *getConsThompSimbolo(char simbolo){
	Estado *ini = new Estado;
	Estado *fin = new Estado;
	ini->agregarTransicion(simbolo, ini);

	Automata *a = new Automata(ini,fin);

	return a;
}

Automata *getConsThompConc(Automata *a1, Automata *a2){
	Estado *ini = a1->getInicial();
	Estado *fin = a2->getFinal();

	Estado *temp = a1->getFinal();
	Estado *temp2 = a2->getInicial();

	temp->setTransiciones(temp2->getTransiciones());
	
	delete temp2;
	delete a1;
	delete a2;

	return new Automata(ini,fin);

}

Automata *getConsThompUnion(Automata *a1, Automata *a2){
	Estado *ini = new Estado;
	Estado *fin = new Estado;
	ini->agregarTransicion('\0', a1->getInicial());
	ini->agregarTransicion('\0', a2->getInicial());

	a1->getFinal()->agregarTransicion('\0', fin);
	a2->getFinal()->agregarTransicion('\0', fin);

	delete a1;
	delete a2;

	return new Automata(ini, fin);
}

Automata *getConsThompPos(Automata *a1){
	Estado *ini = new Estado;
	Estado *fin = new Estado;
	ini->agregarTransicion('\0',a1->getInicial());
	Estado *temp = a1->getFinal();
	temp->agregarTransicion('\0',a1->getInicial());
	temp->agregarTransicion('\0', fin);
	
	delete a1;

	return new Automata(ini,fin);
}

Automata *getConsThompEstrella(Automata *a1){
	Estado *ini = new Estado;
	Estado *fin = new Estado;
	
	ini->agregarTransicion('\0', fin);
	ini->agregarTransicion('\0', a1->getInicial() );

	Estado *temp = a1->getFinal();
	temp->agregarTransicion('\0',a1->getInicial());
	temp->agregarTransicion('\0', fin);
	
	delete a1;
	
	return new Automata(ini, fin);

}




