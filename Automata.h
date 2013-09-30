#ifndef __AUTOMATA_H__
#define	__AUTOMATA_H__
#include "Estado.h"
class Automata{
	private:
		Estado *inicial;
		Estado *final;
	public:
		void setInicial(Estado *e);
		Estado *getInicial();

		void setFinal(Estado *e);
		Estado *getFinal();

		Automata(Estado *inicial, Estado *final);
 };
#endif
