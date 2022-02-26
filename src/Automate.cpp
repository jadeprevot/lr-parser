#include <iostream>
#include "Automate.h"
#include"Etat.h"

Automate::Automate(string flux) 
{
  this->lexer = new Lexer(flux);
  Etat0 *depart = new Etat0();
  pileEtat.push(depart);
}

void Automate::run() 
{
    bool prochainEtat = true;
    while(prochainEtat) {
    Symbole* s = lexer->Consulter();
       
    }

}

void Automate::decalage(Symbole *s, Etat *e) 
{
    pileSymbole.push(s);
    pileEtat.push(e);
}

void Automate::reduction(int n, Symbole *s)
{
    
}