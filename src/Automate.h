#ifndef AUTOMATE_H
#define AUTOMATE_H

#pragma once
#include <string>
#include <stack>
#include "lexer.h"
#include "symbole.h"
using namespace std;

class Etat;
class Etat0;
class Etat1;
class Etat2;
class Etat3;
class Etat4;
class Etat5;
class Etat6;
class Etat7;
class Etat8;
class Etat9;


class Automate {

    public:
    Automate(string flux);
    void decalage(Symbole *s, Etat *e);
    void reduction(int n, Symbole *s);
    void run ();
    Symbole * getTopSymbole();
    void popSymbole();
    void popAndDestroySymbole();

    protected:
    stack<Symbole*> pileSymbole;
    stack<Etat*> pileEtat;
    Lexer * lexer;

};

#endif // Automate_H