#ifndef __PILA_H__
#define __PILA_H__
#include <list>
class Pila{
	public:
		void push(char c);
		char pop();
	private:
		std::list<char> lista;
		
};
#endif
