#ifndef __AUTOMATA_H__
#define	__AUTOMATA_H__
#include "Pila.h"
#include "Arbol.h"
#include <string>
class Automata{
 public:
    Automata();
    Automata(std::string entrada);
 private:
    Automata parser(std::string entrada);
    std::string toPostfija(std::string entrada);
    int precedencia(char op);
};
#endif
