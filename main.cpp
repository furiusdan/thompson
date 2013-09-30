#include "Transicion.h"
#include "Estado.h"
#include "Automata.h"
#include <string>
#include <iostream>

Automata *getConsThompSimbolo(char simbolo);
void imprimirAutomata(Automata *a);
Automata *getConsThompConc(Automata *a1, Automata *a2);
Automata *getConsThompUnion(Automata *a1, Automata *a2);
Automata *getConsThompPos(Automata *a1);
Automata *getConsThompEstrella(Automata *a1);


int main(void){

	
	Automata *a = getConsThompSimbolo('a');
	Automata *a1 = getConsThompSimbolo('b');
	Automata *f = getConsThompUnion(a,a1);
	Automata *f1 = getConsThompEstrella(f);

	imprimirAutomata(f1);
	return 0;
}

//Construcciones de THOMPSOM

Automata *getConsThompSimbolo(char simbolo){
	Estado *ini = new Estado;
	Estado *fin = new Estado;
	ini->agregarTransicion(simbolo, fin);

	Automata *a = new Automata(ini,fin);

	return a;
}



void imprimirAutomata(Automata *a){
	int id = 1;
	std::list<Estado*> cola;
	Estado *ini = a->getInicial();

	ini->setId(std::to_string(id)); //se visita el nodo
	cola.push_back(ini);

	std::list<Transicion*>::iterator i;
	Estado *temp;

	while(!cola.empty()){
		temp = cola.front();
		//std::cout << temp->getId() << std::endl;
		cola.pop_front();
		
		std::list<Transicion*> adj = temp->getTransiciones();

		for(i=adj.begin(); i != adj.end(); ++i){
			Transicion *t = *i;
			Estado *e = t->getDestino();
			
			if(e->getId().empty()){  //No ha sido visitado
				id++;
				e->setId(std::to_string(id));
				
				char sim = t->getSimbolo() == '\0'? 'e' : t->getSimbolo();

				std::cout << temp->getId() << " " << sim << " " << e->getId() << "\n";
				cola.push_back(e);
			}else{
				char sim = t->getSimbolo() == '\0'? 'e' : t->getSimbolo();
				std::cout << temp->getId() << " " << sim << " " << e->getId() << "\n";
			}
		}

	}
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




