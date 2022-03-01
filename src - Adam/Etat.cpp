#include "Etat.h"
#include "symbole.h"
#include <iostream>


bool Etat0::transition(Automate &automate, Symbole *s)
{
    switch(*s) {
    case INT:
        automate.decalage(s, new Etat3);
        break;
    case OPENPAR:
        automate.decalage(s, new Etat2);
        break;
    case EXPR:
        automate.decalage(s, new Etat1);
        break;
    default:
        automate.decalage(new Symbole(ERREUR), NULL);
        return false;  
    }
      return true;
}

bool Etat1::transition(Automate &automate, Symbole *s)
{
    switch(*s) {
    case PLUS:
        automate.decalage(s, new Etat4);
        break;
    case MULT:
        automate.decalage(s, new Etat5);
        break;
    case FIN:
        return false;
    default:
        automate.decalage(new Symbole(ERREUR), NULL);
        return false;  
    }
    return true;
}

bool Etat2::transition(Automate &automate, Symbole *s)
{
    switch (*s) {
    case INT:
        automate.decalage(s, new Etat3);
        break;
    case OPENPAR:
        automate.decalage(s, new Etat2);
        break;
    case EXPR:
        automate.decalage(s, new Etat6);
        break;
    default:
        automate.decalage(new Symbole(ERREUR), NULL);
        return false;
    }
  return true;
}

bool Etat3::transition(Automate &automate, Symbole *s)
{
    switch (*s) {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
    {
        Entier *s1 = (Entier*) (automate.getTopSymbole());
        int e1 = s1->getValeur();
        automate.popSymbole();
        automate.reduction(1, new Expression(e1));
        return false;
    }



    default:
        automate.decalage(new Symbole(ERREUR), NULL);
        return false;
    }
    return true;
}

bool Etat4::transition(Automate &automate, Symbole *s)
{
    switch (*s) {
    case INT:
        automate.decalage(s, new Etat3);
        break;
    case OPENPAR:
        automate.decalage(s, new Etat2);
        break;
    case EXPR:
        automate.decalage(s, new Etat7);
        break;
    default:
        automate.decalage(new Symbole(ERREUR), NULL);
        return false;
    }
  return true;
}

bool Etat5::transition(Automate &automate, Symbole *s)
{
    switch(*s) {
    case INT:
        automate.decalage(s, new Etat3);
        break;
    case OPENPAR:
        automate.decalage(s, new Etat2);
        break;
    case EXPR:
        automate.decalage(s, new Etat8);
        break;
    default:
        automate.decalage(new Symbole(ERREUR), NULL);
        return false;  
    }
  return true;
}

bool Etat6::transition(Automate &automate, Symbole *s)
{
    switch(*s) {
    case PLUS:
        automate.decalage(s, new Etat4);
        break;
    case MULT:
        automate.decalage(s, new Etat5);
        break;
    case CLOSEPAR:
        automate.decalage(s, new Etat9);
        break;
    default:
        automate.decalage(new Symbole(ERREUR), NULL);
        return false;
    }  
  return true;
}

bool Etat7::transition(Automate &automate, Symbole *s)
{
    switch(*s) {
    case PLUS:
    case CLOSEPAR:
    case FIN:
        {
         Expression *s1 = (Expression*) automate.getTopSymbole();
         int ss1 = s1->getValeur();
         automate.popSymbole();
         automate.popSymbole();
         Expression *s2 = (Expression*) automate.getTopSymbole();
         int ss2 = s2->getValeur();
         automate.popSymbole();
         automate.reduction(3, new Expression(ss1+ss2));
         return false;    
        }

    case MULT:
        automate.decalage(s, new Etat5);
        break;

    default:
        automate.decalage(new Symbole(ERREUR), NULL);
        return false;
    }  
  return true;
}

bool Etat8::transition(Automate &automate, Symbole *s)
{
    switch(*s) {
    case PLUS :
    case MULT :
    case CLOSEPAR :
    case FIN :
    {
        Expression *s1 = (Expression*) automate.getTopSymbole();
        int ss1 = s1->getValeur();
        automate.popSymbole();
        automate.popSymbole();
        Expression *s2 = (Expression*) automate.getTopSymbole();
        int ss2 = s2->getValeur();
        automate.popSymbole();
        automate.reduction(3,new Expression(ss1*ss2));
        return false;
    }
    break;
    default:
        automate.decalage(new Symbole(ERREUR), NULL);
        return false;
    }
    return true;
}

bool Etat9::transition(Automate &automate, Symbole *s)
{
    switch(*s) {
    case PLUS :
    case MULT :
    case CLOSEPAR :
    case FIN :
    {
        automate.popSymbole();
        Expression  *s1 = (Expression*) automate.getTopSymbole();
        int ss1 = s1->getValeur();
        automate.popSymbole();
        automate.popSymbole();
        automate.reduction(3,new Expression(ss1));
        return false;
    }
    break;
    default:
        automate.decalage(new Symbole(ERREUR), NULL);
        return false;
    }
    return true;
}