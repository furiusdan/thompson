#include "Arbol.h"
using namespace std;
void Arbol::inicializar_arbol(char val)
{
   nn = new nodo;
   nn->valor=val;
   raiz=nn;
}

void Arbol::ins_izq(struct nodo *p , const char val)
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

void Arbol::ins_der(struct nodo *p, const char val)
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

void Arbol::postorden_aux(struct nodo *p)
{
   if(p==NULL){
      return;
   }
   postorden_aux(p->izq);
   postorden_aux(p->der);
   cout << p->valor;

}

void Arbol::postorden(){
   postorden_aux(raiz);
}
