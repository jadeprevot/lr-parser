#include <string>
#include <stack>
#include "lexer.h"
using namespace std;

class Etat;

class Automate {

    public:
    Automate(string flux);
    void decalage(Symbole *s, Etat *e);
    void reduction(int n, Symbole *s);
    void run();

    protected:
    stack<Symbole*> pileSymbole;
    stack<Etat*> pileEtat;
    Lexer & lexer;

};