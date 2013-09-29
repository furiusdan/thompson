#ifndef ARBOL_H_
#define ARBOL_H_
#include <iostream>
class arbol
{
   struct nodo{
      char valor;
      struct nodo *izq;
      struct nodo *der;
   };

   struct nodo *raiz,*nn;
   public:
      void inicializar_arbol(char val);
      void ins_der(struct nodo *p,char val);
      void ins_izq(struct nodo *p,char val);

		//void inorden(struct nodo *);
		//void preorden(struct nodo *);
      void postorden();
      void postorden_aux(struct nodo *p);
};

#endif // ARBOL_H_
