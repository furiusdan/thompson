a.out:	main.o Estado.o Transicion.o Automata.o
	g++ main.o Estado.o Transicion.o Automata.o
Transicion.o:	Transicion.cpp
	g++ -c Transicion.cpp
Estado.o:	Estado.cpp
	g++ -c Estado.cpp
main.o:	main.cpp
	g++ -c -std=c++11 main.cpp
Automata.o: Automata.cpp
	g++ -c Automata.cpp
clean:
	rm a.out *.o

