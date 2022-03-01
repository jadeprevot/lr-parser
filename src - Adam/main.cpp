#include <iostream>
#include "lexer.h"
#include "Automate.h"


int main(void) {
   string chaine("(1+34)*123");

   Automate *automate = new Automate(chaine);
   automate->run();
   /*Lexer l(chaine);
   Symbole * s;
   while(*(s=l.Consulter())!=FIN) {
      s->Affiche();
      cout<<endl;
      l.Avancer();
   }*/

   return 0;
}

