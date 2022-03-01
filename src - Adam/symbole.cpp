#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

int Entier::getValeur() { return valeur; }

int Symbole::getValeur() { return -1; }

int Expression::getValeur() { return valeur; }

void OpenPar::Affiche() {Symbole::Affiche() ;}

void ClosePar::Affiche() {Symbole::Affiche() ;}

void Plus::Affiche() {Symbole::Affiche() ;}

void Mult::Affiche() {Symbole::Affiche() ;}

void Fin::Affiche() {Symbole::Affiche() ;}

void Erreur::Affiche() {Symbole::Affiche() ;}

void Expression::Affiche() {Symbole::Affiche() ;}