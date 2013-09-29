#include"Pila.h"

char Pila::pop(){
    char c = '\0';
    if(lista.empty()==false){
        c = lista.front();
        lista.pop_front();
        return c;
    }
    else return'\0';
}

void Pila::push(char c){
    lista.push_front(c);
}


