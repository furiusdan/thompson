#include "Arbol.h"
using namespace std;
void arbol::inicializar_arbol(char val)
{
   nn = new nodo;
   nn->valor=val;
   raiz=nn;
}

void arbol::ins_izq(struct nodo *p , const char val)
{
   if(val!=' '){
      nn = new nodo;
      nn->valor=val;
      raiz->izq=nn;

      nn->izq=NULL;
      nn->der=NULL;
      return;
   }
   raiz->izq=p;
}

void arbol::ins_der(struct nodo *p, const char val)
{
   if(val!=' '){
      nn = new nodo;
      nn->valor=val;
      raiz->der=nn;

      nn->izq=NULL;
      nn->der=NULL;

      return;
   }
   raiz->der=p;
}

/*void arbol::inorden(struct nodo *p)
{

}

void arbol::preorden(struct nodo *p)
{

}*/

void arbol::postorden_aux(struct nodo *p)
{
   if(p==NULL){
      return;
   }
   postorden_aux(p->izq);
   postorden_aux(p->der);
   cout << p->valor;

}

void arbol::postorden(){
   postorden_aux(raiz);
}
