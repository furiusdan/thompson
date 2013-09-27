#include"Pila.h"

char Pila::pop(){
    char c = lista.front();
    lista.pop_front();
    return c;
}

void Pila::push(char c){
    lista.push_front(c);
}


