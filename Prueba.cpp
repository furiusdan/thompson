#include <iostream>
#include "Pila.h"
#include <string>
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
int main (void){
    std::string input("(a.a|b.b|c.c)*.b.c");
    Pila *salida= new Pila();
    Pila *operadores= new Pila();
    int i = 0;
    char c = '\0';
    char o = '\0';
    //std::cout << input << std::endl;
    for(i=0 ; i<input.size() ; i++){
        //std::cout << entrada->pop();
        c=input.at(i);
        std::cout << c << std::endl;
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
                std::cout << "otro" << std::endl;
                salida->push(c);
                break;
        };
    }
    while((o=operadores->pop()) != '\0'){
        salida->push(o);
    }
    for(i=0;i<=15;i++){
        char c = salida->pop();
        std::cout << c;
    }


}

