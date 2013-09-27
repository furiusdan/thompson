#include <iostream>
#include "Pila.h"
int main(void){
	Pila *p = new Pila();

	p->push('a');
	p->push('c');

	char c = p->pop();

	std::cout << c << std::endl;

	c = p->pop();

	std::cout << c << std::endl;
	
	c = p->pop();
		
	std::cout << c << std::endl;
}    
