# include"Automata.h"
int Automata::precedencia(char op) {
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
Automata Automata::parser(std::string input){
    Pila entrada;
    Pila salida;
    Pila operadores;
    int i = 0;
    char c = '\0';
    char o = '\0';
    char e = '\0';
    for(i=0 ; i<=input.size() ; i++){
        entrada.push(input[i]);
    }
    while(c=entrada.pop() != '\0'){
        switch(precedencia(c)){
            case 1:
                operadores.push(c);
                break;
            case 2:
                while(o = operadores.pop() != '('){
                    salida.push(o);
                }
                operadores.pop();
                entrada.pop();
                break;
            case 3:
            case 4:
            case 5:
                while(precedencia(o = operadores.pop()) >= precedencia(e = entrada.pop())){
                    salida.push(o);
                    entrada.push(e);
                }
                salida.push(entrada.pop());
                break;
            default:
                salida.push(entrada.pop());
                break;
        };
    }
    
}
