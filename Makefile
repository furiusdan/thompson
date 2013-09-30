automata:	main.o Estado.o Transicion.o Automata.o Pila.o
	g++ -o automata main.o Estado.o Transicion.o Automata.o Pila.o
Transicion.o:	Transicion.cpp
	g++ -c Transicion.cpp
Estado.o:	Estado.cpp
	g++ -c Estado.cpp
main.o:	main.cpp
	g++ -c -std=c++11 main.cpp
Automata.o: Automata.cpp
	g++ -c Automata.cpp
Pila.o:	Pila.cpp
	g++ -c Pila.cpp
clean:
	rm automata *.o

