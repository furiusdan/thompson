#include "Transicion.h"
#include "Estado.h"
#include "Automata.h"
#include <string>
#include <iostream>
#include <list>
#include "Pila.h"

Automata *getConsThompSimbolo(char simbolo);
Automata *getConsThompConc(Automata *a1, Automata *a2);
Automata *getConsThompUnion(Automata *a1, Automata *a2);
Automata *getConsThompPos(Automata *a1);
Automata *getConsThompEstrella(Automata *a1);
Automata *parseThompson(std::string exp);
Automata *parseThompson(std::string exp);
bool esOperando(char a);
int precedencia(char op);
std::string getPosfija(std::string input);
void imprimirAutomata(Automata *a);

int main(int argc, char *argv[]){
	
	if(argc != 2){
		std::cout << "Error: uso ./automata regex" << std::endl;
		exit(1);
	}

	std::cout << "Tabla de transicones:" << std::endl;
	

	std::string posfija =getPosfija(std::string(argv[1]));

	Automata *f = parseThompson(posfija);
	imprimirAutomata(f);
	std::cout << "Inicial: " << f->getInicial()->getId() << std::endl;
	std::cout << "Final: " << f->getFinal()->getId() << std::endl;

	return 0;
}

int precedencia(char op) {
    int prf = 99;
    if (op == '*' || op == '+'){
        prf = 5;
    }
    if (op == '.'){
        prf = 4;
    }
    if (op == '|'){
        prf = 3;
    }
    if (op == ')'){
        prf = 2;
    }
    if (op == '('){
        prf = 1;
    }
    return prf;
}

std::string getPosfija(std::string input){
	std::string resultado;
    Pila *salida= new Pila();
    Pila *operadores= new Pila();
    int i = 0;
    char c = '\0';
    char o = '\0';
    //std::cout << input << std::endl;
    for(i=0 ; i<input.size() ; i++){
        //std::cout << entrada->pop();
        c=input.at(i);
        //std::cout << c << std::endl;
        switch(precedencia(c)){
            case 1:
                //std::cout << 1 << std::endl;
                operadores->push(c);
            break;
            case 2:
                //std::cout << 2 << std::endl;
                while((o = operadores->pop()) != '(' && o!='\0'){
                    salida->push(o);
                }
                //operadores->pop();
                //entrada->pop();
            break;
            case 3:
            case 4:
            case 5:
                //std::cout << 5 << std::endl;
                while(precedencia((o = operadores->pop())) >= precedencia(c) && o!='\0'){
                    salida->push(o);
                }
                if(o != '\0'){
                    operadores->push(o);
                }
                operadores->push(c);
                //operadores->push(c);
            break;
            default:
               // std::cout << "otro" << std::endl;
                salida->push(c);
            break;
        };
    }
	while((o=operadores->pop()) != '\0'){
        salida->push(o);
    }

	while((c=salida->pop()) != '\0'){
		resultado.append(std::string(1,c));
	}
	
	return std::string(resultado.rbegin(), resultado.rend());

}

Automata *parseThompson(std::string exp){
	std::list<Automata*> stack;
	for(char c: exp){
		if(esOperando(c)){
			//Lo agrega a la pila
			Automata *a = getConsThompSimbolo(c);
			stack.push_front(a);
		}else{
			//Extraemos el primer operando
			Automata *op1 = stack.front();
			Automata *op2;
			Automata *retVal;
			stack.pop_front();

			switch(c){
				case '*':
					//Construir el automata de la cerradura positiva
					retVal = getConsThompEstrella(op1);
					stack.push_front(retVal);
				break;
				case '+':
					retVal = getConsThompPos(op1);
					stack.push_front(retVal);
				break;
				case '.':
					op2 = stack.front();
					stack.pop_front();
					
					retVal = getConsThompConc(op2, op1);
					stack.push_front(retVal);
				break;
				case '|':
					op2 = stack.front();
					stack.pop_front();
					retVal = getConsThompUnion(op1,op2);
					stack.push_front(retVal);
				break;

			}

		}
	}

	return stack.front();
}

bool esOperando(char a){
	if(a == '*' || a == '+' || a == '.' || a == '|' )
		return false;
	return true;
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




