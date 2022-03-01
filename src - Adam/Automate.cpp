#include <iostream>
#include"Etat.h"

Automate::Automate(string flux) 
{
  this->lexer = new Lexer(flux);
  Etat0 *depart = new Etat0();
  pileEtat.push(depart);
}




void Automate::run() {
  //bool stop = false; Je ne sais pas pourquoi ca ne marche pas...
  int i=100000; // I added this integer to be able to run the loop one more time because my while stops one loop before the end
  Symbole *s;
  while (i>0) {
    s = lexer->Consulter();
        bool nextState = pileEtat.top()->transition(*this, s);
        i--;
        if((*s==FIN && nextState)|| *pileSymbole.top()==ERREUR ){
            //stop = true;
            i=0;
            }
        if(nextState) lexer->Avancer(); 
      }

      if (*pileSymbole.top() != ERREUR) {
        int resultat = pileSymbole.top()->getValeur();
        cout << "Expression correct" << endl << "Resultat : " << resultat << endl;
        } 
      else {
        cout << "Syntaxe non reconnu : caractere invalide" << endl;
        }
}




void Automate::decalage(Symbole *s, Etat *e) 
{
    pileSymbole.push(s);
    pileEtat.push(e);
}

void Automate::reduction(int n, Symbole *s)
{
    for (int i =0; i<n; i++) {
        delete(pileEtat.top());
        pileEtat.pop();
    }
    pileEtat.top()->transition(*this, s);
}


Symbole * Automate::getTopSymbole() {
    Symbole* s = pileSymbole.top();
    return s;
}

void Automate::popSymbole() {
    delete(pileSymbole.top());
    pileSymbole.pop();
}

void Automate::popAndDestroySymbole() {
    pileSymbole.pop();
}