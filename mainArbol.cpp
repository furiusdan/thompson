#include "Arbol.h"
using namespace std;
int main()
{
   arbol arbol;
   arbol.inicializar_arbol('*');
   arbol.ins_izq(NULL,'a');
   arbol.ins_der(NULL,'b');

  arbol.postorden();
  cout <<endl;

   return 0;
}
