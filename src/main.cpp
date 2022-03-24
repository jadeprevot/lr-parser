#include <iostream>
#include "lexer.h"
#include "Automate.h"

using namespace std;

int main(void) {
   string expression;
   cout<< "Veuillez entrer une expression à analyser : " <<endl;
   cin>> expression;
   Automate *automate = new Automate(expression);
   automate->run();
   return 0;
}